// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"學術走道"NOR);
	set("long", @LONG
你站在一條有學術氣息的走道上。
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
            "east" : __DIR__"room045",
	    "west" : __DIR__"room052",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}