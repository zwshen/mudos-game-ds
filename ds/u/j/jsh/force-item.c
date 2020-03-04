#include <ansi.h>

inherit ITEM;

void create() 
{
     set_name(HIR"Force Item"NOR,({"force item","item"})); 
     set_weight(2000);
     set("no_sell",1);
     setup();
} 
void init()
{
     add_action("do_force","force"); 
}
int do_force(object me, string arg)
{
        string dest, cmd;
        object ob;

        if( me != this_player(1) ) return 0;

        if( !arg || sscanf(arg, "%s to %s", dest, cmd) != 2 )
                return notify_fail("指令格式﹕force <某人> to <指令>\n");
        if( !(ob = present(dest, environment(me))) )
                return notify_fail("這裡沒有 " + dest + "。\n");
        message_vision("$N強制$n去做"+cmd+"這個指令。\n",me,ob);
        return ob->force_me(cmd);
}


