// Room: /d/wiz/hall5.c

inherit ROOM;

void create()
{
 set("short", "Â¾·~§Ş¯à°Q½×ÆU");
 set("long", @LONG

  ³o¸Ì¬O§Å®v°Q½×Â¾·~§Ş¯à¼gªk©Mµoªí·s§Ş¯àªº¦a¤è¡M©¹¤W¬OÅ]¯«·|Ä³«Ç¡M
©¹¤U¬O¥ô°È°Q½×ÆU¡C©¹ªF¨«¦³¾É®vªº½d¨Ò¡M­nÆ[¬İ§Ş¯àª`·N¨Æ¶µ½Ğ¿é¤J
[1;32m about skill[m¡C³o­Ó©Ğ¶¡¤ºªº¾É®vªº§Ş¯à¥i¥HÅı¥ô¦óÂ¾·~ªº¤H¾Ç²ß¡M­n
ª¾¹D¼gªk½ĞÁä¤J[1;33m about master[m¡C
LONG
	);
 set("light",1);
 set("exits", ([ /* sizeof() == 2 */
    "east"   : __DIR__"masterroom",
    "down"   : __DIR__"hall4",
    "up"     : __DIR__"hall6",
 ]));
 set("objects", ([ /* sizeof() == 1 */
	"/u/s/shengsan/npc/swimmaster": 1,
	]));
 set("no_clean_up", 0);
 set("valid_startroom", 1);
 setup();
 call_other("/obj/board/skill_b", "???");
}

void init()
{
 add_action("do_help","about");
}

int do_help(string arg)
{
	if(arg=="skill")
	{
		if( file_size("/doc/wiz/skill.txt")>0 )
		{
			this_player()->start_more( read_file("/doc/wiz/skill.txt") );
			write("\n");
		}
		else write(" SORRY. »¡©úÀÉ©|¥¼«Ø¥ß. \n");
   		return 1;
	}
	else if(arg=="master")
	{
		if( file_size("/u/s/shengsan/npc/swimmaster.c")>0 )
		{
			this_player()->start_more( read_file("/u/s/shengsan/npc/swimmaster.c") );
			write("\n");
		}
		else write(" SORRY. »¡©úÀÉ©|¥¼«Ø¥ß. \n");
		return 1;
	}
	return 0;
}
