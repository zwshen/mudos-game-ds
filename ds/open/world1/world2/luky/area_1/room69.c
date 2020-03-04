// Modify with AreaMaker1.0
// Room69.c

inherit ROOM;

void create()
{
	set("short","大草原");
	set("long", @LONG
這裡是一片大草原。草隨著風搖晃著，就像是海面上的波浪一般
。你想起了小時候聽過的一些輕快的民謠，不禁輕哼了幾句。
LONG
	);
	set("exits", ([
		"north": __DIR__"room59",
		"east": __DIR__"room70",
		"south": __DIR__"room79",
	]));
	set("no_clean_up", 0);
	set("outdoors","land");		//戶外(平原)
	setup();
	replace_program(ROOM);
}

