#include <armor.h>
#include <ansi.h>
inherit SHIELD;
void create()
{
        set_name(WHT"鐵盾牌"NOR,({ "iron shield","shield" }) );
        set("long","這是一件完全用鐵打造的盾牌[0;1;36m�[1mA[0m防禦力高[0;1;36m�[1mC[0m\n");
        set_weight(1000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("volume",5);
         set("material","steel");
                set("unit", "件" );
       set("value",1000);
                set("armor_prop/armor", 10);
                set("armor_prop/shield",10);
        }
        setup();
}

