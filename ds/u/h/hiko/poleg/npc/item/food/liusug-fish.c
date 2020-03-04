#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
  set_name(HIW"六"HIC"川"HIY"祥"HIW"魚"NOR, ({ "liusug fish","fish" }) );
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "一道擺\飾極端華麗的料理，用了很多稀有的材料製作而成\n"
                "而且所用醬汁是從山川取得，所以味道很鮮美亦很淡爽\n"
                "感覺很清涼，也不會油膩。\n");
    set("unit","碟");
    set("value",3000);
    set("heal_hp",70);
    set("heal_ap",70);
    set("heal_mp",70);
    set("eat_msg","$N吃了一口$n。");
    set("eff_msg",HIG "你感到身上傷口復原了，全身舒暢。" NOR );
    set("food_remaining",20);
  }
  setup();
   set("no_sell",1);
   set("no_sac",1);
 set("cure",([
         "head" : 5,
         "body" : 5,
         "right_leg" : 5,
         "left_leg" : 5,
            ]));
}













