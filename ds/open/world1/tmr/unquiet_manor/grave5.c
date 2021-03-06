// Room: /open/world1/tmr/unquiet_manor/grave5.c

inherit ROOM;

void create()
{
	set("short", "無寧之墳");
	set("long", @LONG
你正在走無寧莊園的地下墓道中，墓穴屍氣幾百年不曾流動，你
只吸入幾口就已覺得頭昏腦脹，只想要趕快離開這個地方。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"g1",
  "up" : __DIR__"map_4_8",
]));
	set("no_clean_up", 0);
	set("current_light", 3);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/grove-ghost" : 2,
]));

	setup();
	replace_program(ROOM);
}
