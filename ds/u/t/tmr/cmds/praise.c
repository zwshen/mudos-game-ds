//praise.c By tmr
 
#include <ansi.h>
 
inherit F_CLEAN_UP;
inherit SSERVER; 
 
int main(object me, string arg)
{
        object ob;
        int p,lv;

        seteuid(getuid(me));
        lv=me->query("level");
 
        if( lv < 10 )
                return notify_fail("你必須要升到十級，讚揚才會有效。\n");
        if( lv <= me->query("praised") )
                return notify_fail("你已經讚揚過了。\n");
        if(!arg) 
                return notify_fail("你要讚揚誰呢？\n");
        else
        {
                ob = present(arg, environment(me));
                if (!ob) ob = find_player(arg);
                if (!ob) return notify_fail("線上並沒有這個人耶\n");
        }
	shout(GRN +me->name()+"讚揚了"+ ob->name()+ GRN +"！！\n" NOR);
        write("ok.\n");
//        ob->add("popularity",(lv-9)*3); //聲望
//        me->set("praised", lv );
        return 1;       
}
int help(object me)
{
        write(@HELP
指令格式 :praise <對象名稱>
 
這個指令可以讓你用來讚揚別人，而別人會因為你的讚揚而提升聲望。

HELP
    );
    return 1;
}


