// Room: /u/m/matlab/area/r6.c

inherit ROOM;

void create()
{
	set("short", "空房間");
	set("long", @LONG
這是一間什麼也沒有的空房間。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"r7-1.c",
  "north" : __DIR__"r7.c",
  "south" : __DIR__"r5.c",
  "northwest" : __DIR__"r7-2.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
