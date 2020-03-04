// Room: /d/xiangyang/juyilang.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "水上走廊");
	set("long", @LONG
這是一條筆直的走廊，廊下是一湖池水。湖水映著長長垂
柳，碧綠清澈，你能看見一些魚在遊來遊去。南面就是一個大
花園，園內東西兩側各有一排廂房。
LONG );
        set("outdoors", "xiangyang");
	set("no_clean_up", 0);

	set("exits", ([
		"south" : __DIR__"juyihuayuan",
		"north" : __DIR__"juyiyuan",
	]));
	set("coor/x", -530);
	set("coor/y", -502);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
