// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"魔法用品店"NOR);
	set("long", @LONG
專櫃裡陳列著珍貴的藥水，這些藥水可不是普通的藥水，它們都有各
種不同的魔法效果。在外求生時絕對要準備個幾瓶藥水以備不時之需。你
看到牆上懸掛著一個漂亮的告示牌(note)。
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
            "east" : __DIR__"room064",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}