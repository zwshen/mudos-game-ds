// Room: /open/world1/tmr/north_bar/town33.c

inherit ROOM;

void create()
{
	set("short", "北蠻村－街道");
	set("long", @LONG
來到這裡，你發現這附近似乎是住宅區，旁邊都是一些民房
，村民來來回回的走著，有些小孩子就在路旁玩起跳房子或跳花
繩，路過的人都對你抱著微笑，絲毫不介意你的來訪。
LONG
	);
	set("objects", ([ ]));
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"town34",
  "west" : __DIR__"town32",
]));
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
