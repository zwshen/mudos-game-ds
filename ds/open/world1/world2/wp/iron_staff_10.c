#include <weapon.h>
inherit STAFF;
void create()
{
	set_name("鐵杖", ({ "iron staff","staff" }) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long",@LONG
這是一把由熟鐵打造而成的鐵杖。
LONG
);
		set("material", "iron");
	}
    init_staff(10);
    setup();
    set("value", 800);
    set("volume", 6);
}

int query_autoload() { return 1; }
