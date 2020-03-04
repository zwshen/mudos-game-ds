// ·Rªº¤pºÛ
#include <path.h>
#include <ansi.h>
#include <marry.h>
#define	houseid			"h1"
#define Ladyname		"¦ã²úµ·"
inherit ROOM;

string	query_short();
string	query_long();
string	query_notice();

void create()
{
	set("short", (: query_short :) );
	set("long", (: query_long :) );
	set("exits", ([ /* sizeof() == 4 */
            "east" : SHENGSAN+"workroom",
            ]));
	set("objects", ([ /* sizeof() == 1 */
		 __DIR__"npc/salesman" : 1,
	]));
	set("houseid",houseid);
	set("Ladyname", Ladyname);
	set("no_clean_up", 0);
	set("light", 1);
	set("item_desc",([
	"notice": (: query_notice :) ]));
	set("valid_startroom",1);

	setup();
//	replace_program(ROOM);
}

void init()
{
	if(!MARRY_D->query_house_created(this_object()->query("houseid")))
		MARRY_D->creat_basehouse(this_object()->query("houseid"));
	if(!userp(this_player())) return;
	

	add_action("do_chshort","chshort");
}

string	query_short()
{
	string str;
	str = MARRY_D->query_house_short(query("houseid"));
	return	str;
}


string	query_long()
{
	int i;
	string str;
	string *line;
	
	str = MARRY_D->query_house_long(query("houseid"));
	return	str+"\n";
}


string query_notice()
{
	int i;
	string str = "§A­n¬Ý¤°»ò¡S";
	
	i = MARRY_D->query_house_bought(query("houseid"));
	if(!i)	str = 
"[1;36m¡I¡I¡I¸¹¥~¡I¡I¡I¸¹¥~¡I¡I¡I¸¹¥~¡I¡I¡I¸¹¥~¡I¡I¡I¸¹¥~¡I¡I¡I¸¹¥~¡I¡I¡I[0m"+"\n"
+"\n"
+"ÂÅ¤Ñ«Ø³]¬°ªA°È®¦·R¤§µ²±B¨k¤k¡A¯S§O©ó¦¹¦a»\\¤F³o¶¡[1;31m¡y·Rªº¤pºÛ¡z[0m¡C"+"\n"
+"»ù®æ°ª¶Q¤£¶Q¡A¥u­n±z[1;33m¤G¤d¸Uª÷¹ô[0m¡A¤£¤G»ù¡A³ßÅw¦A¶R¡C¦pªG±z¤ß°Ê¤F¡A½Ð"+"\n"
+"¬¢¸ß§Ú­Ìªº¾P°â¸g²z¡C(ask about house)"+"\n"
+"\n"
+"[1;36m¡I¡I¡I¸¹¥~¡I¡I¡I¸¹¥~¡I¡I¡I¸¹¥~¡I¡I¡I¸¹¥~¡I¡I¡I¸¹¥~¡I¡I¡I¸¹¥~¡I¡I¡I[0m"+"\n";

	return str;
}


int do_chshort()
{
	return 1;
}



