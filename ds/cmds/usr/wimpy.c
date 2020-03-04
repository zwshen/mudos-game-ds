// wimpy.c

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	int wmp;

	if( !arg ) {
		write("[wimpy]: 當你的「生命」低於 " + (int)me->query("wimpy") 
			+ "% 時就會自動嚐試逃跑。\n");
		return 1;
	}
	if( sscanf(arg, "%d", wmp)!=1 || wmp < 0 || wmp > 80)
		return help(me);

	me->set("wimpy", wmp);
	write("[wimpy]: 當你的「生命」低於 " + (int)me->query("wimpy") 
			+ "% 時就會自動嚐試逃跑。\n");
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式﹕ wimpy [<逃跑時「生命」的百分比>]

這個指令讓你設定當「生命」剩下百分之多少時( 0% ~ 80% )﹐要開始「轉進」。
HELP
	);
	return 1;
}

