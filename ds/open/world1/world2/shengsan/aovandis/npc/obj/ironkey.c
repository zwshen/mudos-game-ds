//key for locked door
#include <ansi.h>
inherit ITEM;

void create()
{
set_name("十字鑰匙",({"iron key","red","key"}));
	set_weight(200);
	set("unit", "把");
	set("long",
		"一把很常見的鐵製十字鑰匙，你看到這把鑰匙的背面還刻了一個[貓]字。\n"
		);
	set("door","ironkey");
	set("value", 50);
	set("usage","開啟某一扇門");
        //set("amount",1);
}
