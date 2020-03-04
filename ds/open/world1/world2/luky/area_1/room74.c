// Modify with AreaMaker1.0
// Room74.c

inherit ROOM;

void create()
{
	set("short","樹林");
	set("long", @LONG
你正悠閒的走在一片樹林之中，兩旁綠草如茵。北邊有棵小樹，
雖然並不起眼，但是你仍然必須繞路才可以通過。
LONG
	);
	set("exits", ([
		"east": __DIR__"room75",
		"south": __DIR__"room84",
		"west": __DIR__"room73",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

