// kill.c

#include <ansi.h>
inherit F_CLEAN_UP;
inherit SSERVER;
void create() { seteuid(ROOT_UID); }

int main(object me, string arg)
{

	object obj,target;
	int k=0;
	if( !arg )
	{
		if(obj=me->query_temp("protecter"))
		{
			write("\n你正在保護"+obj->name(1)+"。\n");
			k++;
		}
		if(obj=me->query_temp("defender"))
		{
			write("\n"+obj->name(1)+"正在保護你。\n");
			k++;
		}
		if(!k) write("\n目前沒有人在保護你, 你也沒有保護任何人。\n");
		return 1;
	}
	
	if(!objectp(obj = present(arg, environment(me))))
		return notify_fail("這裡沒有這個人。\n");
	if( !me->visible(obj) )	return notify_fail("這裡沒有這個人。\n");
	if( !obj->is_character() || obj->is_corpse() )
		return notify_fail("看清楚一點﹐那並不是生物。\n");

 	if(!obj->is_fighting()) return notify_fail("對方並沒有戰鬥行為, 不需要保護。\n");
	if(obj->query_temp("defender")==me) return notify_fail("你已經在保護他了喔。\n");
	if(obj->query_temp("protecter")==me) return notify_fail("不用吧...對方正在保護你耶。\n");
	if(!userp(obj))
        {
		if(!obj->query("can_defend")) return notify_fail("對方拒絕你的保護。\n");
	}
	me->set_temp("protecter",obj);
	obj->set_temp("defender",me);
	message_vision("$N突然衝到$n的前面, 試著幫$n擋下所有的攻擊。\n",me,obj);
	target = offensive_target(obj);
	if(!target) return 1;
	if(target->can_fight(me))
	{
		target->kill_ob(me);
		me->kill_ob(target);
	}
	return 1;
}
int help(object me)
{
  write(@HELP
指令格式 : defend <人物>
 
這個指令讓你主動開始保護一個人物, 這個人物的對手會攻擊你, 直到你離開為止。

HELP
    );
    return 1;
}
 
