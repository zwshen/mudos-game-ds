// Room: /u/t/tmr/area/street1.c

inherit ROOM;

void create()
{
	set("short", "街道");
	set("long", @LONG
一條熱鬧又寬廣的街道，走在路上不時都會和人擦撞相碰，路旁除了
店家之外，還有不少的流動攤販，遠遠就看著巡邏官兵在驅逐佔滿街道的
攤販，這裡卻還在和客人在為了價錢在大肆爭吵。往東是一條更大的道路
，往北就是北城門口了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"city-door",
  "east" : __DIR__"street2",
]));
	set("outdoors","land");
	set("no_clean_up", 0);

set("light",1);
	setup();
	replace_program(ROOM);
}
