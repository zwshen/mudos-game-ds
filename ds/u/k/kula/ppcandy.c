#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIY"次次縸"NOR, ({ "candy" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "次次縸┰盽箂\n");
                set("unit", "");
                set("value", 10);  
                set("food_remaining",50);
                set("heal_hp",0);
        }
}

