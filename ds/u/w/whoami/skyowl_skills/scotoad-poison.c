//三蜈五蟆煙(scotoad-poison) sk 80  削減敵人 攻擊力 & 防禦力 & 心靈抵抗力  (固定扣 sk/2) 
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
        int anti = me->query_skill("anti_poison"),
            damage = me->query_temp("shouyu-poison/scotoad-poison/effect");
        if( !duration )
        {
                tell_object(me,HIB"你身上殘餘的三蜈五蟆煙的毒性消失了。\n"NOR);
                me->delete_temp("conditions/scotoad-poison");
                me->add_temp("apply/damage", me->query_temp("shouyu-poison/scotoad-poison/damage"));
                me->add_temp("apply/armor", me->query_temp("shouyu-poison/scotoad-poison/damage"));
                me->add_temp("apply/shield", me->query_temp("shouyu-poison/scotoad-poison/damage"));
                return 0;
        } else 
        {
                if(random(8+duration)<random(5))
                {
                        me->apply_condition("scotoad-poison", duration);
                        return 1;
                }
 //        if( !living(me) ) {
//                message("vision",HIW + me->name() + "瑟瑟發抖，全身結上一層薄薄的白霜。\n"NOR, environment(me), me);
//        }
//        else {
                tell_object(me, HIY "一陣難以言喻的痛感自你麻木的四肢傳來………\n" NOR );
                tell_room(environment(me), HIG + me->name()+"臉上一陣青、一陣紫、一陣紅，活像個五色臉譜。\n" NOR,({me}));
//                }
                damage /= 2;
                damage -= random(anti/10);
                if( damage < 0 ) damage = 0;
                if( !me->query_temp("shouyu-poison/scotoad-poison/damage") ){
                me->set_temp("shouyu-poison/scotoad-poison/damage", damage);
                me->add_temp("apply/damage", -damage);
                me->add_temp("apply/armor", -damage);
                me->add_temp("apply/shield", -damage);
                }
                me->add_block(1);
                me->improve_skill("anti_poison", duration+random(me->query_con()));
                me->set_temp("conditions/scotoad-poison",duration - 1);
                me->apply_condition("scotoad-poison", duration - 1);
        }
        return 1;
}
