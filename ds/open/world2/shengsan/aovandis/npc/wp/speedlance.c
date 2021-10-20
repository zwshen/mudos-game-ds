#include <weapon.h>

inherit FORK;

void create()
{
        set_name("音速槍", ({"speed lance","speed","lance"}) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這是一把尖銳無比的音速槍。\n");
		set("value", 10500);
		set("material", "steel");
	}
	init_fork(24);

	setup();
}

int query_autoload() { return 1; }
