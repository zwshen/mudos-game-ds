#include <armor.h>

inherit SHIELD;

void create()
{
	set_name("大圓盾",({"shield"}) );
	set("long","這是一面大圓盾。\n");
	set_weight(1200);		
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material","steel");
		set("unit", "面");
		set("value",220);
	}
	setup();
}
