// Modify with AreaMaker1.0
// Room63.c

inherit ROOM;

void create()
{
	set("short","樹林");
	set("long", @LONG
你正走在一大片的樹林裡。身旁都是一些常見的樹和草，沒有什
麼特別的東西。林間不時傳來鳥獸求偶所發出的的美妙聲音。
LONG
	);
	set("exits", ([
		"north": __DIR__"room53",
		"south": __DIR__"room73",
		"west": __DIR__"room62",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

