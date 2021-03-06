// 粹精心法 (pure-energy) - 寒澈派進階內功
//by Tmr 2007/03/03

#include <ansi.h>
inherit SKILL;

int heal(object me);
int threahing(object me);
int harvest(object me);
int dust(object me);

int exert(object me,object target, string arg)
{
    if(arg =="heal" )
        return heal(me);
    if(arg=="threshing")
        return threahing(me);
    if(arg=="harvest")
        return harvest(me);
    if(arg=="dust_clean")
        return dust(me);

    return notify_fail("粹精心法的功\能請參考 help pure-energy。\n");

}

int heal(object me) {
    int force,sk,heal;

    force = me->query_skill("force", 2);
    sk = me->query_skill("pure-energy", 2);

    if(me->query("hp") >= me->query("max_hp") ) return notify_fail("你的健康狀況良好，不需要療傷。\n");
    if(me->query("ap") < heal/2 ) return notify_fail("你的內勁不足，無法療傷。\n");
    if (me->is_fighting() ) return notify_fail("你正忙著戰鬥，沒有空療傷。\n");

    heal = (force+sk)/2;
    message_vision( "$N呼地一聲，從嘴裡緩緩吐出幾絲冷氣，身上的傷勢也慢慢恢復了。\n" ,me);
    me->receive_damage("ap",heal/2);
    me->receive_heal("hp",heal/2);
    me->improve_skill("force",1+ random(me->query_int()) );
    me->improve_skill("pure-energy",1+ random(me->query_int()/2) );

    me->start_busy(1);
    return 1;
}


int threahing(object me) {
    int sk;
    sk = me->query_skill("pure-energy");
    if ( sk < 30 ) return notify_fail("你的粹精心法不熟練，無法施展「離蒿取粒」。 \n");
    if ( me->query_skill("force") < 30 ) return notify_fail("你的內功\心法不熟練，無法施展「離蒿取粒」。 \n");
    if ( me->query("ap") < 60 ) return notify_fail("你的內勁不足，無法施展「離蒿取粒」。\n");
    
        if ( me->query_condition("frost_threshing") ) 
                return notify_fail("你已經在施展「離蒿取粒」。\n");
        if ( me->query_temp("pure-energy/threshing") ) 
                return notify_fail("你已經在施展「離蒿取粒」。\n");

    message_vision(HIG "$N使出離蒿取粒之法，手中宛如握有蒿束，束手而擊，呯呯聲做響不停。 \n" NOR,me);

    me->receive_damage("ap",60);
    me->improve_skill("force",1+ random(me->query_int()) );
    me->improve_skill("pure-energy",1+ random(me->query_int()/2) );
    me->set_temp("pure-energy/threshing", sk/2 );
    me->add_temp("apply/damage", sk/2 );
    me->start_busy(2);
        me->apply_condition("frost_threshing", 10 + sk/5);
    return 1;
}

int harvest(object me)
{
    int sk;
    sk = me->query_skill("pure-energy");
    if ( sk < 50 ) return notify_fail("你的粹精心法不熟練，無法施展「九穰一秕」。 \n");
    if ( me->query_skill("force") < 50 ) return notify_fail("你的內功\心法不熟練，無法施展「九穰一秕」。 \n");
    if ( me->query("ap") < 80 ) return notify_fail("你的內勁不足，無法施展「九穰一秕」。\n");
    if ( me->query("mp") < 80 ) return notify_fail("你的魔力不足，無法施展「九穰一秕」。\n");
    if ( me->query_condition("frost_harvest") ) return notify_fail("你已經在施展「九穰一秕」。\n");

    message_vision(HIC "$N運用九穰一秕之法，全身淡淡寒氣飄逸，久久不散。 \n" NOR,me);

    me->receive_damage("ap",80);
    me->receive_damage("mp",80);
    me->improve_skill("force",1+ random(me->query_int()) );
    me->improve_skill("pure-energy",1+ random(me->query_int()/2) );
        me->apply_condition("frost_harvest", 10 + sk/7);
    me->start_busy(2);
    return 1;
}

int dust(object me)
{
    int sk;
    sk = me->query_skill("pure-energy");
    if ( sk < 70 ) return notify_fail("你的粹精心法不熟練，無法施展「塵垢淨盡」。 \n");
    if ( me->query_skill("force") < 70 ) return notify_fail("你的內功\心法不熟練，無法施展「塵垢淨盡」。 \n");
    if ( me->query("ap") < 120 ) return notify_fail("你的內勁不足，無法施展「塵垢淨盡」。\n");
    if ( me->query("mp") < 120 ) return notify_fail("你的魔力不足，無法施展「塵垢淨盡」。\n");
    if ( me->query_condition("frost_dust") ) return notify_fail("你已經在施展「塵垢淨盡」。\n");

    message_vision(HIB "$N運起塵垢淨盡之法，有種低沉而歷久不歇的隆隆聲，不斷從身上發出。 \n" NOR,me);

    me->receive_damage("ap",120);
    me->receive_damage("mp",120);
    me->improve_skill("force",1+ random(me->query_int()) );
    me->improve_skill("pure-energy",1+ random(me->query_int()/2) );
        me->apply_condition("frost_dust", 10 + sk/9);
    me->start_busy(2);
    return 1;
}

int valid_learn(object me)
{
    return 1;
}

int practice_skill(object me)
{
    return 1;
}


