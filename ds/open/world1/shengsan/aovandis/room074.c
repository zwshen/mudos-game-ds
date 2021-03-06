// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"武器專賣店"NOR);
	set("long", @LONG
你看到牆上及專櫃裡擺著好多各式各樣的攻擊類武器，看到這些不經
讓你有搶購的衝動，如果需要可以跟老闆買你想要的武器。你注意到牆上
有個用木板釘成的告示牌(note)。
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
	set("exits", ([ /* sizeof() == 1 */
            "east" : __DIR__"room062",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}