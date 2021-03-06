//盤石刀法(stone-blade) by Acme Sat Jan 1 2000

#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void superpower(object me);
mapping *action = ({
        ([
        "action": "$N一招「雲峰隔水深」，",
        "damage":                12,
        "dodge" :                12,
        "parry" :                18,
        "attact_type":  "bio",  
        "damage_type":  "刀傷",
        ]),
        ([
        "action": "$N一招「寒磬滿空林」",
        "damage":                15,
        "dodge" :                 5,
        "parry" :                25,
        "attact_type":  "bio",  
        "damage_type":  "刀傷",
        ]),
        ([
        "action": "$N一式「涵虛混太清」",
        "damage":                20,
        "dodge" :                10,
        "parry" :                20,
        "attact_type":  "bio",  
        "damage_type":  "砍傷",
        ]),
        ([
        "action": "$N一式「天寒夢澤深」",
        "damage":                18,
        "dodge" :                17,
        "parry" :                13,
        "attact_type":  "bio",  
        "damage_type":  "砍傷",
        ]),

        ([
        "action": "$N一招「深竹暗浮煙」",
        "damage":                10,
        "dodge" :                15,
        "parry" :                15,
        "attact_type":  "bio",  
        "damage_type":  "砍傷",
        ]),

        ([
        "action": "$N一式「晴翠接荒城」",
        "damage":                15,
        "dodge" :                10,
        "parry" :                20,
        "attact_type":  "bio",  
        "damage_type":  "砍傷",
        ]),

        ([
        "action": "$N一式「孤燈寒照雨」",
        "damage":                12,
        "dodge" :                20,
        "parry" :                10,
        "attact_type":  "bio",  
        "damage_type":  "砍傷",
        ]),

});
mapping *s_action = ({
        ([
        "action": HIB "$N使出盤石特攻「殘雲歸太華」"NOR,
        "damage":                90,
        "dodge" :                20,
        "parry" :                40,
        "attact_type":  "bio",  
        "damage_type":  "砍傷",
        ]),
});

int exert(object me, object target, string arg)
{
        string msg;
        object weapon;
        
        weapon=me->query_temp("weapon");
        if(arg=="off" )
        {
                if( me->query_skill_mapped("blade")!="stone-blade")
                        return notify_fail("你並沒有施展盤石刀法\n");
                me->map_skill("unarmed");
                me->reset_action();
                write("技能盤石刀法已取消。\n");
                return 1;
        }
    if ( !weapon )  return notify_fail("手中要有刀才能用盤石刀法。\n");
          if( weapon->query("skill_type")!="blade")
                return notify_fail("手中要有刀才能用盤石刀法。\n");

        if(me->query_skill_mapped("blade")=="stone-blade") 
                return notify_fail("你已經在施展盤石刀法了。\n");
        if(me->query("ap")<10 || me->query("hp")<10 )
                 return notify_fail("你的身體狀況無法使用盤石刀法。\n");
        me->map_skill("blade", "stone-blade");
        me->reset_action();
        message_vision(HIW "$N握緊手中的"+weapon->query("name")+"舞了一遍盤石刀法的「起刀式」。\n"NOR,me);
//        me->receive_damage("ap",5);
        me->start_busy(1);
 
        return 1;
}
  mapping query_action(object me, object weapon)
{
   if (me->query_temp("stone-blade/superpower") ) return action[random(sizeof(action))];
    if ( me->query_skill("stone-blade") >= 70  && me->query("ap") > 100 && random(100)>=79 )
    {
//        me->receive_damage("ap",50);
//        me->start_busy(1);
          return s_action[0];
    }
    if ( me->query_skill("stone-blade") >=90 && me->query("ap") > 200 && random(100)>=30 )
    {
//        me->receive_damage("ap",80);
          me->start_busy(2);
     me->skill_active( "stone-blade",(: call_other, __FILE__, "superpower",this_player():), 3);
    }
    return action[random(sizeof(action))];
}

void superpower(object me)
{
     int i;
     object target,weapon;
     string *limbs;
     me=this_player();
     weapon=me->query_temp("weapon");

     if( !target ) target = offensive_target(me);
     if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
        return;

     if(!me->is_fighting()) return;
     if( environment(me) != environment(target) ) return;

     if(me->query_temp("stone-blade/superpower") ) return;
     message_vision(HIW"$N大喝一聲，使出六式特功\。"NOR,me);
     for (i=0;i<=5;i++)
     {
       limbs = target->query("limbs");
       message_vision("$N將手中"+weapon->query("name")+"緊握，砍向$n的"+limbs[random(sizeof(limbs))]+"。"NOR,me,target);
       if(me->query_skill("stone-blade") > random(30) )
       {
          COMBAT_D->report_status(target);         //顯示target狀態
          target->receive_damage("hp",30+random(20));
       }
       else {
          message_vision("但是被$n及時避開。\n",me,target);
       }
     }
     me->delete_temp("active/superpower");
}

int practice_skill(object me) { return 1; }
int valid_learn(object me)    { return 1; }

