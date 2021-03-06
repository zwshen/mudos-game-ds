// use.c
#include <ansi.h>
#include <skill.h>

inherit SSERVER;

int main(object me, string arg)
{
	object target,weapon,arrow,creater;
	
	seteuid(getuid());
        
	if( !weapon=me->query_temp("weapon") ) return 0;
	if( weapon->query("skill_type")=="bow")
	{
	 if( !arrow=present("arrow", me ) ) return notify_fail(" 你沒有箭, 不能射擊。\n");
	}
	else
	{
	 if(!weapon->query("can_shoot"))
		return notify_fail("目前使用的武器無法使用射擊指令。\n");
	 if(weapon->query_temp("loaded") < 1 )
		return notify_fail("武器沒有彈藥, 你需要先裝填(reload)才能發射。\n");
	}
	
	if( me->is_busy() || me->is_block() )
		return notify_fail("( 你上一個動作還沒有完成﹐不能射擊。)\n");

	if(!arg) target = offensive_target(me);
	else target = present(arg, environment(me));
	if( !target ) return notify_fail("[shoot] error: 找不到目標。\n");

	if(!userp(me))
	{
		if(creater=me->query("creater"))
		{
		  if(!creater->can_fight(target)) return creater->can_fight(target);
		}
	}
 	
 	if(!me->can_fight(target)) return me->can_fight(target);

	if(weapon->do_shoot(me,target)) //武器可以設計特殊動作和敘述
	{
		return 1;	
	}
	
	return notify_fail("[shoot] error: 此武器無攻擊設定(do_shoot)。\n");
}

int help (object me)
{
        write(@HELP
指令格式﹕shoot [<對象>]
 
使用射擊武器, 必須是已經裝備的武器, 如果是槍(Gun)類的, 則必須要有彈藥.
 
HELP
        );
        return 1;
}
