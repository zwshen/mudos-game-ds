// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"上層走道"NOR);
	set("long", @LONG
你站在一排排往北而上的石階之上，石階上鑲著各種炫麗的琉璃，所
排出的圖騰樣式讓人匪夷所思。從這往西走是法師工會。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"room093",
	    "west" : __DIR__"room092",
	    "south": __DIR__"room089",
	    "north": __DIR__"room082",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}