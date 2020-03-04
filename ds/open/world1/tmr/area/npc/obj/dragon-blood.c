#include <ansi.h>
inherit ITEM;


void delay(object me);

void create()
{
        set_name(HIM "點液血塊" NOR,({"dab-aqua blood","blood"}) );
        set("long",
"這是一塊由「狡龍  點液」血所凝聚而成的血塊，約略有半個手掌大小，\n"
"聽說其血有活腦的效用，由於「狡龍　點液」少有，能取其血者更是少之又少\n"
"，真正的用處，也沒多人知道。\n"
);
        set_weight(1000);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("value",2000);
                set("unit","塊");       
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
                return notify_fail("你已含在嘴裡了。\n");

        message_vision("$N從懷裡拿出一塊泛著紅光的血塊含在口中。\n",this_player() );
         tell_object(this_player(),HIY "你忽然覺得你的腦子靈活了許\多！！\n" NOR);

        this_player()->add_temp("apply/int",4); //附加int 
        this_object()->set("do_eat",1);
        this_object()->set("no_drop",1);
        this_object()->set("value",0);
        this_object()->set("no_sac",1);
        this_object()->set("no_give",1);
        call_out("delay",20,this_player() );     //附加屬性維持時間

        return 1;
}

void delay(object me)
{
        if(!me) return;
          tell_object(me,"隨著你口中的點液血塊漸漸融化，你的悟性慢慢地回復了。\n" );
        me->add_temp("apply/int",-4);
        me->receive_heal("hp",200);
          tell_object(me,HIY "你覺得你的生命值恢復了許\多。\n"NOR);
       destruct(this_object() );
}
