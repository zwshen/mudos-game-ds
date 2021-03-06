// Room: /open/world1/dragoncity/southroad1.c

inherit ROOM;

void create()
{
	set("short", "南內大街");
	set("long", @LONG
這是一條用青石鋪就的大道。向西就是丁字街口，只見
南面不時有馬車飛奔而出，東面也是一個大街口，你好像看
到一條大街通向南面。北面是一堵上蓋紅色琉璃瓦的高牆，
裡面是少帥軍統帥寇仲的府邸。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"southroad1e",
  "west" : __DIR__"south_din",
]));
	set("outdoors", "land");
	set("no_clean_up", 0);
	set("current_light", 4);

	setup();
	replace_program(ROOM);
}
