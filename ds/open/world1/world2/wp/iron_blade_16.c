#include <weapon.h>
inherit BLADE;

void create()
{
set_name("短刺刀",({"short combat blade","blade"}));
	set_weight(4300);   //設重量
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("long",@LONG
這是一把軍隊公發的短刺刀，除了殺敵必要時也用來自刎。
LONG);
		set("unit", "把");
		set("material","iron");
        }
 	init_blade(16);
	setup();
        set("value",1550);
        set("backstab_bonus",18);
}
int can_stab() { return 1; }
//int query_autoload() { return 1; }
