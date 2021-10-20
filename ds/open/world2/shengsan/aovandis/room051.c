// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"學術走道"NOR);
	set("long", @LONG
你站在一條有學術氣息的走道上。兩旁有藝術造型的路燈，發出淡黃
色的光芒，
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
            "east" : __DIR__"room045",
	    "west" : __DIR__"room052",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}