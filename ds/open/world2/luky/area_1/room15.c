// Modify with AreaMaker1.0
// Room15.c

inherit ROOM;

void create()
{
	set("short","樹林草堆");
	set("long", @LONG
這裡四周都是和人一樣高的草，你很難看到哪裡有路可走。北邊
是高聳的岩壁，南邊則是一棵很高很高的大樹。
LONG
	);
	set("exits", ([
		"west": __DIR__"room14",
	]));
	set("hide_exits", ([
		"east": __DIR__"room16",
 	]));
 	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/pig0" : 3,
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

