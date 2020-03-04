#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
        int anti,damage;
        if( !duration )
        {
                tell_object(me,HIG"你身上的燒傷已經不痛了。\n"NOR);
                me->delete_temp("conditions/burn");
                return 0;
        } 
        else 
        {
                if(random(8+duration)<random(5))
                {
                        me->apply_condition("burn", duration);
                        return 1;
                }
//                anti=me->query_skill("anti_poison");
//                anti=100-anti+random(21);
//                damage=duration*anti/50;
                  damage=duration+random(5);
                tell_object(me,HIR"你身上的燒傷使你疼痛不已。\n"NOR);
                tell_room(environment(me),me->name()+"身上的燒傷因為接觸到空氣而疼痛難當。\n",({me}));
                me->set_temp("temp/death_type","[燒傷過度而死]"); 
                me->receive_damage("hp", 4+damage);
                me->receive_damage("ap", 3+damage);
                me->receive_damage("mp", 5+damage);
                me->add_block(1);
                if(duration>50) duration=50;
//                me->improve_skill("anti_poison", duration+random(me->query_con()));
//                me->set_temp("conditions/burn",duration - 1);
                me->apply_condition("burn", duration - 1);
        }
        return 1;
}
