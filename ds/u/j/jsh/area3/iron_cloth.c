#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name(WHT"鐵絲外衣"NOR,({ "iron cloth","cloth" }) );
        set("long","這是一件完全用鐵絲編成的上衣[0;1;36m�[1mA[0m非常輕巧[0;1;36m�[1mC[0m\n");
        set_weight(500);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("volume",5);
         set("material","steel");
                set("unit", "件" );
       set("value",500);
                set("armor_prop/dodge", 6);
                
        }
        setup();
}

