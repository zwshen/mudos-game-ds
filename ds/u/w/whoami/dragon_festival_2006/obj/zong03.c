
inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(YEL"陳皮牛肉粽"NOR, ({ "str zong zi", "zong", "zi" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "顆");
                set("value", 10);  
        }
}

void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        object env;
        string type,msg;
        if( !this_object() ) return 0;
        if(! env = environment(this_object())) return 0;
        if( this_player()->is_busy() )
                return notify_fail("你上一個動作還沒有完成。\n");
        if(this_player()->query("eat_strzong") )
                return notify_fail("你已經吃過陳皮牛肉粽了。\n");

        message_vision("$N大口大口的吃下一顆陳皮牛肉粽。\n",this_player() );
        switch(random(2)){
             case 0:        
              message_vision("$N的身體好像因為陳皮牛肉粽產生了一些變化...\n",this_player() );
              this_player()->add_temp("apply/str",5);
              this_player()->add_temp("eat_strzong",1);
              call_out("delay",1800,this_player() );     
              break;       
              default: 
              message_vision("$N大口大口的吃下一顆陳皮牛肉粽，突然間好像被啥東西噎到...\n",this_player() );    
               new(__DIR__"ticket")->move(this_player());
              destruct(this_object());
              break;
}

return 1;
}

void delay(object me)
{
        if(!me) return;
        tell_object(me,"陳皮牛肉粽帶來的效果好像從你身上消失了。\n" );
        me->add_temp("apply/str",-5);
        me->delete_temp("eat_strzong");
        destruct(this_object() );
}
