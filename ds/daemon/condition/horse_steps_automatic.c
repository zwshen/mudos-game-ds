// horse_steps_automatic
// Tmr 2006/06/06

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
        if(!me) return 0;
        if(me->query("ap") < 50 ) return 0;
        if( me->query_temp("exert_mark/bagi-power") >= 90 ) return 0;
        me->receive_damage("ap", 15 );
        me->add_temp("exert_mark/bagi-power", 10);
        me->apply_condition("horse_steps_automatic", duration - 1);
        message_vision(CYN "$N"CYN"全身的氣勁自動自發地旋轉、穿扭般在體內循環不息！！\n" NOR,me );
        if( duration < 1 ) return 0;
        return CND_CONTINUE;
}


