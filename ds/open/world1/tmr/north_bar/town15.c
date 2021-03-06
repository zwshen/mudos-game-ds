// Room: /open/world1/tmr/north_bar/town15.c

inherit ROOM;

void create()
{
	set("short", "北蠻村－街道");
	set("long", @LONG
來到這裡，你發覺周圍開始有風了，而且受到陽光照射的面
積開始減少了，東北角有間武器店，如果你有需要的話，也可以
去那邊看看。不過這村一向和平，也沒有什麼紛爭，店內的生意
也就三三兩兩了。
LONG
	);
	set("objects", ([ ]));
	set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"town26",
  "south" : __DIR__"town13",
  "west" : __DIR__"town7",
]));
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
