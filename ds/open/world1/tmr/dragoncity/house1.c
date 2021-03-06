// Room: /open/world1/tmr/dragoncity/house1.c

inherit ROOM;

void create()
{
	set("short", "少帥府－大門");
	set("long", @LONG
一座建築古樸的大宅院出現在你的眼前。只見門樓高挑，上書正楷大
字「少帥府」。少帥軍的幾個子弟兵和家丁就守在門前，接待前來保衛磐
龍城的客人，只見人們進進出出，非常的熱鬧。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "land");
        set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/guard3" : 2,
]));

	set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"house2",
  "south" : __DIR__"south_din",
]));
	set("current_light", 2);

	setup();
	replace_program(ROOM);
}
