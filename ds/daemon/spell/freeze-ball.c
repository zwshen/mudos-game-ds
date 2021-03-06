/*
◎ 封寒球(freeze-ball) - 寒澈派(frost) 技能

    封寒球是寒澈派的基本冰派法術，將敵人四週的
空氣急速降溫到達冰點的程度，造成敵人無法自由行
動及冰凍傷害。

基本傷害為 5% ~ 30% 攻擊力。
技能每10級增加3%傷害力，共30%，練滿為35% ~ 60%攻擊力。

冰凍回合：基本1回，每33級增加1回，全部共4回。

Last update: Tmr 2006/11/13
*/

#include <ansi.h>

#define SKILL_NAME "freeze-ball"
#define MIN_DAMAGE 5
#define MAX_DAMAGE 30

inherit SSERVER;
inherit SKILL;

int cast_delay(object target,object me);

int cast(object me, object target)
{
    int skill, cost;

    skill = me->query_spell(SKILL_NAME);
    cost = 10 + skill/5;

    if ( !target )
        target = offensive_target(me);
    if ( !target )
        return notify_fail("你找不到可以施法的對像。\n");
    if ( me == target )
        return notify_fail("你無法對自已施法。\n");
    if ( me->query("mp") < cost )
        return notify_fail("你的法力不足，無法施法。\n");
    if ( !me->is_fighting(target) )
        return notify_fail("你並沒有和對方在戰鬥中。\n");
    if ( !me->can_fight(target))
        return me->can_fight(target);


    message_vision(HBK"$N施展出封寒球法術，兩手掌心中的空氣逐漸凝聚在一起。\n"NOR, me, target);
    me->receive_damage("mp", cost);
    me->start_busy(1);
call_out( (:cast_delay, target, me:), 1);
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
int cast_delay(object target, object me)
{
    int probit, damage;
    int hit;
    string msg;

    if ( !me )
        return 0;
    if ( !target )
        return notify_fail("目標消失了。\n");
    if ( environment(me) != environment(target) )
        return notify_fail("目標離開了你的施法範圍。\n");

    message_vision("$N手中的"HIW"『"HIC"封寒球"HIW"』"NOR"蓄勢已足，隨即朝$n"NOR"的方向推去！！\n"NOR,me,target);

    probit += me->query_spell(SKILL_NAME) + me->query_int();
    probit -= random(target->query_skill("dodge")+target->query_int());

    hit = probit > random(100);
    msg = HIB"$N"HIB"被封寒球擊個正著，猶如置身冰窖！！"NOR;
    if ( !hit ) {
        if ( me->query_condition("frost_dust")
                && me->query_skill("pure-energy")/3 > random(100)  // 33%
                && 50 > random(100)   // 50%
           ) {
            // dust_clean 二次再命中
            hit = 1;
            msg = HIB"$N"HIB"被塵垢淨盡的封寒球擊個正著，猶如置身冰窖！！"NOR;
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

        me->improve_spell(SKILL_NAME, 1 + random(me->query_int()) );
        target->start_busy( getBusyTime(me) );
    }
    else {
        message_vision(GRN"但是$N"GRN"躲開了這次攻擊。\n"NOR,target);
        me->improve_spell(SKILL_NAME, 1 + random(me->query_int()/3) );
    }

    if ( !target->is_fighting(me) )
        target->kill_ob(me);
    if ( !me->is_fighting(target) )
        me->kill_ob(target);

    return 1;
}


