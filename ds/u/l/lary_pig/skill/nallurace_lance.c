#include <ansi.h>
inherit SKILL;
inherit SSERVER;

mapping *action = ({
        ([
        "action": "$N倒持手中的$w使出一式「天河倒懸」，槍勢由下而上直取\n$n的$l",
        "damage":                20,
        "dodge":                 -5,
        "parry" :                -10,
        "damage_type":  "刺傷",
        ]),

        ([
        "action": "$N迅速的移動腳下的步伐，趁著$n一個行動上的破綻使出一式「風嘯狂嵐斬」，只見$N將手中\n的$w往上一撩攻向$n的下顎，同時轉身繞至$n的身後給與連番重擊\n",
        "damage":                25,
        "dodge":                 10,
        "damage_type":  "擊傷",
        ]),

        ([
        "action": "$N摒氣凝神，將全身的力量凝聚自槍頭，施展一式「天地劫」，只見$N逆持手中的$w以大鵬展翅高飛之勢\n將$n擊飛至高空再將他重重的擊下",
        "damage":                25,
        "dodge" :               -10,
        "parry" :               -10,
        "damage_type":  "撞傷",
        ]),

        ([
        "action": "$N倏然將槍身平擺，使出一式「裂風斬」以最簡單直接，也最有效的攻勢，\n猛掃$n的下盤",
        "damage":                 15,
        "dodge" :                 -5,
        "parry" :                 -5,
        "damage_type":  "劈傷",
        ]),

        ([
        "action": "$N以槍身的中心為支點快速的轉動手中的$w使出一式「龍卷風暴」，\n密集的槍勢，接連不斷的轟向$n周身要害",
        "damage":                20,
        "parry" :                 5,
        "damage_type":  "槍傷",
        ]),

});

int exert(object me, object target, string arg)
{
        string msg;
        object weapon;
        
        weapon=me->query_temp("weapon");
        if(arg=="off" )
        {
                if( me->query_skill_mapped("fork")!="nallurace_lance")
                        return notify_fail("你並沒有使用那魯雷斯騎士流槍法。\n");
                me->map_skill("fork");
                me->reset_action();
                write("技能『那魯雷斯騎士流槍法』取消。\n");
                return 1;
        }
        if(!weapon) return notify_fail("哇！空手使用槍法！？好歹也帶把武器吧。\n");
        if(weapon->query("skill_type")!="fork") return notify_fail("你不會認為這把武器能施展槍法吧。\n");
        if(me->query_skill("fork")<10) return notify_fail("拜託！你的基礎槍術那麼差，根本在汙辱這套槍法。\n");
        if(me->query_skill_mapped("fork")=="nallurace_lance")
                return notify_fail("你正在使用那魯雷斯騎士流槍法。\n");
        if(me->query("mp")<10 || me->query("hp")<10) return notify_fail("你的身體狀況無法使用那魯雷斯騎士流劍法。\n");
        me->map_skill("fork", "nallurace_lance");
        me->reset_action();
        message_vision("\n"HIC" $N高舉手中的"+weapon->name()+"，向那魯雷斯王國的方向行個持槍禮，開始施展『那魯雷斯騎士流槍法』。\n"NOR,me,target);
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
                me->map_skill("fork");
                me->reset_action();
                remove_call_out("delay");
                return;
        }
        if(weapon->query("skill_type")!="fork")
        {
                me->map_skill("fork");
                me->reset_action();
                remove_call_out("delay");
                return;
        }
        if(me->query_skill_mapped("fork")!="nallurace_lance")
        {
         remove_call_out("delay");
         return;
        }
        if(me->query("mp")<4)
        {
                me->map_skill("lance");
                me->reset_action();
                message_vision("\n"HIW"$N體力不繼，無法繼續施展那魯雷斯騎士流槍法，速度逐漸慢了下來。\n"NOR,me);
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
