#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "守衛塔頂"HIB"崗哨"NOR);
	set("long", @LONG

你來到了守衛塔的頂端，在旁邊只有一道約至腰部高的石牆，站在
你身邊的是一個個站崗崗哨的守衛，一臉嚴肅之神情，不時的遠望在城
戕四周任何的異狀，南邊的森林似乎有些大風，所以都霧茫茫的，看不
清楚，中間的地方有一個圓形投發器。

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"tower_2.c",
]));
	set("objects",([
  __DIR__"npc/fort_g.c": 3,
]));
	set("item_desc",([
  "圓形投發器" : "一個圓形的投發器，聽說是當有外敵侵入時，就會發射狼煙，讓全城進去戒備狀態，\n"
		+"所以派使的衛兵必須要經過嚴格的挑選，以免一天投發器會誤投而造成荒亂。\n",
]));
	set("light", 1);
	set("no_clean_up", 0);
	set("level","tower_3");
	setup();
	replace_program(ROOM);
}