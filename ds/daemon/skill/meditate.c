//meditate.c 冥想之術 by Luky

#include <ansi.h>
inherit SKILL;
void delay(object me,int cost);
int exert(object me, object target, string arg)
{
    if(arg=="off" )
    {
        if(!me->query_temp("is_busy/meditate") ) return notify_fail("你現在並沒有冥思。\n");
        message_vision("\n"HIW"$N緩緩的睜開眼睛，看起來十分有精神。\n"NOR,me);
        me->delete_temp("is_busy/meditate");
        return 1;
    }
    if(me->is_ghost() ) return notify_fail("你還是鬼魂。\n");
    if(me->is_fighting() ) return notify_fail("你正在戰鬥，無法冥思。\n");
    if(me->is_busy() ) return notify_fail("(你的上一個動作還沒有完成。)\n");

    if(me->query("hp")<10 ) return notify_fail("你現在的生命力不夠，萬一走火入魔十分危險。\n");
    if(me->query("mp")>=me->query("max_mp") ) return notify_fail("你現在的精神狀況已經到達顛峰了。\n");

    if( sizeof(me->query_temp("is_busy")) ) return notify_fail("你現在正在忙。\n");
if(!me->skill_active( "meditate",(: call_other, __FILE__, "delay", me ,5:), 5))
        return notify_fail("你結束冥思的動作還沒完成。\n");
    message_vision("\n"HIW"$N席地而坐，心神歸一，開始進入冥思狀態。\n"NOR,me);
    me->set_temp("is_busy/meditate","你正在冥思不能移動。");
    me->start_busy(2);
    // me->start_call_out( (: call_other, __FILE__, "delay", me ,5:), 5);
    return 1;
}

void delay(object me,int cost)
{
    if(!me) return;
    if(!me->query_temp("is_busy/meditate") )
    {
        return;
    }

    if(me->query("mp")>=me->query("max_mp") || me->query("hp") <10)
    {
        message_vision("\n"HIW"$N緩緩的睜開眼睛，看起來十分有精神。\n"NOR,me);
        me->delete_temp("is_busy/meditate");
        return;
    }

    if(me->is_fighting())
    {
        message_vision(HIR"$N由於突然受到攻擊，走火入魔，而吐了一口鮮血。\n"NOR,me);
        me->receive_damage("hp",7);
        me->delete_temp("is_busy/meditate");
        me->start_busy(1);
        return;
    }


    if( random(me->query_skill("meditate",1)+20) < 10 || random(9)==0 )
    {
        message_vision("$N抽搐了一下，滿頭大汗，似乎有點走火入魔了。\n",me);
        me->receive_damage("hp",5);
    }
    else
    {
        me->receive_heal("mp", 3+(me->query_int()/2)+random(me->query_skill("meditate")));
        me->improve_skill("meditate",1 + random(1+me->query_int()/2));
    }
    //me->start_call_out( (: call_other, __FILE__, "delay", me ,cost:), 5);
me->skill_active( "meditate",(: call_other, __FILE__, "delay", me ,5:), 5);
}

int valid_learn(object me) { return 1; }
int practice_skill(object me) { return 1; }
