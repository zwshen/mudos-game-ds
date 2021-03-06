// halt.c

#include "/doc/help.h"
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object *obj;
	int i;
	if(wiz_level(me) < 5)
	{
		if( !me->is_fighting() ) return notify_fail("你現在並沒有在戰鬥。\n");
		me->remove_all_killer();
		message_vision("$N用巫師的神力停止了這場打鬥。\n", me);
		write("Ok.\n");
		return 1;
	} else
	{
		obj=all_inventory(environment(me));
		for(i=0;i<sizeof(obj);i++)
		{
			obj[i]->remove_all_killer();
		}
		message_vision("$N用大神的力量停止了這裡所有的打鬥。\n", me);
		return 1;
	}
}

int help(object me)
{
   write(@HELP
指令格式: halt

可以停止所有與你(妳)有關的戰鬥。
HELP
   );
   return 1;
}
