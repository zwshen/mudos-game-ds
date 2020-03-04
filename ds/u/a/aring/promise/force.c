 inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIW"Force機器"NOR, ({"force machine", "force"}));
        set_weight(1000);
        set("unit", "顆");
        set("long", @LONG一個超強力足球
LONG);
        set("value", 99999);

        setup();
}


void init() 
{          
 add_action("do_force","fo");
}

int do_force(string arg)
{
object me, ob;
        string cmd;

        if( me != this_player(1) ) return 0;

        if( !arg || sscanf(arg, "%s to %s", cmd) != 2 )
                return notify_fail("指令格式﹕force <某人> to <指令>\n");
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

強迫某人做某事, 但你的巫師等級必須比對方高, 而且必須是在同一個房間裡。
Help
        );

        return 1;
}


