#include <ansi.h>
inherit SKILL;
inherit SSERVER;

int exert(object me, object target, string arg)
{
        int sk, bonus;

           if(me->query_condition("buddha-body-cd") || me->query_condition("buddha-body-clear"))
                    return notify_fail("你身體狀況還沒有恢復，還無法使用「肉身成佛」\n"); 
            if(me->query_temp("buddha-body") )
                      return notify_fail("你身體狀況還沒有恢復，還無法使用「肉身成佛」\n"); 

        if(me->query("hp") < 300 )
                return notify_fail("你的生命值不夠，無法使用「肉身成佛」。\n"); 
        if(me->query("mp") < 300 )
                return notify_fail("你的魔法值不夠，無法使用「肉身成佛」。\n"); 
        if(me->query("ap") < 300 )
                return notify_fail("你的內勁值不夠，無法使用「肉身成佛」。\n"); 
        
        sk = me->query_skill("buddha-body");
        if( me->query_skill("buddha-skill") < 80 )
                return notify_fail("你的「如來九式」修為還不足夠，無法使用。\n");
        if(sk<33)
                return notify_fail("你的「肉身成佛」修為還不足夠，無法使用。\n");

        bonus = sk/33;

        me->set_temp("buddha-body", bonus);
        me->add_temp("apply/sou",bonus);
        me->add_temp("apply/wit",bonus);

        me->set("hp",50);
        me->set("ap",50);
        me->set("mp",50);
        me->set_temp("fly",1);  // 會飛

        message_vision(
                        HIY "只見$N七孔綻放七色虹光，天地間充滿奇異的香味！！\n"
                        + HIC "$N以武入佛，證入自性，一切從自性流露而出...\n"
                        + HIM "$N面泛微笑，肉身變的若有似無，看不清楚也摸不著，就地肉身成佛！！\n" NOR, 
        me);
        
        if( me->query_tec()>10 ) {
                // 有效時間，最長13分鐘
                 me->apply_condition("buddha-body-clear", 4*13); 
                // 冷卻時間，最短為5分鐘
                 me->apply_condition("buddha-body-cd", 5); 
        } else {
                // 3 + sou
                 me->apply_condition("buddha-body-clear", 4*(me->query_tec()+3)); 
                // 15 - sou
                 me->apply_condition("buddha-body-cd", 4*(15-me->query_tec())); 
        }
        return 1;
}

int improve_limite(object ob)
{
        return ob->query_con() + 60;
}

// add by acme 2007.01.09
int receive_damage_buffer_effect(string type, int damage, object me, object who)
{
    if( !objectp(me) || !objectp(who) ) return damage;
    if(me == who) return damage;
      if( type == "hp" && damage > 10) {
        if( me->query_temp("buddha-body") ) {
            int damage_reflex = damage * (me->query_skill("buddha-body") * 20 / 100) / 100;
            int damage_cancel = damage * (me->query_skill("buddha-body") * 30 / 100) / 100;

            damage = damage - damage_cancel;
             if(damage_reflex<1) damage_reflex = 1;

            message_vision(HIW"$N「肉身成佛」抵消了傷害並反射給$n。\n"NOR, me, who);

            // npc 最後才受攻擊
            if( damage_reflex > 0 )
                who->receive_damage(type, damage_reflex, me);
        }
    }
    return damage <= 0 ? 0: damage;
}

