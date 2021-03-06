// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"學術走道"NOR);
	set("long", @LONG
這是條林蔭夾道的寬闊走道，有時這條直直的大道會升起一層似紗的
薄霧，使得這條學術氣息的走道上增添幾分的朦朧之美。北方有個小神殿，
往西直走可以到達美達崙學院。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"room051",
	    "west" : __DIR__"room053",
	    "south": __DIR__"room082",
	    "north": __DIR__"room083",
            ]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/guard" : 2,
		__DIR__"npc/citizen2" : 2,
	]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}