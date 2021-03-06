// 全真劍法 quanzhen-sword.c
// Tmr 2006/10/28

#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void delay(object me,int cost);
void firesword(object me,object target,int damage);
mapping *action = ({
                       ([
                        "action":"$N意帶神閑，一式"GRN"「分花拂柳」"NOR"，$w輕輕飛動，幻起一片劍光，圍掠$n全身",
                            "damage":                15,
                            "dodge" :                10,
                            "parry" :                -8,
                            "attact_type":  "bar",  
                            "damage_type":  "刺傷",
                        ]),

                       ([
                        "action":"$N使一招"HIY"「琴心三疊」"NOR"，身形向上飄起，手中$w虛虛實實幻出三點寒光射向$n$l",
                            "damage":                10,
                            "dodge":                 -5,
                            "parry" :                14,
                            "attact_type":  "bar",
                            "damage_type":  "刺傷",
                        ]),

                       ([
                        "action":"$N身形一轉，猛然一式"HIG"「罡\風掃葉」"NOR"，舞出滿天劍影，挾著勁風向$n的$l掃去",
                            "damage":                17,
                            "dodge" :               -10,
                            "parry" :                10,
                            "attact_type":  "bar",
                            "damage_type":  "劈傷",
                        ]),

                       ([
                            "action":"$N仰天長笑，身形飄然而起，在半空中身子一旋，一式"HIM"「狂歌痛飲」"NOR"狂風般地擊向$n",
                            "damage":                13,
                            "dodge" :                20,
                            "parry" :                -10,
                            "attact_type":  "bar",
                            "damage_type":  "劍傷",
                        ]),

                       ([
                        "action":"$N向前邁去一大步，使出"HIB"「探海屠龍」"NOR"，手中$w舞成一個光球，迅若奔雷擊向$n的$l",
                            "damage":                10,
                            "attact_type":  "bar",
                            "damage_type":  "刺傷",
                        ]),
                       ([
                                "action":"$N運力一抖$w，一時"HIM"「馬蹴落花」"NOR"，$w幻出點點劍花，飄然刺向$n的$l",
                            "damage":                10,
                            "attact_type":  "bar",
                            "damage_type":  "刺傷",
                        ]),
                       ([
                        "action":"$N手中$w斜指蒼天，縱起丈餘，一時"YEL"「橫行漠北」"NOR"，$w雷霆般射向$n的$l",
                            "damage":                10,
                            "attact_type":  "bar",
                            "damage_type":  "刺傷",
                        ]),
                       ([
                                "action":"$N大喝一聲，一招"HIW"「白虹經天」"NOR"，$w閃電般劃出一道大圓弧劈向$n的$l",
                            "damage":                10,
                            "attact_type":  "bar",
                            "damage_type":  "刺傷",
                        ]),
                       ([
                "action":"$N身形向上飄起，突然一轉身，頭下腳上，手握$w，一招"HIW"「絮墜無聲」"NOR"，無聲無息地攻向$n的$l",
                            "damage":                10,
                            "attact_type":  "bar",
                            "damage_type":  "刺傷",
                        ]),
                       ([
                "action":"$N手中$w一抖，一招"HIR"「照破萬緣」"NOR"，$w逼出耀眼光芒，奮力擊向$n的$l",
                            "damage":                10,
                            "attact_type":  "bar",
                            "damage_type":  "刺傷",
                        ]),
                       ([
        "action":"$N忽然身形高高躍起，使出"HIC"「浪跡天涯」"NOR"，$w幻出漫天花瓣，迅如雷霆射向$n的$l",
                            "damage":                10,
                            "attact_type":  "bar",
                            "damage_type":  "刺傷",
                        ]),
                   });

int exert(object me, object target, string arg)
{
    object weapon;
    weapon=me->query_temp("weapon");

    if(arg=="off" )
    {
        if( me->query_skill_mapped("sword")!="quanzhen-sword")
            return notify_fail("你並沒有使用全真劍法。\n");
        me->map_skill("sword");
        me->reset_action();
        write("技能[全真劍法]已取消。\n");
        return 1;
    }

    if(!weapon)
        return notify_fail("使用全真劍法必須手中要有劍。\n");
    if(weapon->query("skill_type")!="sword")
        return notify_fail("使用全真劍法必須手中要有劍。\n");
    if(me->query_skill("sword")<10)
        return notify_fail("你的劍法基礎不夠無法使用全真劍法。\n");
    if(me->query("ap") < 10 || me->query("hp") < 10)
        return notify_fail("你的身體狀況無法使用全真劍法。\n");
    if( me->query_skill_mapped("sword")=="quanzhen-sword")
        return notify_fail("你已經在使用全真劍法。\n");

    me->map_skill("sword", "godsword");
    me->reset_action();
    message_vision(CYN" $N口誦劍訣，開始施展『全真劍法』。\n"NOR,me);
    me->receive_damage("ap",6); //luky
    me->start_busy(1);
    return 1;
}

int valid_learn(object me) {    return 1;       }

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int practice_skill(object me) { return 1; }

