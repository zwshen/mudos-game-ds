// Room: /u/a/aring/tomb/8.c

inherit ROOM;

void create()
{
	set("short", "[0m[35m¤j¹Ó¶é¡Ð[1;33m¦è°¼¤jªù[0m");
	set("long", @LONG
³o¸Ì¬O¤j¹Ó¶é¤¤ªº¦è°¼¤jªù¡A»¡¬Oªù¨ä¹ê¦­¤w±YÃa¤£³ô¡A¬Ý°_¨Ó­Ë
¤ñ¸û¹³¬O¤@­Ó¯Ê¤f¡A©¹¦èÃä«h¬O³q©¹¤õ¤sªº¤s¸ô¡C
LONG
	);
	set("no_clean_up", 0);
	set("light", "0");
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"10.c",
  "north" : __DIR__"6.c",
]));
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}
