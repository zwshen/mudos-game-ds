// pwd.c
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
  {
   object ob;
        
	if( !arg ) {
	   me->set("hp",me->query("max_hp") );
	   me->set("mp",me->query("max_mp") );
	   me->set("ap",me->query("max_ap") );
		message_vision(HIY"$N喃喃唸道: 覺醒吧! 水之精靈.. 將香純的美酒, 注滿整個屍櫃..\n"NOR,me);
	   return 1;    }
	  else {
	    ob = present(arg,environment(me));
	    if (!ob) ob = find_living(arg);
	    if (!ob) return notify_fail("沒有這玩家或是生物。\n");
	    
	         ob->set("hp",ob->query("max_hp") );
	         ob->set("mp",ob->query("max_mp") );
                 ob->set("ap",ob->query("max_ap") );
 
		message_vision(HIW"$N的周圍出現了幾圈淡藍色的光圈, 生命恢復了不少。\n"NOR,ob);
	        return 1;    
	     }     
}

int help(object me)
{
write(@HELP
指令格式 : full
 這可以讓你恢復滿血及mp,ap        用法full <對象>
 
HELP
    );
    return 1;
}
