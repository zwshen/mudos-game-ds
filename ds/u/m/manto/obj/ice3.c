inherit ITEM;
#include <ansi.h>
inherit F_FOOD;

void create()
{
        set_name(YEL"提拉米蘇"NOR, ({ "tiramisu" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "塊");
    set("long", "提拉米蘇，Tiramisu，在義大利文里，有 「帶我走 」的含義，帶走的不只是美味，還有愛和幸福。\n一層浸透了Espresso咖啡與酒（Masala、Rum或Brandy）、質感和海綿蛋糕有點像的手指餅乾，一層\n混合了Mascar鄄ponecheese（最適合專門用來做Tiramisu的芝士）、蛋、鮮奶油和糖的芝士糊，層層\n疊上去，上頭再撒一層薄薄的可可粉……這就是提拉米蘇Tiramisu。\n");
                set("value", 10);  
                set("food_remaining",10);
        }
}
