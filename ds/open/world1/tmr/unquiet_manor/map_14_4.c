// Room: /open/world1/tmr/unquiet_manor/map_14_4.c

inherit ROOM;

void create()
{
	set("short", "µIÅ¦¤§¼X-¤J¤f");
	set("long", @LONG

LONG
	);
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"map_15_4",
  "down" : __DIR__"grave1",
]));
	set("current_light", 3);
	set("map_long", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
