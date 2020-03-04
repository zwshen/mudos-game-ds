// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"學術走道"NOR);
	set("long", @LONG
你站在一條有學術氣息的走道上，這條大道的兩旁是足以蔽天的大樹
，有時會有霧氣在這裡擴散在地面之上。往西直走可以到達美達崙學院。
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
            "east" : __DIR__"room052",
	    "west" : __DIR__"room054",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}