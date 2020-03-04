// xiaowu2.c 蜂屋
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "蜂屋");
	set("long", @LONG
這里是小龍女喂養訓練玉蜂的蜂屋，屋角上掛著很多個六角形的蜂
巢，還未進門，就聞得到一陣蜂蜜的甜香。
LONG	);
	set("exits", ([
		"west"  : __DIR__"mudao12",
		"south" : __DIR__"mudao13",
	]));
	set("objects", ([
		__DIR__"obj/fengjiang" : 3,
		__DIR__"obj/fengmi" : 1,
	]));


	setup();
	replace_program(ROOM);
}
