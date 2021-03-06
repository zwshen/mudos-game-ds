//五線蠱毒(gu-poison)        sk 60  削減敵人 str & con & int & dex         (固定扣 sk/10) 
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
        int anti = me->query_skill("anti_poison"),
            damage = me->query_temp("shouyu-poison/gu-poison/effect");
        if( !duration )
        {
                tell_object(me,HIB"你身上殘餘的五線蠱毒毒性消失了。\n"NOR);
                me->delete_temp("conditions/gu-poison");
                me->add_temp("apply/str", me->query_temp("shouyu-poison/gu-poison/damage"));
                me->add_temp("apply/con", me->query_temp("shouyu-poison/gu-poison/damage"));
                me->add_temp("apply/int", me->query_temp("shouyu-poison/gu-poison/damage"));
                me->add_temp("apply/dex", me->query_temp("shouyu-poison/gu-poison/damage"));
                return 0;
        } else 
        {
                if(random(8+duration)<random(5))
                {
                        me->apply_condition("gu-poison", duration);
                        return 1;
                }
 //        if( !living(me) ) {
//                message("vision",HIW + me->name() + "瑟瑟發抖，全身結上一層薄薄的白霜。\n"NOR, environment(me), me);
//        }
//        else {
        if( duration < 5) 
           tell_room(environment(me), YEL+me->name()+"突然只膝彎曲，身子慢慢垂下，口中發出似人似獸的荷荷之聲。\n" NOR, ({ me }));            
        else if( duration < 15) 
                tell_room(environment(me), BLU+me->name()+"忽然滿面堆歡裂嘴嘻笑，更顯得詭異無倫。\n" NOR,  ({ me }));        
        else if( duration < 25)
                tell_room(environment(me), HIB+me->name()+"此時神智更加糊塗，指東打西，亂吼亂咬。\n" NOR,({ me }));           
        else    tell_room(environment(me), HIR+me->name()+"突然縮成一團，滾在地上不停地發顫。\n" NOR,({ me }));
        tell_object(me, HIR "你忽然感到身體僵直，已經不聽使喚了。\n" NOR );

//                }
                damage *= 10;
                damage -= random(anti*5);
                if( damage < 0 ) damage = 0;
                if( !me->query_temp("shouyu-poison/gu-poison/damage") ){
                me->set_temp("shouyu-poison/gu-poison/damage", damage);
                me->add_temp("apply/str", -damage);
                me->add_temp("apply/con", -damage);
                me->add_temp("apply/int", -damage);
                me->add_temp("apply/dex", -damage);
                }
                me->add_block(1);
                me->improve_skill("anti_poison", duration+random(me->query_con()));
                me->set_temp("conditions/gu-poison",duration - 1);
                me->apply_condition("gu-poison", duration - 1);
        }
        return 1;
}
