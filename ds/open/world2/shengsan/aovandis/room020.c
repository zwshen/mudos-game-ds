// 奧凡迪斯
// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"奧凡大道"NOR);
	set("long", @LONG
你在奧凡迪斯的奧凡大道上，這條大道是位於城裡的西半邊，往西直
走就是西城門了。
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
            "east" : __DIR__"room019",
	    "west" : __DIR__"room021",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}