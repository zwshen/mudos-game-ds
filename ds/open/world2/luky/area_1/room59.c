// Modify with AreaMaker1.0
// Room59.c

inherit ROOM;

void create()
{
	set("short","樹林邊緣");
	set("long", @LONG
你正走在樹林裡，這裡的草長的比較低一些。微風輕吹，樹葉發
出一陣沙沙沙的聲音。西邊有個小池塘，天色倒映在水面上十分寫意
。
LONG
	);
	set("exits", ([
		"north": __DIR__"room49",
		"east": __DIR__"room60",
		"south": __DIR__"room69",
		"northwest": __DIR__"room48",
	]));
 	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/bird1" : 1,
		__DIR__"npc/bird0" : 2,
		__DIR__"npc/pig1" : 2,
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

