// Room: /open/world1/tmr/north_bar/s16.c

inherit ROOM;

void create()
{
	set("short", "千年古洞-地下二層");
	set("long", @LONG
這裡似乎蠻安靜地，往左邊就沒有路了。但是一樣是有怪物
在跑來跑去，而且地面還持續搖晃著，讓人感覺十分不安，會不
會走到一半突然整個洞垮下來••
LONG
	);
	set("objects", ([ ]));
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"s13",
  "east" : __DIR__"s7",
]));
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
