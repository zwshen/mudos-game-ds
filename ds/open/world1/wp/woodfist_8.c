#include <weapon.h>
inherit FIST;
void create()
{
	set_name("木製指虎",({"wood finger","finger"}));
	set("long",@LONG
這把木製指虎十分輕盈，但似乎不怎麼堅固，一般平時拿來練習
拳法用倒十分合適。

LONG
);
	set_weight(2800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "副");
		set("material","wood");
	}
	set("value",280);
	init_fist(13);
        setup();
}
