// home.c

#include "/doc/help.h"

inherit F_CLEAN_UP;

int main(object me, string arg)
{
         string msg;
        if(!arg || arg==me->query("id"))
	{
	  if( file_size(user_path(geteuid(me)) + "workroom.c") <= 0 )
		return notify_fail("你沒有自己的工作室。\n");
	  if(!me->query_temp("invis"))
	  {
	    if( stringp(msg = me->query("msg_home")) ) message_vision(msg + "\n", me);
		else message_vision("$N摸摸鼻子, 回到自己的工作室開始用功\了。\n", me);
	  }
	  me->move(user_path(geteuid(me)) + "workroom");
	}
	else
	{
	  if( file_size("/u/"+arg[0..0]+"/"+arg + "/workroom.c") <= 0 )
		return notify_fail("沒有這個人的工作室。\n");
	  if(!me->query_temp("invis"))
	  {
	    if( stringp(msg = me->query("msg_home")) )  message_vision(msg + "\n", me);
		else message_vision("$N摸摸鼻子, 跑到"+arg+"的工作室去串門子了。\n", me);
	  }
	  me->move("/u/"+arg[0..0]+"/"+arg + "/workroom");
	}
	return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : home 或 home <巫師>

利用此一指令可直接回到自己的工作室。或到其他巫師的工作室,如果
你沒有自己的工作室,請到/u/下面建立自己的工作室
如果你有設定 'msg_home' property, 則在場的人都會看到那個訊息.
HELP
    );
    return 1;
}
