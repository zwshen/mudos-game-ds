// Room: /open/world1/tmr/bagi/area/2f/map_14_12.c

inherit ROOM;

void create()
{
	set("short", "�H��}�G�h");
	set("long", @LONG

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"map_15_12",
  "northwest" : __DIR__"map_13_11",
]));
	set("map_long", 1);
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
