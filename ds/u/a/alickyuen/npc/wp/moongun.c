#include <weapon.h>
#include <ansi.h>
inherit GUN;
inherit F_UNIQUE;

void create()
{
set_name(HIY"月影神鎗"NOR,({"moonshade gun","gun"}));
set("long","這是一把射擊武器, 聽說是一百多年前【月影神】所留下的武器,是最原始的鎗。\n");
set_weight(6500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value",2000);
                set("rigidity",800);    
                set("material","iron");
                set("no_sell",1);
                set("no_drop",1);
                set("no_sac",1);
//
// 條件可以是   limit_lv        limit_str 
//              limit_dex       limit_con 
//              limit_int       limit_skill
//
   set("limit_lv",15);
                                set("limit_con",25);
                set("limit_int",25);
                set("limit_str",25);
        }

        set("wield_msg","$N從鎗袋裡拿出一把$n。\n");
        set("unwield_msg", "$N將手上的$n放回鎗袋裡。\n");


//  weapon_prop/dex
//  weapon_prop/str
//  weapon_prop/int
//  weapon_prop/con
//  weapon_prop/hit     命中率
//  weapon_prop/parry   招架率
//
        set("bullet_type","moon_clip"); //可用子彈種類
        set("max_load",25);             //最大裝填量
        init_gun(14);   // 肉搏傷害力=set("weapon_prop/damage", 14);
        setup();
}

