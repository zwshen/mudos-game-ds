//u/c/chiaa/obj/eq/leading_sword.c

#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
  set_name(GRN"絕"HIB"代"HIR"之"HIC"狂"NOR,({"leading sword","sword"}));
  if (clonep() )
             set_default_object(__FILE__);
    else {
      set("unit","把");
      set("long","這是一把能與主人心意相通的劍,只要能做到人劍合一,
          甚至能散發出想像不到的威力。\n");
      set_weight(7000);
      set("value",20000);
      set("material","wolfram");  //材質 鎢
      set("wield_msg", "$n以極快的速度從你背上飛出,劍身嗡嗡作響,
          落在你眼前不遠處。\n");
       set("unwield_msg", "$N將手中的$n插入背上的劍鞘。\n");

   }
        init_sword(511);     //武器攻擊力
 set("weapon_prop/sword",35);        //加 enable 技能35
 set("weapon_prop/parry",20);        //加enable  技能20
setup();
}
