// Room: /u/s/sevil/1f/7.c

inherit ROOM;

void create()
{
	set("short", "空房間");
	set("long", @LONG
這是一間什麼也沒有的空房間。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"8.c",
  "south" : __DIR__"2.c",
  "north" : __DIR__"12.c",
  "east" : __DIR__"6.c",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
