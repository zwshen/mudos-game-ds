#include <weapon.h>
inherit HAMMER;

void create()
{
	set_name("木槌",({"wood hammer","hammer"}));
	set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        	set("long",@LONG
這是一把很便宜的木槌。
LONG);
		set("unit", "把");
		set("material","wood");
        }
	init_hammer(5); 	// 傷害力=set("weapon_prop/damage", 14);
	setup();
	set("value",300);
}
