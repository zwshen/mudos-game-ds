// 針法 - 天梟針法 (skyowl-needle)
// QC by tmr 2007/01/05
// 不需要特攻

#include <ansi.h>
inherit SKILL;
inherit SSERVER;

// 以穴道認知來增加攻擊力
int BonusDamage = this_player()->query_skill("acupuncture-cognition")/6;

void show_damage(object me, object target,int damage)
{
    if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
        tell_object(me,HIY"("+damage+")"NOR);
    if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
        tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
    if(wizardp(me) && me->query("env/debug"))
        tell_object(me, HIR"  ("+damage+")\n"NOR);
}

string *parry_msg = ({
                         "只聽見「鏘」一聲﹐被$p格開了。\n",
                         "結果「噹」地一聲被$p擋開了。\n",
                         "但是被$n用手中兵刃架開。\n",
                         "但是$n身子一側﹐用手中兵刃格開。\n",
                     });

mapping *action = ({
                       ([
                            "action": "$N方位急轉，「"HIW+BLK"落地之鳩"NOR"」已然出招，$w急轉而起，朝向$n急刺而去。",
                            "damage":               2+BonusDamage,
                            "dodge" :               10,
                            "attact_type":  "tec", 
                            "damage_type":  "刺傷",
                        ]),

                       ([
                            "action": "$N使出「"HIY"黃雀在後"NOR"」，忽然撲到$n身後，手中緊握$w，猛向$n刺去，",
                            "damage":                4+BonusDamage,
                            "dodge":                -15,
                            "parry" :               -10,
                            "attact_type":  "tec",
                            "damage_type":  "刺傷",
                        ]),
                       ([
                            "action": "$N使出一招「"HIW+BLK"鳶飛戾天"NOR"」，縱起半尺高，忽然朝$n飛身而下，",
                            "damage":                6+BonusDamage,
                            "dodge" :               -10,
                            "parry" :                10,
                            "attact_type":  "tec",
                            "damage_type":  "剉傷",
                        ]),

                       ([
                            "action": "$N左手一昂，一式「月落烏啼」，手中$w朝$n旋轉而去，",
                            "damage":                8+BonusDamage,
                            "dodge" :               -10,
                            "parry" :                15,
                            "attact_type":  "tec",
                            "damage_type":  "剉傷",
                        ]),

                       ([
                            "action": "$N向後一躍，「"HIY"黃鶯出谷"NOR"」右手$w交給左手，忽然出招直朝$n左手缺盆穴而去，",
                            "damage":                10+BonusDamage,
                            "dodge" :                20,
                            "parry" :               -20,
                            "attact_type":  "tec",
                            "damage_type":  "刺傷",
                        ]),

                       ([
                            "action": "$N使出「一石二鳥」，左肱微屈，左手出掌而右手出匕，趁$n錯愕之時，$w已朝$n直劈而去，",
                            "damage":                12+BonusDamage,
                            "dodge" :                10,
                            "parry" :               -20,
                            "attact_type":  "tec",
                            "damage_type":  "劈傷",
                        ]),

                       ([
                            "action": "$N急使「"HIW+BLK"落地之鳩"NOR"」轉至$n後方，忽然又一式「"HIC"翱翔天際"NOR"」，$w由下而上刺向$n，",
                            "damage":                14+BonusDamage,
                            "dodge" :                10,
                            "parry" :                10,
                            "attact_type":  "tec",
                            "damage_type":  "刺傷",
                        ]),

                       ([
                            "action": "$N雙手高舉, 一招「"HIC"大鵬展翅"NOR"」手中$w朝向$n狠狠擲了過去，",
                            "damage":                16+BonusDamage,
                            "dodge" :                20,
                            "parry" :               -10,
                            "attact_type":  "tec",
                            "damage_type":  "剉傷",
                        ]),

                       ([
                            "action": "$N使出「"HIR"鷹爪無情"NOR"」，忽然撲到$n身前，左手呈鷹爪之勢引開敵人注意，忽然大喝一聲，$w狠刺而去，",
                            "damage":                18+BonusDamage,
                            "dodge" :               -10,
                            "parry" :               -10,
                            "attact_type":  "tec",
                            "damage_type":  "刺傷",
                        ]),

                   });

int exert(object me, object target, string arg)
{
    object weapon;
    weapon=me->query_temp("weapon");
    if(!weapon)
        return notify_fail("使用天梟針法必須手中要有針。\n");
    if(weapon->query("skill_type")!="needle")
        return notify_fail("使用天梟針法必須手中要有針。\n");

    if(arg=="off" )
    {
        if( me->query_skill_mapped("needle")!="skyowl-needle")
            return notify_fail("你並沒有使用天梟針法。\n");
        me->map_skill("needle");
        me->map_skill("parry");
        me->reset_action();
        write("技能[天梟針法]已取消。\n");
        return 1;
    }
    if(me->query_skill("needle")<20)
        return notify_fail("你的基礎針法基礎不夠無法使用天梟針法。\n");
    if(me->query("ap")<20 || me->query("hp")<20)
        return notify_fail("你的身體狀況無法使用天梟針法。\n");

    if(me->query_skill_mapped("needle")=="skyowl-needle")
        return notify_fail("你正在使用天梟針法。\n");
	if(!me->skill_active( "skyowl-needle",(: call_other, __FILE__, "delay", me, 6 :), 10))
        return notify_fail("你收招的動作還沒完成。\n");

    me->map_skill("needle", "skyowl-needle");
    me->map_skill("parry", "skyowl-needle");

//    if( me->query("class2") == "skyowl_military" )
    me->reset_action();
    message_vision("\n"HIW"$N手握"+weapon->name()+HIW"於胸前，腳呈「天鷹立枝」, 開始施展『天梟針法』。\n"NOR,me);
    me->receive_damage("ap",5);
    me->start_busy(1);
    return 1;
}

void delay(object me,int cost)
{
    object weapon;
    if(!me)
        return;
    weapon=me->query_temp("weapon");
    if(!weapon)
    {
        me->map_skill("needle");
        me->map_skill("parry");
        me->reset_action();
        return;
    }
    if(weapon->query("skill_type")!="needle")
    {
        me->map_skill("needle");
        me->map_skill("parry");
        me->reset_action();
        return;
    }
    if(me->query_skill_mapped("needle")!="skyowl-needle")
        return;
    if(me->query_skill_mapped("parry")!="skyowl-needle")
        return;

    if(me->query("ap")<7)
    {
        me->map_skill("needle");
        me->map_skill("parry");
        me->reset_action();
        message_vision(HIW"$N的體力不夠無法繼續使用天梟針法，只好改用一般招式。\n"NOR,me);
        return ;
    }
me->skill_active( "skyowl-needle",(: call_other, __FILE__, "delay", me, 6 :), 10);
}

mapping query_action(object me, object target, object weapon)
{
    return action[random(sizeof(action))];
}

string query_parry_msg(object me, object target, object weapon)
{
    return parry_msg[random(sizeof(parry_msg))];
}


int valid_learn(object me)
{
    return 1;
}
int practice_skill(object me)
{
    return 1;
}
