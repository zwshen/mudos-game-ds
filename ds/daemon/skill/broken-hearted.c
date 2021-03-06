// Tmr 2007/04/14
// 柔腸一寸愁千縷 (broken-hearted)      - 進階技能
        
#include <ansi.h>
#define SKILL_NAME "柔腸一寸愁千縷\"
inherit SKILL;
inherit SSERVER;

void clear(object me);
                         
int exert(object me, object target, string arg)
{
    int damage,effect;
    int sk = me->query_skill("broken-hearted");
    if(!target) target = offensive_target(me);  // 敵人
    if( !target )
        return notify_fail("你要對誰使用？\n");
    if(me->query("ap") < 150)
                return notify_fail("你的內勁不夠使出"+SKILL_NAME+ "\n");
    if(!me->is_fighting(target) )
                return notify_fail("你得在戰鬥中才能使用"+SKILL_NAME + "\n");
    if(me->query_skill("seven-love") < 90)
        return notify_fail("使用"+SKILL_NAME+"需要先精通七夕情意。\n");
    if(me->query_skill("thousand-hair") < 90)
        return notify_fail("使用"+SKILL_NAME+"需要先精通三千煩惱絲。\n");
    if( me->query_temp("BROKEN_HEARTED_DAMAGE") && userp(me) )
                return notify_fail("你短時間內無法再使用"+SKILL_NAME+"。\n");

    damage = me->query_damage() * 5/2; // 250%
    damage -= target->query_armor() + random(target->query_armor());
    damage = COMBAT_D->Merits_damage(me, target, damage, "bio");
    
    message_vision(MAG "\n$N發動「柔腸一寸愁千縷\」，激起內心深處的一股愁思...\n" NOR,me,target);
    message_vision(HIM "這股愁思微不可察，但轉瞬間龐雜而悲愴，將$n"HIM"團團包圍住！\n"NOR,me,target);

    // 攻擊命中
    if( damage > 0 &&
            ( random(sk*2) > COMBAT_D->attack_factor(me, "whip")*10/15
            || random(sk*2) > -COMBAT_D->dodge_factor(target,"dodge") ) ) {
         message_vision(HIR "$n"HIR"無法承受住這股柔腸千縷\的愁思，在身心上造成無法挽救的傷害！！[" + damage +"]\n"
                       NOR,me,target);
        target->receive_damage("hp", damage, me);
                // 愁思有busy的效果
                if( !userp(me) || random(100) < 30 + sk/2) {
                message_vision( HIB "\t愁思仍然縈繞$n"HIB"的心頭上，$n"HIB"不禁怔怔地流起淚\來。\n"NOR,me,target);
                        effect = 1 + sk/45;
                target->start_busy(effect);
                } else {
                target->start_busy(1);
                }
        me->start_busy(1);
        me->receive_damage("ap", 80, me);
        me->improve_skill("broken-hearted", 1 + random(me->query_con()) );
    } else {
            message_vision( CYN ""+target->query("name")+CYN"在非常緊急的情況下，硬是將自已脫離這股愁思的影響。\n" NOR,target,me);
            me->start_busy(2);
    }
    me->set_temp("BROKEN_HEARTED_DAMAGE",1);
        if( (me->query_bar()+me->query_tec()) <= 12 )
                call_out("clear", 20-(me->query_bar()+me->query_tec()) , me);
        else
                call_out("clear", 8 , me);


    return 1;
}

void clear(object me)
{
    if(!me) return;
            tell_object(me,"你可以再使用"+SKILL_NAME+"了。\n");
    me->delete_temp("BROKEN_HEARTED_DAMAGE");
}

int improve_limite(object ob)
{
      return 100;
}


