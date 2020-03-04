// Modify with AreaMaker1.0
// Room83.c

inherit ROOM;

void create()
{
	set("short","湖畔");
	set("long", @LONG
你正走在美麗的依莉莎湖東畔。湖邊有些含苞待放的荷花，正散
發出絲絲的清香。荷葉上有隻小青蛙正鼓動著牠的氣囊。湖面水草旁
偶爾冒出一些氣泡，或許有大魚躲在下面。
LONG
	);
	set("exits", ([
		"north": __DIR__"room73",
		"east": __DIR__"room84",
		"south": __DIR__"room93",
		"northwest": __DIR__"room72",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

