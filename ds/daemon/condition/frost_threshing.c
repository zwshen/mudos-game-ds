// 寒澈派
// tmr 2007/03/03

#include <ansi.h> 
#include <condition.h>

inherit F_CLEAN_UP;
int update_condition(object me, int duration)
{
		// 玩家可能有quit過
		if( !me->query_temp("pure-energy/threshing") )
				return 0;

        if( !duration )
        {
			    message_vision(  "$N全身一陣酸麻，離蒿取粒的效果也消失了。\n" ,me);
                  me->add_temp("apply/damage",-me->query_temp("pure-energy/threshing"));
			    me->delete_temp("pure-energy/threshing");
                return 0;
        } 

        me->apply_condition("frost_threshing", duration-1 );
        return 1;
}

