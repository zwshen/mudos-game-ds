#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name(HIR"牛肉麵"NOR, ({ "beef noodle","noodle" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一碗有大片大片牛肉的麵。\n");
                set("unit","碗");
                    set("value",600);
           set("heal_hp",50);
                set("food_remaining",3);
     }
     setup();
}
