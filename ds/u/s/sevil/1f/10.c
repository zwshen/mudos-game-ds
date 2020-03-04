// Room: /u/s/sevil/1f/10.c

inherit ROOM;

void create()
{
	set("short", "寬廣的走道");
	set("long", @LONG
這是一間什麼也沒有的空房間。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"15.c",
  "south" : __DIR__"5.c",
  "east" : __DIR__"9.c",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
