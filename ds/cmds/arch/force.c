// force.c

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string dest, cmd;
	object ob;

	if( me != this_player(1) ) return 0;

	if( !arg || sscanf(arg, "%s to %s", dest, cmd) != 2 )
		return notify_fail("指令格式﹕force <某人> to <指令>\n");
	if( !(ob = present(dest, environment(me))) )
	{
		if(wizhood(me) == "(admin)") ob = find_living(dest);
		if(!ob) return notify_fail("這裡沒有 " + dest + "。\n");
	}
	if( !living(ob) )
		return notify_fail("這個物件不能執行命令。\n");
	if(wiz_level(me) <= wiz_level(ob) && getuid(ob) != me->query("id") )
		return notify_fail("你沒有強制" + ob->name() + "執行指令的權力。\n");
	if( userp(ob) )
		log_file("FORCE_PLAYER", sprintf("[%s] %s forces %s to %s\n",  
			ctime(time()), geteuid(me), geteuid(ob), cmd));
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
