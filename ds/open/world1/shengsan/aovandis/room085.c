// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"巫師工會招待所"NOR);
	set("long", @LONG
你來到巫師們常常聚會的場所，這裡正是巫師工會。你察覺到身旁有
種詭異的魔力在身旁震盪著。在房間的中央有個刻畫著美麗花飾的臺子，
而臺子之上有顆浮起的紫色魔石。
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
	    "south": __DIR__"room048",
	    "north": __DIR__"room102",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}