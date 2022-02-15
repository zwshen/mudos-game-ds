// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"民房"NOR);
	set("long", @LONG
你來到一間市民居住的房子裡頭，家具擺飾都井然有序的陳放著，可
見這家的主人是多麼的細心.
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
            "east" : __DIR__"room082",
            ]));

	set("objects", ([ /* sizeof() == 1 */
//		__DIR__"npc/boss.c" : 1,
	]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}