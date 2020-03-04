#include <ansi.h>
#include <path.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name(HIY"蜂蜜"NOR, ({"honey"}) );
  set("long", 
"一塊半凝固狀的新鮮蜂蜜，散發濃濃的花香。\n"
);
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "塊");
    set("volume",1);
    set("value",50);
    set("food_remaining",1);
    set("heal_hp",30);  
    set("heal_ap",30);  
    set("heal_mp",30);  
    set("eat_msg","$N吃下一塊香甜的蜂蜜。");
    set("eff_msg",HIG "你覺得甜蜜的感覺充斥在口腔中，令你回味無窮。" NOR );
  }
  setup(); 
}
