// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"守衛隊辦公室"NOR);
	set("long", @LONG
你感覺有種緊張的氣氛在這個小房間裡，不由自主的你也提高了警覺
心深怕自己會做錯什麼事來。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
	    "north": __DIR__"room040",
            ]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/guard" : 2,
	]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}