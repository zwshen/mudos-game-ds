// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"第二商街"NOR);
	set("long", @LONG
這是一條車水馬龍的熱鬧街道，路旁停滿了各家廠牌形式不一的汽機
車，以及店家擺放在騎樓裡的商品。有許多逛街的年輕人在仔細的挑選他
們想要的商品。
LONG
	);

	set("exits", ([ /* sizeof() == 3 */
	    "west" : __DIR__"room060",
	    "south": __DIR__"room068",
	    "north": __DIR__"room011",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}