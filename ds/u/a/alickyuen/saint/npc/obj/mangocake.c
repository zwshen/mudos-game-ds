#include <ansi.h>    //new add
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name(HIY"芒果蛋糕"NOR, ({ "mango cake" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", HIG"一個用新鮮芒果製成的蛋糕\n"NOR);
                set("unit", "個");
                set("value", 200);
                set("food_remaining",6);
                set("heal_ap",30+random(6));
        }
}