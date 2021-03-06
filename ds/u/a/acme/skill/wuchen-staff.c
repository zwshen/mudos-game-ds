#include <ansi.h>
inherit SKILL;
inherit SSERVER;
mapping *action = ({
        ([
        "action": "$N手抖$w，一股奇猛無匹的潛勁，疾逾奔馬，猛若崩山，朝$n的$l猛然揮去",
        "damage":                10,
        "dodge" :                8,
        "parry" :                5,
        "attact_type":  "bio",  // 設定技能的攻擊種類
                                // 種類有 生物(bio) 獸性(bar)
                                // 魔法(wit)心靈(sou)科技(tec)
        "damage_type":  "搥傷",
        ]),

        ([
        "action": "$N手中$w杖頭一甩，一股無與倫比的掌勁，登時如排山倒海般，匝地捲地，朝$n疾捲而去",
        "damage":                8,
        "dodge":                 -5,
        "parry" :                12,
        "attact_type":  "bio",
        "damage_type":  "撞傷",
        ]),
        ([
        "action": "$N身形疾如行雲流水，手中$w揮來，招中套招，一團杖影，緊罩住$n的$l",
        "damage":                 7,
        "dodge" :                 9,
        "parry" :                -6,
        "attact_type":  "bio",
        "damage_type":  "搥傷",
        ]),

        ([
        "action": "$N身影一幌，手中$w一股勁急杖氣，疾如流水，猛若山崩，當$n的頭劈來",
        "damage":                13,
        "dodge" :                20,
        "parry" :                -15,
        "attact_type":  "bio",
        "damage_type":  "撞傷",
        ]),

        ([
        "action": "$N手中$w陡湧光芒，一招"HIG"「杖打如來」"NOR"，當$n的$l襲去，快疾凌厲。",
        "damage":                15,
        "dodge" :                -10,
        "parry" :                13,
        "attact_type":  "bio",
        "damage_type":  "搥傷",
        ]),
});
void delay(object me,int cost);
int exert(object me, object target, string arg)
{
        string msg;
        object weapon;
        
        weapon=me->query_temp("weapon");
        if(arg=="off" )
        {
                if( me->query_skill_mapped("staff")!="wuchen-staff")
                        return notify_fail("你並沒有使用無塵杖法\n");
                me->map_skill("staff");
                me->reset_action();
                write("技能[無塵杖法]已取消。\n");
                return 1;
        }
        if(!weapon) return notify_fail("使用無塵杖法必須手中要有根杖。\n");
        if(weapon->query("skill_type")!="staff") return notify_fail("使用無塵杖法必須手中要有根杖。\n");
        if(me->query_skill_mapped("staff")=="wuchen-staff") return notify_fail("你正在使用無塵杖法。\n");
if(me->query("ap")<10 || me->query("hp")<10 ) return notify_fail("你的身體狀況無法使用無塵杖法。\n");
        if(!me->skill_active( "wuchen-staff",(: call_other, __FILE__, "delay", me ,6:), 10))
          return notify_fail("你的收招動作還沒完成。\n");
        me->map_skill("staff", "wuchen-staff");
        me->reset_action();
        message_vision("\n"HIW" $N功\貫無臂，凝神聚氣，手上"+weapon->name()+"虎虎生風，開始施展無塵杖法。\n"NOR,me);
        me->receive_damage("ap",5);
        me->start_busy(1);
  
      //me->start_call_out( (: call_other, __FILE__, "delay", me ,6:), 10);
        return 1;
}

void delay(object me,int cost)
{
        object weapon;
        if(!me) return;
        weapon=me->query_temp("weapon");
        if(!weapon)
        {
                me->map_skill("staff");
                me->reset_action();
                return;
        if(weapon->query("skill_type")!="staff")
        {
                me->map_skill("staff");
                me->reset_action();
                return;
        }
        if(me->query_skill_mapped("staff")!="wuchen-staff")
        {
         return;
        }
    if(me->query("ap")<7)
        {
                me->map_skill("staff");
                me->reset_action();
                message_vision("\n"HIW"$N的體力不夠無法繼續使用無塵杖法, 只好改用一般招式。\n"NOR,me);
                return ;
   
     }
    if( me->is_fighting() ) me->receive_damage("ap",5); //luky
        //me->start_call_out( (: call_other, __FILE__, "delay", me ,cost:), 10);
        me->skill_active( "wuchen-staff",(: call_other, __FILE__, "delay", me ,cost:), 10);
}
}
int valid_learn(object me) {    return 1;       }

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me) { return 1; }
