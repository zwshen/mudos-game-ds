// Modify with AreaMaker1.0
// Room37.c

inherit ROOM;

void create()
{
	set("short","樹林");
	set("long", @LONG
這裡是一條長滿雜草的小路。道路兩旁的草長得雜亂無章，路面
是由厚實的泥土所鋪成。
LONG
	);
	set("exits", ([
		"south": __DIR__"room47",
		"west": __DIR__"room36",
		"southeast": __DIR__"room48",
	]));
 	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/spider1" : 3,
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

