// 奧凡迪斯
// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"迪斯大道"NOR);
	set("long", @LONG
你在奧凡迪斯的迪斯大道上，這條大道是位於城裡的東半邊，往東直
走就是東城門了。
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
            "east" : __DIR__"room015",
	    "west" : __DIR__"room013",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}