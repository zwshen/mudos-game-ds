#include <ansi2.h>
inherit ITEM;

void create()
{
  set_name(WHT"神力符"NOR,({"power tally","tally"}));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long","這是一道謎般的符紙，符紙上寫了一堆奇怪文字，詭譎無比。\n使用方法: power");
    set("value",2000);
    set("unit","張");
  }
  setup();
}
void init()
{
  add_action("power","power");
}

int power()
{
  object me=this_player(), ob=this_object();
  if(ob->query("in_use")) return notify_fail("一張只能用一次。\n");
  if(me->query_temp("power_tally_useing")) return notify_fail("你的身體己經無法承受更大的力量了。\n");
  set("in_use",1);
  set("no_sac",1);
  set("no_sell",1);
  set("no_drop",1);
  set("no_give",1);
  set("value",0);
  me->add_temp("apply/damage",150);
  me->set_temp("power_tally_useing",1);
  message_vision(HIR"$N緊握手中的$n"HIR"，大喝一聲，凌厲無比的氣勁四散而出！！\n"NOR,me,ob);
  call_out("out_contorl",100,ob,me);
  return 1;
}

int out_contorl(object ob,object me)
{
  if(!me) destruct(ob);
  me->delete_temp("power_tally_useing");
  me->add_temp("apply/damage",-150);
  write(HIR"封印於神力符中的力量己消失殆盡，化成碎片在空中飛舞 .... \n"NOR);
  destruct(ob);
  return 1;
}

