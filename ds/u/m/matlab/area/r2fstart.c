// Room: /u/m/matlab/area/r2fstart.c

inherit ROOM;

void create()
{
	set("short", "焚天閣2樓");
	set("long", @LONG
這是一間什麼也沒有的空房間。
LONG
	);
	set("exits", ([ /* sizeof() == 5 */
  "west" : __DIR__"2f4.c",
  "south" : __DIR__"2f3.c",
  "north" : __DIR__"2f1.c",
  "down" : __DIR__"r8.c",
  "east" : __DIR__"2f2.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
