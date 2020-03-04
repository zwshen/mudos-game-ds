// Room: /open/world1/manto/sky2_2f/map_3_12.c

inherit ROOM;

void create()
{
	set("short", "°ó¥D©Ð");
	set("long", @LONG

LONG
	);
	set("light", 1);
	set("current_light", 1);
	set("map_long", 1);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"map_3_10",
]));

	setup();
        set("stroom", 1);
}
