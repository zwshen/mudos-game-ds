// mkdir.c

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	string dir;

	if(!arg) return help(me);

	dir = resolve_path(me->query("cwd"), arg);

	seteuid(geteuid(me));
	if( mkdir(dir) )
		write("Ok.\n");
	else
		write("你沒有在這裡建子目錄的權利。\n");
	return 1;	
}

int help(object me)
{
	write(@HELP
指令格式 : mkdir <子目錄名>

建立一個子目錄。
HELP
	);
	return 1;
}
