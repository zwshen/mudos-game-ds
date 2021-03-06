// drop.c

inherit F_CLEAN_UP;

int do_drop(object me, object obj);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object obj, *inv, obj2;
	int i, amount;
	string item;

	if(!arg) return notify_fail("你要丟棄什麼東西﹖\n");

	if(sscanf(arg, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, me)) )
			return notify_fail("你身上沒有這樣東西。\n");
		if( stringp(obj->query("no_drop")) )
			return notify_fail( (string)obj->query("no_drop") );
		if( obj->query("secured") )
			return notify_fail("請先用[secure 物品名 off]解除此物的保存狀態\n");
		if( !obj->query_amount() )
			return notify_fail( obj->name() + "不能被分開丟棄。\n");
		if( amount < 1 )
			return notify_fail("東西的數量至少是一個。\n");
		if( amount > obj->query_amount() )
			return notify_fail("你沒有那麼多的" + obj->name() + "。\n");
		else if( amount == (int)obj->query_amount() )
			return do_drop(me, obj);
		else {
			obj->set_amount( (int)obj->query_amount() - amount );
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
			return do_drop(me, obj2);
		}
	}

	if(arg=="all") {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++) {
			if( inv[i]->query("money_id") ) continue;
			do_drop(me, inv[i]);
		}
		write("Ok.\n");
		return 1;
	}

	if(!objectp(obj = present(arg, me)))
		return notify_fail("你身上沒有這樣東西。\n");
	return do_drop(me, obj);
}

int do_drop(object me, object obj)
{
	mixed no_drop;
	string temp;
	if( obj->query("secured") )
			return notify_fail("請先用[secure 物品名 off]解除此物的保存狀態\n");
	if( no_drop = obj->query("no_drop") )
		return notify_fail( stringp(no_drop) ? no_drop : "這樣東西不能隨意丟棄。\n");
        if(obj->query("equipped")) return notify_fail("請先解除裝備.\n");
	if(obj->query_temp("riden")) return notify_fail("請用 ride <座騎id> off.\n");
	if(environment(me)->query("no_drop")) return notify_fail("這裡沒有空間讓你丟東西。\n");
	if (obj->move(environment(me)))
	{
		if(wizardp(me) && userp(me) && sscanf(base_name(environment(me)),"/open/%s",temp)>=1 )
		{
			temp+="("+environment(me)->query("short")+")";
			log_file( "static/drop", "[" + geteuid(me) + "] drop a" + obj->short() + "("+base_name(obj)+")"+" at "+temp+" on " + ctime(time()) + "\n" );
			obj->set("wiz_only",1);
		}
		if( obj->is_character() )
			message_vision("$N將$n從背上放了下來。\n", me, obj);
		else {
			message_vision( sprintf("$N丟下一%s$n。\n",	obj->query("unit")),
				me, obj );
			if( !obj->query("value") && !obj->value() ) {
				write("因為這樣東西並不值錢﹐所以人們並不會注意到它的存在。\n");
				destruct(obj);
			}
		}
		return 1;
	}
	return 0;
}

int help(object me)
{
	write(@HELP
指令格式 : drop <物品名稱>
 
這個指令可以讓你丟下你所攜帶的物品.
 
HELP
    );
    return 1;
}
 
