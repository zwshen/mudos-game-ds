// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"道具店"NOR);
	set("long", @LONG
這個商店專門提供各種旅行或平時所要用到的工具及道具，『工欲善
其事，必先利其器。』是這家店面老闆最常講的一句話。你會需要它們的
。牆上有個告示牌(note)。
LONG
	);
	set("item_desc", (["sign":@NOTE
[1;32m
佈告牌上寫著:

		buy       向老闆買東西
		list      老闆會告訴你這裡賣些什麼
		value     老闆會告訴你賣這件東西他會給你多少金幣
		sell      把某個東西賣給老闆
[m
NOTE
        ]) );
	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"room063",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}