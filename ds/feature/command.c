// command.c
// #pragma save_binary

#include <command.h>
#include <dbase.h>
#include <origin.h>

// Let command path be nosave, thus we can make sure no one can get command
// path directly from restore_object().
nosave string *path;
nosave mixed halt_command_hook=0;
// Leave this to allow other objects can search your commands such as
// help, which...
string find_command(string verb)
{
	return (string)COMMAND_D->find_command(verb, path);
}
// This is the add_action hook handling movement, commands, emotes and
// channels. Optimization is needed.
protected nomask int command_hook(string arg)
{
	string verb, file;
	
#ifdef PROFILE_COMMANDS
	int mem, utime, stime;
	mapping info;

	mem = memory_info();
	info = rusage();
	utime = info["utime"];
	stime = info["stime"];
#endif

	verb = query_verb();
	if(this_object()->is_inactive() && verb != "save") {
		this_object()->set_inactive(0);
		write("[���m�Ҧ�]�w�����C\n");
	}
	// ��player�ȮɵL�k�ϥΥ�����O.
	if(halt_command_hook && verb!="quit")
	{
		if(stringp(halt_command_hook))
		{	
			//write(halt_command_hook+"\n");
			//message("system", halt_command_hook+"\n", this_object());
			this_object()->receive(halt_command_hook+"\n");
			return 1;
		}
		else if(functionp(halt_command_hook))
		{
			evaluate(halt_command_hook);
			write("\n");
			return 1;
		}
		else if(halt_command_hook!=0)
		{
			//write("�b�ʧ@�����e�A���򳣤��వ�C\n");
			this_object()->receive("�b�ʧ@�����e�A���򳣤��వ�C\n");
			return 1;
		}
	}
	
	// �S���ѼƤ]���O�X�f�άO����
	if( !arg 
	&&	(environment() && (stringp(environment()->query("exits/" + verb)) || stringp(environment()->query("hide_exits/" + verb)) || objectp(environment()->query("exits/" + verb))))
	&&	stringp(file = find_command("go"))
	&&	call_other(file, "main", this_object(), verb))
		;
	
	else if( stringp(file = find_command(verb)) //���O�b�ۤv�����O�j�M���|��
	&& call_other(file, "main", this_object(), arg))
		;
	else if( CHANNEL_D->do_channel( this_object(), verb, arg ) ) //�O�_�����}�����W�D
		;
	else if( EMOTE_D->do_emote( this_object(), verb, arg ) ) //�M��emote�O�_���۲Ū�
		;
	else return 0;

#ifdef PROFILE_COMMANDS
	info = rusage();
	PROFILE_D->log_command(verb, memory_info() - mem, info["stime"] - stime,
		info["utime"] - utime);
#endif

	return 1;
}

protected nomask void set_path(string *p)
{
//	if( origin() != ORIGIN_LOCAL
//	&&	geteuid(previous_object()) != ROOT_UID )
//		return;
	path = p;
}

string *query_path() { return path; }
mixed *query_commands() { return commands(); }

int force_me(string cmd)
{
	if( geteuid(previous_object()) != ROOT_UID 
	   && geteuid(previous_object()) != getuid(this_object())
	)
		return 0;

	return command( this_object()->process_input(cmd) );
}

nomask void enable_player()
{
	string *command_path=({});
	if( stringp(query("id")) ) set_living_name(query("id"));
	else set_living_name(query("name"));

	enable_commands();
	add_action("command_hook", "", 1);

	switch(this_object()->query("race"))
	{
		case "human":command_path=({"/cmds/human/"}); break;
		case "zerg": command_path=({"/cmds/zerg/"}); break;
		case "protoss": command_path=({"/cmds/protoss/"}); break;
		case "robot": command_path=({"/cmds/robot/"}); break;
		case "monster": command_path=({"/cmds/monster/"}); break;
		case "beast": command_path=({"/cmds/beast/"}); break;
		case "meda": command_path=({"/cmds/meda/"}); break;
		default: command_path=({"/cmds/human/"}); break;
	}

	if( !userp(this_object()) )
	{
	 command_path+=NPC_PATH;
	 set_path(command_path);
	}
	else
	switch( wizhood(this_object()) )
	{
		case "(admin)":
			command_path+=ADM_PATH;
			set_path(command_path);
			enable_wizard();
			break;
		case "(arch)":
			command_path+=ARC_PATH;
			set_path(command_path);
			enable_wizard();
			break;
		case "(wizard)":
			command_path+=WIZ_PATH;
			set_path(command_path);
			enable_wizard();
			break;
		case "(apprentice)":
			command_path+=APR_PATH;
			set_path(command_path);
			enable_wizard();
			break;
		case "(immortal)":
			command_path+=IMM_PATH;
			set_path(command_path);
			enable_wizard();	//add by luky
			break;
		case "(superplayer)":
			command_path+=SPL_PATH;
			set_path(command_path);
			break;
		default:
			command_path+=PLR_PATH;
			set_path(command_path);
	}
}

nomask void disable_player(string type)
{
	if( geteuid(previous_object())!=ROOT_UID
	&&	previous_object()!=this_object()) return;

	set("disable_type", type);
	disable_commands();
}

nomask void disable_player_cmds(mixed type)
{
//	if( geteuid(previous_object())!=ROOT_UID
//	&&	previous_object()!=this_object()) return;
	halt_command_hook=type;
}

nomask void enable_player_cmds()
{
	
//	if( geteuid(previous_object())!=ROOT_UID
//	&&	previous_object()!=this_object()) return;

	halt_command_hook=0;
}

mixed query_player_cmds()
{
	return halt_command_hook;
}