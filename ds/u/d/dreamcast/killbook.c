#include <ansi.h>
inherit SSERVER;
inherit ITEM;
inherit F_UNIQUE;
void create()
{
        set_name(HIR"《驚世天魔寶典》"NOR,({"skyevil book","book"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",
              "這是天魔滅世時所用的一本書，記載這天魔的武功驚世滅神擊•\n");
             }
        set("value", 100);
        set_weight(250);
        setup();
}

void init()
{
        add_action("do_you","you");
}

int do_you(string arg)
{
        object me, target;
        me=this_player();

        if( arg )
                if( environment(me) ) target = present(arg, environment(me));
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「驚世天魔寶典」只能對戰鬥中的對手使用。\n");

        if( me->is_busy() )
                  return notify_fail("你的上一個動作還沒有完成，不能施展特攻。\n");
        if( me->query("mp") < 90 || me->query("ap") < 120 )
                return notify_fail("你的身體狀況不太好，承受不住這強烈的衝擊。\n");
        if( me->query_temp("you"))
                return notify_fail("你已正在施展中了，不能再用了。\n");
        message_vision(HIR"\n$N心中突然對驚世天魔寶典有了認同感，寶典便引你始出「驚世滅神擊」\n\n"NOR,me);

        me->set_temp("you",1);
        me->start_busy(4);
        call_out("do_crazy",10, me, target,10);
        call_out("do_clean",10,me);
        return 1;
}

int do_crazy(object me,object target,int times)
{
  int i;
     if( random(100)>35 && me->query("ap")>80 && me->query("mp")>90 )
  {
    if(!me) return 0;
    if(!target) return 1;
    if(target!=present(target->query("id"), environment(me)))
    {
      me->delete_temp("you");
      return notify_fail("目標似乎脫離了你的攻擊範圍..\n");
      return 0;
    }
      message_vision(HIR"\n$N全身的妖氣和魔性全都爆發出來對著"+target->query("name")+"喊：死吧\n\n"NOR,me);
      for(i=0;i < times;i++)
    {
      COMBAT_D->do_attack(me,target,me->query_temp("weapon"),4);
          me->receive_damage("ap",random(7)+10);
          me->receive_damage("mp",random(7)+5);
    }
      return 0; 
   }
   else {
      message_vision(HIR"\n$N身上的殺意和魔性不過多，沒法領會「驚世滅神擊」。\n\n"NOR,me);
          me->receive_damage("ap",30);
   return 1;
   }
}
int do_clean(object me)
{
          if(!me) return 0;
          me->delete_temp("you");
          return 1;
}

