#include <weapon.h>
inherit BLADE;

void create()
{
set_name("菜刀",({"cook blade","blade"}));
	set_weight(7000);   //設重量
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("long",@LONG
這是一把十分精緻的菜刀，相當銳利。
LONG);
		set("unit", "把");
		set("material","iron");
        }
 	init_blade(22);
	setup();
        set("value",2350);
        set("backstab_bonus",31);
}
int can_stab() { return 1; }
//int query_autoload() { return 1; }
