#include <armor.h>
#include <combat.h>
#include <ansi.h>
inherit SSERVER;
inherit NECK;

void create()
{
set_name(HIW"NIKE"HIC"項鍊"NOR,({"nike necklace","necklace"}));
set_weight(1800);
set("long","這是烏漆嗎黑專用的護具。\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("material", "iron");
set("unit", "串");
set("value",0);
set("no_sell",1);          
set("limit_con",1);
set("armor_prop/armor",12);
set("armor_prop/shield",12);
}
setup();
}

void init()
{
 add_action("do_help","help");
 add_action("do_berserk","berserk");
}

int do_help(string arg)
{
 if(arg=="necklace")
 {
  write(
   "\n戰士指令說明:\n"
  +"berserk: 瘋狂攻擊\n"
  );
  return 1;
 }
 return 0;
}

int do_berserk(string arg)
{
object me, target;
 int skill, cost;
 
 me=this_player();
 if(!me) return 0;
 if(me->start_busy()) return notify_fail("你動作還沒完成..\n");
 if(me->query_temp("berserk")) return notify_fail("你不能連續做這麼激烈的動作.\n");
 if(!me->is_fighting())
        return notify_fail("這個技能只能在戰鬥時使用。\n");
 if(arg)
 {
  target=present(arg, environment(me));
  if(!target) return notify_fail("要對誰施展瘋狂攻擊??\n");
  if(!me->is_fighting(target)) return notify_fail("這個技能只能對你目前的敵人使用。\n");
 }
 else target = offensive_target(me);    //此函數需inherit SSERVER;
 if(!target) return notify_fail("這個技能只能對你目前的敵人使用。\n");
 skill=me->query_skill("berserk",1);
 // if(skill<5) return notify_fail("你的技能還不夠熟練\n");
 cost = 25;
 if(me->query("mp") < cost) return notify_fail("你目前的體力狀況無法做如此劇烈的動作\n");
 message_vision(HIR"\n$N兩眼發紅, 漸漸陷入了瘋狂狀態...\n\n"NOR,me);
 skill/=8;
skill+=2;
 me->set_temp("berserk",1);
 me->start_busy(2);
 me->add("mp",-cost);
 call_out("do_crazy",4,me,target,skill);
 call_out("do_clean",8,me);
 return 1;
}

int do_crazy(object me,object target,int times)
{
  int i;
  if(!me) return 0;
  if(target!=present(target->query("id"), environment(me)))
  {
    me->delete_temp("berserk");
    return notify_fail("目標似乎脫離了你的攻擊範圍..\n");
  }
  message_vision(HIW"\n∼∼吼∼∼$N仰天長嘯開始發狂了!!!\n\n"NOR,me);
  for(i=0;i < times ;i++)
  COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_BERSERK); 
  COMBAT_D->report_status(target);      //加上這行可以顯示target的健康狀況
  me->improve_skill("berserk",1+random(me->query_int()/10));
return 1;
}

int do_clean(object me)
{
 if(!me) return 0;
 me->delete_temp("berserk");
 return 1;
}

int query_autoload() { return 1; }


