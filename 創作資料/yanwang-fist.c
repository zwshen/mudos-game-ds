// 閻王拳 (yanwang_fist)
// copy from dragon_fist.c
// Bluerex 2007/10/11
#include <ansi.h>
inherit SKILL;
inherit SSERVER;

mapping *action = ({
        ([
        "action": "$N大聲歌誦「萬般將不去，唯有業隨身」，雙掌以奇異的角度擊向$n",
        "damage":                20,
        "attack":                20,
        "attact_type":  "bar",
            "damage_type":  "掌傷",
        ]),

        ([
        "action": "$N含首默默吟出「巧謀油水千缸滿，辜負人間一片誠」，突然間接連數式狠辣的錯綜手法打向$n",
        "damage":                20,
        "dodge" :               -15,
        "parry" :               -10,
        "attact_type":  "bar",
            "damage_type":  "內傷",
        ]),

        ([
        "action": "$N身形微頓，低聲唱出「青燈如豆千斤油，難照黑心無道人」，右手握拳直直往$n的$l擊去",
        "damage":                20,
        "dodge" :                20,
        "attack":               -15,
        "attact_type":  "bar",
        "damage_type":  "捶傷",
        ]),

        ([
        "action": "$N雙眼爆紅，引領怒斥「人依造作罪業，押赴各獄受報消業」，雙手換化成無數掌影打向$n的$l",
        "damage":                20,
        "dodge" :                5,
        "parry" :                5,
        "attact_type":  "bar",
        "damage_type":  "掌傷",
        ]),

        ([
        "action": "$N一喝一唱「學不安道，\愧\對聖賢書」，兩指有如利劍，硬是往$n的$l重重劈下",
        "damage":                20,
        "attack":                20,
        "parry" :                20,
        "attact_type":  "bar",
        "damage_type":  "劈傷",
        ]),

        ([
        "action": "$N霸氣湧現，吟唱「造無量業，得無邊罪」之餘，閒暇地將雙手之力道推向$n",
        "damage":                25,
        "dodge" :               -15,
        "parry" :               -15,
        "attact_type":  "bar",
        "damage_type":  "內傷",
        ]),
});

int exert(object me, object target, string arg)
{
        string msg;
        object weapon;

        weapon=me->query_temp("weapon");
        if(weapon)
        {
                if(weapon->query("skill_type")!="unarmed")
                        return notify_fail("你手中所持的武器，不適合用在閻王拳。\n");
        }
        if(arg=="off" )
        {
                if( me->query_skill_mapped("unarmed")!="yanwang-fist")
                        return notify_fail("你並沒有在使用「閻王拳」。\n");
                me->map_skill("unarmed");
                me->reset_action();
                write("你停止使用閻王拳了。\n");
                return 1;
        }
  

        if( me->query_skill_mapped("unarmed") == "yanwang-fist")
                        return notify_fail("你已經在使用「閻王拳」了。\n");
        if(me->query_skill("unarmed")<50) 
                return notify_fail("你的徒手搏鬥需要50級，才能使用閻王拳。\n");
   if(me->query("ap")<20 || me->query("hp")<30) 
                return notify_fail("你的身體狀況不良，不能使用閻王拳。\n");
        me->map_skill("unarmed", "yanwang-fist");
        me->reset_action();
        message_vision(HIG "$N全身發出有如爆豆丁聲，施展出閻王拳。\n"NOR,me);
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

