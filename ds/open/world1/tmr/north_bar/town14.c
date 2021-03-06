// Room: /open/world1/tmr/north_bar/town14.c

inherit ROOM;

void create()
{
	set("short", "北蠻村－街道");
	set("long", @LONG
來到這裡，你發覺周圍開始有風了，而且受到陽光照射的面
積開始減少了，西北角的房向有間防具店，賣的都是村內上好的
防具，不過這村一向和平，也沒有什麼紛爭，店內的生意也就三
三兩兩了。
LONG
	);
	set("objects", ([ ]));
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"town12",
  "east" : __DIR__"town7",
  "northwest" : __DIR__"town16",
]));
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
