#include <ansi.h>
inherit ITEM;
inherit F_PILL;

void create()
{
        set_name(HIW"萬靈"+HIC+"解"+HIR+"毒"+HIW+"丹"NOR,({"pill"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "個");
                set("value", 10);
        }
}
void init()
{
     add_action("do_eat","eat");
}

int do_eat(string arg)
{ 

         object me;
         int x;
        me=this_player();
        x = me->query_condition("poison");
    if ( x > 0)
    {
    tell_object(me,HIW"你感覺一陣涼爽, 看來毒性減弱不少\n"NOR);
    x = x - 1;
    }
    else
    {
     tell_object(me,HIW"你不需要服食這顆丹藥\n"NOR);
    }
    return 1;

}
