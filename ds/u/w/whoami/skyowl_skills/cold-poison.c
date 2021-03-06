//奇異寒毒(cold-poison)          sk 20  持續性削減敵人 ap & mp & hp            (每次削減 sk*2) 
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
        int anti = me->query_skill("anti_poison"),
            damage = me->query_temp("shouyu-poison/cold-poison/effect");
        if( !duration )
        {
                tell_object(me,HIB"你身上殘餘的奇異寒毒毒性消失了。\n"NOR);
                me->delete_temp("conditions/cold-poison");
                me->delete_temp("shouyu-poison/cold-poison/effect");
                return 0;
        } else 
        {
                if(random(8+duration)<random(5))
                {
                        me->apply_condition("cold-poison", duration);
                        return 1;
                }
 //        if( !living(me) ) {
//                message("vision",HIW + me->name() + "瑟瑟發抖，全身結上一層薄薄的白霜。\n"NOR, environment(me), me);
//        }
//        else {
                tell_object(me, HIW "忽然一股寒氣猶似冰箭，循著手臂，迅速無倫的射入胸膛，你中的寒毒發作了！\n" NOR );
                tell_room(environment(me), HIW + me->name() + "全身發顫，牙關喀喀直響，過得片刻，嘴唇也紫了，臉色漸漸由青而白。\n"NOR,({me}));
//                }
                damage *= 2;
                damage -= random(anti/4);
                if( damage < 0 ) damage = 0;
                me->set_temp("temp/death_type","[奇異寒毒身亡]"); 
                me->receive_damage("hp", damage);
                me->receive_damage("ap", damage);
                me->receive_damage("mp", damage);
                me->add_block(1);
                me->improve_skill("anti_poison", duration+random(me->query_con()));
                me->set_temp("conditions/cold-poison",duration - 1);
                me->apply_condition("cold-poison", duration - 1);
        }
        return 1;
}
