#include <ansi.h>
inherit SSERVER;
inherit ITEM;
void create()
{
       set_name(HIB"《幽冥神殺寶典•改》"NOR,({"you ming book","book"}));
       if( clonep() )
         set_default_object(__FILE__);
       else {
          set("unit", "本");
          set("long",
              "這是一本只有一頁的書，雖然只是一頁但卻花\n"
              "費了天殘邪佬十年的光陰才撰寫而成的，傳說\n"
              "中能夠一口氣爆發人體極限本能，但裡頭只有\n"
              "個血紅偌大的【幽冥】二字，及一些看不懂的\n"
              "符號，實不知有何用途。\n");
            }
        set("value", 0);
        set_weight(250);
        setup();
}

void init()
{
        add_action("do_you","you");
}
int do_you(object target,string arg)
{
        object me;
        me=this_player();
      if( arg == "" ) return 0;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「幽冥神殺訣」只能對戰鬥中的對手使用。\n");

        if (me->is_busy() )
                return notify_fail("你的上一個動作還沒有完成，不能施展特攻。\n");
     if(me->query("mp")<60 || me->query("ap")<100 ) return notify_fail("你的身體狀況不太好，承受不住這強烈的衝擊。\n");
        if(me->query_temp("you"))
                 return notify_fail("你已正在施展中了，不能再用了。\n");
        message_vision(HIR"\n$N氣凝神定，低聲說了幾句，突然大喝一聲，準備施展出「幽冥神殺訣」！！\n\n"NOR,me);

         me->set_temp("you",1);
         me->start_busy(0);
         call_out("do_crazy",4,me,target,40);
         call_out("do_clean",8,me);
         return 1;
}

int do_crazy(object me,object target,int times)
{
  int i;
     if( random(100)>0 && me->query("ap")>50 && me->query("mp")>30 )
  {
    if(!me) return 0;
    if(!target) return 1;
    if(target!=present(target->query("id"), environment(me)))
    {
      me->delete_temp("you");
      return notify_fail("目標似乎脫離了你的攻擊範圍..\n");
      return 0;
    }
      message_vision(HIR"\n$N仰天長嘯一聲，全身赤火乍現，對著"+target->query("name")+"施展出驚世絕技「幽冥神殺訣」！！\n\n"NOR,me);
      for(i=0;i < times;i++)
      COMBAT_D->do_attack(me,target,me->query_temp("weapon"),4);
         me->receive_damage("ap",random(10)+1);
      return 0; 
   }
   else {
      message_vision(HIR"\n$N心煩意亂，一時間使不出「幽冥神殺訣」。\n\n"NOR,me);
         me->receive_damage("ap",10);
   return 1;
   }
}
int do_clean(object me)
{
         if(!me) return 0;
         me->delete_temp("you");
         return 1;
}
