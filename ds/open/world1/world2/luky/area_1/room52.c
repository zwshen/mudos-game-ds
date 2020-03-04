// Modify with AreaMaker1.0
// Room52.c

inherit ROOM;

void create()
{
	set("short","樹林");
	set("long", @LONG
這裡是樹林的一角。身旁都是一些常見的樹和草，沒有什麼特別
的東西，你考慮了一下還是決定繼續趕路，沒必要在這裡浪費時間。
LONG
	);
	set("exits", ([
		"north": __DIR__"room42",
		"east": __DIR__"room53",
		"south": __DIR__"room62",
	]));
 	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/bird1" : 1,
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

