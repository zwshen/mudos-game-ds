// Modify with AreaMaker1.0
// Room62.c

inherit ROOM;

void create()
{
	set("short","樹林");
	set("long", @LONG
你正走在樹林中。遠離大都市的塵囂，倘佯在大自然中的感覺令
人煥然一新。你看到西南邊有一片湖泊。
LONG
	);
	set("exits", ([
		"north": __DIR__"room52",
		"east": __DIR__"room63",
		"south": __DIR__"room72",
		"west": __DIR__"room61",
	]));
 	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/bird1" : 2,
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

