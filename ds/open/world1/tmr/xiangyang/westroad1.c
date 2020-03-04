// Room: /d/xiangyang/westroad1.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "西內大街");
	set("long", @LONG
這是一條青石鋪就的大街。隱隱地能望見南面是一座很高
的彩樓，東面是一堵蓋著紅色琉璃瓦的高牆，裡面是郭府大院。
西面是襄陽城老字號的客店，北面是青石鋪的大街。
LONG );
        set("outdoors", "xiangyang");

	set("no_clean_up", 0);
	set("exits", ([
		"west"  : __DIR__"kedian",
		"south" : __DIR__"westjie2",
		"north" : __DIR__"westroad2",
	]));
	set("coor/x", -530);
	set("coor/y", -490);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}