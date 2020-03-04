// Modify with AreaMaker1.0
// Room26.c

inherit ROOM;

void create()
{
	set("short","樹林");
	set("long", @LONG
這裡是一片人煙稀少的樹林。樹葉非常茂密，即使是白天也很難
看到陽光。
LONG
	);
	set("exits", ([
		"north": __DIR__"room16",
		"south": __DIR__"room36",
		"northeast": __DIR__"room17",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

