
#include <armor.h>

inherit SHIELD;

void create()
{
	set_name("防暴盾牌",({"riot shield","shield","riot"}) );
	set("long","這是奧凡迪斯警衛所裝備的防暴盾牌。\n");
	set_weight(5400);		
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material","steel");
		set("unit", "面");
		set("value",1960);
	}
	setup();
}
