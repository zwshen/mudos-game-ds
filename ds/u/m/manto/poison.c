// bandaged.c
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	int anti,damage;
	if( !duration )
	{
		tell_object(me,HIW"你身上殘餘的毒性消失了。\n"NOR);
		me->delete_temp("conditions/poison");
		return 0;
	} else 
	{
		if(random(8+duration)<random(5))
		{
            		me->apply_condition("poison", duration);
			return 1;
		}
		anti=me->query_skill("anti_poison");
		anti=100-anti+random(21);
		damage=duration*anti/50;
		tell_object(me,HIC"你身上的毒發作了。\n"NOR);
    		tell_room(environment(me),me->name()+"突然臉色發紫..露出很痛苦的樣子。\n",({me}));
		me->set_temp("temp/death_type","[[1;31m毒發身亡[0m]"); 
		me->receive_damage("hp", 10+damage*2);
		me->receive_damage("ap", 5+damage);
		me->receive_damage("mp", 5+damage);
		me->add_block(1);
		if(duration>50) duration=50;
		me->improve_skill("anti_poison", duration+random(me->query_con()));
		me->set_temp("conditions/poison",duration - 1);
		me->apply_condition("poison", duration - 1);
	}
	return 1;
}
