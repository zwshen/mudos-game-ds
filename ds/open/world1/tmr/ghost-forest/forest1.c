// Room: /open/world1/tmr/ghost-forest/forest1.c

inherit ROOM;

void create()
{
	set("short", "林間小路");
	set("long", @LONG
你正走在林中的一條小路，往南不遠處可出森林到滄縣城內。耳中不
時可聽到一些蟲鳴鳥叫，別有一番清幽之意。往北望去，樹木高聳群密，
陰陰森森，了無人煙，連當地久住的樵夫也不敢再往北走。
LONG
	);
	set("world", "past");
	set("outdoors", "forest");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"forest2",
  "southwest" : "/open/world1/tmr/area/river_road",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
