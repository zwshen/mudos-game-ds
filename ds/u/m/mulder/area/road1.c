// Room: /u/m/mulder/area/road1.c

inherit ROOM;

void create()
{
	set("short", "新彼得城-旅店大街");
	set("long", @LONG
你從旅店走出來，看目許多高科技的設備．令你目不暇給地
將你的視線轉移在這一件又一件的高科技設備上．令你差點撞落
去電燈柱上，幸好原來那只是影像．向北走可以到廣場中心．
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "inn" : __DIR__"inn",
  "north" : __DIR__"road2",
]));
	set("no_clean_up", 0);
set("light",1);

	setup();
	replace_program(ROOM);
}
