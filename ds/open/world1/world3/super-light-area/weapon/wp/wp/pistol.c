#include <ansi.h>; 
#include <weapon.h>
inherit GUN;
void create()
{
set_name(HIW"9釐米手槍"NOR,({".9MM pistol","pistol"}));
set("long","屬於半自動型手槍, 不適合與大量敵人對戰時使用。
[最多能填裝50發子彈]\n");
 set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value",1500);
                set("rigidity",700);   
                set("material","iron");
        }

        set("wield_msg","$N從身上掏出一把$n, 並將$n的保險裝置解開。\n");
        set("unwield_msg", "$N將手中的$n保險裝置關閉, 並放回身上。\n");
        set("bullet_type","9mm");     
        set("max_load",50);           
        init_gun(12);   
        setup();
}

