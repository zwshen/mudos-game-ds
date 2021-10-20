// securityd.c

// #pragma save_binary

#include <login.h>

//#define DEBUG

inherit F_DBASE;

// By Annihilator@Eastern.Stories (11/25/94)

// This is the "effective" access status compare to the "status" property
// in login object that this mapping determine wizards' access rights
// directly. It is important to make the "status" property matches this
// mapping for wizards higher than regular wizard such as sage, arch and
// admin. For thoese users whose name doesnot appear in this mapping, they
// are divided into three groups (wizard),(player) and (object) using
// wizardp() and interactive() efun.
// The parenthesis is nessessary to prevend players naming themself "admin"
// to hack the security system.
// 
// 01/14/95 Annihilator - wiz_status are defined outside this daemon in the
//                        WIZLIST file.

// Note: This mapping need be initialized before any file access to let
//       valid_read() and valid_write() works correctly on boot time.
private mapping wiz_status = ([]);

private string *wiz_levels = ({
	"(player)",
	"(immortal)",
	"(apprentice)",
	"(wizard)",
	"(arch)",
	"(admin)"
});

// A valid write attempt must pass 2 checks: your uid or status must not be
// "excluded" and must be "trusted" on that directory in order to write in 
// that directory. The directories containing the file is searched backward
// from the current directory to root. And exclude is checked prior than
// trusted.

private mapping trusted_write = ([
	"/": 			({ "Root", "(admin)", "(arch)" }),
	"open":			({ "(wizard)", "(apprentice)" }),
//	"d/breakland":	({ "swordheart" }),
	"d/cloudy":		({ "knomo" }),
	"ftp/upload":	({ "anonymous" }),
]);

private mapping exclude_write = ([
	"adm":		({ "(arch)" }),
	"data":		({ "(arch)" }),
	"log":		({ "(arch)" }),
	"u":		({ "(arch)" }),
]);

private mapping trusted_read = ([
	"/": 		({	"Root", "Mudlib",
					"(admin)", "(arch)", "(wizard)", "(apprentice)" }),
	"d":		({ "Domain" }),
	"obj":		({ "Domain" }),
	"ftp":		({ "anonymous" }),
]);

private mapping exclude_read = ([
	"adm":		({ "(wizard)", "(apprentice)" }),
	"data":		({ "(wizard)", "(apprentice)" }),
	"u":		({ /*"(wizard)",*/ "(apprentice)" }),
]);

void create()
{
	string *wizlist, wiz_name, wiz_level;
	int i;

	seteuid(getuid());
	set("channel_id", "�w���t��");
	wizlist = explode(read_file(WIZLIST), "\n");
	wiz_status = allocate_mapping(sizeof(wizlist));
	for(i=0; i<sizeof(wizlist); i++) {
		if( wizlist[i][0]=='#' 
		|| sscanf(wizlist[i], "%s %s", wiz_name, wiz_level)!=2 ) continue;
		wiz_status[wiz_name] = wiz_level;
	}
}

string *query_wizlist() { return keys(wiz_status); }

// This function returns the status of an uid.
string get_status(mixed ob)
{
	string euid;
	
	if( objectp(ob) ) {
//	This cause some tools lost access write.
//		if( clonep(ob) && !userp(ob) ) return "(player)";
		euid = geteuid(ob);
		if( !euid ) euid = getuid(ob);
	}
	else if( stringp(ob) ) euid = ob;

	if( member_array(euid, wiz_levels)!=-1 ) return euid;

	if( !undefinedp(wiz_status[euid]) ) return wiz_status[euid];
	else return "(player)";
}

int get_wiz_level(object ob)
{
	return member_array(get_status(ob), wiz_levels);
}

int set_status(mixed ob, string status)
{
	string uid, *wiz, wizlist, old_status;
	int i;

	if( !this_player(1) || member_array(status, wiz_levels) < 0 ) return 0;
	if( geteuid(previous_object())!= ROOT_UID ) return 0;

	if( objectp(ob) )			uid = getuid(ob);
	else if(stringp(ob))		uid = ob;
	else return 0;

	old_status = wiz_status[uid];
	if( !old_status ) old_status = "(player)";
	if( status == old_status ) return 0;
	
	if( status == "(player)" )	map_delete(wiz_status, uid);
	else						wiz_status[uid] = status;

	wiz = keys(wiz_status);
	for(wizlist = "", i=0; i<sizeof(wiz); i++)
		wizlist += wiz[i] + " " + wiz_status[wiz[i]] + "\n";
	rm(WIZLIST);
	write_file(WIZLIST, wizlist);

	log_file( "static/promotion", capitalize(geteuid(this_player(1)))
		+ " promotes " + capitalize(uid) + " from " + old_status + " to "
		+ status + " on " + ctime(time()) + "\n" );


	return 1;
}

string *get_wizlist() { return keys(wiz_status); }

// valid_write - called by the master object to determine whether if an user
//               is allowed to write on a certain file.
// NOTE:
//     The argument user should be an object according to the source code
// of driver. However, it is a mixed type in the released docs. We assume
// it is an object in normal case here and issue an error if it was not
// an object. 												- Annihilator

int valid_write(string file, mixed user, string func)
{
	string euid, status, *path, dir;
	int i;

#ifdef DEBUG
	CHANNEL_D->do_channel(this_object(), "sys",
		sprintf("valid_write: %s, %O, %s", file, user, func));
#endif

	if( !objectp(user) ) return 0;

	// Get the euid and status of the user.
	if( !(euid = geteuid(user)) ) return 0;
	status = get_status(user);

	if( euid==ROOT_UID ) return 1;

	// The following are some special cases.
	path = explode(file, "/");

	if( func=="write_file" && sscanf(file, LOG_DIR + "%*s") ) return 1;

	if( func=="save_object" && sscanf(file, DATA_DIR + "%*s") ) {
		if( euid == MUDLIB_UID ) return 1;
		return 1;
	}

	if( sscanf(file, "/u/" + euid[0..0] + "/" + euid + "/%*s") )
		return 1;

	// Check if we are excluded in one of the directories containing the file.
	for(i=sizeof(path)-1; i>=0; i--) {
		dir = implode(path[0..i], "/");
		if( undefinedp(exclude_write[dir]) ) continue;
		if( (member_array(euid, exclude_write[dir])!=-1)
		||	(member_array(status, exclude_write[dir])!=-1) )
			return userp(user) ? 0: valid_write(file, this_player(1), func);
	}

	// And then check if we are trusted in one of the directories containing
	// the file.
	if( member_array(euid, trusted_write["/"])!=-1 ) return 1;
	if( member_array(status, trusted_write["/"])!=-1 ) return 1;
	for(i=sizeof(path)-1; i>=0; i--) {
		dir = implode(path[0..i], "/");
		if( undefinedp(trusted_write[dir]) ) continue;
		if( member_array(euid, trusted_write[dir])!=-1 ) return 1;
		if( member_array(status, trusted_write[dir])!=-1 ) return 1;
	}

	return 0;
}

int valid_read(string file, mixed user, string func)
{
	string euid, status, *path, dir;
	int i;

#ifdef DEBUG
	CHANNEL_D->do_channel(this_object(), "sys",
		sprintf("valid_read: %s, %O, %s", file, user, func));
#endif

	if( !objectp(user) ) return 0;

	// Let user save their save file
	if( func=="restore_object" ) {
		if( sscanf(base_name(user), "/obj/%*s")
		&&	sscanf(file, "/data/%*s")
		&&	file == (string)user->query_save_file() )
			return 1;
	}

	// Get the euid and status of the user.
	euid = geteuid(user);
	if( !euid ) return 0;
	status = get_status(user);

	if( euid==ROOT_UID ) return 1;

	if( sscanf(file, "/u/" + euid[0..0] + "/" + euid + "%*s") )
		return 1;

	path = explode(file, "/");

	// Check if we are excluded in one of the directories containing the file.
	for(i=sizeof(path)-1; i>=0; i--) {
		dir = implode(path[0..i], "/");
		if( undefinedp(exclude_read[dir]) ) continue;
		if( (member_array(euid, exclude_read[dir])!=-1)
		||	(member_array(status, exclude_read[dir])!=-1) )
			return userp(user) ? 0: valid_read(file, this_player(1), func);
	}

	// And then check if we are trusted in one of the directories containing
	// the file.
	if( member_array(euid, trusted_read["/"])!=-1 ) return 1;
	if( member_array(status, trusted_read["/"])!=-1 ) return 1;
	for(i=sizeof(path)-1; i>=0; i--) {
		dir = implode(path[0..i], "/");
		if( undefinedp(trusted_read[dir]) ) continue;
		if( member_array(euid, trusted_read[dir])!=-1 ) return 1;
		if( member_array(status, trusted_read[dir])!=-1 ) return 1;
	}

	return 0;
}

int valid_seteuid( object ob, string uid )
{
	if( uid==0 ) return 1;
	if( uid==getuid(ob) ) return 1;

	if( getuid(ob)==ROOT_UID ) return 1;
	if( getuid(ob)==MUDLIB_UID || getuid(ob)==DOMAIN_UID )
		return (uid[0]>='a' && uid[0]<='z');
	if( wiz_level(ob) >= wiz_level(uid) )  return 1;

	return 0;
}

