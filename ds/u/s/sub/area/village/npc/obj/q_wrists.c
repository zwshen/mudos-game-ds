#include <armor.h>
inherit WRISTS;
void create()
{
        set_name("白金手環" ,({ "platinum wrists","platinum","wrists" }) );
        set("long",@LONG
這是一個白金製成的手環，銀色的光芒讓人幾乎無法直視。
LONG);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(300);
        set("unit", "個" );
        set("value",5000);
        }
        set("armor_prop/armor", 3);
        set("armor_prop/con", 1);
        set("armor_prop/bar", 2);
        set("armor_prop/str",-1);
        setup();
}
