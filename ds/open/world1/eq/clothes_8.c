#include <armor.h>
inherit CLOTH;

void create()
{
	set_name("粗布麻衫",({"grass clothes","clothes"}) );
	set("long",@LONG
這是一件麻布編織而成的運動衫，可以防止運動時一些輕微的擦
傷。
[SAVE-EQ]

LONG
);
	set_weight(2100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "件");
        }
	set("value",240);
    set("armor_prop/armor",4);
        setup();
}

int query_autoload() { return 1; }
