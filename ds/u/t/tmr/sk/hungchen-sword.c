#include <ansi.h>
inherit SKILL;
inherit SSERVER;

mapping *action = ({
        ([
        "action": "$N使出『紅塵劍法』第一式【殺無赦】，舉起$w向$n殺去。",
        "damage":                20,
        "dodge" :               -10,
        "parry" :               -10,
        "attact_type":  "bar",
        "damage_type":  "劍傷",
        ]),

        ([
        "action": "$N一式『紅塵劍法』第二式【恨無心】，揮$w直搗$n的心窩。",
        "damage":                15,
        "dodge":                 10,
        "parry" :                10,
        "attact_type":  "bar",
        "damage_type":  "刺傷",
        ]),

        ([
        "action": "$N一招『紅塵劍法』第三式【斬無情】，揮動著$w斬落$n的肩頭。",
        "damage":                15,
        "dodge" :                -5,
        "parry" :               -10,
        "attact_type":  "bar",
        "damage_type":  "斬傷",
        ]),

        ([
        "action": "$N使出『紅塵劍法』第四式【滅無形】，提劍急旋，股起無形劍氣，朝$n攻去。",
        "damage":                16,
        "dodge" :                10,
        "parry" :               -15,
        "attact_type":  "bar",
        "damage_type":  "刺傷",
        ]),

        ([
        "action": "$N一式『紅塵劍法』第五式【去無痕】，抖然刺出凌厲的一劍。",
        "damage":                18,
        "dodge" :                20,
        "parry" :               -30,
        "attact_type":  "bar",
        "damage_type":  "劍傷",
        ]),

        ([
        "action": "$N一式『紅塵劍法』第六式【劈無極】，揮劍攔腰向$n直劈而去。",
        "damage":                15,
        "dodge" :               -10,
        "parry" :                 5,
        "attact_type":  "bar",
        "damage_type":  "劈傷",
        ]),

        ([
        "action": "$N一式『紅塵劍法』第七式【迅如風】，劍勢快如風，一招接一招向$n刺去。",
        "damage":                12,
        "dodge" :                20,
        "parry" :               -20,
        "attact_type":  "bar",
        "damage_type":  "刺傷",
        ]),

        ([
        "action": "$N一式『紅塵劍法』第八式【猛如虎】，提劍猛揮，看似亂舞，卻是剛猛。",
        "damage":                23,
        "dodge" :               -10,
        "parry" :               -15,
        "attact_type":  "bar",
        "damage_type":  "劍傷",
        ]),
        ([
        "action": "$N一式『紅塵劍法』第九式【悍如天】，只聽$w發出「嗡∼嗡∼」之響，勁力十足。",
        "damage":                18,
        "dodge" :               -14,
        "parry" :               -11,
        "attact_type":  "bar",
        "damage_type":  "劍傷",
        ]),
        ([
        "action": "$N一式『紅塵劍法』第十式【矢如龍】，劍招連綿不絕，一式接一式。",
        "damage":                13,
        "dodge" :                10,
        "parry" :                10,
        "attact_type":  "bar",
        "damage_type":  "刺傷",
        ]),
        ([
        "action": "$N一式『紅塵劍法』第十一式【定如山】，定氣凝神，提劍抖然一揮，攻其不備。",
        "damage":                10,
        "dodge" :               -20,
        "parry" :                30,
        "attact_type":  "bar",
        "damage_type":  "刺傷",
        ]),
        ([
        "action": "$N一式『紅塵劍法』第十二式【柔如水】，劍招遲緩，陰柔巧妙。",
        "damage":                10,
        "dodge" :                25,
        "parry" :                25,
        "attact_type":  "bar",
        "damage_type":  "刺傷",
        ]),

});

int exert(object me, object target, string arg)
{
        int i,str,c,damage;
        string msg;
        object weapon;
        mapping type;
       
        weapon=me->query_temp("weapon");
        if(arg=="off" )
        {
                if( me->query_skill_mapped("sword")!="hungchen-sword")
                        return notify_fail("你並沒有使用[紅塵劍法]。\n");
                me->map_skill("sword");
                me->reset_action();
                write("技能[紅塵劍法]已取消。\n");
                return 1;
        }
        if(!weapon) return notify_fail("使用[紅塵劍法]必須手中要有劍。\n");
        if(weapon->query("skill_type")!="sword") return notify_fail("使用神武劍訣必須手中要有劍。\n");
        if(me->query_skill("sword")<20) return notify_fail("你的劍法基礎不夠無法使用[紅塵劍法]。\n");

        //第二次exert
        if(me->query_skill_mapped("sword")=="hungchen-sword")
        {     
          if( !target ) target = offensive_target(me);
          if(!target)   return notify_fail("你已經在使用[紅塵劍法]。\n");

          //攻擊性的要特別注意要加下面兩行.
          if(!target->can_fight(me))
             return target->can_fight(me);
          c = target->query_armor();
          if(me->query_skill("hungchen-sword")>80 && me->query("mp")>me->query("max_mp")/3)
          {
             msg = HIC "\n只見$N雙眼噴火，從第一式直至第十三式，一氣喝成，行雲流水，最後殺著『紅塵劍法』\n";
             msg += HIC "最終式【七星落長空】，$N挺劍向$n當胸刺到，劍光閃爍，發出嗡嗡之聲，已罩住了$n胸口\n";
             msg += HIC "「膻中」、「神藏」、「靈墟」、「神封」、「步廊」、「幽門」、「通谷」七處大穴。\n" NOR;
            if( random(100)>30)
            {
             str=me->query("str");
             damage = random(me->query_skill("hungchen-sword")) + me->query_damage() + random(str*2);
             damage -= random(target->query_armor());
             me->start_busy(2);
             msg += HIR "\n結果$n的胸口要穴連中七劍，身子幌了幾下，狂噴鮮血，顯然受傷不輕。\n" NOR;
             target->start_busy(3);
             damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
             target->receive_damage("hp",damage,me);
             COMBAT_D->report_status(target);
             message_vision(msg, me, target);
             i=(damage/10)+(str/2);
             me->receive_damage("mp",i);
            }
            else
            {
             me->start_busy(2);
             msg += HIW "\n$n大驚失色，縱聲大叫，左支右拙，狼狽的滾開了，卻也嚇得臉色鐵青。\n" NOR;
             message_vision(msg, me, target);
            }
          }
          else
          {
            msg = HIW "\n你的[紅塵劍法]不夠精熟，不能使用特攻。\n"NOR;
            message_vision(msg, me, target);
          }     
       }
        if(me->query("mp")<10 || me->query("hp")<10) return notify_fail("你的身體狀況無法使用[紅塵劍法]。\n");
        me->map_skill("sword", "hungchen-sword");
        me->reset_action();
        message_vision("\n"HIW" $N拿起手上的"+weapon->name()+"，左手屈指捏了個劍訣，開始施展[紅塵劍法]。\n"NOR,me);
        me->receive_damage("mp",4);
        me->start_busy(1);
me->start_call_out( (: call_other, __FILE__, "delay", me ,6:), 10);
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
        if(me->query_skill_mapped("sword")!="hungchen-sword");
        {
         remove_call_out("delay");
         return;
        }
        if(me->query("mp")<4)
        {
                me->map_skill("sword");
                me->reset_action();
                message_vision("\n"HIW"$N的體力不夠無法繼續使用[紅塵劍法], 只好改用一般劍招。\n"NOR,me);
                remove_call_out("delay");
                return ;
        }
        me->add("mp",-4);
        call_out("delay",10,me);
}

int valid_learn(object me) {    return 1;       }
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me) { return 1; }
