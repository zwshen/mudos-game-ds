// finger.c

inherit F_CLEAN_UP;

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	object body;
	string msg,name,mud,t1,t2;
	if( !arg )
	{
		if(wizardp(me) || me->query("level")>24 ) me->start_more( FINGER_D->finger_all(1) );
		else me->start_more( FINGER_D->finger_all(0) );
	}
	 else if(arg == "-dn" )
	{
		if(wizardp(me) || me->query("level")>24 ) me->start_more( FINGER_D->finger_all(2) );
		else me->start_more( FINGER_D->finger_all(0) );
	}
	else
	{
		if(sscanf(arg, "%s %s", t1, t2) == 2 )	return notify_fail("你想查誰的資料﹖\n");
		if(wizardp(me) || arg==getuid(me)) msg= FINGER_D->finger_user(arg,1);
		else msg= FINGER_D->finger_user(arg,0);
		if( sscanf(arg, "%s@%s", name, mud)==2 ) arg=name;
		if( objectp(body = find_player(arg)) && me->visible(body) )
		{
		 if(me==body) msg += sprintf("%s目前正在從 %s 連線中。\n\n", body->name(1),query_ip_name(body) );
		 else if(wizardp(me) || me->query("level")>24 ) msg += sprintf("%s目前正在從 %s 連線中。\n\n", body->name(1),
			wiz_level(me) < wiz_level(body) ? "??.??.??.??" : query_ip_name(body) );
		 else msg += sprintf("%s目前正在連線中。\n\n", body->name(1),);
		}
		write(msg);
	}
	return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : finger [使用者姓名]  (巫師或高級玩家: finger -dn 查詢網域名稱)
 
這個指令, 如果沒有指定使用者姓明, 會顯示出所有正在線上玩家
的連線資料. 反之, 則可顯示有關某個玩家的連線, 權限等資料.

see also : who

HELP
    );
    return 1;
}
 
