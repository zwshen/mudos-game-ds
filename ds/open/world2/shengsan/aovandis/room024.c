// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"奧凡大道"NOR);
	set("long", @LONG
你在奧凡迪斯的奧凡大道上，四周不時會有陽光打到琉璃反射出來的
耀眼反光，金的、紅的、黃的或綠的。這條大道是位於城裡的西半邊，往
西直走就是西城門了。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"room017",
	    "west" : __DIR__"room019",
	    "south": __DIR__"room061",
	    "north": __DIR__"room089",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}