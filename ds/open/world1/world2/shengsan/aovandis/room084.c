// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"上層走道"NOR);
	set("long", @LONG
你站在一排排往北而上的石階之上，石階上鑲著各種炫麗的琉璃，所
排出的圖騰樣式讓人匪夷所思。左右兩側有兩間外表樸素的民房。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"room097",
	    "west" : __DIR__"room056",
	    "south": __DIR__"room090",
	    "north": __DIR__"room048",
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