
#include <armor.h>
inherit BOOTS;

void create()
{
	set_name("布鞋",({"boots"}) );
	set("long",@LONG
這是一雙很常見的布鞋。
LONG
);
	set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "iron");
		set("unit", "雙");
	}
	set("auto_set",2);
	setup();
}

// int query_autoload() { return 1; }
