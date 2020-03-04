#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("清靈丹", ({ "green pill","pill" }));
        set("long",
"一顆呈暗綠色的藥丸，有令人醒神解腦的效果。\n"
        );
        set_weight(220);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
        set("unit", "顆");
        set("value", 500);
        set("heal_mp",70+random(16));
        set("eat_msg","$N吃下一顆清新的綠色藥丸。\n");
        set("eff_msg",HIM "一股清涼的味道直衝你靈竅。\n" NOR );
        set("food_remaining", 20);
        }
        setup();
}


