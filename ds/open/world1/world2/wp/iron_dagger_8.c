#include <weapon.h>
inherit DAGGER;

void create()
{
	set_name("鐵柄短匕",({"iron short dagger","short dagger","dagger"}));
	set("long",@LONG
這是一把鐵製的短匕首，十分的銳利。
LONG
);
	set_weight(2410);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "把");
		set("material","iron");
        }
    	set("weapon_prop/perception",6);
    	set("weapon_prop/hit",11);
	set("backstab_bonus",14);
	init_dagger(8);
        setup();
        set("value",730);
        set("volume",4);
}
