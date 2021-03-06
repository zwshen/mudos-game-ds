// use.c

#include <skill.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
         string item, arg1;
          object target;
	
	seteuid(getuid());
        if(me->is_ghost()) return notify_fail("	你現在還是鬼魂吧\n");
	if( me->is_busy() )
		return notify_fail("( 你上一個動作還沒有完成﹐不能使用物品。)\n");

	if( !arg ) return notify_fail("指令格式﹕use <物品> [<參數>]\n");
	if( sscanf(arg, "%s %s", item, arg1)==2 )
	{
		target = present(item, me);
		if( !target ) target = present(item, environment(me));
		if( !target ) 
		{
			target = environment(me);
			arg1 = arg;
		}
	}
	else
	{
		target = present(arg, me);
		if( !target ) target = present(arg, environment(me));
		if( !target )
		{
			target = environment(me);
		}
	}
	
	if(!target) return 0;
	if(!arg1) arg1 = arg;
	if(wizardp(me) && me->query("env/debug")) write(" target = "+base_name(target)+" .. arg = "+arg1+"  ..\n");
	//if(target!=environment(me)) return notify_fail("這個 "+target->name()+" 並不能這麼使用。\n");
	return target->do_use(me,arg1);
}

int help (object me)
{
        write(@HELP
指令格式﹕use <道具名稱> [<參數>]或[<對象>]
 
使用物品, 必須是身上有的道具 或是 房間裡面有的道具.
 
HELP
        );
        return 1;
}
