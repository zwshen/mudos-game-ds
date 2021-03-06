
//QC: Luky 1999.8.17
// 神龍八擊 (dragon_fist)
// copy from dragonfist.c
// Tmr 2006/12/12
#include <ansi.h>
inherit SKILL;
inherit SSERVER;

mapping *action = ({
        ([
        "action": "$N掌勢錯綜迷離，一招「龍遊淺水」以奇異的角度擊向$n",
        "damage":                20,
        "attack":                20,
        "attact_type":  "bar",
            "damage_type":  "掌傷",
        ]),

        ([
        "action": "$N使出「龍脈寸斷」，接連數式狠辣的錯綜手法打向$n",
        "damage":                20,
        "dodge" :               -15,
        "parry" :               -10,
        "attact_type":  "bar",
            "damage_type":  "內傷",
        ]),

        ([
        "action": "$N身形微頓，由下而上起拳，一招「龍破穹蒼」直直往$n的$l擊去",
        "damage":                20,
        "dodge" :                20,
        "attack":               -15,
        "attact_type":  "bar",
        "damage_type":  "捶傷",
        ]),

        ([
        "action": "$N長跳一步，身形靈轉如意，在半空中使出了「龍飛雲天」一招打向$n的$l",
        "damage":                20,
        "dodge" :                5,
        "parry" :                5,
        "attact_type":  "bar",
        "damage_type":  "掌傷",
        ]),

        ([
        "action": "$N一招「怒龍天火」掌勁透發燥熱的氣勁，硬是往$n的$l重重劈下",
        "damage":                20,
        "attack":                20,
        "parry" :                20,
        "attact_type":  "bar",
        "damage_type":  "劈傷",
        ]),

        ([
        "action": "$N雙掌運氣，「天龍現世」之勢將雙手之力道推向$n",
        "damage":                25,
        "dodge" :               -15,
        "parry" :               -15,
        "attact_type":  "bar",
        "damage_type":  "內傷",
        ]),

        ([
        "action": "$N殺氣騰騰，殺招「狂龍嘯天」全身氣勁集於右掌上，順勢推向$n",
        "damage":                40,
        "dodge" :               -35,
        "parry" :               -35,
        "attact_type":  "bar",
        "damage_type":  "內傷",
        ]),
});

int exert(object me, object target, string arg)
{
        object weapon;

        weapon=me->query_temp("weapon");
        if(weapon)
        {
                if(weapon->query("skill_type")!="unarmed")
                        return notify_fail("你手中所持的武器，不適合用在神龍八擊。\n");
        }
        if(arg=="off" )
        {
                if( me->query_skill_mapped("unarmed")!="dragon-fist")
                        return notify_fail("你並沒有在使用「神龍八擊」。\n");
                me->map_skill("unarmed");
                me->reset_action();
                write("你停止使用神龍八擊了。\n");
                return 1;
        }
  

        if( me->query_skill_mapped("unarmed") == "dragon-fist")
                        return notify_fail("你已經在使用「神龍八擊」了。\n");
        if(me->query_skill("unarmed")<10) 
                return notify_fail("你的徒手搏鬥需要10級，才能使用神龍八擊。\n");
   if(me->query("ap")<20 || me->query("hp")<30) 
                return notify_fail("你的身體狀況不良，不能使用神龍八擊。\n");
        me->map_skill("unarmed", "dragon-fist");
        me->reset_action();
        message_vision(HIG "$N結合血戰十式及截脈法，施展出神龍八擊。\n"NOR,me);
    me->receive_damage("ap",10);
        me->start_busy(2);
    return 1;
}

int valid_learn(object me) {    return 1;       }

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me) { return 1; }

int improve_limite(object ob)
{
        return ob->query_str() + 30;
}

