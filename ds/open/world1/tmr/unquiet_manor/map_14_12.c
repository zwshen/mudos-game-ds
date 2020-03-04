// Room: /open/world1/tmr/unquiet_manor/map_14_12.c

inherit ROOM;

void create()
{
	set("short", "­é¥Ö¤§¼X-¤J¤f");
	set("long", @LONG

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"map_15_12",
  "down" : __DIR__"grave2",
]));
	set("outdoors", "land");
	set("no_clean_up", 0);
	set("current_light", 2);
	set("map_long", 1);

	setup();
	replace_program(ROOM);
}
