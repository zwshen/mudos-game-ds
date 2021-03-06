// Room: /open/world1/tmr/dragoncity/bridge3.c

inherit ROOM;

void create()
{
	set("short", "磐龍城-城門護城大橋");
	set("long", @LONG
你正站著磐龍城南城門口外的護城大橋，這兒排滿了數條長長的人龍
跟車隊，都是等著要進城或離城的，由於少帥軍的管制，大家都非常
守秩序等侯檢驗。不時有小孩來回奔走，一片熱鬧和平的景象。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"bridge2",
  "north" : __DIR__"southgate2",
]));
	set("current_light", 5);
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
