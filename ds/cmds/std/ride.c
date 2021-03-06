//ride.c
#include <ride.h>

inherit F_CLEAN_UP;

int do_ride(object me, object obj);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object ob;

	if(arg=="off")
	{
		if(!objectp(ob=me->query_temp("ride")))
			return notify_fail("  你並沒有騎任何的東西\n");
		//如果ride_off_action(me)傳回1表示順利下馬, 否則不能下馬.
		if(!ob->ride_off_action(me)) return 1;
		ob->move(environment(me));
		message_vision(" $N從"+ob->name()+"上跳了下來。\n",me);
		this_player()->delete_temp("ride");
		ob->delete_temp("riden");
		return 1;
	}
	
	if(objectp(ob=me->query_temp("ride")))
		return notify_fail(" 你現在正坐在"+ob->name()+"上\n");
		
        if(!arg) return notify_fail(" 你要騎什麼東西﹖\n");
        
        if( !objectp(ob = present(arg, environment(me))) )
		return notify_fail(" 你附近沒有這樣東西。\n");
		
        if(!ob->query("ridable") )
		return notify_fail(" 這東西不能騎。\n");
//	if(me->query_skill("ride",1) < 1)
//		return notify_fail("你沒學過這項技能喔!!!\n");
	if(!ob->ride_before_action(me)) return 1;
	return do_ride(me, ob);
}

int do_ride(object me, object ob)
{
	ob->set_weight(1);
	if(ob->move(me))
	{
		ob->set_temp("riden",1);
		if( ob->is_character() )
		{
			message_vision("$N往$n上面騎了上去!!\n", me, ob);
		}
		else
		{
			message_vision( "$N坐上$n。\n",me, ob );
		}
		ob->ride_after_action(me);
		me->set_temp("ride",ob);
		return 1;
	}
	//[Ride error]: Can't move ride object to This Player。
	return notify_fail(" 你負荷太重了, 爬不上"+ob->name()+"\n");
}

int help(object me)
{
	write(
@HELP
指令格式 :
		ride [生物|物品]	騎乘生物或物品
		ride off		不騎了
 
HELP
	);
    return 1;
}
 
