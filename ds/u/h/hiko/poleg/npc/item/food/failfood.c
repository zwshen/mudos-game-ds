#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
  set_name("失敗料理", ({ "fail food","food" }) );
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "一道味道刺鼻且顏色奇特的失敗料理，令人望之生畏\n");    
    set("unit","碟");
    set("heal_hp",-5);
    set("heal_ap",10);
    set("heal_mp",-5);
    set("food_remaining",1);
  }
  setup();
   set("no_sell",1);
   set("no_sac",1);
}







