#include <ansi.h>
inherit ITEM;
void create()
{
            set_name(HIB"大神不在時的管理器"NOR,({"for no adm item","item"}) );
            set("unit","個");
            set("long",HIC"這是 Jangshow 為了因為沒人管理的 DS 所寫的。\n"NOR); 

       setup();
}
void init ()
{  
     add_action("do_jail","jail");
}
int do_jail(string z)
{
        object me,ob;
        me = this_player();
        if( !z )
        return notify_fail("你想要關誰 ﹖\n");
        if(!(ob = present(z, environment(me)))
        || !ob->is_character() || ob->is_corpse() )
        return notify_fail("這裡沒有這個人。\n");
        if(ob==me)
        return notify_fail("別想不開!\n");
        message_vision(HIC"\t$n因為作錯了事，所以被$N關了起來。\n"NOR,me,users(),ob);
        call_out("gr",1,me,ob);
        return 1;
       }
void gr(object me,object ob)
{
if(!me) return; 
ob->set("out_of_power",1); 
ob->move("/open/always/ppl_jail"); 
ob->set("no_free",1);
ob->save();
return;
} 
int query_autoload() { return 1; }

