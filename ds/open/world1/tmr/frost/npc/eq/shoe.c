#include <armor.h>
inherit BOOTS;

void create()
{
        set_name("草鞋" ,({ "shoe" }) );
        set("long","這是一雙蘆草編製的草鞋，多是出家修道人所穿的。\n");
        set_weight(800);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
               set("material", "plant");
               set("unit", "雙" );
        }
        set("value",150);
        set("armor_prop/armor", 1);
        set("armor_prop/dodge", 1);
        setup();
}

