#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name("插著"HIR"蠟燭"NOR"的"NOR""YEL"提拉米蘇"NOR, ({ "tiramisu", "cake" }) );
        set_weight(1000);
        if( clonep() )
            set_default_object(__FILE__);
        else {
                set("unit", "塊");
set("long", "
提拉米蘇，Tiramisu，在義大利文里，有「帶我走」的含義，帶走的不只是美味，還有"HIR"愛"NOR"和"HIY"幸福"NOR"。

一層浸透了Espresso咖啡與酒、質感和海綿蛋糕有點像的手指餅乾，一層混合了Mascar ponecheese
、蛋、鮮奶油和糖的芝士糊，層層疊上去，上頭再撒一層薄薄的可可粉...

大口咬下去，滿滿的幸福感從口中擴散到全身。

上面插著幾根蠟燭，旁邊用巧克力粉寫上了"HIM"∼"HIW"Ｍｏｏｎ"HIY"生日快樂"HIM"∼
"NOR);
        }
set("food_remaining", 4);
        set("heal_hp",2000);  
set("heal_mp",2000);
set("heal_ap",2000);

        setup();
}

int query_autoload() { return 1; }
