// Room: /u/m/matlab/area/r8.c

inherit ROOM;

void create()
{
	set("short", "焚天閣入口");
	set("long", @LONG
這是一間什麼也沒有的空房間。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "sun" : __DIR__"r7-2.c",
  "up" : __DIR__"r2fstart.c",
  "star" : __DIR__"r7-1.c",
  "moon" : __DIR__"r7.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
