
#include <armor.h>
inherit WRISTS;

void create()
{
	set_name("制式護臂",({"typical wrists","wrists"}) );
	set("long","這是奧凡迪斯守衛所裝備的護臂。\n");
	set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "對");
		set("material", "steel");
		set("value",1900);
        	set("armor_prop/dodge", 1);
	}
	setup();
}
