// Room: /u/c/cominging/past/death/port2.c

inherit ROOM;

void create()
{
	set("short", "海岸旁");
	set("long", @LONG
這是一間什麼也沒有的空房間。
LONG
	);
	set("current_light", 1);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"port3",
  "south" : __DIR__"port5",
  "west" : __DIR__"port1",
  "east" : __DIR__"port4",
]));
	set("world", "undefine");

	setup();
	replace_program(ROOM);
}
