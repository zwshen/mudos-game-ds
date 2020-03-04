// Modify with AreaMaker1.0
// Room88.c

inherit ROOM;

void create()
{
	set("short","池塘邊");
	set("long", @LONG
一走進這裡你就看到這裡有許多的水筆仔。水邊還有一些可愛的
彈塗魚，一看到你走近便鑽到了地洞裡。東邊有一座小山丘，山丘上
有幾個小洞，可能是一些小動物的窩。
LONG
	);
	set("exits", ([
		"north": __DIR__"room78",
		"west": __DIR__"room87",
		"northeast": __DIR__"room79",
	]));
	set("hide_exits", ([
		"south": __DIR__"room98",
 	]));
	set("no_clean_up", 0);
	set("outdoors","land");
	setup();
	replace_program(ROOM);
}

