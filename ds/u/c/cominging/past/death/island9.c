// Room: /u/c/cominging/past/death/island9.c

inherit ROOM;

void create()
{
	set("short", "小島上");
	set("long", @LONG
這是一間什麼也沒有的空房間。
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 4);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"island12",
  "west" : __DIR__"island10",
  "south" : __DIR__"island2",
  "east" : __DIR__"island8",
]));
	set("world", "undefine");

	setup();
	replace_program(ROOM);
}
