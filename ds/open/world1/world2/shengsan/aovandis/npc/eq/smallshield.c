
#include <armor.h>

inherit SHIELD;

void create()
{
	set_name("小圓盾",({"small shield","shield","small"}) );
	set("long","這是一面木製的小圓盾。\n");
	set_weight(1220);		
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material","wood");
		set("unit", "面");
		set("value",330);
	}
	setup();
}
