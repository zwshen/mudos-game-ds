// id.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int i, j;
	object obj, *inv;
	string *id,sec;

	if( !arg ) {
		inv = all_inventory(me);
		if( !sizeof(inv) )
			return notify_fail("你身上沒有任何東西。\n");
        write( "你(妳)身上攜帶物品的別稱如下(右方) :\n");
		for(i=0; i<sizeof(inv); i++)
		{
			if( !me->visible(inv[i]) ) continue;
			if(inv[i]->query("secured")) sec=" (保護中)"; else sec="";
			printf("%-20s = %O\n", inv[i]->name()+sec,inv[i]);
		}
		return 1;
	}

	if( arg=="here" && wizardp(me))
	{
		inv = all_inventory(environment(me));
		if( !sizeof(inv) )
			return notify_fail("這裡沒有任何東西。\n");
        	write( "在這個房間中, 生物及物品的(英文)名稱如下 :\n");
		for(i=0; i<sizeof(inv); i++)
		{
			if(!me->visible(inv[i]) ) continue;
			if(inv[i]->query("secured")) sec=" (保護中)"; else sec="";
			printf("%-20s = %O \n", inv[i]->name()+sec,inv[i]);
		}
		return 1;
	}
}
int help(object me)
{
write(@HELP
指令格式 : id
	   id [here]	巫師專用
 
這個指令可以讓你知道物品的英文名稱及名字. 只打 id 會顯示
你身上所攜帶物品的名稱. 

巫師可以用 'id here' 來顯示所有跟你在同一個環境裡的物件名稱.

 Also see: [search]

HELP
    );
    return 1;
}
 
