// secure.c

inherit F_CLEAN_UP;

int do_sec(object me, object obj,int flag);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
          object obj, *inv;
	int i;
         string item;

	if(!arg) return notify_fail("你要保存什麼東西﹖\n");
	
	if(arg=="all")
	{
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++) {
			do_sec(me, inv[i], 0);
		}
		write("你將身上所有物品設為保存狀態.\n");
		return 1;
	}

	if(arg=="all off")
	{
			inv = all_inventory(me);
			for(i=0; i<sizeof(inv); i++)
			{
				do_sec(me, inv[i], 1);
			}
			write("你將身上的所有物品的保存狀態解除!!\n");
			return 1;

	}
	
	if(sscanf(arg, "%s off", item )==1)
	{
		if( !objectp(obj = present(item, me)) )
			return notify_fail("你身上沒有這樣東西。\n");
		if( !obj->query("secured") )
			return notify_fail("此物並沒有設定保存狀態。\n");
		if( do_sec(me, obj, 1) )
		{
			write("你將"+obj->name()+"的保存狀態解除。\n");
			return 1;
		}
		else notify_fail("解除保存狀態失敗。\n");
	}
	
	if(!objectp(obj = present(arg, me)))
		return notify_fail("你身上沒有這樣東西。\n");
	if( obj->query("secured") )
			return notify_fail("此物已經是保存狀態了。\n");
	if(do_sec(me, obj, 0))
	{
		write("你將"+obj->name()+"設定為保存狀態。\n");
		return 1;
	}
	else notify_fail("設定保存狀態失敗。\n");
}

int do_sec(object me, object obj,int flag)
{
	if(flag)
	{
		if(obj->query("secured")) obj->delete("secured");
		return 1;
	}
	else
	{
		obj->set("secured",1);
		return 1;
	}
}

int help(object me)
{
	write(@HELP
指令格式 : secure <物品名稱> [off]
	   sec <物品名稱> [off]

這個指令可以讓你將你所攜帶的物品設定保護或是解除(off).
 
HELP
    );
    return 1;
}
 
