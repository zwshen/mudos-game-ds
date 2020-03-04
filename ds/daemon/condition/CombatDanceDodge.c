#include <ansi.h> 

int update_condition(object me, int duration)
{
    if( me->query_temp("CombatDanceDodge") == 0 ) return 0;

    if( duration < 1 ) {
        tell_object(me,"你感覺戰舞給予你的迴避能力已經消失了•\n");
        me->add_temp("apply/dodge", -me->query_temp("CombatDanceDodge"));
        me->delete_temp("CombatDanceDodge");
        return 0;
    } 

    me->apply_condition("CombatDanceDodge", duration-1 );
    return 1;
}
