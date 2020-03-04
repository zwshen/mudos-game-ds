// mishi2.c 密室
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "密室");
	set("long", @LONG
這里是古墓中的密室，四周密不透風，你只能借著�暀W昏暗的燈光
來勉強分辨方向。�椄O用整塊的青石砌合起來的，接合的甚是完美，你
難以從中找出一絲縫隙。�暀W好象雕有一些花紋。
LONG	);
	set("exits", ([
		"east"  : __DIR__"mishi3",
		"west"  : __FILE__,
		"north" : __FILE__,
		"south" : __DIR__"mishi1",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
