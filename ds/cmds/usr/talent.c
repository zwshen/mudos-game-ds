// talent cmds - tmr 2008/07/31

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    object ob;
    mapping my;
    string str="";
    seteuid(getuid(me));

    if(!arg)
        ob = me;
    else if (wizardp(me)) {
        ob = present(arg, environment(me));
        if (!ob) ob = find_player(arg);
        if (!ob) ob = find_living(arg);
        if (!ob) return notify_fail("你要察看誰的等級狀態﹖\n");
    } else
        return notify_fail("只有巫師能察看別人的等級狀態。\n");

    my = ob->query_entire_dbase();

    str = sprintf("目前可用的天賦還有 %d 點。\n", my["gifts"]  );
   

    write(str);
    return 1;
}

int help(object me)
{
    write(@HELP
指令格式 : talent
           talent <對象名稱>                   (巫師專用)

          這個指令可以查詢你的天賦點數及天賦的選擇。

HELP
         );
    return 1;
}


