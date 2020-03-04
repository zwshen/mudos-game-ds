// Room: /open/world1/tmr/bagi/area/2f/map_8_14.c

inherit ROOM;

void create()
{
	set("short", "´H¤é¬}¤G¼h");
	set("long", @LONG

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"map_9_13",
  "southeast" : __DIR__"map_9_15",
]));
	set("map_long", 1);
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
