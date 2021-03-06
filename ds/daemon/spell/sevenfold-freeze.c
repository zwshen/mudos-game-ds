/*
◎ 七重玄冰 (sevenfold-freeze) - 寒澈派(frost) 進階技能

    封寒球是寒澈派的基本冰派法術，將敵人四週的
空氣急速降溫到達冰點的程度，造成敵人無法自由行
動及冰凍傷害。

基本傷害為 5% ~ 30% 攻擊力。
技能每10級增加3%傷害力，共30%，練滿為35% ~ 60%攻擊力。

冰凍回合：基本1回，每33級增加1回，全部共4回。

Last update: Tmr 2006/11/13
*/

#include <ansi.h>

#define SKILL_NAME "sevenfold-freeze"
#define MIN_DAMAGE 30
#define MAX_DAMAGE 60

inherit SSERVER;
inherit SKILL;

int cast_delay(object me);

int cast(object me, object target)
{
    int skill, cost;
    object *targets;
	targets = me->query_enemy();

    skill = me->query_spell(SKILL_NAME);
    cost = 20 + skill/4;

	if( !me->is_fighting() )
        return notify_fail("你並沒有在戰鬥中。\n");
    if ( sizeof(targets) < 0 )
        return notify_fail("你沒有可以攻擊的對像。\n");
    if ( me->query("mp") < cost )
        return notify_fail("你的法力不足，無法施法。\n");

    message_vision(HBK"$N念咒施展"HIC"『七重玄冰』"HBK"法術，$N身旁的氣壓氣溫都在瞬間降了下來！！\n"NOR, me);
    me->receive_damage("mp", cost);
    if(!userp(me))
	    me->start_busy(1);	// NPC
   	else
	    me->start_busy(2);	// player
	call_out( (:cast_delay, me:), 2);
    return 1;
}

int getDamageWeight(object me)
{
    int bonus;
    // 每10級加3%
    bonus = (me->query_spell(SKILL_NAME)/10) * 3;
    return (MIN_DAMAGE + bonus) + random(MAX_DAMAGE - MIN_DAMAGE);
}

int getShield(object target)
{
    return target->query_shield()/2 - random(target->query_shield()/2);
}

int getDamage(object me, object target)
{
    int damage;
    damage = me->query_damage() * getDamageWeight(me)/100 - getShield(target);
    if ( damage < 1 )
        damage = 1;
    // 增加素質對傷害的影響
    return COMBAT_D->Merits_damage(me,target,damage,"wit");
}

void show_damage(object me, object target, int damage)
{
    if ( me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
        tell_object(me,HIY"( 傷害: "+damage+")"NOR);
    if ( target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
        tell_object(target,HIR"( 傷害: "+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
    if (wizardp(me) && me->query("env/debug"))
        tell_object(me,"(debug):  造成"+damage+"點傷害!!\n");
}

int getBusyTime(object me)
{
    return 1 + (me->query_spell(SKILL_NAME)/33); // 每33級加1 busy
}

void doAttack(object me, object target) {
    int probit, damage;
    int hit;
    string msg;

    message_vision("一重巨大無形的"HIC"玄冰"NOR"漫天蓋\地往$n"NOR"撲去！！\n"NOR,me,target);

    probit += me->query_spell(SKILL_NAME) + me->query_int();
    probit -= random(target->query_skill("dodge")+target->query_int());

    hit = probit > random(100);
    msg = HIB"$N"HIB"被"HIC"七重玄冰"HIB"侵入體內，登時罩了層寒霜，動彈不得！！"NOR;
    if ( !hit ) {
        if ( me->query_condition("frost_dust")
                && me->query_skill("pure-energy")/3 > random(100)  // 33%
                && 50 > random(100)   // 50%
           ) {
            // dust_clean 二次再命中
            hit = 1;
            msg = HIB"$N"HIB"被塵垢淨盡的"HIC"七重玄冰"HIB"侵入體內，登時罩了層寒霜，動彈不得！！"NOR;
        }
    }

    if ( hit > 0 )  {
        damage = getDamage(me, target);
        if (damage<1) damage = 1;
        target->receive_damage("hp", damage, me );
        message_vision(msg,target);
        show_damage(me, target, damage);
        message_vision("\n", me, target);
        COMBAT_D->report_status(target);         //顯示target狀態

        me->improve_spell(SKILL_NAME, 1 + random(me->query_int()/4) );
        target->start_busy( getBusyTime(me) );
    }
    else {
        message_vision(GRN"但是$N"GRN"在千鈞一髮之際避開了攻擊。\n"NOR,target);
        me->improve_spell(SKILL_NAME, 1 + random(me->query_int()/12) );
    }

    if ( !target->is_fighting(me) )
        target->kill_ob(me);
    if ( !me->is_fighting(target) )
        me->kill_ob(target);
}

int cast_delay(object me)
{
    object *targets;

	int i, sz, ct;
    if ( !me )
        return 0;
	targets = me->query_enemy();
	sz = sizeof(targets);
	if(sz<0)
		return notify_fail("你沒有任何可以攻擊的對像。\n");
	// 最多四個敵人
    for(i=0, ct =0 ;i<sz && ct < 4; i++) {
	    if ( !targets[i] ) continue;
    	if ( environment(me) != environment(targets[i]) ) continue;
    	
    	doAttack(me, targets[i]);
    	ct++;
    }

    return 1;
}


