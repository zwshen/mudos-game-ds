// 
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	int anti,damage;
	if( !duration )
	{
		tell_object(me,HIR"你身上殘餘的熱毒毒性消失了。\n"NOR);
		me->delete_temp("conditions/super_poison");
		return 0;
	} else 
	{
		if(random(8+duration)<random(5))
		{
            		me->apply_condition("super_poison", duration);
			return 1;
		}
		anti=me->query_skill("anti_poison");
		anti=100-anti+random(500);
		damage=duration*anti/50;

    	if( !living(me) ){
    		message("vision",HIW + me->name() + "的身體突然抽動了一下！\n"NOR, environment(me), me);
    	}
   else {
      	if( me->query("hp") >= 1500)
              	tell_room(environment(me), YEL+me->name()+"突然只膝彎曲，身子慢慢垂下，口中發出似人似獸的荷荷之聲。\n" NOR, ({ me }));            
      	else if( me->query("hp") < 1500 && me->query("hp") >= 1000)
              	tell_room(environment(me), BLU+me->name()+"忽然滿面堆歡裂嘴嘻笑，更顯得詭異無倫。\n" NOR,  ({ me }));        
      	else if( me->query("hp") < 1000 && me->query("hp") >= 500)
              	tell_room(environment(me), HIB+me->name()+"此時神智更加糊塗，指東打西，亂吼亂咬。\n" NOR,({ me }));           
      	else    tell_room(environment(me), HIR+me->name()+"突然縮成一團，滾在地上不停地發顫。\n" NOR,({ me }));
   }
    tell_object(me, HIR "你忽然感到身體僵直，已經不聽使喚了。\n" NOR );
		me->set_temp("temp/death_type","[[1;31m五線蠱毒而死[0m]"); 
		me->receive_damage("hp", 10+damage*5);
		me->receive_damage("ap", 5+damage*3);
		me->receive_damage("mp", 5+damage*3);
		me->add_block(1);
		if(duration>50) duration=50;
		me->improve_skill("anti_poison", duration+random(me->query_con()));
		me->set_temp("conditions/poison",duration - 1);
		me->apply_condition("poison", duration - 1);
	}
	return 1;
}
