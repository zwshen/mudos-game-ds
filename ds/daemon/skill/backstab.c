#include <ansi.h>
inherit SKILL;

void skill_improved(object me)
{
    int b;
    b=me->query_skill("backstab");
    if( b >= 85 && !me->query_skill("combat_backstab") )
        //	        if( b == 85 && !me->query("skill/backstab") )
    {
        tell_object(me, HIW+BEEP+"\n你領悟了新的技能 -- 戰鬥背刺(combat_backstab)！！\n"NOR);
        me->set_skill("combat_backstab", 1);
        //                me->set("skill/backstab", 1);
    }
    me->save();
}

int improve_limite(object ob)
{
    if(ob->query("level")<26) return 80;
    return 100;
}
