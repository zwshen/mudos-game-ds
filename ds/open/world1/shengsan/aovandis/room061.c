// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"第一商街"NOR);
	set("long", @LONG
這裡是奧凡迪斯的第一商街，這裡是全城中最熱鬧的地方之一，在這
逛逛你一定會有很多收穫的。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
            "east" : __DIR__"room059",
	    "south": __DIR__"room062",
	    "north": __DIR__"room024",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}