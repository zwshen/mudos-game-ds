#include <armor.h>
inherit BOOTS;
void create()
{
	set_name("厚重靴子" ,({ "heavy boots","boots" }) );
	set("long","一雙看起來很沉重的靴子。\n");
	set_weight(3100);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "雙" );
		set("value" , 900);
		set("armor_prop/armor", 6);
		set("armor_prop/shield", 4);
		set("armor_prop/dodge", -7);
	}
	setup();
}
