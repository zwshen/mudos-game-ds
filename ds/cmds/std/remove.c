// remove.c

#include <ansi.h>

inherit F_CLEAN_UP;

varargs int do_remove(object me, object ob,int silent);

int main(object me, string arg)
{
	object ob, *inv;
	int i;
	if(me->is_busy() || me->is_block())
		return notify_fail("你的上一個動作還沒完成。\n");
	if( !arg ) return notify_fail("你要脫掉什麼﹖\n");

	if(arg=="all") {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
			do_remove(me, inv[i]);
		write("Ok.\n");
		return 1;
	}

	if( !objectp(ob = present(arg, me)) )
		return notify_fail("你身上沒有這樣東西。\n");
	return do_remove(me, ob,0);
}

varargs int do_remove(object me, object ob,int silent)
{
	string str,gender;

	if( (string)ob->query("equipped")!="worn" )
		return notify_fail("你並沒有裝備"+ob->name()+"當作防具。\n");

	if( ob->unequip() )
	{
		if(!silent)
		{
			if( !stringp(str = ob->query("unequip_msg")) )
				switch(ob->query("armor_type")) {
					case "cloth":
					case "armor":
					case "surcoat":
					case "boots":
					case "pants":
					case "legging":
					case "mask":
					case "hands":
					case "neck":
					case "finger":
						str = YEL "$N脫下一"+ob->query("unit")+"$n。\n" NOR;
						break;
					case "bandage":
						str = YEL "$N將$n從傷口處拆了下來。\n" NOR;
						break;
					default:
						str = YEL "$N卸下一"+ob->query("unit")+"$n。\n" NOR;
				}
			if(me->query_temp("hide")+me->query_temp("invis")<1) message_vision(str, me, ob);
			else
			{	
				if(me->query("gender")=="女性") gender="妳";
				else gender="你";
				str=replace_string( str, "$N", gender);
				str=replace_string( str, "$n", ob->name());
				tell_object(me,str);
			}
		}
                // 重新計算屬性
                RACE_D( me->query("race") )->reset_attribute( me );
	if(me->is_fighting()) me->add_block(1);
		return 1;
	} else
		return 0;
}

int help(object me)
{
  write(@HELP
指令格式 : remove all | <物品名稱>
 
這個指令讓你脫掉身上某件防具.
 
HELP
    );
    return 1;
}
 
