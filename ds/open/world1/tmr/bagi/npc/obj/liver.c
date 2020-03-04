#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW"肝臟"NOR, ({ "monster liver" ,"liver" }));
        set("long",@LONG
這是一片持續散發著寒氣的慘白色肝臟，似乎是著名八極禁地守護獸
「冷月」的內臟。你握在掌心裡，直覺得整隻手快被凍彊了，不知吃在嘴
裡會是怎樣滋味。
LONG
        );
        set("weight",50);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
        set("unit", "片");
        set("value",1);
        }
        setup();
}
void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        string type,msg;
        object ob,me,env;
        me = this_player();
        ob = this_object();
        if( !ob ) return 0;
        if( !ob->id(arg) ) return 0;
        if( !env = environment(ob)) return 0;
        if( env != me && !ob->query("no_get")) return 0;
        if( me->is_busy() )
                return notify_fail("你上一個動作還沒有完成。\n");
        if( ob->query("do_eat") )
                return notify_fail("你已經含在嘴裡了。\n");
        if(me->query_temp("super_used") )
                return notify_fail("你嘴裡正含著東西，不能再塞東西進去了。\n");
        /*
        me->receive_heal("hp", me->query("max_hp") - me->query("hp"));
        me->receive_heal("mp", me->query("max_mp") - me->query("mp"));
        me->receive_heal("ap", me->query("max_ap") - me->query("ap"));
        */

        if( me->is_fighting() ) me->start_busy(2);
        message_vision(HIW "$N從懷中拿出了一片似乎是動物內臟含在嘴裡..\n" NOR,me);
        if( me->query_skill("force") < 50 )
        {
                tell_object(me,CYN"你體內的真氣忽然大亂，你無法克制鎮壓！！\n" NOR);
                message_vision(HIR "$N一聲慘叫，急把嘴裡的東西吐掉，隨即吐出了幾口鮮血，臉上血色都沒了...\n" NOR,me);
                me->receive_damage("hp",me->query("max_hp")/2 );
                me->receive_damage("ap",me->query("max_ap")/2 );
                me->start_busy(2);
                destruct(ob);
                return 1;      
        } 

        if(!ob->query("super_used") && !me->query_temp("super_used") )
        {
                tell_object(me,
                HIG"你嘴裡的一陣寒氣和你的內勁交互混合，使得你身體的狀態改善許\多。\n" NOR
                );
                message_vision(HIW "$N嘿的一聲，雙眼射出一道如電似閃的精光！！\n" NOR,me);
                me->add_temp("apply/dex",2);
                me->add_temp("apply/str",2);
                me->add_temp("super_used",1);
                ob->set("super_used",1);
                ob->set("do_eat",1);
                ob->set("no_drop",1);
                ob->set("no_sac",1);
                ob->set("no_give",1);
                ob->set("no_sell",1);
                call_out("delay",600,me);     //附加屬性維持時間
        }
        return 1;
}

void delay(object me)
{
        if(!me) return;
        message_vision(CYN"$N咕嚕一聲，似乎吞下了什麼東西....\n" NOR,me);
        me->add_temp("apply/str",-2);
        me->add_temp("apply/dex",-2);
        me->delete_temp("super_used");
        destruct(this_object());
}
