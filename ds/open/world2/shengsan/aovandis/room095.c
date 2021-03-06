// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"服飾精品店"NOR);
	set("long", @LONG
櫥窗上站著一兩個模特兒，身穿美麗的服裝，戴著亮麗的飾品。一旁
的店員正在天花亂墜地為客戶推銷店內的所有服飾精品。店內的天花板吊
著一個個閃亮的水晶，有藍顏色，綠顏色，粉紅色等等。
牆上有個牌子(sign)
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
            "east" : __DIR__"room101",
	    "west" : __DIR__"room090",
            ]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/miss4.c" : 1,
	]));

	set("item_desc", (["sign":@NOTE
[1;32m
佈告牌上寫著:
[1;33m
		buy       向老闆買東西
		list      老闆會告訴你這裡賣些什麼

[m
NOTE
        ]) );

	set("no_clean_up", 0);
	set("valid_startroom",1);
	set("light", 1);
	set("room_type","sell");	// 商店(只能買東西)

	setup();
	replace_program(ROOM);
}