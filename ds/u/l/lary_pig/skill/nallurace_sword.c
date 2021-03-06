#include <ansi.h>
inherit SKILL;
inherit SSERVER;

mapping *action = ({
        ([
        "action": "$N疾速的揮舞手中的$w使出「固」字訣，無數的劍氣形成一道劍網將$N整個人\n環繞在一片劍網之中",
        "damage":                5,
        "dodge":                 -5,
        "parry" :               30,
        "damage_type":  "刺傷",
        ]),

        ([
        "action": "$N暴喝一聲，凝神尋找$n的破綻，使出「破」字訣劍劍攻向$n的破綻，\n招招直取$n的要害",
        "damage":                20,
        "dodge":                -15,
        "damage_type":  "刺傷",
        ]),

        ([
        "action": "$N劍勢一變，施展一式「旋」字訣，整個人以極快的速度進行高速的迴轉\n，同時往$n的$l狂斬而去",
        "damage":                15,
        "dodge" :                -5,
        "parry" :                10,
        "damage_type":  "劈傷",
        ]),

        ([
        "action": "$N暴吼一聲，一躍至空中使出「斬」字訣，\n強大的劍氣配合無比的破壞力直轟$n的腦門",
        "damage":                25,
        "dodge" :                -15,
        "parry" :                -15,
        "damage_type":  "劈傷",
        ]),

        ([
        "action": "$N以極快的身法直欺$n的身旁，使出一式「翔」字訣，\n由下而上，斬向$n的下顎",
        "damage":                15,
        "dodge" :                5,
        "damage_type":  "劍傷",
        ]),

      
});

int exert(object me, object target, string arg)
{
        string msg;
        object weapon;
        
        weapon=me->query_temp("weapon");
        if(arg=="off" )
        {
                if( me->query_skill_mapped("sword")!="nallurace_sword")
                        return notify_fail("你並沒有使用那魯雷斯騎士流劍法。\n");
                me->map_skill("sword");
                me->reset_action();
                write("技能『那魯雷斯騎士流劍法』取消。\n");
                return 1;
        }
        if(!weapon) return notify_fail("你不認為你可以空手使用劍法吧。\n");
        if(weapon->query("skill_type")!="sword") return notify_fail("使用劍法手中要有把劍，這是基本常識吧。\n");
        if(me->query_skill("sword")<10) return notify_fail("拜託！你的基礎劍術那麼差，根本在汙辱這套劍法。\n");
        if(me->query_skill_mapped("sword")=="nallurace_sword")
                return notify_fail("你正在使用那魯雷斯騎士流劍法。\n");
        if(me->query("mp")<10 || me->query("hp")<10) return notify_fail("你的身體狀況無法使用那魯雷斯騎士流劍法。\n");
        me->map_skill("sword", "nallurace_sword");
        me->reset_action();
        message_vision("\n"HIC" $N高舉手中的"+weapon->name()+"，向那魯雷斯王國的方向行個劍禮，開始施展『那魯雷斯騎士流劍法』。\n"NOR,me,target);
        me->add("mp", -4);
        me->start_busy(1);
        call_out("delay",10,me);
        return 1;
}

void delay(object me)
{
        object weapon;
        if(!me) return;
        weapon=me->query_temp("weapon");
        if(!weapon)
        {
                me->map_skill("sword");
                me->reset_action();
                remove_call_out("delay");
                return;
        }
        if(weapon->query("skill_type")!="sword")
        {
                me->map_skill("sword");
                me->reset_action();
                remove_call_out("delay");
                return;
        }
        if(me->query_skill_mapped("sword")!="nallurace_sword")
        {
         remove_call_out("delay");
         return;
        }
        if(me->query("mp")<4)
        {
                me->map_skill("sword");
                me->reset_action();
                message_vision("\n"HIW"$N體力不繼，無法繼續施展那魯雷斯騎士流劍法，速度逐漸慢了下來。\n"NOR,me);
                remove_call_out("delay");
                return ;
        }
        me->add("mp",-4);
        call_out("delay",5,me);
}

int valid_learn(object me) {    return 1;       }
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me) { return 1; }
