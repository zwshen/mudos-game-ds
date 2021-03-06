// Room: /open/world1/tmr/north_forest/sn20.c

inherit ROOM;

void create()
{
	set("short", "地底洞穴");
	set("long", @LONG
你正處在一個地底洞穴中，由於陽光無法照射進來，所以四週盡是黑漆
漆的一切，你只能勉強順著岩壁往前進。
LONG
	);
	set("current_light", 4);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
	  __DIR__"npc/troll3" : 2,
	  __DIR__"npc/troll2" : 2,
	]));
	set("exits", ([ /* sizeof() == 2 */
 "north" : __DIR__"cave1",
 "south" : __DIR__"cave3",
 "southeast" : __DIR__"cave4",
 "southwest" : __DIR__"cave5",
 "east" : __DIR__"cave2e",
 "west" : __DIR__"cave2w",
]));

	setup();
	replace_program(ROOM);
}
