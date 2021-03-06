// pick-plumblossom.c
// 折梅手 -Tmr 2006/11/19

#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void delay(object me,int cost);
void firesword(object me,object target,int damage);
mapping *action = ({
                       ([
                            "action": "$N一招「吹梅笛怨」，雙手橫揮，抓向$n的$l",
                            "damage":                15,
                            "attact_type":  "wit", 
                            "damage_type":  "瘀傷",
                        ]),
                       ([
                              "action": "$N施出「虛妄笑紅」，右手橫掃$n的$l，左手攻向$n的$l",
                            "damage":                15,
                            "attact_type":  "wit", 
                            "damage_type":  "瘀傷",
                        ]),
                       ([
                            "action": "$N一招「黃昏獨自愁」，身子躍然而起，抓向$n的$l",
                            "damage":                18,
                            "attact_type":  "wit", 
                            "damage_type":  "瘀傷",
                        ]),
                       ([
                            "action": "$N雙手平舉，一招「雲破月來花弄影」擊向$n$l",
                            "damage":                15,
                            "attact_type":  "wit", 
                            "damage_type":  "瘀傷",
                        ]),
                       ([
                            "action": "$N左手虛晃，右手一記「紅顏未老恩先絕」擊向$n$l",
                            "damage":                10,
                            "attact_type":  "wit", 
                            "damage_type":  "瘀傷",
                        ]),
                       ([
                            "action": "$N一招「砌下落梅如雪亂」，雙手飄然抓向$n$l",
                            "damage":                20,
                            "attact_type":  "wit", 
                            "damage_type":  "瘀傷",
                        ]),

                        });

int exert(object me, object target, string arg)
{
    object weapon;
    weapon=me->query_temp("weapon");

    if(arg=="off" )
    {
        if( me->query_skill_mapped("unarmed") != "pick-plumblossom")
            return notify_fail("你沒有使用「折梅手」。\n");
        me->map_skill("unarmed");
        me->reset_action();
        write("技能[折梅手]已取消。\n");
        return 1;
    }
    if( me->query_temp("weapon") && me->query_temp("weapon")->query("skill_type")!="unarmed")
        return notify_fail("你手中拿的武器種類，並不能使用於「折梅手」。\n");
    
    if(me->query("ap") < 10 || me->query("hp") < 10)
        return notify_fail("你的身體狀況無法使用「折梅手」。\n");
    if(me->query_skill("unarmed")<5)
        return notify_fail("你的空手搏擊基礎不夠無法使用「折梅手」。\n");
    if( me->query_skill_mapped("unarmed")=="pick-plumblossom")
        return notify_fail("你已經在使用折梅手。\n");

    me->map_skill("unarmed", "pick-plumblossom");
    me->reset_action();
      message_vision( HIG"$N"HIG"掌中套招，精彩絕倫，開始施展「折梅手」。\n"NOR,me);
    me->receive_damage("ap",6);
    me->start_busy(1);
    return 1;
}

int valid_learn(object me) {    return 1;       }

mapping query_action(object me, object weapon)
{
    int i,j,sk,busy;
    object target;
    target = offensive_target(me);
    sk=me->query_skill("pick-plumblossom");

    //扣ap
    if(me->query("ap") > 10 )
        me->receive_damage("ap", 1);

    if ( objectp(target) && sk > 50 && !target->is_busy() && !me->is_busy() && me->query("ap") > me->query("max_ap")/4*3 && sk > random(200))
    {

        i=COMBAT_D->attack_factor(me,"unarmed")*10;
        j=COMBAT_D->dodge_factor(target,"dodge")*6;
        //設定busy
                busy = 1;
        message_vision(HIW "$N凝神閉息，使出折梅手絕技「花開堪折直須折」，掌風呼呼逼得$n"HIW"破綻百出！！\n" NOR ,me,target);

        if( random(i) > random(j) ) {
            message_vision(GRN"($N"GRN"一時之間不知道如何反應！！)\n"NOR,target,me);
            target->start_busy(busy);
            me->receive_damage("ap", busy*10);
        }
    }

    if( me->query("ap") <10 )
    {
        me->map_skill("unarmed");
        me->reset_action();
        message_vision("\n$N停止施展「折梅手」了。\n"NOR,me);
    }

    return action[random(sizeof(action))];
}

int practice_skill(object me) { return 1; }

int improve_limite(object ob)
{
    if(ob->query("int") < 30) return 90;
    else return 100;
}


