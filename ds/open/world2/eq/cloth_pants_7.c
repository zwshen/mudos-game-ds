#include <armor.h>
inherit PANTS;

void create()
{
	set_name("麻布長褲",({ "cloth pants","pants" }) );
	set("long",@LONG
這是一件褐色的布製長褲。
LONG
);
	set_weight(2220);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "件");
        }
        set("armor_prop/armor",7);
        setup();
        set("value",849);
        set("volume", 4);
}

int query_autoload() { return 1; }
