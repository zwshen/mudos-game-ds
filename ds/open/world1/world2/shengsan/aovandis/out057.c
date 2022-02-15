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
            "east" : __DIR__"out058",
	    "north": __DIR__"out053",
            ]));

	set("outdoors","land");	// 平原
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}