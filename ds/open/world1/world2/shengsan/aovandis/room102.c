// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"市立醫院開刀房"NOR);
	set("long", @LONG
這裡是醫院的開刀房，周圍都是開刀所要用到的醫療器材。很多病患
都曾經在這裡救回一條可貴的生命。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
	    "south": __DIR__"room085",
            ]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/doctor1" : 1,
		__DIR__"npc/nurse" : 1,
	]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);
	set("room_type","hospital");	//醫院

	setup();
	replace_program(ROOM);
}

