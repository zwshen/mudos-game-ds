// Room: /open/world1/tmr/bagi/area/2f/map_11_7.c

inherit ROOM;

void create()
{
	set("short", "´H¤é¬}¤G¼h");
	set("long", @LONG

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"map_12_6",
  "northwest" : __DIR__"map_10_6",
]));
	set("map_long", 1);
        set("objects",([
                __DIR__"npc/corpse":4,
        ]));

	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
