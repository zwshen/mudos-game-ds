#include <armor.h>
#include <ansi.h>
inherit HANDS;
void create()
{
        set_name(WHT"鐵絲手套"NOR,({ "iron gloves","gloves" }) );
        set("long","這是一件完全用鐵絲編成的手套[0;1;36m�[1mC[0m\n");
        set_weight(200);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("volume",5);
         set("material","steel");
                set("unit", "件" );
       set("value",300);
                set("armor_prop/shield", -2); 
                set("armor_prop/armor", 12);
               
        }
        setup();
}

