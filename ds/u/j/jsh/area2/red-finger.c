#include <armor.h>
#include <ansi.h>
inherit FINGER;
void create()
{
        set_name(HIR"紅毛指套"NOR,({ "red finger","finger" }) );
        set("long","一只全身毛茸茸的指套[0;1;36m�[1mA[0m好像有奇特的能力[0;1;36m�[1mC[0m\n");
        set_weight(100);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("volume",5);
         set("material","steel");
                set("unit", "件" );
       set("value",1000);
                set("armor_prop/armor", 10);
                set("armor_prop/shield",10); 
                set("armor_prop/str",1);        }
        setup();
}

