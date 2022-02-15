// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"植物園"NOR);
	set("long", @LONG
清新的空氣全都是這裡的植物所製造出來的，這些空氣讓你覺得頭腦
變得清新冷靜。各式各樣的植物全在你的眼底下了，你看到有許多可愛的
小生物在其中玩耍鬥樂。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "north": __DIR__"room110",
            "east" : __DIR__"room113",
	    "south": __DIR__"room114",
	    "west" : __DIR__"room111",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}

