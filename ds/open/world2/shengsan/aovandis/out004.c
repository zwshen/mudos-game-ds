// 奧凡迪斯郊區
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "道路");
	set("long", @LONG
這條道路是由柏油鋪成的，往東通往奧凡迪斯。路旁長起長短不一的
雜草，偶而往遠處看會看到一兩棵的大樹。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out005",
	    "south": __DIR__"out010",
            ]));

	set("outdoors","land");	// 平原
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}