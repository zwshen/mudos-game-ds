#include <ansi.h> 
#include <armor.h>
inherit ARMOR;

void create() 
{
        set_name(HIY"龍皮"HIC"軟"HIW"甲"NOR,({ "dragon-soft armor","armor" }) );
        set("long","光之子祖傳的愷甲，據說是古青眼白龍身體的某部份軟皮所製成的。\n");
        set_weight(10000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
     set("volume",5);
         set("material","steel");
                set("unit", "件" );
       set("value",5000);
                set("armor_prop/armor", 46);
                set("armor_prop/shield",5);
        }
        setup();
}

