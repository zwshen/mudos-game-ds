// Room: /open/world1/tmr/north_bar/s11.c

inherit ROOM;

void create()
{
	set("short", "千年古洞-地下二層");
	set("long", @LONG
這裡的地面都是泥沼，只要你一不小心，腳就會陷入泥巴中
，讓你行動十分困難。又面對數隻怪獸的追趕，還是小心一點吧
。
LONG
	);
	set("objects", ([ ]));
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"s10",
]));
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
