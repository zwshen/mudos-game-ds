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
達城市的中心地帶，往南直走是城市的正城門。
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
	    "south": __DIR__"room007",
	    "north": __DIR__"room005",
            ]));

	set("light", 1);

	setup();
	replace_program(ROOM);
}