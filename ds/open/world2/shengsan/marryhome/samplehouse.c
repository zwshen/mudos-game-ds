// ·Rªº¤pºÛ
#include <path.h>
#include <ansi.h>
#include <marry.h>
#define	houseid			DefaultHOUSEID
inherit ROOM;


string	query_short();
string	query_long();
string	query_notice();

void create()
{
	set("short", (: query_short :) );
	set("long", (: query_long :) );
	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"room010",
	    "west" : __DIR__"room017",
	    "south": __DIR__"room002",
	    "north": __DIR__"room042",
            "down" : WD_NOW+"magic-card/room1",
            ]));
	set("objects", ([ /* sizeof() == 1 */
		 __DIR__"npc/salesman" : 1,
	]));
	set("houseid",houseid);
	set("no_clean_up", 0);
	set("light", 1);
	set("item_desc",([
	"notice": (: query_notice :) ]));
	set("valid_startroom",1);

	setup();
//	replace_program(ROOM);
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


