
#include <armor.h>

inherit HEAD;

void create()
{
	set_name("制式頭盔",({"typical helmet","helmet"}) );
	set("long","這是奧凡迪斯守衛所穿的頭盔。\n");
	set_weight(3300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material","steel");
		set("unit", "件");
		set("value",1400);
        	set("armor_prop/armor", 4);
	}
	setup();
}
