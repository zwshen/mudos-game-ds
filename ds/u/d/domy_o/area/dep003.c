// Room: /u/d/domy/area/dep003.c

inherit ROOM;

void create()
{
	set("short", "一樓");
	set("long", @LONG
這是一間什麼也沒有的空房間。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"dep002",
  "east" : __DIR__"dep004",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
