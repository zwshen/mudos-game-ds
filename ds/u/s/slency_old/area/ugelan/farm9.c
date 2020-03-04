// Room: /u/s/slency/area/ugelan/farm9.c

inherit ROOM;

void create()
{
	set("short", "空房間");
	set("long", @LONG
這是一間什麼也沒有的空房間。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"farm10",
  "northwest" : __DIR__"farm8",
]));
	set("no_clean_up", 0);
	set("outdoors", "land");
	setup();
	replace_program(ROOM);
}
