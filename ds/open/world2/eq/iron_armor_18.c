#include <armor.h>
inherit ARMOR;

void create()
{
	set_name("強化型鐵護胸",({"s-iron chest protector","protector"}) );
	set("long",@LONG
這是一件用鐵片接合而成的護胸，但是接合處經過了強化處理。
LONG
);
	set_weight(9750);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "iron");
                set("unit", "件");
        }
        set("armor_prop/armor",18);
        setup();
        set("value",2980);
        set("volume", 8);
}

int query_autoload() { return 1; }
