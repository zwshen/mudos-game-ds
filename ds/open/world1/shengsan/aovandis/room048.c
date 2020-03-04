// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"走道"NOR);
	set("long", @LONG
你站在一條乾淨的走道上。往北是巫師工會，往南可以到達牧師工會
。往東直走是植物園。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"room049",
	    "west" : __DIR__"room047",
	    "south": __DIR__"room084",
	    "north": __DIR__"room085",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}