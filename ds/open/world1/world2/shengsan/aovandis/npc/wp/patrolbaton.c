#include <weapon.h>

inherit STAFF;

void create()
{
        set_name("警棍", ({"baton"}) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這是一把長劍﹐上面刻著「亞特」兩個字。\n");
		set("value", 1000);
	}
	init_staff(20);
	setup();
}

int query_autoload() { return 1; }
