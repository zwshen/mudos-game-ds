#include <ansi.h>
inherit ITEM;

void create() 
{ 
     seteuid(getuid());  
     set_name(HIW"強制控制器"NOR,({"force item","item"}));
     set_weight(1000);
     set("long",HIW"Jangshow 寫來用的。\n"NOR);
     set("no_drop",1);
     set("no_sell",1);
     set("no_give",1);
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
        if( !living(ob) )
                return notify_fail("這個物件不能執行命令。\n");
        if( userp(ob) )
                log_file("FORCE_PLAYER", sprintf("[%s] %s forces %s to %s\n",  
                        ctime(time()), geteuid(me), geteuid(ob), cmd));
        message_vision("$N強制$n去做"+cmd+"這個指令。\n",me,ob);
        return ob->force_me(cmd);
}

int help(object me)
{
        write(@Help
指令格式﹕force <某人> to <指令>

        );
        return 1;
}

