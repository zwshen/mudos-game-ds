#include <weapon.h>
inherit BLADE;

void create()
{
set_name("木刀",({"wood blade","blade"}));
	set_weight(3000);   //設重量
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("long",@LONG
這是一把木製的刀，似乎不太耐用。
LONG);
		set("unit", "把");
		set("material","wood");
        }
 	init_blade(5);
	setup();
        set("value",300);
}

int query_autoload() { return 1; }
