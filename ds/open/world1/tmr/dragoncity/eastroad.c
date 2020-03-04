// Room: /open/world1/tmr/dragoncity/eastroad.c

inherit ROOM;

void create()
{
	set("short", "東內大街");
	set("long", @LONG
這是一條用青石鋪就的大街，西面是一堵上蓋紅色琉璃
瓦的高牆，裡面是少帥軍統帥寇仲的府邸。北面是用青石鋪
的大街道。南面是一個大的十字街道，只見人來人往，非常
熱鬧。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"east_din",
  "north" : __DIR__"northroad1e",
]));
	set("current_light", 5);
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
