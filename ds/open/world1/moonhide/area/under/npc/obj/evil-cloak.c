#include <armor.h>
#include <ansi.h>
inherit SURCOAT;
void create()
{
        set_name(HIB"渾天骷"NOR,({ "chaos cloak","cloak" }) );
        set("long","由天魔的角質硬化而成的披風。\n");
        set_weight(1000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("volume",5);
         set("material","steel");
                set("unit", "件" );
       set("value",4000);
                set("armor_prop/armor", 20);
        }
        setup();
}


