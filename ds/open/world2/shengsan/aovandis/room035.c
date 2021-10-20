// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"迪斯區守衛室"NOR);
	set("long", @LONG
這個小房間就是守衛休息及辦公的地方，守衛們為了保護奧凡迪斯而
辛勤忙碌著，我們應該為他們致上最大的敬意。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
	    "north": __DIR__"room015",
            ]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/guard" : 2,
	]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}