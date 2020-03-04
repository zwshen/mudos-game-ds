// hp cmds
 
#include <ansi.h>
 
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object ob;
        string *club,id;

        if(!arg) return notify_fail("你要向誰申請入幫派﹖\n");
        ob = present(arg, environment(me));
	if(!ob || ob==me ) return notify_fail("這裡沒有這個人。\n");
	if(!wizardp(me))
	{
		if( !userp(ob) || wizardp(ob) ) return notify_fail("只對玩家申請幫派。\n");
	
		club = CLUB_D->find_player_club(getuid(me));
		if(sizeof(club)>1)  return notify_fail("你已經加入"+club[0]+"了。\n");
		club = CLUB_D->find_player_club(getuid(ob));
		if( sizeof(club)<1 ) return notify_fail("對方似乎並沒有參加幫會。\n");
	}
	id = ob->query("id");
	if(me->query_temp("joinclub") == id) return notify_fail("你已經申請過了, 對方正在考慮中。\n");
	message_vision("$N正式向$n提出加入幫會的要求。\n",me,ob);
	tell_object(ob,"如果你同意對方加入, 請用 accept "+me->query("id")+" 指令收他入幫。\n");
	me->set_temp("joinclub",id);
	return 1;
}
                          
int help(object me)
{
        write(@HELP
指令格式 : 
           joinclub <對象名稱> 
           
這個指令可以請求對方收你入幫會。

see also : score
HELP
    );
    return 1;
}

