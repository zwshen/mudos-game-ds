#include <ansi.h>
inherit SSERVER;
inherit SKILL;

int cure_all(object me,object target,int sk,int inn);
int attack_a(object me,object target,int sk,int inn);
int attack_b(object me,object target,int sk,int inn);

int cast(object me, object target)
{
        int sk,i,inn,cost;
        object *enemy;
        
        //1. 施法的delay要放前面(可用call_out) 2.注意delay之後人物空間的變化.
        //3. ghost的指令要有所限制.
        //luky
        //return notify_fail("這個技能因為有問題, 暫停使用。\n");
        
        sk=me->query_spell("god-benison");
        inn=me->query_int();

        if(sk < 20) return notify_fail("你的「神祝禱篇」還未成火侯，尚無能力使用。\n");
        if(me->is_busy() ) return notify_fail("你現在正忙著，沒有空吧。\n");
        if(environment(me)->query("no_cast")) return notify_fail("這裡不能施法。\n");
        if(me->query("hp")<100 || me->query("mp")<100) return notify_fail("你目前的身體狀態無法使用「神祝禱篇」的。\n");
        
        if(me->is_fighting() )
        {

                if(!target ) target = offensive_target(me);
                if(!me->can_fight(target)) return me->can_fight(target);

                switch( random(2) ) 
                {
                  case 0:
                     message_vision(
                     "\n$N默唸"HIM"「神祝禱篇」"NOR"之"HIR"「神殺」"NOR"訣：\n\n"
                     +"      「血刃浮沉戍上遊，披頭五鬼在辰求。」\n"
                     +"      「天哭逆數起於午，凡占切忌動當頭。」\n"
                     +HIC"\n只見$N頭上一道刺眼強光，赫然出現三位神將，威風凜凜，不可一世！！\n" NOR,me);
                     cost=(sk/4)+(inn/4)+random(inn/2);
                     me->start_busy(2);
                     call_out("attack_a",3,me,target,sk,inn);
                     break;
                  default:
                     message_vision(
                     "\n$N默唸"HIM"「神祝禱篇」"NOR"之"HIC"「長生」"NOR"訣：\n\n"
                     +"      「大哉乾元，萬物滋始。」\n"
                     +"      「至哉坤元，萬物滋生。」\n"
                     +HIC"\n$N雙手左右畫圈，泛出淡藍之光，霎時藍光四散，團團圍繞著$n。\n"NOR,me,target);
                     cost=(sk/5)+(inn/4)+random(inn/3);
                     me->start_busy(2);
                     call_out("attack_b",2,me,target,sk,inn);
                     break;
                } //end of switch()
                me->receive_damage("mp",cost);
                me->set_temp("power_cast",1+sk/20);
         } //end of is_fighting()
        else
        {
                if(!target ) target = me;
                message_vision(
                "\n$N默唸"HIM"「神祝禱篇」"NOR"之"HIW"「沫浴」"NOR"訣：\n\n" NOR
                +"      「天門日射彩雲開，大降洪恩布九垓。」\n" 
                +"      「萬物一時沾聖化，蒼生鼓舞醉金罍。」\n" NOR,me);

                me->receive_damage("mp",15);
                me->start_busy(3);
                call_out("cure_all",3,me,target,sk,inn);
        }
        return 1;
}

int cure_all(object me,object target,int sk,int inn)
{
 if(!me) return 0;
 if(!target) target=me;
 else if(environment(me)!=environment(target)) target==me;
 if(random(inn+sk+me->query("level")) > random(20) )
 {
   message_vision(HIW"\n$N全身上下圍繞著一陣白光，然後漸漸消去。\n" NOR,target);
   target->receive_curing("all",sk/20+inn/8);
   me->improve_spell("god-benison",random(2+inn/5));
   return 1;
 }
 tell_object(me,"結果什麼事情都沒發生。\n");
 tell_room(environment(me),me->query("name")+"搖搖頭, 失望的嘆了一口氣。\n",({me}));
}

int attack_a(object me,object target,int sk,int inn)
{
 int damage,i;
 if(!me) return 0;
 if(!target) return notify_fail("目標消失了。\n");      
 if( environment(me) != environment(target) )           
          return notify_fail("目標離開了你的施法範圍。\n");
 if(!me->query_temp("power_cast") || me->query_temp("power_cast") < 1) 
 {
  message_vision(HIW"$N"HIW"因為受到創傷而亂了思緒, 無法順利施展法術。\n"NOR,me);
  return 1;
 }
 me->delete_temp("power_cast");
 message_vision(HIW"$N雙手結卬，低念數聲，驅使"HIR"「血刃」"NOR"，"HIY"「披頭」"NOR"，"HIC"「天哭」"HIW"引嘯同擊$n！！\n"NOR,me,target);
 
    for (i=0;i<=2;i++)
    {
      switch( i ) 
      {
         case 0:
   message_vision(HIR"血刃殺"NOR"手中剝血刃直砍橫劈十三刀，砍向$N頭、手、胸三盤要害！！"NOR,target);
         break;

         case 1:
   message_vision(HIY"披頭殺"NOR"揮舞手上二把奪魂匕，七七四十九式連往$N胸、腰各要害招呼！！"NOR,target);
         break;
 
         default:
   message_vision(HIC"天哭殺"NOR"氣運手上穿骨槍，一式「石破天驚」，十成力道刺向$N胸口要穴！！"NOR,target);
         break;
      }

      if(random(target->query_skill("dodge")/2+target->query_shield()*3/2 ) < random(sk)+inn )
      {
         damage = (sk/3)+inn+random(inn+sk);
         if(userp(target)) damage = damage - (damage/5);
         damage = damage - (target->query_shield()/2);

         if(damage<20) damage=20+random(inn/2); //限制最低傷害
         if(damage>150) damage=100+random(50);  //限制最高傷害

         damage = COMBAT_D->Merits_damage(me,target,damage,"wit"); 
         target->receive_damage("hp",damage,me);
         target->start_busy(1);

      if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
      tell_object(me,HIY"("+damage+")"NOR);
      if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
      tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
      message_vision("\n",target);
      if(wizardp(me) && me->query("env/debug")) tell_object(me,"  造成"+damage+"點傷害!!\n"); 
      COMBAT_D->report_status(target);         //顯示target狀態
      }
      else
      {
           switch( random(5) ) {
           case 0:
               message_vision("\n結果力道太小並沒有造成$n的傷害。\n",me,target);
               break;
           case 1:
               message_vision("\n      但是被$n及時閃過了。\n",me,target);
               break;
           case 2:
               message_vision("\n      但是被$n機靈地躲開了。\n",me,target);
               break;
           case 3:
               message_vision("\n      但是被$n及時避開。\n",me,target);
               break;
           case 4:
               message_vision("\n      但是$n慌慌張張的逃開了。\n",me,target);
               break;
           default:
               message_vision("\n      但是$n慌慌張張的逃開了。\n",me,target);
               break;
           }
      }
   }
  message_vision("\n",me);
  me->improve_spell("god-benison",random(2+me->query("level")/3)+inn/10);
  if(!target->is_fighting(me)) target->kill_ob(me);
  if(!me->is_fighting(target)) me->kill_ob(target);

}

int attack_b(object me,object target,int sk,int inn)
{
 int damage,i;
 if(!me) return 0;
 if(!target) return notify_fail("目標消失了。\n");      
 if( environment(me) != environment(target) )           
          return notify_fail("目標離開了你的施法範圍。\n");
 if(!me->query_temp("power_cast") || me->query_temp("power_cast") < 1) 
 {
  message_vision(HIW"$N"HIW"因為受到創傷而亂了思緒, 無法順利施展法術。\n"NOR,me);
  return 1;
 }
 me->delete_temp("power_cast");
 
 if(target->query("mp")<10) i += 1;
 if(target->query("ap")<10) i += 2;
 
 if(random(target->query_skill("dodge")/2+target->query_shield()*3/2 ) < random(sk)+inn )
 {
     damage = ((sk+inn)*3)/5;
     if(userp(me)) damage = damage + (damage/4) - random(damage/5);
     damage = damage - (target->query_shield()/2);
     if(damage<6) damage=6+random(sk/3);
     damage = COMBAT_D->Merits_damage(me,target,damage,"wit");

   switch( i ) {
     case 1:  //這表示敵人mp沒有了，故吸他的ap
     message_vision(HIC"淡藍色薄霧"NOR"衝入$n體內，$n但覺內勁一洩千里，霎時薄霧從$n散出，被$N吸收了。\n"NOR,me,target);
            target->receive_damage("ap",damage,me);
            me->receive_heal("ap",damage/2);
     break;
     case 2:  //這表示敵人ap沒有了，故吸他的mp
     message_vision(HIC"淡藍色薄霧"NOR"衝入$n體內，$n頓時精神恍惚，霎時薄霧從$n散出，被$N吸收了。\n"NOR,me,target);
            target->receive_damage("mp",damage,me);
            me->receive_heal("mp",damage/2);
     break;
     case 3:  //這表示敵人ap和mp都沒有了，故吸他的hp
     message_vision(HIC"淡藍色薄霧"NOR"衝入$n體內，$n吐了一口鮮血，霎時薄霧從$n散出，被$N吸收了。\n"NOR,me,target);
            target->receive_damage("hp",damage,me);
            me->receive_heal("hp",damage/2);
     break;
     default: //這表示敵人hp,ap,mp都還很多，吸他的mp
     message_vision(HIC"淡藍色薄霧"NOR"衝入$n體內，$n頓時精神恍惚，霎時薄霧從$n散出，被$N吸收了。\n"NOR,me,target);
            target->receive_damage("mp",damage,me);
            me->receive_heal("mp",damage/2);
     break;
   }
      if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
      tell_object(me,HIY"("+damage+")"NOR);
      if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
      tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
      message_vision("\n",target);
      if(wizardp(me) && me->query("env/debug")) tell_object(me,"  造成"+damage+"點傷害!!\n"); 
      COMBAT_D->report_status(target);         //顯示target狀態
      target->start_busy(2);
 }
 else
 {
   message_vision(HIC"淡藍色薄霧"HIG"衝向$n，但是$n慌慌張張，左支右絀，逃出了藍光的圍繞。\n\n"NOR,me,target);
 }

  if(!target->is_fighting(me)) target->kill_ob(me);
  if(!me->is_fighting(target)) me->kill_ob(target);
  me->improve_spell("god-benison",random(2+me->query("level")/3)+inn/10);
}

int improve_limite(object ob)
{
        if(ob->query("adv_class")==1) return (ob->query_int()+30); 
        else return 90;
}
