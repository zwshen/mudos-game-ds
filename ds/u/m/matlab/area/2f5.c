// Room: /u/m/matlab/area/2f5.c

inherit ROOM;

void create()
{
	set("short", "空房間");
	set("long", @LONG
這是一間什麼也沒有的空房間。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"2fto3f.c",
  "south" : __DIR__"2f1.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
