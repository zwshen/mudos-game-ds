/*
◎ 落雷箭 (fall-thunder) - 寒澈派(frost) 技能
 
    落雷箭是寒澈派的基本雷法法術，以咒語擲出一道
帶強烈電勁的箭矢，造成敵人傷害。使用落雷箭攻擊敵
人，有可能發生「電殛」現像，造成更高的傷害。
 
落雷箭傷害：30% ~ 70% 攻擊力
技能每5級增加3%傷害，共60%，可達到 90% ~ 130% 攻擊力
 
電殛機率：技能等級40時為10%，每3級增加2%，最高機率到50%。
電殛傷害：落電箭傷害的 80%
 
◎ 三聲催魂箭
 
    技能等級60級時，可一次擲出三道落雷箭。
    每24秒可使用一次，每一點sou可減少2秒等待時間，最多降至12秒。
 
Last update: Tmr 2006/11/27

11.27 加上「生死符」
        
*/

#include <ansi.h>

#define SKILL_NAME "fall-thunder"
#define MIN_DAMAGE 30
#define MAX_DAMAGE 70

inherit SSERVER;
inherit SKILL;

int cast_delay(object target,object me);

void clear_flag(object me)
{
    if( !objectp(me) )
        return;
    me->delete_temp("FROST_FALL_THUNDER");
    tell_object(me, "你已經恢復了三聲催魂箭的法術。\n");
}

int cast(object me, object target, string act)
{
    int skill, cost;

    skill = me->query_spell(SKILL_NAME);
    cost = 20 + skill/4;

    if( me == target )
        return notify_fail("你無法對自已施法。\n");
    if ( !target )
        target = offensive_target(me);
    if ( !target )
        return notify_fail("你找不到可以施法的對像。\n");
    if( me->query("mp") < cost )
        return notify_fail("你的法力不足，無法施法。\n");
    if( !me->is_fighting(target) )
        return notify_fail("你並沒有和對方在戰鬥中。\n");
    if( !me->can_fight(target))
        return me->can_fight(target);
    if( me==target )
        return notify_fail("你想要對自已施法？\n");
    if ( !target )
        target = offensive_target(me);
    if ( !target )
        return notify_fail("你找不到可以施法的對像。\n");


    me->start_busy(2);
    if( skill >= 60
            && !me->query_temp("FROST_FALL_THUNDER")
            && me->query("mp") > cost*3 )
    {
        int delay;
        // 三聲催魂箭
        message_vision(HBK"$N施展"HIM"三聲催魂箭"HBK"法術，手中不斷放出滋滋電響，一聲比一聲更大聲。\n"NOR, me, target);
        me->receive_damage("mp", cost*3);
        me->set_temp("FROST_FALL_THUNDER", 1);
call_out( (:cast_delay, target, me:), 2);
        delay = 24 - me->query_sou()*2;
        if(delay <12) delay = 12;
call_out( (:clear_flag, me:), delay);
    }
    else
    {
        message_vision(HBK"$N施展落雷箭法術，手中不斷放出滋滋電響。\n"NOR, me, target);
        me->receive_damage("mp", cost);
call_out( (:cast_delay, target, me:), 2);
    }
    return 1;
}

int getDamageWeight(object me)
{
    int bonus;
    // 每5級加3%
    bonus = (me->query_spell(SKILL_NAME)/5) * 3;
    return (MIN_DAMAGE + bonus) + random(MAX_DAMAGE - MIN_DAMAGE);
}

int getShield(object target)
{
    return target->query_shield() - random(target->query_shield()/2);
}


int getDamage(object me, object target)
{
        int damage;
        object symbol;
        // 加上 int
        damage = me->query_damage() + me->query_int();
        if ( objectp(symbol=present("__LIFE_DEATH_SYMBOL_", me)) )
                damage += symbol->query("power")*3/2;
        damage = damage * getDamageWeight(me)/100;
        damage -= getShield(target);
        if ( damage < 1 )
        damage = 1;
        // 增加素質對傷害的影響
        return COMBAT_D->Merits_damage(me, target, damage,"wit");
}

void show_damage(object me, object target, int damage)
{
    if( me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
        tell_object(me,HIY"( 傷害: "+damage+")"NOR);
    if( target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
        tell_object(target,HIR"( 傷害: "+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
    if(wizardp(me) && me->query("env/debug"))
        tell_object(me,"(debug):  造成"+damage+"點傷害!!\n");
}

// 電殛機率：技能等級40時為10%，每3級增加2%，最高機率到50%。
void do_attack(object me, object target)
{
    int  sk_lv, chance, damage;
    sk_lv = me->query_spell(SKILL_NAME);
    chance = 10 + (sk_lv-40)/3*2;
    if( chance < random(100) )
        return; // nothing happen
    damage = getDamage(me, target) * 8/10; // 80%
    if(damage < 1) damage = 1;
    message_vision(RED"一陣"HIB"暴響"NOR RED"從$N體內傳出來，造成更嚴重的傷害！！"NOR,target);
    show_damage(me, target, damage);
    message_vision("\n", me, target);
}

int cast_delay(object target, object me)
{
    int probit, damage;
    int sk_lv, i, times, hit;
    object symbol;

    if( !me )
        return 0;
    if( !target )
        return notify_fail("目標消失了。\n");
    if( environment(me) != environment(target) )
        return notify_fail("目標離開了你的施法範圍。\n");

    sk_lv = me->query_spell(SKILL_NAME);
    probit = sk_lv + me->query_int();
    probit -= random(target->query_skill("dodge")+target->query_dex());
    if(me->query_temp("FROST_FALL_THUNDER") == 1 ) {
        times = 3; // 三聲催魂箭
        me->set_temp("FROST_FALL_THUNDER", 2);
    }
    else times = 1;
    hit =  probit > random(100) || target->is_busy() ;

   if( !hit ) {
                if( me->query_condition("frost_dust") 
                        && me->query_skill("pure-energy")/3 > random(100)  // 33%
                        && 50 > random(100)   // 50%
        ) {
                // dust_clean 二次再命中
                hit = 1;
                message_vision(HIB"$N塵垢淨盡，身上發出低沉而歷久不歇的隆隆聲！！"NOR,me);
        }
        } 


    if( hit )
    {
        for(i = 0;i<times;i++) {
            damage = getDamage(me, target);
            if( objectp(symbol=present("__LIFE_DEATH_SYMBOL_", me)) ) {
                // add harvest by tmr 2007/03/03
                if( me->query_condition("frost_harvest") && me->query_skill("pure-energy")/2 > random(100) ) {
                    message_vision(HIC"$N全身淡淡寒氣飄逸，一道若有似無的無形箭矢伴著片薄冰，帶著滋滋電響，轉瞬間就沒入$n"HIC"體內！！"NOR,me, target);
                } else {
                    symbol->add_amount(-1);    // 減少生死符
                    message_vision(HIC"一道若有似無的無形箭矢伴著片薄冰，帶著滋滋電響，轉瞬間就沒入$N"HIC"體內！！"NOR,target);
                }
            } else {
                message_vision(HIC"一道若有似無的無形箭矢帶著滋滋電響，轉瞬間就沒入$N"HIC"體內！！"NOR,target);
            }
            target->receive_damage("hp", damage, me );
            show_damage(me, target, damage);
            message_vision("\n", me, target);
            // 電殛
            if(sk_lv > 40)
                do_attack(me, target);

            COMBAT_D->report_status(target);         //顯示target狀態
        }

        me->improve_spell(SKILL_NAME, 1 + random(me->query_int()) );
    }
    else
    {
        message_vision(GRN"但是什麼事也沒有發生...\n"NOR,target);
        me->improve_spell(SKILL_NAME, 1 + random(me->query_int()/3) );
    }

    if( !target->is_fighting(me) )
        target->kill_ob(me);
    if( !me->is_fighting(target) )
        me->kill_ob(target);

    return 1;
}


