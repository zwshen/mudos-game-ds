// Room: /d/wiz/hall_master3.c

inherit ROOM;

void create()
{
 set("short", "¦Û¥Ñ§Ş¯à¾É®v½d¨Ò©Ğ¶¡");
 set("long", @LONG
³o¸Ì¬O¦Û¥Ñ§Ş¯à¾É®v½d¨Òªº©Ğ¶¡¡C½ĞÁä¤J[1;33m about master [m¤wÀò¨ú¼g¾É®vªº
¤èªk»Pª`·N¨Æ¶µ¡C
LONG
	);
 set("light",1);
 set("exits", ([ /* sizeof() == 2 */
    "south"   : __DIR__"hall_master2",
 ]));
 set("objects", ([ /* sizeof() == 1 */
	"/u/s/shengsan/npc/swimmaster": 1,
	]));
 set("no_clean_up", 0);
 set("valid_startroom", 1);
 setup();
// replace_program(ROOM);
}

void init()
{
 add_action("do_help","about");
}

int do_help(string arg)
{
 if(arg=="master")
 {
   if( file_size("/u/s/shengsan/npc/swimmaster.c")>0 )
   {
    this_player()->start_more( read_file("/u/s/shengsan/npc/swimmaster.c") );
    write("\n");
   } else write(" SORRY. »¡©úÀÉ©|¥¼«Ø¥ß. \n");
  return 1;
 }
 return 0;
}
