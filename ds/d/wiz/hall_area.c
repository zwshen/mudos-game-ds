// Room: /d/wiz/hall2.c
#include <path.h>
inherit ROOM;

void create()
{
 set("short", "°Ï°ì¬ã¨s«Ç");
 set("long", @LONG
§A¬Ý¨ì³o­Ó¥Õ¦âªº©Ð¶¡¨ì³B³£¬O¤@Å|Å|ªº¬ö¿ý¤åÄm©M¬ã¨s³ø§i¡A  
³o¸Ì´N¬O§Å®v­Ì¤½§G·s°Ï°ì©M¤j¯«­Ìµoªí·s¬Fµ¦ªº¦a¤è¡A¦pªG§A¬O·s
¶i¤H­û¡A³Ì¦n¥ý§â³o¸Ìªþªñªº¤½§i¬Ý§¹¡C¹Ú¤Û°Ï°ìªº§Å®v¥²¶·¥ýµoªí
°Ï°ì¤~¦³¸ê®æ¤É¯Å¡A¤]¤~¯à¦V§ó°ª¯Åªºµ{¦¡³Ð§@¬D¾Ô¡A¤][1;37m°ß¦³°Ï°ì³q
¹L¼f¬d¨Ã¥B³q¹L°òÂ¦¦Ò¸Õªº§Å®v¯à°÷¶i¤J¤W­±ªº©Ð¶¡¬ã¨sÂ¾·~§Þ¯à©M
¾Ôª§ªº¼gªk[0m¡C¦³Ãö°Ï°ìªº°ò¥»³W©w»Pª`·N¨Æ¶µ½Ð¥Î < [1;34mabout area[m > 
¬d¸ß¡C

LONG
	);
 set("light",1);
 set("exits", ([ /* sizeof() == 2 */
    "down"   : __DIR__"hall1",
    "up"     : __DIR__"hall_guild",
    "east"   : __DIR__"hall_room",
    "west"   : __DIR__"hall_equip",
    "north"   : __DIR__"hall_quest",
    "south"   : __DIR__"hall_npc",
 ]));
 set("no_clean_up", 0);
 set("valid_startroom", 1);
 setup();
 call_other("/obj/board/area_b", "???");
}

void init()
{
 add_action("do_help","about");
}

int do_help(string arg)
{
 if(arg=="area")
 {
   if( file_size("/doc/wiz/area.txt")>0 )
   {
    this_player()->start_more( read_file("/doc/wiz/area.txt") );
    write("\n");
   } else write(" SORRY. »¡©úÀÉ©|¥¼«Ø¥ß. \n");
  return 1;
 }
 return 0;
}

int valid_leave(object me, string dir)
{
	if( dir=="up" && wiz_level(me)<=wiz_level("(apprentice)") )
		return notify_fail("¥u¦³¥¿¦¡§Å®v(Wizard)¤~¯à¤W¥h¨º­Ó³q©¹Â¾·~¬ã¨s«Çªº¼Ó±è¡C\n");
	return ::valid_leave(me, dir);
}