// Room: /u/m/matlab/area/2f2.c

inherit ROOM;

void create()
{
	set("short", "空房間");
	set("long", @LONG
這是一間什麼也沒有的空房間。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"2f6.c",
  "west" : __DIR__"r2fstart.c",
  "east" : __DIR__"2f7.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
