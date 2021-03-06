// 寒澈派咒術 - 生死符 (life-death-symbol)

#include <ansi.h>
#define SYMBOL  __DIR__"frost-obj/life-death-symbol"
#define NAME "生死符"
#define SPELL_NAME "life-death-symbol"

inherit SSERVER;
inherit SKILL;

int clone_symbol(object me, object target);

int cast(object me, object target)
{
    int sk,cost;

    sk = me->query_spell(SPELL_NAME);
    cost = 5 + sk/20;
    if ( me->query("mp") < cost )
        return notify_fail("你的魔力不足，無法使用"NAME"。\n");
    if ( !objectp(target) )
        return notify_fail("你想要將什麼東西轉成生死符？\n");
    if ( !target->query("water_remaining")
            || target->query("no_get")
            || target->query("no_sac")
       )
        return notify_fail("這種東西無法轉成生死符。\n");

    message_vision(
        HBK "$N對著掌中的$n"HBK"施展生死符咒術...\n" NOR,me, target);

    me->receive_damage("mp",cost );
    call_out("clone_symbol",3,me,target);
    me->start_busy(2);
    return 1;
}

int clone_symbol(object me, object target)
{
    object symbol;
    string msg;
    int amount;
    if ( !me ) return 0;
    amount = 1 + me->query_spell(SPELL_NAME)/30;

    msg = HIW "不多時$N已將掌中$n化成片片薄薄的寒冰！！\n" NOR;
    // add harvest by tmr 2007/03/03
    if ( me->query_condition("frost_harvest") && me->query_skill("pure-energy")/2 > random(100) ) {
        msg = HIW "$N全身淡淡寒氣飄逸，" NOR + msg;
        amount += 2; // 多了2片，價格不變
    }

            symbol = new(SYMBOL);
            symbol->set_amount(amount);
            if ( !target || !symbol->move(me) ) {
                message_vision("但是$n什麼事也沒有發生。\n",me, target);
                me->improve_spell(SPELL_NAME, 2 + random(me->query_int()/2) );
                destruct(symbol);
                return 1;
            }

    message_vision( msg, me, target);
    me->improve_spell(SPELL_NAME, 2 + random(me->query_int()) );
    target->set("water_remaining", target->query("water_remaining") -1 );
    if ( target->query("water_remaining") < 1)
        destruct(target);
    return 1;
}

int improve_limite(object ob)
{
    return  40 + ob->query_int();
}


