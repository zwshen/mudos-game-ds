// Room: /u/s/sevil/1f/20.c

inherit ROOM;

void create()
{
	set("short", "空房間");
	set("long", @LONG
這是一間什麼也沒有的空房間。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"25.c",
  "south" : __DIR__"15.c",
  "east" : __DIR__"19.c",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
