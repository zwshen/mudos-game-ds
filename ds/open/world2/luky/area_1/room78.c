// Modify with AreaMaker1.0
// Room78.c

inherit ROOM;

void create()
{
	set("short","池塘邊");
	set("long", @LONG
你正走在一個池塘旁邊。路面都是一些濕粘的土壤，你小心翼翼
的走著，深怕泥巴弄髒了你的新鞋子。池邊有些破舊的鐵網，上面長
滿了青苔。
LONG
	);
	set("exits", ([
		"east": __DIR__"room79",
		"south": __DIR__"room88",
	]));
	set("no_clean_up", 0);
	set("outdoors","land");
	setup();
	replace_program(ROOM);
}

