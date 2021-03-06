// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"走道"NOR);
	set("long", @LONG
在這條冷清的走道上，你看到兩旁牆上的窗戶，種植著各式各樣的花
草藤蔓，他們的主人殷勤的澆水施肥才有這般的景象。而這條走道卻鮮少
有人經過，也許是因為這條走道位於城牆旁邊的關係吧。
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
            "east" : __DIR__"room037",
	    "west" : __DIR__"room008",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}