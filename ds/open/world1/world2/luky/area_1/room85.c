// Modify with AreaMaker1.0
// Room85.c

inherit ROOM;

void create()
{
	set("short","樹林");
	set("long", @LONG
疑!?似乎有什麼東西正在看著你，但是你看了一下四周，除了一
些灌木和雜草，這裡也沒什麼可疑的。或許是你太多心了，不過心裡
總是覺得怪怪的..
LONG
	);
	set("exits", ([
		"north": __DIR__"room75",
		"east": __DIR__"room86",
		"west": __DIR__"room84",
		"southwest": __DIR__"room94",
	]));
 	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

