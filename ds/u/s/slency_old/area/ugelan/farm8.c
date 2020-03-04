// Room: /u/s/slency/area/ugelan/farm8.c

inherit ROOM;

void create()
{
	set("short", "¤s¶¡¯U¹D");
	set("long", @LONG
¡C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"farm9",
  "north" : __DIR__"farm1",
]));
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
