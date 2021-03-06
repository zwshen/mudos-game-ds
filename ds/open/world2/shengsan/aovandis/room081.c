// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"麵包店"NOR);
	set("long", @LONG
如果你要吃吃最具特色的麵包，那麼你來對地方了。這是一間以創意
及美味掛帥的麵包店，料好實在，而且價錢也相當的便宜。城裡的居民都
會在這買他們愛吃的麵包，每當有慶生時，這裡所做出的蛋糕也是他們的
最愛。牆上掛著一個告示(sign)。
LONG
	);

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/boss2.c" : 1,
	]));

	set("item_desc", (["sign":@NOTE
[1;32m
佈告牌上寫著:

		buy       向老闆買東西
		list      老闆會告訴你這裡賣些什麼
[m
NOTE
        ]) );
	set("exits", ([ /* sizeof() == 1 */
            "west" : __DIR__"room070",
            ]));

	set("no_clean_up", 0);
	set("valid_startroom",1);
	set("light", 1);
	set("room_type","sell");	// 商店(只能買東西)

	setup();
	replace_program(ROOM);
}