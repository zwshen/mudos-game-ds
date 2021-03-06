// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"上層走道"NOR);
	set("long", @LONG
你站在一排排往北而上的石階之上，石階上鑲著各種炫麗的琉璃，所
排出的圖騰樣式讓人匪夷所思。然而這裡確有許多的逛街人潮在這裡聚集
，從這往東走是服飾精品店，往西走去則是間小孩最喜歡去的糖果屋。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"room095",
	    "west" : __DIR__"room096",
	    "south": __DIR__"room091",
	    "north": __DIR__"room084",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}