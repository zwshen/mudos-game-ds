// Room: /u/s/sevil/1f/28.c

inherit ROOM;

void create()
{
	set("short", "化妝室");
	set("long", @LONG
這是一間什麼也沒有的空房間。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"24.c",
  "west" : __DIR__"29.c",
  "east" : __DIR__"30.c",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
