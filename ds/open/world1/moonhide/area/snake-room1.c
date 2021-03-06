// Room: /open/world1/moonhide/area/snake-room1.c

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
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"snake-room",
  "north" : __DIR__"snake-room0",
  "west" : __DIR__"snake-room2",
  "east" : __DIR__"snake-room3",
]));
	set("current_light", 2);

	setup();
	replace_program(ROOM);
}
