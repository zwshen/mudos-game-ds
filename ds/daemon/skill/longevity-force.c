// 長生訣 (longevity-force)
// Tmr 2007/07/19

#include <ansi.h>
#define SKILL_NAME "longevity-force"

inherit SKILL;
inherit SSERVER;

int do_heal(object me) {
    int force,sk,heal;

    force = me->query_skill("force", 2);
    sk = me->query_skill(SKILL_NAME, 2);
    heal = force + sk;
    if (me->is_fighting() ) return notify_fail("你正忙著戰鬥，沒有空療傷");
    if(me->query("hp") >= me->query("max_hp") ) return notify_fail("你的健康狀況已達顛峰。\n");
    if(me->query("ap") < heal/3 ) return notify_fail("你的內勁不足，無法使用療傷功\能。\n");

     message_vision( "$N使出長生訣"HIW"療傷真氣"NOR"，長生真元起丹田降氣府，全身傷勢開始好轉了。\n" ,me);
    me->receive_damage("ap", heal/2);
    me->receive_heal("hp", heal);
    me->start_busy(1);
    me->improve_skill(SKILL_NAME, 1 + random(me->query_con()/4) );
    me->improve_skill("force", 1 + random(me->query_con()/4)  );
    return 1;
}

int do_spiral(object me, object target) {
    int force,sk;
      int damage;
    force = me->query_skill("force", 2);
    sk = me->query_skill(SKILL_NAME, 2);

    if(!target) target = offensive_target(me);  // 敵人
    if( !target )
        return notify_fail("你要對誰使用？\n");
    if(me->query_skill( SKILL_NAME ) < 30)
        return notify_fail("你的"+SKILL_NAME+"必需達到30級，才能發出螺蜁氣勁。\n");
    if(me->query("ap") < 100)
        return notify_fail("你的內勁不夠發出螺旋氣勁。\n");
    if(!me->is_fighting(target) )
        return notify_fail("你並沒有與對方在戰鬥。\n");

    message_vision( HIW "\n$N運起長生訣"HIC"螺旋勁"HIW"，真氣立時如高速迴旋的無形尖椎，從不可思議的方向往$n"HIW"攻去！！\n" ,me , target);
    me->start_busy(1);
    me->receive_damage("ap", 40 );

    if( random(sk*2) > COMBAT_D->attack_factor(me, SKILL_NAME)*10/15
            || random(sk*2) > -COMBAT_D->dodge_factor(target,"dodge") ) {
        // 命中
        damage = 1 + random(sk);
        message_vision( HIR "威猛無倫的螺旋勁道侵入$n"HIR"要穴，$n"HIR"真氣運行登時不暢，一口氣提不上來！！("+damage+")\n\n" NOR, me , target);
        target->start_busy(2);
         target->receive_damage( "hp", damage, me );
            me->improve_skill(SKILL_NAME, 1 + random(me->query_con()/4) );
            me->improve_skill("force", 1 + random(me->query_con()/4)  );
    } else {
           message_vision( CYN "但是被$n"CYN"有驚無險地避了開去。\n" NOR,me , target);
    }

    return 1;
}

int exert(object me,object target, string arg)
{
    //療傷功能
    if( arg =="heal" )
        return do_heal(me);

    return do_spiral(me, target);
//    return notify_fail("長生訣的功\能有：療傷(heal) 及 螺旋勁(exert longevity-force on [id])。\n");
}

int valid_learn(object me)
{
    return 1;
}

int practice_skill(object me)
{
    return 1;
}


