// Modify with AreaMaker1.0
// Room14.c

inherit ROOM;

void create()
{
	set("short","樹林草堆");
	set("long", @LONG
這裡四周都是和人一樣高的草，你很難看到哪裡有路可走。不過
你發現東方的草似乎有被人踩踏過的痕跡。
LONG
	);
	set("exits", ([
		"east": __DIR__"room15",
	]));
	set("hide_exits", ([
		"west": __DIR__"room13",
 	]));
 	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/pig1" : 2,
		__DIR__"npc/pig0" : 1,
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

