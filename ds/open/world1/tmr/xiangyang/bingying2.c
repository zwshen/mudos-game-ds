// Room: /d/xiangyang/bingying2.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "兵營");
	set("long", @LONG
這裡是兵營，密密麻麻到處都是官兵，有的在武將的指揮
下列隊操練，有的獨自在練功，有的坐著、躺著正在休息。南
牆下坐著主帥，不動聲色地尋視著四周。看到你進來，他們全
都向你瞪大眼睛盯著你。
LONG );
	set("item_desc", ([
		"dong" : "\n",
	]));

	set("exits", ([
		"south" : __DIR__"eastjie3",
	]));
	set("objects", ([
		__DIR__"npc/pian" : 1,
		__DIR__"npc/zuo"  : 1,
		__DIR__"npc/bing" : 2,
	]));
	set("coor/x", -470);
	set("coor/y", -500);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}