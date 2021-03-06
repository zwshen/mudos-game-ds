// Modify with AreaMaker1.0
// Room53.c

inherit ROOM;

void create()
{
	set("short","樹林");
	set("long", @LONG
你正走在樹林裡。你發現附近有個廢棄的電線桿，上面已經佈滿
了青苔，看來已經被棄置了一段時間了。
LONG
	);
	set("exits", ([
		"north": __DIR__"room43",
		"east": __DIR__"room54",
		"south": __DIR__"room63",
		"west": __DIR__"room52",
	]));
	set("item_desc",([
        "pole":"一支廢棄的電線桿(pole)，上面長滿了青苔。\n",
        "電線桿":"一支廢棄的電線桿(pole)，上面長滿了青苔。\n",
         ]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

