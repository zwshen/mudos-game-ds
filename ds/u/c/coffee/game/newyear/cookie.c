#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIY"大餅"NOR, ({ "cookie","cookie" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "為了過年特別製作的大餅。\n");
                set("unit", "塊");
                set("value", 0);  
                set("food_remaining",7);
                set("heal_hp",500);
                set("heal_ap",500);
                set("heal_mp",500);
        }
}


