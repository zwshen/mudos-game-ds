// 奧凡迪斯
// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"寬廣的走道"NOR);
	set("long", @LONG
你在一個南北走向的寬廣走道上，走道上鑲著各種炫麗的琉璃，所排
出的圖騰樣式讓人匪夷所思，但你不得不贊嘆城市的美麗，往北直走可到
達城市的中心地帶。往東或往西，可以通往本城市的兩大商圈地帶。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"room072",
	    "west" : __DIR__"room066",
	    "south": __DIR__"room006",
	    "north": __DIR__"room004",
            ]));
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/patrol" : 2,
	]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}