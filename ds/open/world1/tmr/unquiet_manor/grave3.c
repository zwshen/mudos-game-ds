// Room: /open/world1/tmr/unquiet_manor/grave2.c

inherit ROOM;

void create()
{
	set("short", "剁骨墓室");
	set("long", @LONG
你正處在一處墓室內，四面全是的石牆，墓室中間停有烏漆紅木棺材
，墓穴屍氣幾百年不曾流動，你只吸入幾口就已覺得頭昏腦脹，只想要趕
快離開這個地方。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "up" : __DIR__"map_6_4",
]));
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/grove-ghost" : 4,
  __DIR__"npc/moon-tiger" : 1,
]));
	set("current_light", 2);

	setup();
	replace_program(ROOM);
}
