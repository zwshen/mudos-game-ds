#include <ansi.h>
#include <weapon.h>
#include "std_fist.c"
inherit SSERVER;

void create()
{
  set_name( HIY "異能手套" NOR , ({ "ability gloves","gloves" }) );
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "隻");
    set("long", HIY "這是一隻用特殊材質做的手套，上面泛著一股寒氣。\n這隻看起來是右手用的。\n" NOR );
    set("material", "gold");
    set("value",1);
    set("volume",3);
  }
set("weapon_prop/hit",30);
set("weapon_prop/tec",1);
set("combat_msg", ({
   "$N一式「寸殺」，右向前小跨一步，強勁的短拳擊向$n的腹部\n",
   "$N使出「起式板機」，舉起右手在手上吹了一口氣，一道凍氣往$n射去\n",
   "$N迴旋轉身，縱躍入空，使出「飛天爪擊」，在空中留下一條細長的冰柱\n",
   "$N將凍氣凝結在頭髮上，往$n的胸口刺去\n",
   "$N跳了起來，把寒氣注入雙手，向$n狠狠的戳了一下\n",
   "$N把地面結一層薄冰，滑踢攻向$n的雙腳\n",
}) );
  init_fist(150);
  setup();
}

void init()
{
        add_action("do_hits","hits");
        add_action("do_blizzard","blizzard");
        add_action("do_blizzard","bliz");
}

int do_hits(string arg)
{
        object me, target;
        me=this_player();

        if( arg )
                if( environment(me) ) target = present(arg, environment(me));
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「熱血驅動」只能對戰鬥中的對手使用。\n");

        if( me->is_busy() )
                  return notify_fail("你的上一個動作還沒有完成，不能施展特攻。\n");
        if( me->query("mp") < 90 || me->query("ap") < 120 )
                return notify_fail("你的身體狀況不太好，承受不住這強烈的衝擊。\n");
        if( me->query_temp("hits"))
                return notify_fail("你已正在施展中了，不能再用了。\n");
        message_vision( HIC "\n$N看到對手露出破綻，突然目光一閃，準備施展出「熱血驅動」！！\n\n"NOR,me);

        me->set_temp("hits",1);
        me->start_busy(2);
        call_out("do_crazy",2, me, target, random(6)+4);
        call_out("do_clean",4,me);
        return 1;
}

int do_crazy(object me,object target,int times)
{
  int i;
     if( random(100)>10 && me->query("ap")>80 && me->query("mp")>90 )
  {
    if(!me) return 0;
    if(!target) return 1;
    if(target!=present(target->query("id"), environment(me)))
    {
      me->delete_temp("hits");
      return notify_fail("目標似乎脫離了你的攻擊範圍..\n");
      return 0;
    }
      message_vision(HIC"\n$N目光一閃，全身發出紅光，對著"+target->query("name")+"施展出「熱血驅動」！！\n\n"NOR,me);
      for(i=0;i < times;i++)
    {
      COMBAT_D->do_attack(me,target,me->query_temp("weapon"),4);
          me->receive_damage("ap",random(7)+10);
          me->receive_damage("mp",random(7)+5);
    }
      return 0; 
   }
   else {
      message_vision(HIR"\n$N心煩意亂，一時間使不出「熱血驅動」。\n\n"NOR,me);
          me->receive_damage("ap",30);
   return 1;
   }
}

int do_blizzard(string arg)
{
        object me, target;
        me=this_player();

        if( arg )
                if( environment(me) ) target = present(arg, environment(me));
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「寒冬降臨」只能對戰鬥中的對手使用。\n");

        if( me->is_busy() )
                  return notify_fail("你的上一個動作還沒有完成，不能施展特攻。\n");
        if( me->query("mp") < 90 || me->query("ap") < 120 )
                return notify_fail("你的身體狀況不太好，承受不住這強烈的衝擊。\n");
        if( me->query_temp("bliz"))
                return notify_fail("你已正在施展中了，不能再用了。\n");
        message_vision( HIC "\n$N看到對手露出破綻，突然目光一閃，準備施展出「寒冬降臨」！！\n\n"NOR,me);

        me->set_temp("bliz",1);
        me->start_busy(2);
        call_out("do_bliz",2, me, target);
        call_out("do_clean",4,me);
        return 1;
}

int do_bliz(object me,object target)
{
  int i;
  int dmg;
  dmg = random(200)+random(300)+random(me->query("int")*10)+5000;
     if( random(100)>10 && me->query("ap")>80 && me->query("mp")>90 )
  {
    if(!me) return 0;
    if(!target) return 1;
    if(target!=present(target->query("id"), environment(me)))
    {
      me->delete_temp("bliz");
      return notify_fail("目標似乎脫離了你的攻擊範圍..\n");
      return 0;
    }
      message_vision(HIW"\n$N目光一閃，全身發出白光，對著"+target->query("name")+"施展出「寒冬降臨」！！\n"NOR,me);
          target->receive_damage("hp",dmg);
          target ->start_busy(random(me->query("int"))/2);
          me ->start_busy(2);
          me->receive_damage("ap",random(7)+10);
          me->receive_damage("mp",random(7)+5);
      return 0; 
   }
   else {
      message_vision(HIR"\n$N心煩意亂，一時間使不出「寒冬降臨」。\n\n"NOR,me);
          me->receive_damage("ap",30);
   return 1;
   }
}

int do_clean(object me)
{
          if(!me) return 0;
          me->delete_temp("hits");
          me->delete_temp("bliz");
          return 1;
}

int query_autoload() { return 1; }

