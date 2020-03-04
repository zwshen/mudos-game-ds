#include <ansi.h>
inherit ITEM;
void delay(object me);
void create()
{
        set_name(HIG "慧通神丹" NOR,({"int pill","pill"}) );
        set("long",
"這是由天梟高級煉丹士加以精良之設備烘焙而成, 自天梟分裂後, 全天梟所剩\n"
"屈指可數, 據說服下後可將智慧提高!\n"
);
        set_weight(700);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("value",2000);
                set("unit","顆");       
        }
        setup();
}

void init()
{
        add_action("do_eat","eat");
}

int do_eat(string arg)
{
        object env;
        string type,msg;
        if( !this_object() ) return 0;
        if( !this_object()->id(arg) ) return 0;
        if(! env = environment(this_object())) return 0;
        if(env !=this_player() && !this_object()->query("no_get")) return 0;
        if( this_player()->is_busy() )
                return notify_fail("你上一個動作還沒有完成。\n");
        if(this_object()->query("do_eat") )
                return notify_fail("你已服下了!。\n");

        message_vision("$N從懷裡拿出一顆神丹服下。\n",this_player() );
         tell_object(this_player(),HIY "你忽然覺得一股熱氣衝上天靈穴！！\n" NOR);
        this_player()->add_temp("apply/int",2); //附加int 
        this_object()->set("do_eat",1);
        this_object()->set("no_drop",1);
        this_object()->set("value",50000);
        this_object()->set("no_sac",1);
        this_object()->set("no_give",1);
        call_out("delay",200,this_player() );     //附加屬性維持時間

        return 1;
}

void delay(object me)
{
        if(!me) return;
          tell_object(me,"你忽覺天靈穴一陣寒氣衝上! 似乎神丹藥效已過。\n" );
        me->add_temp("apply/int",-2);
       destruct(this_object() );
}
