// bandaged.c
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	if( !duration )
	{
		tell_object(me,HIW"§A¨­¤Wªº¶Ë¤f¦ü¥G°±¤î¬y¦å¤F¡C\n"NOR);
		me->delete_temp("conditions/blooding");
		return 0;
	} else 
	{
		if(random(2))
		{
			me->apply_condition("blooding", duration);
			return CND_CONTINUE;
		}
		message_vision(RED"$N¨­¤Wªº¶Ë¤f¬y¦å¤F¡C\n"NOR,me);
		if(userp(me))
		{
			me->set_temp("temp/death_type","[[1;31m¥¢¦å¹L¦h¦Ó¦º[0m]"); 
			me->receive_damage("hp", 15+duration*3);
		}
		else
		{
			me->set_temp("temp/death_type","[[1;31m¥¢¦å¹L¦h¦Ó¦º[0m]");
			me->receive_damage("hp", 10+random(40));
		}
		if(duration>30) duration=30;
		me->set_temp("conditions/blooding",duration - 1);
		me->apply_condition("blooding", duration - 1);
	}
	return CND_CONTINUE;
}
