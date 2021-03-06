// ice-puppet 冰晶傀儡
// create by tmr 2007/01/04

#include <ansi.h>
#define PUPPET  __DIR__"frost-obj/ice-puppet"

inherit SSERVER;
inherit SKILL;

int clone_shield(object me,int sk,int inn);

int cast(object me, object target)
{
      int sk,inn,cost;

    sk = me->query_spell("ice-puppet");
    inn=me->query_int();
    cost=(sk*3+inn*2)/2;
    if( me->query("mp") < 200 || me->query("mp") < me->query("max_mp")/2 )
        return notify_fail("你的魔法不足，無法使用「冰晶傀儡」。\n");
    if( me->query("hp") < me->query("max_hp")/2 )
        return notify_fail("看來你受傷不輕，無法使用「冰晶傀儡」。\n");
    if(me->is_fighting() )
        return notify_fail("你正在戰鬥中。\n");

    message_vision(
          HIB "$N施展起冰晶傀儡之法，身旁的水氣降至冰點，慢慢地凝聚起來...\n" NOR
        ,me);

    call_out("clone_shield", 3,me,sk,inn);
    if( userp(me) )
        me->receive_damage("mp", cost );
    me->start_busy(2);
    return 1;
}

int clone_shield(object me,int sk,int inn)
{
    object pet,ob;
    if( !me ) return 0;
    if( me->is_fighting() )
        return notify_fail("什麼事也沒發生...\n");
    if( (sk*3+inn*2)/4 < random(70)
            || objectp(ob = present("ice-puppet", me) )  )
        //限制施法者只能擁有一個 pet。
        message_vision("結果什麼事也沒發生.....\n",me);
    else    {
        pet=new(PUPPET);
        if( !pet->move(me) ) {
            message_vision("結果什麼事也沒發生.....\n",me);
            me->improve_spell("ice-puppet",random(inn) + 2);
            return 1;
        }

        pet->update_pet( me );
        message_vision(HIW "一塊維妙維肖的冰晶傀儡出現在$N手裡，散發著絲絲寒氣。\n" NOR,me);
        me->improve_spell("ice-puppet", random(inn) + 2);
    }
    return 1;
}

int improve_limite(object ob)
{
    if(ob->query("int") < 60) return 90;

    return 100;
}


