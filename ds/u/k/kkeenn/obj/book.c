#include <ansi.h>
inherit SSERVER;
inherit ITEM;
void create()
{
        set_name(MAG"爆氣寶典"NOR,({"berserk book","book"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",
     "這是遊龍俠當年巧遇幽冥佬之時, 兩人相見甚歡, 所合制的紀念品。\n");
             }
        set("value", 10000);
        set_weight(250);
        setup();
}
void init()
{
        add_action("do_berserk","berserk");
}

int do_berserk(string arg)
{
        object me, target;
        me=this_player();

        if( arg )
                if( environment(me) ) target = present(arg, environment(me));
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「爆氣迫」只能對戰鬥中的對手使用。\n");

        if( me->is_busy() )
                  return notify_fail("你的上一個動作還沒有完成，不能施展特攻。\n");
        if( me->query("mp") < 50 || me->query("ap") < 100 )
                return notify_fail("你的身體狀況不太好，承受不住這強烈的衝擊。\n");
        if( me->query_temp("berserk"))
                return notify_fail("你已正在施展中了，不能再用了。\n");
        message_vision(HIR"\n$N怒氣攻心, 一生爆喝, 把多年的火氣全部釋放出來！！\n\n"NOR,me);

        me->set_temp("berserk",1);
        me->start_busy(1);
        call_out("do_ber",1, me, target,20);
        call_out("do_serk",10,me);
        return 1;
}

int do_ber(object me,object target,int times)
{
  int i;
     if( random(100)>35 && me->query("ap")>80 && me->query("mp")>90 )
  {
    if(!me) return 0;
    if(!target) return 1;
    if(target!=present(target->query("id"), environment(me)))
    {
      me->delete_temp("berserk");
      return notify_fail("目標慌慌張張的逃走了..\n");
      return 0;
    }
     message_vision(HIR"\n$N仰天長嘯一聲，身上隱約浮出一隻赤龍，對著"+target->query("name")+"施展出不傳之技「"MAG"爆氣迫"HIR"」！！\n\n"NOR,me);
      for(i=0;i < times;i++)
    {
      COMBAT_D->do_attack(me,target,me->query_temp("weapon"),20);
          me->receive_damage("ap",random(2));
          me->receive_damage("mp",random(2));
    }
      return 0; 
   }
   else {
      message_vision(HIR"\n$N被偷襲到, 全身火氣逆衝, 看來受了點內傷了。\n\n"NOR,me);
          me->receive_damage("hp",random(300));
   return 1;
   }
}
int do_serk(object me)
{
          if(!me) return 0;
          me->delete_temp("berserk");
          return 1;
}

