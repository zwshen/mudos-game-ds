#include <armor.h>
inherit NECK;
void create()
{
        set_name("幸運符", ({"lucky necklace","necklace","lucky" }) );
        set("long", @LONG
一個圓圓的石頭用一條鍊子串了起來，石頭裡面還有一個弧形的光澤。
LONG);
    set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "個" );
        set("armor_prop/armor", 1);
        set("armor_prop/dex",2); 
        set("armor_prop/str",-1);
        set("armor_prop/con",-1);        set("armor_prop/bar",1);
        set("value", 800);
        }
        setup();
}
