#include <ansi.h> 
#include <condition.h>

inherit F_CLEAN_UP;
int update_condition(object me, int duration)
{
        // 玩家可能有quit過
        if(me->query_temp("constant-virtue") == 0)
                return 0;

        if( !duration )
        {
                tell_object(me, HIC"你靈台一陣波動，原來是你《常德不離》的力量消失了。\n"NOR);
                me->add_temp("apply/hit_ratio", -me->query_temp("constant-virtue"));
                me->delete_temp("constant-virtue");
                return 0;
        } 

        me->apply_condition("constant-virtue", duration-1 );
        return 1;
}


