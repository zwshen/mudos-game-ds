//
#include <ansi.h>
inherit SKILL;

int combine(object me, object target,object *members)
{
	string msg;
	object member,weapon;
	int i,damage,exp;
	
	if( !target ) return 0;

	if(!me->can_fight(target)) return me->can_fight(target);
	
	for(i=0;i<sizeof(members);i++)
	{
	 if(members[i]->query_skill_mapped("unarmed")!="bagi_fist") continue;
	 if(members[i]->is_busy()) continue;
	 weapon=members[i]->query_temp("weapon");
	 if(weapon)
	 {
	  if(weapon->query("skill_type")!="unarmed") continue;
	 }
   	 member=members[i];
	 break;
	}
	 
	if(!member)
	{
	//	message_vision("Combine_attack Error: Can't find member !\n",me);
		return 0;
	}
	
	if(member->query("mp")< 10 || me->query("mp") < 10 ) return 0;

//第一階段	
	message_vision("\n"HIY"$N"NOR"和"HIG"$n"NOR"交換了一下眼神, 突然合力施展雙人必殺技!!\n\n\t"HIC"『∼∼神極狂風斬∼∼』\n\n"NOR,me,member);
	message_vision(HIY"$N"NOR"縱身一躍, "HIG"$n"NOR"順勢使出"HIC"『揚炮』"NOR"由後方將"HIY"$N"NOR"推送至半空中,\n"NOR,me,member);
	member->improve_skill("bagi_fist",1+member->query_int()/2);
	me->improve_skill("godsword",1+me->query_int()/2);
	member->receive_damage("mp",3);
	me->receive_damage("mp",3);
	me->start_busy(1);
	
	if( random(COMBAT_D->attack_factor(member,"unarmed")+30)  > random(-COMBAT_D->dodge_factor(target,"dodge")))
	{
		message_vision("\n正當$n將注意力放在空中時, "HIG"$N"NOR"身隨意轉閃到$n身旁,\n  一式"HIW"『白虎雙掌打』"NOR"將"HIR"$n震飛三尺!!\n\n"NOR,member,target);
		damage=member->query_damage() + member->query_skill("bagi_fist")/3;
		damage-=target->query_armor();
		if(damage<10) damage=10;
		target->receive_damage("hp",damage,member);
		member->receive_damage("mp",2);
		target->start_busy(3);
		member->start_busy(1);
		tell_object(member,"  你得到額外的"+damage*3+"點經驗值!\n\n");
		member->add("exp",damage*3);
		member->improve_skill("bagi_fist",1+member->query_int()/3);
	}
//第二階段
	message_vision("此時"HIY"$N"NOR"俯衝而下, 極招"HIW"『翻雲覆雨』"NOR"鬼神般同時發動,\n"HIR"  無數劍影如浪花般往$n撲去, "NOR,me,target);
	if( random(COMBAT_D->attack_factor(me,"sword")+50)  > random(-COMBAT_D->dodge_factor(target,"dodge")))
	{
	 message_vision(HIW"$N閃避不及, "HIR"登時皮開肉綻, 血花四濺!!\n\n"NOR,target);
	 damage=me->query_damage() + me->query_skill("godsword")/3;
	 damage-=target->query_armor();
	 if(damage<10) damage=10;
	 target->receive_damage("hp",damage,me);
	 if(!target->is_busy()) target->start_busy(2);
	 me->receive_damage("mp",2);
	 me->start_busy(1);
	 tell_object(me,"  你得到額外的"+damage*3+"點經驗值!\n");
	 me->add("exp",damage*3);
	 me->improve_skill("godsword",1+me->query_int()/3);
	}
	 else
	{
		message_vision("$N連翻了五個觔斗狼狽的躲開這伶俐的殺著!!\n\n",target);
		me->start_busy(1);
	}
	
	if(!target->is_fighting(me)) target->kill_ob(me);
	if(!target->is_fighting(member)) target->kill_ob(member);
	return 1;
}
