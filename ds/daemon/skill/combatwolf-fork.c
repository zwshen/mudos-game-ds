//戰狼槍法(combatwolf-fork.c)
//特攻兩式：北斗天狼破(skywolf)，高攻擊力
//          冰狼心封訣(icewolf)，牽制用
//普通攻擊：挑，刺，點，旋，纏
//          數值合計：20
//目前打算只讓mob使用
//                         2001.11.19 sdo
#include <ansi2.h>
inherit SKILL;
inherit SSERVER;

mapping *action = ({
                       ([
                            "action": "$N將手中$w的槍尖虛點地上，忽然快速的使了一式"HIC"挑"NOR"，槍尖由地上彈起，擊向$n",
                            "damage": 5,  //這個是傷害強化的百分比 , 不是傷害點數
                            "attack": 15,
                            "attact_type":  "bar",  // 設定技能的攻擊種類 生物(bio) 獸性(bar) 魔法(wit)心靈(sou)科技(tec)
                            "damage_type":  "刺傷",
                        ]),
                       ([
                            "action": "$N舉起手中的$w，運起"HIC"刺"NOR"字訣，狠狠的向$n的咽喉連攻三次",
                            "damage": 35,
                            "attack": -5,
                            "parry": -10,
                            "dodge": -10,
                            "attack_type":  "bar",
                            "damage_type":  "刺傷",
                        ]),
                       ([
                            "action": "$N將手中的$w在身前虛挽了朵槍花，憶起"HIC"點"NOR"，急攻$n周身各大要害",
                            "damage": 10,
                            "attack": 10,
                            "dodge": 10,
                            "parry": -10,
                            "attack_type":  "bar",
                            "damage_type":  "戳傷",
                        ]),
                       ([
                            "action": "$N大喝了一聲『"HIC"旋"NOR"』，飛快的舞動手上的$w，以千軍萬馬之勢向$n橫掃而去",
                            "damage": 5,
                            "attack": 20,
                            "parry": -5,
                            "attack_type":  "bar",
                            "damage_type":  "擊傷",
                        ]),
                       ([
                            "action": "$N默運"HIC"纏"NOR"，反手握住$w中央處，近身與$n相搏",
                            "damage": 5,
                            "attack": 5,
                            "parry":10,
                            "dodge":10,
                            "attack_type":  "bar",
                            "damage_type":  "瘀傷",
                        ])
                   });

int exert(object me, object target, string arg)
{
    int sk = me->query_skill("combatwolf-fork"),
             f_sk = me->query_skill("fork"),
                    force = me->query_skill("force");
    int target_armor,target_dodge,me_dex,me_damage,sum_damage;

    object weapon,wp;
    weapon = me->query_temp("weapon");

    if( arg=="off" )
    {
        if( me->query_skill_mapped("fork")!="combatwolf-fork" )
            return notify_fail("你並沒有使用戰狼槍法。\n");
        me->map_skill("fork");
        me->reset_action();
        write("你停止使用戰狼槍法了。\n");
        return 1;
    }

    if( me->query("ap") < 20 )
        return notify_fail("你目前的身體情形並不允許\使用戰狼槍法。\n");

    if( !weapon ) return notify_fail("你要找支槍才能用喔。\n");

    if( f_sk < 25 ) return notify_fail("你的槍類武器知識還不夠喔。\n");

    if( weapon->query("skill_type")!="fork" )
        return notify_fail("你想用這種武器使用槍法？\n");

    if( arg == "?" || arg == "help" )
    {
        tell_object(me,"目前有北斗天狼破(skywolf)、冰狼心封訣(icewolf)可以使用。\n"NOR);
        return 1;
    }


    if( me->query_skill_mapped("fork") == "combatwolf-fork" )
    {
        if( !target ) target = offensive_target(me);
        if( !target ) return notify_fail("你並沒有目標可以攻擊！\n");
        if( !me->can_fight(target) ) return me->can_fight(target);

        target_armor = target->query_armor();
        target_dodge = target->query_skill("dodge");
        me_dex = me->query_dex() + random(me->query_dex()/2);
        me_damage = me->query_damage() + force/3 + sk/3;
        me_damage = me_damage + random(me_damage/4);
        sum_damage = me_damage - target_armor/3 - random(target_armor*2/3);

        // qc section
        if(wizardp(me)) tell_object(me,sprintf("  me_damage=%-d  sum_damage=%-d\n",me_damage,sum_damage));
        // end of qc section

        if( !arg || arg == "?" )
        {
            tell_object(me,"目前有北斗天狼破(skywolf)、冰狼心封訣(icewolf)可以使用。\n"NOR);
            return 1;
        }
        if( arg == "skywolf" )
        {
            if( !me->is_fighting(target) ) me->kill_ob(target);
            if( !target->is_fighting(me) ) target->kill_ob(me);
            if( me->is_busy() ) return notify_fail("你正在忙！\n");
            if( me->query_skill("combatwolf-fork") < 85 )
                return notify_fail("你的戰狼槍法還沒未夠班呢！\n");
            message_vision(
                "\n$N眼睛通紅，一股殺氣由周身散發開來，接著大喝一聲，緊握手中的"+weapon->name()+"，向$n使出"HIY"『北斗天狼破！』\n\n", me, target);
            if( random(me_dex) > random(target_dodge)&& sum_damage = COMBAT_D->Merits_damage(me, target, sum_damage + random(sum_damage/3), "bar") )
            {
                target->receive_damage("ap", sum_damage/10, me);
                target->receive_damage("hp", sum_damage, me);
                message_vision(
                    HIR"$n"HIR"慘叫一聲，被$N"HIR"的"HIY"北斗天狼破"HIR"打中胸口，身體向後平飛而出！"NOR, me, target);
                // QC
                if(wizardp(me)) tell_object(me,sprintf("  (damage=%-d) \n",sum_damage));
                // End QC
                me->improve_skill("combatwolf-fork", random(me->query_int()/5) + 5);
                me->improve_skill("fork", random(me->query_int()/6) + 5 );
                me->add_busy(1+random(2));
                if( objectp(wp = me->query_temp("weapon")) ) wp->attack(); // wp 損壞率 add by wilfred
            }
            else
            {
                message_vision(
                    HIC"$n"HIC"急忙向後使出了一招『鐵板橋』，在千鈞一髮之際閃過了這致命的一招。"NOR, me, target);
                target->imporve_skill("dodge", 2);
                sum_damage = 0;
                me->add_busy(2+random(2));
            }
            if( me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                message_vision(HIY" ("+ HIR + sum_damage + HIY")"NOR" \n\n"NOR, me);
            else message_vision("\n\n", me);
            COMBAT_D->report_status(target);
            me->receive_damage("ap", 20 + sum_damage/30 );
            return 1;
        }

        if( arg == "icewolf" )
        {
            if( !me->is_fighting(target) ) me->kill_ob(target);
            if( !target->is_fighting(me) ) target->kill_ob(me);
            message_vision(
                "$N將手中長槍的槍尖遙指$n，正在沉寂之際，$N忽然運起"HIC"冰狼封心訣"NOR"，槍尖向$n射出一道寒氣"NOR, me, target);
            if( random(target->query_dex()) < random(me->query_dex()*3/2) )
            {
                message_vision(HIW"讓$N如陷玄冰之中，動彈不得！\n"NOR, target);
                if( objectp(wp = me->query_temp("weapon")) ) wp->attack(); // wp 損壞率 add by wilfred
                target->start_busy(2+random(3));
                if( me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                    message_vision(HIY" ("+ HIR + me->query_damage()/3 + HIY")"NOR" \n"NOR, me);
                else message_vision("\n", me);
                COMBAT_D->report_status(target);
            }
            else
            {
                message_vision("$N急忙閃身，躲過了那道無形寒氣。\n"NOR,target);
                me->add_busy(random(2));
            }
            me->receive_damage("ap", 20 - sk/20);
            return 1;
        }
    }

    message_vision(HIY"$N橫槍一立，氣運周身，一個狼形隱約出現在身後。\n"NOR,me);
    me->map_skill("fork", "combatwolf-fork");
    me->receive_damage("ap",30);
    me->reset_action();
    me->start_busy(1);
    return 1;
}
int valid_learn(object me)
{
    return 1;
}
mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int practice_skill(object me)
{
    return 1;
}

int improve_limite(object ob)
{
    return 80;
}
