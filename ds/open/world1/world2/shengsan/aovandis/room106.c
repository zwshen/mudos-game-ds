// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"酒吧地下室"NOR);
	set("long", @LONG
這裡是酒店的地下室，有種醉人的香味直直撲向你的鼻尖讓你昏昏欲
睡。有很多裝滿名貴酒類的桶子存放在這。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
	    "up"   : __DIR__"room120",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}

