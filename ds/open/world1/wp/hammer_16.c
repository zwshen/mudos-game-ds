#include <weapon.h>
inherit HAMMER;
void create()
{
	set_name("大鐵鎚",({"big hammer","hammer"}));
	set("long",@LONG
這把重約七公斤的大鐵鎚看起來十分堅硬，錘頭部分曾經因為強
力的撞擊而有些小缺口。

LONG
);
	set_weight(6800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "把");
		set("material","iron");
	}
	set("value",580);
	init_hammer(16);
        setup();
}
