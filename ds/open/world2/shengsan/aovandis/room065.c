// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"超級商店"NOR);
	set("long", @LONG
你走進了一間超級便利商店裡面，你發現這裡賣的東西很雜，不
過卻都十分實用，在這裡你可以買到一些日常用品和一些衣物。
牆上還掛著一個告示牌(sign)。

LONG
	);
	set("item_desc", (["sign":@NOTE
[1;36m
佈告牌上寫著:
[1;32m
		buy       向店員買東西
		list      看看這裡有賣些什麼
[m
NOTE
        ]) );
	set("exits", ([ /* sizeof() == 2 */
	    "west" : __DIR__"room063",
	    "south": __DIR__"room066",
            ]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/miss6.c" : 1,
	]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);
	set("room_type","sell");
	setup();
	replace_program(ROOM);
}