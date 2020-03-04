
inherit ITEM;
inherit F_FOOD;
#include <ansi.h>

void create()
{
        set_name(HIG"ºñ¨§Àn³Jºê"NOR, ({ "ap zong zi", "zong", "zi" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Áû");
                set("value", 10);  
                set("heal_ap",200);
                set("food_remaining",2);
        }
}
