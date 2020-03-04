#include <weapon.h>           //要先include 武器的函數
#include <ansi.h>             //定義色碼
inherit BLADE;

void create()
{
 set_name( HIY "焰" YEL "熇" NOR , ({"flame blade","blade"}));
        set_weight(5678);
        if( clonep() )     //系統的參數..設定....
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long","這把刀與一般厚實的刀大不相同,刀身極細,
                 但也相當的鋒利。\n");
      set("value",5555);
      set("material", "steel");  //材質 鋼
      set("wield_msg", "$n從你腰間竄出,在天空轉了幾圈,
                    落到$N手中。\n");//$N玩家$n武器
      set("unwield_msg", "$N將手中的$n轉了幾下俐落插入刀鞘。\n");
        }
        init_blade(456);
 set("weapon_prop/blade",30);       //加enable技能30
 set("weapon_prop/force",20);        //加enable技能20
        setup();
}
