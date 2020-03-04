// Room: /open/world1/tmr/north_bar/town26.c

inherit ROOM;

void create()
{
	set("short", "北蠻村－巷子");
	set("long", @LONG
來到這裡，你發現前面有家武器店，從這裡就可以看見門口
陳列十八般武器，每一把都擦著閃閃發光，看樣子素質不差，可
見鐵匠的功夫不俗。
LONG
	);
	set("objects", ([ ]));
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"town27",
  "southwest" : __DIR__"town15",
]));
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
