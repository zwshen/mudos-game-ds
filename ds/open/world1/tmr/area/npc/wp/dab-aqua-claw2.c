#include <ansi.h>
#include <weapon.h>

inherit FIST;

void create()
{
        set_name("點液爪",({"dab-aqua-claw","claw"}) );
	set("long","一隻龍爪，色作淡紅，略帶香味，似乎為「狡龍  點液」的爪。\n");
        set_weight(3000);
 	if (clonep() )
        	     set_default_object(__FILE__);
	else {
	set("unit","隻");
        set("value",2500);
        set("material","leather");
	set("weapon_prop/int",2);
		set("volume",2);
	set("weapon_prop/hit",5);
	set("limit_str",30);
	set("limit_level",15);
	set("wield_msg","$N裝備一隻$n"+NOR"當武器，身上似乎散放地一股香味。\n" NOR);
	}
	set("weapon_prop/int",2);
	set("weapon_prop/hit",5);
	set("beast_weapon_prop/damage",58);
	set("beast_weapon_prop/hit",5);
	set("beast_weapon_prop/int",2);
	init_fist(58);
	setup();
}
