#include <armor.h>

inherit BOOTS;

void create()
{
	set_name("普通的草靴",({"straw boots","boots"}) );
	set("long","一雙到處都買得到的草靴。\n");
	set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        	set("material", "grass");
		set("unit", "雙");
		set("value",380);
	}
	setup();
}
