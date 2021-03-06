// Room: /open/world1/moonhide/area/snake-room3.c

inherit ROOM;

void create()
{
	set("short", "霧洞內");
	set("long", @LONG
只見洞內盡是霧茫茫的一片，從洞外只勉強照進些許日光，著
實讓人伸手不見五指，難以視物。從洞內深不斷傳來沙沙的怪響，
噁心的腐臭味不斷傳出來。
LONG
	);
	set("current_light", 4);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"snake1" : 3,
]));
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"snake-room1",
  "east" : __DIR__"snake-room6",
]));

	setup();
	replace_program(ROOM);
}
