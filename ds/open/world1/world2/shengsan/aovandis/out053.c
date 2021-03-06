// 奧凡迪斯郊區
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "解迷地");
	set("long", @LONG
這裡是奧凡迪斯的郊區。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out054",
	    "south": __DIR__"out057",
            ]));

	set("outdoors","land");	// 平原
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
}

void init()
{
	add_action("do_drill","drill");
	return;
}

int do_drill(string arg)
{
	object me;
	me = this_player();
	message_vision("$N小心翼翼的鑽進林間的小洞中。\n",me);
	me->move(__DIR__"out046");
	message_vision("$N從樹林旁的隙縫中鑽了出來。\n",me);
	return 1;
}