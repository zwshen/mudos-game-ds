// Room: /u/l/lestia/area/map_12_1.c

inherit ROOM;

void create()
{
	set("short", "魔力屏障");
	set("long", @LONG

這裡迷漫著一股充滿白色的霧氣，從你的四周緩緩升起直奔遠處而去，
霧氣中透露出絲絲寒氣，黑暗陰冷的氣息讓你不禁渾身發抖，你望著前
方一片茫然，當你回過神時，你發現你已經深深的陷在這片森林之中了。

LONG
	);
	set("outdoors", 1);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"map_12_2",
  "north" : __DIR__"map_11_1",
  "south" : __DIR__"sn22",
]));
	set("world", "undefine");
	set("current_light", 4);

	setup();
	replace_program(ROOM);
}
