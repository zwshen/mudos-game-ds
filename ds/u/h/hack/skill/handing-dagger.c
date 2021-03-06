// Programed by Suez
/*
    這個技能的特點是機敏愈高，發出強力攻擊的機會愈大，如果機敏100加上此技能等級100
    則可以有153左右的攻擊力，但是受到random的影響，也有可能只有5而已。招式的攻擊力
     加上技能的影響，最多不超過10，算是十分沒威力的招式。由於是自然對數取值，所以機敏
     50之前，都不會有多大威力，頂多20左右，但50之後，威力增加的極快。我希望能保留此特
     點，如此來強調此技能機敏的重要性，區別以力量造成傷害的武者招式，使運氣及速度成為
     盜賊門派與眾不同之處。此技能我是以更改「大槍訣」而來，在此特別感謝。

 */

#include <ansi.h>
inherit SKILL;
inherit SSERVER;

void delay(object me,int cost);
void delay2(object me,object victim);
int h = random(exp(this_player()->query_dex()/20)-this_player()->query_skill("handing-dagger")/20)+this_player()->query_skill("handing-dagger")/20;//攻擊力的計算式

mapping *action = ({
	([
	"action": "$N突然將手上的$w旋轉起來，輕叱一聲，使出「快字訣」﹗只見無數刀影襲向$n",
	"damage":		1+h,
	"dodge" :		40,
	"parry" :		-10,
	"attact_type":  "bar",  
	"damage_type":  "刺傷",
	]),

	([
	"action": "$N突然向後飄開，說了一聲﹔「疾。」也不見$N如何移動，一道寒光已劃上了$n的頸項",
	"damage":		4+h,
	"dodge" :		30,
	"parry" :		-20,
	"attact_type":  "bar",  
	"damage_type":  "割傷",
	]),

	([
	"action": "$N眼神一閃，趁$n手中招式將盡未盡之時，一式「破字訣」直攻$n招式上的破綻",
	"damage":		1+h,
	"dodge" :		20,
	"parry" :		20,
	"attact_type":  "bar",  
	"damage_type":  "刺傷",
	]),

	([
	"action": "$N將$w舉與眼平，刃尖前指，口中喝了一聲「殺」，整個人猶如電閃雷擊一般向$n衝了過來",
	"damage":		5+h,
	"dodge" :		-30,
	"parry" :		-30,
	"attact_type":  "bar",  
	"damage_type":  "殺傷",
	]),

	([
	"action": "只見$N左一踏，右一轉，使出「迴字訣」﹗不等$n看清其身型，一把$w已向$n遞了過去…",
	"damage":		2+h,
	"dodge" :		30,
	"parry" :		30,
	"attact_type":  "bar",  
	"damage_type":  "削傷",
	]),

	([
	"action": "$N頭一低，腳一踩，順勢鑽入$n的懷中，一招「入字訣」瞬間勾掠削砍攻了數招…",
	"damage":		3+h,
	"dodge" :		-20,
	"parry" :		40,
	"attact_type":  "bar",  
	"damage_type":  "擊傷",
	]),
});

int exert(object me, object target, string arg)
{
	int damage;
	object weapon, tar;
		
	weapon=me->query_temp("weapon");
	if(!weapon) return notify_fail("「入手匕」除了手以外還需要一把匕首才能施展。\n");
	if( weapon->query("skill_type")!="dagger") return notify_fail("你確定要拿這東西施展「入手匕」嗎﹖\n");

	if( arg=="off" )
	{
		if( me->query_skill_mapped("dagger")!="handing-dagger")
			return notify_fail("嗯﹗沒錯，你現在的確沒有使用「入手匕」。\n");
		me->map_skill("dagger");
		me->reset_action();
		message_vision("$N將手上的匕首轉了兩轉，暫時不打算使用「入手匕」了。\n",me);
		return 1;
	}

	if( me->query_skill("dagger")<1 )
		return notify_fail("你連匕首怎麼用都不會ㄝ…\n");
	if( me->query("ap") < 10 || me->query("mp") < 20 )
		return notify_fail("你的注意力不夠，無法發揮「入手匕」的招式。\n");


	// The Second Exert
	if(me->query_skill_mapped("dagger")=="handing-dagger")
	{
		if( !me->is_fighting() )
			return notify_fail("你不在戰鬥中，要打誰呢？\n");
//			return notify_fail("你仔細的檢查了手上的匕首，活動活動手腕，嗯﹗現在使用「入手匕」絕對沒問題﹗\n");	       
		if( me->query_skill("handing-dagger") < 70 )
			return notify_fail("你現在想使用「狂字訣」嗎﹖太危險了﹗你根本還不熟招式，無法將它們連貫起來。\n");
		if( me->query("ap")<50 )
			return notify_fail("你很想使出「狂字訣」，但是內勁就是不聽話。\n");
		if( me->query("hp") <150 )
			return notify_fail("你已經累的忘記「狂字訣」要怎麼開始了…\n");

		message_vision("\n"HIW"$N手中握緊匕首，內勁一提，手中的匕首發出微弱的光線。\n"NOR,me);

		if( !tar ) tar = offensive_target(me);
		if( !tar ) return notify_fail("找不到目標！\n");

		me->start_busy(1);
		me->receive_damage("ap", 30);
		call_out("delay2",3,me,tar);
		return 1;
	}
	
	me->map_skill("dagger", "handing-dagger");
	me->reset_action();
	message_vision("\n"HIR"$N將手中的"+weapon->query("name")+HIR"反手握住，彎臂凝氣、刃藏於袖，正是「入手匕」的起手式﹗\n"NOR,me);
	me->receive_damage("mp",20);
	me->start_busy(1);
	me->start_call_out( (: call_other, __FILE__, "delay", me , 4:), 3);
	return 1;
}

void delay2(object me,object victim)
{
	int damage,dex;
	object target,weapon;

	damage = random(me->query_skill("handing-dagger"))/2+1 ;
	weapon=me->query_temp("weapon");
	dex=victim->query("dex");

	if( !weapon ) return;
	message_vision(HIR"$N向後一踏，手上的匕首輕輕一揮，「快疾破殺迴入」五訣合一的「狂訣」在毫無前兆的情況下斗然發出﹗",me);
	if( victim->query("dodge") > random(me->query_dex()) )
	{
		message_vision("$N向旁邊一跳，避開了這瘋狂的攻擊。\n", victim);
		return;
	}
	victim->receive_damage("hp",damage, me );
	victim->receive_wound("body", (random(damage/dex)) ); // 給予身體傷害
	message_vision(HIR"$N的鮮血隨著匕首的攻勢四散而出﹗竟在地上描繪出一朵血牡丹﹗",victim);
	victim->start_busy(3);
	me->start_busy(2);
	me->improve_skill("handing-dagger",1+random(me->query_int()/3+me->query_dex()/4));
	me->improve_skill("dagger",1+random(me->query_int()/3+me->query_dex()/4));
	return ;
}

void delay(object me,int cost)
{
	object weapon,target;

	if(!me) return;
	weapon=me->query_temp("weapon");
	if (!weapon || weapon->query("skill_type")!= "dagger" )
	{
		me->map_skill("dagger");
		me->reset_action();
		return;
	}
	
	if(me->query_skill_mapped("dagger")!="handing-dagger")  return;
	
	if(me->query("ap")<10)
	{
		me->map_skill("dagger");
		me->reset_action();
		tell_object(me,"\n你漸漸喪失了注意力，無法再繼續使用「入手匕」了。\n");
		return ;
	}
	me->receive_damage("ap", cost);
	me->receive_damage("mp", cost-2);
	me->start_call_out( (: call_other, __FILE__, "delay", me , 4:), 3);
//	me->skill_active("handing-dagger",(: call_other, __FILE__, "delay", me ,cost:), 4);
	return;
}

int valid_learn(object me) {    return 1; }

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me) { return 1; }

int improve_limite(object ob)
{
	int a = ob->query_int() + 70;
	return a;
}