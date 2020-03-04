#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("¯}ÂÂ¥¬¦ç", ({ "old cloth", "cloth" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¥ó");
                set("material", "cloth");
                set("armor_prop/armor", 4);
                set("value",300);
        }
        setup();
}