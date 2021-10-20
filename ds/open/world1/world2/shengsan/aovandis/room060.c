// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"守衛隊總司令辦公室"NOR);
	set("long", @LONG
這裡是守衛隊總司令亞特的辦公室，牆上有各種的刀劍，每隻刀劍都
是精品之作，讓你也想擁有它們。
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
            "east" : __DIR__"room067",
	    "north": __DIR__"room010",
            ]));
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/art" : 1,
	]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}