#include <armor.h>
inherit BOOTS;
void create()
{
        set_name("虎皮靴" ,({ "tiger boots","boots" }) );
        set("long","這是一個虎皮包製而成的長靴, 相當牢固耐用。\n");
        set_weight(1000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件" );
                set("value" ,900);
                set("material","fur");
        }
        set("armor_prop/armor", 3); 
        setup();
}
