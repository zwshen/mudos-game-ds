#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIR"金莎巧克力"NOR, ({"gin-sha chocolate","chocolate"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long", "市面各大超商皆有在賣的巧克力，口味十分之爽口。\n");
                set("unit", "個");
                set("value", 10000);
        }
}

void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        object me = this_player();
        if( !arg ) return notify_fail("你要吃什麼?\n");
        if( arg == "chocolate" )
        {
                if( me->is_busy() ) return notify_fail("忙碌中，請稍後！\n");
                me->set("hp",me->query("max_hp") );
                me->set("mp",me->query("max_mp") );
                me->set("ap",me->query("max_ap") );
                message_vision(HIW"$N吃下一個$n。\n", me, this_object() );
                tell_object(me, "幸福滿分，全身體力皆恢復了!!\n");
                if(random(2))
                {
                        tell_object(me, HIY"巧克力當中，夾帶的一張摸彩卷!!\n"NOR);
                        new(__DIR__"bliss-ticket")->move(me);
                } else tell_object(me, HIB"用力一咬，嘴巴破了，但都沒東西...\n"NOR);

        me->start_busy(1);
        call_out( (: destruct(this_object()) :), 1);

        return 1;
        } 
}

