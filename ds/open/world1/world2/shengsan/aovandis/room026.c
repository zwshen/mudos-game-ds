// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"奧凡大道"NOR);
	set("long", @LONG
四周不時會有陽光打到琉璃反射出來的耀眼反光，金的、紅的、黃的
或綠的。在奧凡迪斯的奧凡大道上，你看到了純樸的市民在殷切的向你打
招呼，這條大道是位於城裡的西半邊，往西直走就是西城門了。
LONG
	);

	set("exits", ([ /* sizeof() == 3 */
            "east" : __DIR__"room021",
	    "west" : __DIR__"room033",
	    "south": __DIR__"room034",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}