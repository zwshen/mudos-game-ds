// astral_vision.c
#include <ansi.h>
inherit SKILL;
int cast(object me, object target)
{
    int skill,a,b;
    mapping learned;
    learned=me->query_learned();
if( !mapp(learned) ) learned = (["invis" : 1 ]);
    if(me->query_skill("invis",1)<1)
    {
        me->add_temp("apply/attack",-3);
        return notify_fail("你的技能不夠\n");
    }
    if( me->query_temp("invis") >0 )
        return notify_fail("你必須休息一下!!你身體還沒恢復呢。\n");

    if( (int)me->query("mp") < 5 )
        return notify_fail("你的魔力不夠。\n");

    skill = me->query_skill("invis")*me->query("env/spellpower");

    a=random(3)+learned["invis"];
    b=(int)me->query_skill("invis",1);
    if(random(100) >learned["invis"] )
    {
        me->add("magicexp",1);
        me->add("mp", -5);
        if(a<=b)
        {
            if(random(10) > 5)
            {
                write("你失敗了!!你從失敗的經驗學習﹗\n");
                learned["invis"]=a;
                return 1;
            }
        }
        write("你失敗了\n");
        return 1;
    }
    me-> add("mp",-skill/5);
    me->add("magicexp",skill/100);
    message_vision(HIB "$N閉著眼睛念了幾句咒語﹐施展「隱形」法術。\n" NOR, me);

    me->set_temp("invis", 1);
me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), skill);

    if( me->is_fighting() ) me->start_busy(1);

    return 1;
}

void remove_effect(object me)
{
    call_out("remove_eff2",30,me);
    tell_object(me, "你的隱形法術失效了。\n");
    me->delete_temp("invis");
}
void remove_eff2(object me)
{
    me->delete_temp("invis");
}
