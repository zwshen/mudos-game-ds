#include <weapon.h>
inherit DAGGER;

void create()
{
	set_name("木匕首",({"wood dagger","dagger"}));
	set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "把");
		set("material","wood");
	set("long",@LONG
這是一把木頭削成的匕首。
LONG
);
        }
	init_dagger(5);
        setup();
        set("value",300);
	set("backstab_bonus",6);
}

int query_autoload() { return 1; }

