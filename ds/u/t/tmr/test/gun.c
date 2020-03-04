#include <weapon.h>

inherit GUN;

void create()
{
        set_name("左輪手槍",({"left gun","gun"}));
        set("long","這是一把小型的左輪手槍，一次能裝填六發子槍。\n");
        set_weight(4600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value",380);
                set("rigidity",500);    //新增: 硬度
                set("material","iron");
        }

        set("wield_msg","$N從口袋裡拿出一把$n, 並將$n的保險裝置解開。\n");
        set("unwield_msg", "$N將手中的$n保險裝置關閉, 並放入口袋中。\n");
        set("bullet_type","left_gun");     //可用子彈種類
        set("max_load",6);                 //最大裝填量
        init_gun(10); 
        setup();
}

