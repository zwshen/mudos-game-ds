#include <ansi.h>

int update_condition(object me, int duration)
{
        if( duration < 1 ) return 0;

        me->receive_damage("hp", 1);
          me->improve_skill("strong-body", 1 + random(me->query_con()));
        message_vision(CYN"$N嘶啞著嗓子咳了兩聲，然後又連續咳了好一陣，看來是病了不輕。\n" NOR,me);

        me->apply_condition("ill_kesou", duration -1);

        return 1;
}

