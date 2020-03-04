// Modify with AreaMaker1.0
// Room17.c

inherit ROOM;

void create()
{
	set("short","樹林");
	set("long", @LONG
你正走在樹林裡。周圍的一草一木都讓你體會到在宇宙間的浩瀚
無邊以及人的渺小。
LONG
	);
	set("exits", ([
		"east": __DIR__"room18",
		"west": __DIR__"room16",
		"southwest": __DIR__"room26",
	]));
 	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

