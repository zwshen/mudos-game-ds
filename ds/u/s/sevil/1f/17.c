// Room: /u/s/sevil/1f/17.c

inherit ROOM;

void create()
{
	set("short", "化妝品店");
	set("long", @LONG
這裡是一間化妝品店，擺滿了各式各樣的化妝品，內裡正有兩位婦人正
在保養，也許你應該問問店員，有什麼適合你的化妝品。

LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"12.c",
  "west" : __DIR__"18.c",
  "north" : __DIR__"22.c",
  "east" : __DIR__"16.c",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
