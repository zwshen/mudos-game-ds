// follow.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;
	string arg1, who;
	if(!me) return 0;
	if( !arg ) return notify_fail("請打 help follow 查閱\指令用法。\n");
	if(sscanf(arg,"%s %s", arg1, who)==2)
	{
	 if(arg1!="stop") return notify_fail("請打 help follow 查閱\指令用法。\n");
	 if( !objectp(ob = present(who, environment(me))) )
		return notify_fail("這裡沒有 " + who + "。\n");
	 if(me != ob->query_leader()) return notify_fail(who + "現在並沒有跟隨你啊?\n");
	 ob->set_leader(0);
	 write("你決定不再讓"+ who +"跟隨你了。\n");
	 tell_object(ob,me->query("name")+"決定不再讓你跟著他行動了。\n");
	 return 1;
	}

	if( arg=="none")
		if( me->query_leader() ) {
			me->set_leader(0);
			write("Ok.\n");
			return 1;
		} else {
			write("你現在並沒有跟隨任何人。\n");
			return 1;
		}
        if( arg=="no" || arg=="NO" || arg =="No")
        {
         if(me->query_temp("no_follow")) 
          return notify_fail("你已經是[拒絕]跟隨狀態了。\n");
          me->set_temp("no_follow",1);
          write("你設定為[拒絕]跟隨狀態。\n");
          return 1;
        }
        
        if( arg=="yes" || arg=="YES" || arg=="Yes")
        {
         if(!me->query_temp("no_follow"))	
         return notify_fail("你已經是[接受]跟隨狀態了。\n");
         me->delete_temp("no_follow");
         write("你設定為[接受]跟隨狀態。\n");
         return 1;
	}

	if( !objectp(ob = present(arg, environment(me))) )
		return notify_fail("這裡沒有 " + arg + "。\n");

	if( !ob->is_character() )
		return notify_fail("什麼﹖跟隨...." + ob->name() + "。\n");

	if( userp(me) && ob->query_temp("no_follow") )  // add by Luky.
		return notify_fail(ob->query("name")+"拒絕和你一起行動。\n");

	if( ob==me )
		return notify_fail("跟隨自己﹖\n");

	me->set_leader(ob);
	message_vision("$N開始緊跟著$n。\n", me, ob);

	return 1;
}

int help (object me)
{
        write(@HELP
指令格式 : follow [<生物>|none|no|yes]
 
這個指令讓你能跟隨某人或生物。
如果輸入 follow none		則停止跟隨。
如果輸入 follow no		則設定拒絕被跟隨。
如果輸入 follow yes  		則設定允許被跟隨。
如果輸入 follow stop <id>	將跟隨者甩開。
HELP
);
        return 1;
}
