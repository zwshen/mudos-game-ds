// give.c

inherit F_CLEAN_UP;

int do_give(object me, object obj, object who);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string target, item;
	object obj, who, *inv, obj2;
	int i, amount;

	if(!arg) return notify_fail("你要給誰什麼東西﹖\n");

	if( sscanf(arg, "%s to %s", item, target)==2
	|| sscanf(arg, "%s %s", target, item)==2 );
	else return notify_fail("你要給誰什麼東西﹖\n");

	if(!objectp(who = present(target, environment(me))) || !living(who))
		return notify_fail("這裡沒有這個人。\n");
	if(who == me) return notify_fail("自己給自己?? 別鬧了。\n");
	if( who->is_inactive() ) 
		return notify_fail("對方正在〔閒置〕中，沒空收你的東西。\n");
	if(sscanf(item, "%d %s", amount, item)==2)
	{
		if( !objectp(obj = present(item, me)) )	
			return notify_fail("你身上沒有這樣東西。\n");
		if( obj->query("no_drop") && !obj->query("can_give"))
			return notify_fail("這樣東西不能隨便給人。\n");
		if( !obj->query_amount() )	
			return notify_fail( obj->name() + "不能被分開給人。\n");
		if( amount < 1 )
			return notify_fail("東西的數量至少是一個。\n");
		if( amount > obj->query_amount() ) 
			return notify_fail("你沒有那麼多的" + obj->name() + "。\n");
                if( who->is_inactive() )
                        return notify_fail("你無法拿東西給正在閒置狀態的玩家。\n");
		else if( amount == (int)obj->query_amount() )
			return do_give(me, obj, who);
		else {
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
			if(!obj2->can_move(who) )
			{
				
				return notify_fail( who->name() + "拿不動"+obj2->name()+"。\n");
				
			}
			obj->set_amount( (int)obj->query_amount() - amount );
			return do_give(me, obj2, who);
		}
	}

	if(item=="all") {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++) {
			do_give(me, inv[i], who);
		}
		write("Ok.\n");
		return 1;
	}

	if(!objectp(obj = present(item, me)))
		return notify_fail("你身上沒有這樣東西。\n");
	return do_give(me, obj, who);
}

int do_give(object me, object obj, object who)
{
	string name,date;
	if( (obj->query("no_drop") ||  obj->query("no_give")) && !obj->query("can_give") && wiz_level(me) < 5)
		return notify_fail("這樣東西不能隨便給人。\n");
	if( obj->query_temp("riden") )
		return notify_fail("請下來(ride xx off)換人騎吧。\n");
        if(obj->query("equipped")) return notify_fail("請先解除裝備.\n");
	if(!obj->can_move(who))
		return notify_fail("對方似乎拿不動。\n");
	if( !interactive(who) )
	{
		if(who->accept_object(me, obj))
		{
			if(obj) obj->move(who);
			return 1;
		} else return 0;
	}
	if( obj->query("secured") )
			return notify_fail("請先用[secure 物品名 off]解除此物的保存狀態\n");
	if( obj->value() )
	{
		//destruct(obj);
		name=obj->short();
		if(obj->move(who))
		{
			message_vision("$N拿出" + name + "給$n。\n", me, who);
			if( me->is_fighting() ) me->add_block(1);
			return 1;
		}
		else
		{
			tell_object(who,me->name()+"想給你錢可是你拿不動。\n");
			return notify_fail(who->name()+"拿不動這麼多錢。\n");
		}
	} else
	{
		name=obj->name();
		if( obj->move(who) )
		{
                write(sprintf("你給%s一%s%s。\n", who->name(), obj->query("unit"),name));
			message("vision", sprintf("%s給你一%s%s。\n", me->name(),
				stringp(obj->query("unit"))? obj->query("unit") : "個", name), who );
			message("vision", sprintf("%s給%s一%s%s。\n", me->name(), who->name(),
				stringp(obj->query("unit"))? obj->query("unit") : "個", name), environment(me), ({me, who}) );
			if( wizardp(me) && !wizardp(who) && userp(who))
			{
				date=ctime(time());
				date=sprintf("%s",date[0..15]);
                                log_file( "static/give",sprintf("[%s] %s(%s) give %s(%s) %s[%s]\n",date,me->name(1),getuid(me),who->name(1),getuid(who),obj->name(1),base_name(obj)));
			}
			if( me->is_fighting() ) me->add_block(1);
			return 1;
		}
		else
		{

			tell_object(who,me->name()+"想給你"+name+"可是你拿不動。\n");
			return notify_fail(who->name()+"拿不動"+name+"。\n");
		}
	}
}
int help(object me)
{
write(@HELP
指令格式 : give <物品名稱> to <某人>
      或 : give <某人> <物品名稱>
 
這個指令可以讓你將某樣物品給別人, 當然, 首先你要擁有這樣物品.
 
HELP
    );
    return 1;
}
