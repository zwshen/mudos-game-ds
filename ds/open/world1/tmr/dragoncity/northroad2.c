// Room: /open/world1/tmr/dragoncity/northroad2.c

inherit ROOM;

void create()
{
	set("short", "北內大街");
	set("long", @LONG
你正走在一條用青石鋪就的大道。向東就是丁字街口，
可通往玄武門，西面也是一個大街口，你好像看到一條大街
通向南面。南面是一堵上蓋紅色琉璃瓦的高牆，裡面是少帥
軍統帥寇仲的府邸。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"northroad2w",
  "east" : __DIR__"north_din",
]));
	set("current_light", 2);
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
