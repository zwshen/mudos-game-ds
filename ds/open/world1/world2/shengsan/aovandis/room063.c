// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"第一商街"NOR);
	set("long", @LONG
這裡是奧凡迪斯的第一商街，這裡是全城中最熱鬧的地方之一，在這
逛逛你一定會有很多收穫的。往西是婚姻介紹所。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"room065",
	    "west" : __DIR__"room075",
	    "south": __DIR__"room064",
	    "north": __DIR__"room062",
            ]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/citizen1" : 2,
	]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}