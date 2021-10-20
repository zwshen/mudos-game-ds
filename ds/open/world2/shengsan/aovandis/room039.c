// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"走道"NOR);
	set("long", @LONG
你在一個冷清的走道上。
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
            "east" : __DIR__"room008",
	    "west" : __DIR__"room040",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}