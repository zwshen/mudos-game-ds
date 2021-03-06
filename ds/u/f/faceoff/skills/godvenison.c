// 更新日期: 1999.10.15
// 更新者: Luky
// QCer: Luky
#include <ansi.h>
inherit SSERVER;
inherit SKILL;

int cure_all(object me,object target,int sk,int inn);
int attack_a(object me,object target,int sk,int inn);
int attack_b(object me,object target,int sk,int inn);
int attack_c(object me,object target,int sk,int inn);

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

        if(sk < 20) tell_object(me,"你的「神祝禱篇」還未成火侯，尚無能力使用。\n");
        if(me->is_busy() ) return notify_fail("你現在正忙著，沒有空吧。\n");
	if(environment(me)->query("no_cast")) return notify_fail("這裡不能施法。\n");
        if(me->query("hp")<100 || me->query("mp")<100) return notify_fail("你目前的身體狀態無法使用「神祝禱篇」的。\n");
	
        if(me->is_fighting() )
        {

		if(!target ) target = offensive_target(me);
		if(!me->can_fight(target)) return me->can_fight(target);

        	switch( random(3) ) 
        	{
        	  case 0:
                     message_vision(HIG
                     "$N默唸「神祝禱篇」之「六合」訣：\n\n" NOR
        	     +HIM    "      「群兇彌六合，日月蔽風塵。」\n" NOR
        	     +HIM    "      「祥煙浮寶殿，明月照金床。」\n" NOR
        	     +HIY    "\n$N頭頂上方數尺忽凝聚數道無形金黃箭氣....\n" NOR
                		,me);
 		     cost=15;
 		     enemy = me->query_enemy();
                     me->start_busy(2);
                     for(i=0; i<= (sk/20) && i<sizeof(enemy); i++) call_out("attack_a",2,me,enemy[i],sk,inn);
                     break;
                  case 1:
                     message_vision(HIG
                     "$N默唸「神祝禱篇」之「神殺」訣：\n\n" NOR
                     +HIM    "      「血刃浮沉戍上遊，披頭五鬼在辰求。」\n" NOR
                     +HIM    "      「天哭逆數起於午，凡占切忌動當頭。」\n" NOR
                     +HIC    "\n只見$N頭上一道刺眼強光，赫然出現三位神將，威風凜凜，不可一世！！\n" NOR,me);
                     cost=(sk/2)+(inn/2)+random(inn/2);
                     me->start_busy(2);
                     call_out("attack_b",3,me,target,sk,inn);
                     break;
                  default:
                     message_vision(HIG
                     "$N默唸「神祝禱篇」中的「長生」訣：\n\n" NOR
                     +HIM"      「大哉乾元，萬物滋始。」\n" NOR
                     +HIM"      「至哉坤元，萬物滋生。」\n" NOR    
                     +HIC"\n$N雙手左右畫圈，泛出淡藍色之光，霎時藍光四散，團團圍繞著$n。\n"NOR,me,target);
                     cost=(sk/3)+(inn/2)+random(inn/3);
                     me->start_busy(2);
                     call_out("attack_c",2,me,target,sk,inn);
                     break;
                } //end of switch()
                me->receive_damage("mp",cost);
                me->set_temp("power_cast",1+sk/20);
         } //end of is_fighting()
        else
        {
        	if(!target ) target = me;
                message_vision(HIG
                "$N默唸「神祝禱篇」之「沫浴」訣：\n\n" NOR
                +HIM"      「天門日射彩雲開，大降洪恩布九垓。」\n" NOR
                +HIM"      「萬物一時沾聖化，蒼生鼓舞醉金罍。」\n" NOR
                ,me);

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
 int damage;
 if(!me) return 0;
 if(me->query("mp")<15) return notify_fail("你的魔力不夠。\n");
 if(!target) return notify_fail("目標消失了。\n");	
 if( environment(me) != environment(target) )		
	  return notify_fail("目標離開了你的施法範圍。\n");
 if(!me->query_temp("power_cast") || me->query_temp("power_cast") < 1) 
 {
  message_vision(HIW"$N"HIW"因為受到創傷而亂了思緒, 無法順利施展法術。\n"NOR,me);
  return 1;
 }
 me->delete_temp("power_cast");
 	  
       message_vision(HIY"$N默唸一聲：「去」，一道金黃箭氣迅捷無迅無比地往$n射去！！\n" NOR,me,target);
       if(random(target->query_skill("dodge")/2+target->query_shield() ) < random(sk+inn) )
       {
         message_vision(HIR"\n$N閃躲不及中了道金黃箭氣，只聽$N慘呼一聲，看來受傷不輕。\n\n"NOR,target);
	damage = (sk*2/3)+random(inn*2)+10+me->query("level");
	damage = damage - target->query_shield();
	if(damage<10) damage=10+random(inn/3);
	damage = COMBAT_D->Merits_damage(me,target,damage,"wit");
         target->receive_damage("hp",damage,me);
         COMBAT_D->report_status(target);
       }
        else
       message_vision(HIG"\n只聽$N驚呼一聲，使盡吃奶的力氣，好不容易躲開了金黃箭氣的追擊。\n\n"NOR,target);
     
     me->improve_spell("god-benison",random(2+me->query("level")/3)+inn/10);
     if(!target->is_fighting(me)) target->kill_ob(me);
     if(!me->is_fighting(target)) me->kill_ob(target);
     return 1;
}

int attack_b(object me,object target,int sk,int inn)
{
 int damage;
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
 
  message_vision(HIY "\n$N雙手結卬，低念數聲，驅使「血刃」，「披頭」，「天哭」引嘯同擊$n！！\n\n"NOR,me,target);

  if(random(target->query_skill("dodge")/2+target->query_shield() )< random(sk+inn) )
  {
   message_vision( MAG"血刃殺手中剝血刃直砍橫劈十三刀，砍向$N頭、手、胸三盤要害！！\n" NOR
                  +MAG"披頭殺揮舞手上二把奪魂匕，七七四十九式連往$N胸、腰各要害招呼！！\n" NOR
                  +MAG"天哭殺氣運手上穿骨槍，一式「石破天驚」，十成力道刺向$N胸口要穴！！\n" NOR
                  +HIR"\n$N慘呼一聲，登時血花四濺、狂吐數口鮮血，看來受傷不輕。\n\n" NOR
                  ,target);
   damage = (sk/3)+inn+random(inn+sk);
   if(userp(target)) damage = damage - (damage/5);
   damage = damage - (target->query_shield()/2);
   if(damage<20) damage=20+random(inn/2);
   damage = COMBAT_D->Merits_damage(me,target,damage,"wit"); 
   target->receive_damage("hp",damage,me);
   COMBAT_D->report_status(target);
  }
  else
  {
   message_vision(HIG"\n$n使出渾身解數，狼狽的逃開了這一擊。\n\n"NOR,me,target);
  }
  me->improve_spell("god-benison",random(2+me->query("level")/3)+inn/10);
  if(!target->is_fighting(me)) target->kill_ob(me);
  if(!me->is_fighting(target)) me->kill_ob(target);
}

int attack_c(object me,object target,int sk,int inn)
{
 int damage;
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
  if(random(target->query("inn")/2+target->query_shield() )< random(sk+inn) )
  {
   message_vision( HIC"淡藍色之光衝向$n體內，只見$n癱軟在地上，慢慢地從$n身體裡散出\n" NOR
                  +HIR"血紅色的薄霧，$N伸出雙手，閉目吐吶，血色對霧緩緩的被$N吸收了。\n\n" NOR,me,target);
   damage = ((sk+inn)*3)/5;
    if(userp(me)) damage = damage + (damage/4) - random(damage/5);
   damage = damage - (target->query_shield()/2);
   if(damage<6) damage=6+random(sk/3);
   damage = COMBAT_D->Merits_damage(me,target,damage,"wit");
   target->receive_damage("mp",damage,me);
   target->receive_damage("hp",damage/3,me);
   me->receive_heal("mp",damage);
   me->receive_heal("hp",damage/3);
  }
   else
  {
   message_vision(HIG"\n$n慌慌張張，左支右絀，逃出了藍光的圍繞。\n\n"NOR,me,target);
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
