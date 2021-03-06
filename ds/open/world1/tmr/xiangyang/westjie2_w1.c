// Room: /open/world1/tmr/xiangyang/westjie2_w1.c

inherit ROOM;

void create()
{
	set("short", "西大街");
	set("long", @LONG
這是一條寬闊的青石板街道，向東西兩頭延伸。街上的人
潮非常擁擠，看的出來這一帶非常的熱鬧繁華，四週盡是一片
詳和的氣氛，百姓們都安居樂業。.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"westjie3",
  "east" : __DIR__"westjie2",
]));
	set("coor", ([ /* sizeof() == 3 */
  "y" : -500,
  "x" : -520,
  "z" : 0,
]));
	set("no_clean_up", 0);
	set("current_light", 4);
	set("outdoors", "xiangyang");

	setup();
	replace_program(ROOM);
}
