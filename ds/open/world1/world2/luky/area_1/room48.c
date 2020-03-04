// Modify with AreaMaker1.0
// Room48.c

inherit ROOM;

void create()
{
	set("short","樹林小徑");
	set("long", @LONG
你正走在樹林小徑上, 兩旁都長滿了不知名的樹, 整排的樹向西
邊一直線地延伸。你可以看到在你的南邊有一個小池塘。從水面上吹
來陣陣的涼風, 使你感到非常舒適。
LONG
	);
	set("exits", ([
		"west": __DIR__"room47",
		"northeast": __DIR__"room39",
		"southeast": __DIR__"room59",
		"northwest": __DIR__"room37",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

