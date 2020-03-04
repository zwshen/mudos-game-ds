#include <ansi.h>
        
inherit ITEM;

void create()
{
        set_name("碎骨血塊",({"crush-bone blood", "blood"}) );
        set_weight(80);
        set("long",@long
這是一塊由碎骨寨半獸人血液集結而成的血塊。
long
);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","塊");
                set("value",1);
        }
        setup();
}

void init() 
{
        add_action("summon_book", "eat");
}

int summon_book(string arg)
{
        object me;
        if(arg != "blood")
                return 0;

        me = this_player();
    if(!me) return 0;
    if(me->is_ghost()) return 0;
         if(me->query("str") < 5) return notify_fail("你力氣已經夠小，不需要再吃這個。\n");
 
        message_vision(CYN "$N忍淚\咬牙將$n吞下肚裡。\n"NOR ,me, this_object() );
        tell_object(me, HIG"你覺得手臂上肌肉劇痛難忍，好像力氣變小了。\n"NOR);
        me->set("str", me->query("str")-1);
        me->start_busy(1);
        me->save();
   
    destruct( this_object() );
    return 1;
}


