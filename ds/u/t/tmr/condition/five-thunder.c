// five-thunder (六卦追雷)

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
        int cost;
        if(!me) return 0;
        cost=20+random(5);
        me->receive_damage("hp", cost );
        me->receive_damage("ap", cost );
        me->receive_damage("mp", cost );
        me->apply_condition("five-thunder", duration - 1);
        message_vision(HIB "遠方的天空忽然響起一陣暴響，一道急雷劈上$N！！\n" NOR,me );
        message_vision("一陣陣焦臭味從$N身上傳出來......\n",me);
        if(me->query("hp") < cost)
        {
                me->die();
                duration =0;
        }
        if( !duration ) return 0;
        
        return CND_CONTINUE;
}

