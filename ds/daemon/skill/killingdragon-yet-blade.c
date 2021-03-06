#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void delay(object me);
void superpower(object me,object target,int z,int damage);
mapping *action = ({
                       ([
                            "action": "$N喃喃自語的說 :『一刀』【斬破山河埂】，手中的$w隨著句子變化，攻向$n的胸部 ",
                            "damage":                20,
                            "dodge" :               -10,
                            "parry" :               10,
                            "attact_type":  "bar",
                            "damage_type":  "砍傷",
                        ]),
                       ([
                            "action": "$N喃喃自語的說 :『二劃』【紫氣東山崚】，手中的$w隨著句子變化，攻向$n的頭部",
                            "damage":                20,
                            "dodge" :               -10,
                            "parry" :               10,
                            "attact_type":  "bar",
                            "damage_type":  "劃傷",
                        ]),
                       ([
                            "action": "$N喃喃自語的說 :『三斷』【奇筋失數魂】，手中的$w隨著句子變化，攻向$n的肩部",
                            "damage":                20,
                            "dodge" :                -10,
                            "parry" :                10,
                            "attact_type":  "bar",
                            "damage_type":  "割傷",
                        ]),
                       ([
                            "action": "$N喃喃自語的說 :『四劈』【龍虎毋相爭】，手中的$w隨著句子變化，攻向$n的手部",
                            "damage":                20,
                            "dodge" :               -10,
                            "parry" :                10,
                            "attact_type":  "bar",
                            "damage_type":  "割傷",
                        ]),
                       ([
                            "action": "$N喃喃自語的說 :『五砍』【塵拂百地分】，手中的$w隨著句子變化，攻向$n的腳部",
                            "damage":                20,
                            "dodge" :                -10,
                            "parry" :                15,
                            "attact_type":  "bar",
                            "damage_type":  "劈傷",
                        ]),
                   });
int exert(object me, object target, string arg)
{
    int sk,damage;
    object weapon;
    mapping type;
    sk=me->query_skill("killingdragon-yet blade");
    weapon=me->query_temp("weapon");
    if( me->is_ghost() ) return notify_fail("你要幹嘛 ?\n");
    if (!weapon) return notify_fail("「破龍斬-未完」需要用刀...方能使出。\n");
    if(weapon->query("skill_type")!="blade") return notify_fail("你手上拿著東西怎麼使出「破龍斬-未完」。\n");
    if(arg=="off" )
    {
        if( me->query_skill_mapped("blade")!="killingdragon-yet blade")
            return notify_fail("你並沒有使用「破龍斬-未完」。\n");
        me->map_skill("blade");
        me->reset_action();
        write("「破龍斬-未完」已停止使用。\n");
        return 1;
    }

    if(me->query_skill("killingdragon-yet blade")<2) return notify_fail("加油 ! ! 再 train  一次「破龍斬-未完」。\n");
    if(me->query("ap")<1 || me->query("hp")<50) return notify_fail("你的身體無法繼續負擔「破龍斬-未完」了。\n");


    //第二次exert
    if(me->query_skill_mapped("blade")=="killingdragon-yet blade")
    {
        if( me->is_ghost() ) return notify_fail("你要幹嘛 ?\n");
        if( !target ) target = offensive_target(me);
        if (!me->is_fighting())
            return notify_fail("你正在使用「破龍斬-未完」了。\n");
        if (me->query_skill("killingdragon-yet blade") < 50)
            return notify_fail("你目前的「破龍斬-未完」，尚未到達「龍行天下」的境界。\n");
        if(me->query("ap")<30)
            return notify_fail("你的內勁不足，無法使出「龍行天下」。\n");
        if(!me->can_fight(target)) return me->can_fight(target);
        if(!me->is_fighting(target) ) return notify_fail("你並沒有在戰鬥。\n");
        message_vision(BLU"一陣寂靜 . . . . . . . 。\n\n"NOR,me);
        me->receive_damage("ap",10+random(40));
        me->start_busy(2);
        call_out("superpower",1,me,target,1,damage);
        return 1;
    }

if(!me->skill_active( "killingdragon-yet blade",(: call_other, __FILE__, "delay", me ,5:), 10)) return notify_fail("你的動作還沒完成。\n");
    me->map_skill("blade", "killingdragon-yet blade");
    me->reset_action();
    message_vision("\n"HIY"$N以光龍之氣，運行於"+weapon->query("name")+HIC"陣陣龍吟蕩漾迴響
                   運起了「破」
                   「龍」
                   「斬」
                   「未」
                   「完」。\n"NOR,me);
    me->receive_damage("ap",15);
    me->start_busy(2);
    //      me->start_call_out( (: call_other, __FILE__, "delay", me ,5:), 10);
    return 1;
}
void superpower(object me,object target,int z,int damage)
{
    string msg;
    if(!target) target = offensive_target(me);
    if(!target) return;
    if(!me) return ;
    if(!me->is_fighting()) return;
    if( environment(me) != environment(target) ) return;
    if(!me->is_fighting(target)) me->kill_ob(target);

    z=me->query_skill("killingdragon-yet-blade");
    msg +=HIW"忽然$N雙眼發光，直立定的握實手中之刀"NOR"，\n";
    msg +=HIR"一陣氣爆 ! ! ! ! ! 七條飛龍直噴而出，環繞著七種彩色 ! ! \n"NOR;
    msg +=HIY"一式「龍行天下」，帶領著$N飛向$n!!\n"NOR;
    message_vision(msg, me, target);

    if( z > random(target->query_skill("dodge")) )
    {
        damage = me->query_skill("killingdragon-yet blade")+random(me->query("str")) +random(target->query("str"))+random(target->query("con"))-target->query_armor() - random(target->query_armor()/3);
        message_vision(HIR "\n「嘩」"HIC"的一聲，只見$n體內一陣"HIY"金光"HIC"爆射 ! ! !。\n" NOR,me,target);

        damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
        target->receive_damage("hp",damage,me);
        if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
            tell_object(me,HIY"("+damage+")"NOR);
        if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
            tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
        message_vision("\n",target);
        COMBAT_D->report_status(target);
    }
    else {
        message_vision(HIG "\n$n兩眼呆滯 . . . 手忙腳亂的逃過一劫\n" NOR,me,target);
    }
    if(!me->is_fighting(target)) me->kill_ob(target);
}

void delay(object me)
{
    object weapon;
    if( !me ) return;

    weapon=me->query_temp( "weapon" );

    if( !weapon || weapon->query("skill_type") != "blade" )
    {
        me->map_skill("blade");
        me->reset_action();
        return;
    }

    if( me->query_skill_mapped("blade")!="killingdragon-yet blade" )
    {
        return;
    }

    if( me->query("ap")<1 )
    {
        me->map_skill("blade");
        me->reset_action();
        message_vision("\n"HIW"$N的內力不足 . . . 無法使用「破龍斬-未完」。\n"NOR,me);
        return ;
    }

    if( me->is_fighting() ) me->receive_damage("ap",5);
me->skill_active( "killingdragon-yet blade",(: call_other, __FILE__, "delay", me :), 8);
}

int valid_learn(object me) {    return 1;       }
mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int practice_skill(object me) { return 1; }



