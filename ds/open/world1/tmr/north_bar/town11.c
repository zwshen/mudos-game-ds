// Room: /open/world1/tmr/north_bar/town11.c

inherit ROOM;

void create()
{
	set("short", "北蠻村－街道");
	set("long", @LONG
這裡十分熱鬧，到處充滿了熱鬧的吵雜聲，有小孩的草雜聲
，也有從市集傳來的叫賣聲，前面不遠處有一口井，那裡也聚集
很多人，也許有什麼有趣的事。
LONG
	);
	set("objects", ([ ]));
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"town32",
  "north" : __DIR__"town13",
  "west" : __DIR__"town5",
]));
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
