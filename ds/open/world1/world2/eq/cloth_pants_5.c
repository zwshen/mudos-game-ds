#include <armor.h>
inherit PANTS;

void create()
{
	set_name("布短褲",({ "cloth short pants","pants" }) );
	set("long",@LONG
這是一件白色的布製短褲，穿起來十分透氣。
LONG
);
	set_weight(1620);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "件");
        }
        set("armor_prop/armor",5);
        setup();
        set("value",499);
        set("volume", 3);
}

int query_autoload() { return 1; }
