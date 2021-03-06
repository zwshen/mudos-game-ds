/*	File : "/std/room/club_bank.c		*
 *	Author : -Alickyuen@DS-			*
 *	Desc : 幫會專屬銀行,存放幫派存款	*
 *	Last Modify : 20-11-2001		*/

#include <dbase.h>
#include <ansi2.h>

inherit ROOM;

mapping info;

void init()
{
	add_action("do_deposit", "deposit");
	add_action("do_transfer", "transfer");
	add_action("do_withdraw", "withdraw");
	add_action("clear_log", "clear");
	add_action("do_list", "list");
}

int clear_log(string arg)
{
	object me;

	me = this_player();

	info = CLUB_D->query_member_info(query("club_id") ,getuid(me));

	if( !wizardp(me) && info["level"] < query("club_level") )
		return notify_fail("你的幫會等級不夠。\n");

	if( !arg )
		return notify_fail("你要清除什麼記錄(deposit, withdraw)？\n");

	if( arg != "withdraw" && arg != "deposit" ) 
		return notify_fail("你要清除什麼記錄(deposit, withdraw)？\n");

	BANK_D->clear_data(this_player()->query("id"), query("club_id"), arg);

	this_object()->create();

	return 1;
}

int do_deposit(string arg)
{
	object me;
	string name;
	int money,world;
 
	me=this_player();

	name = geteuid(me);

	if(!arg) return notify_fail("你要存多少錢？\n");

	if(sscanf(arg,"%d",money)!=1) return notify_fail("你想存多少金額(數字)？\n");

        if(money < 1000) return notify_fail("每次最少要存1000元。\n"); 

	if(!me->can_afford(money)) return notify_fail("你沒有這麼多的錢在身上。\n");

	world = me->money_type();

	BANK_D->do_save(query("club_id"), world, money, name, "deposit");

	me->receive_money(-money);

	message_vision("$N把一些錢存放到幫會銀行的戶口裡去。\n",me);
 
	me->save();

	this_object()->create();

	return 1;	
}

int do_withdraw(string arg)
{
	object me;
	string name;
	int money,world;
 
	me=this_player();

	name = geteuid(me);
	info = CLUB_D->query_member_info(query("club_id") ,getuid(me));

	if( !wizardp(me) && info["level"] < query("club_level") )
		return notify_fail("你的幫會等級不夠。\n");

	if(!arg) return notify_fail("你要提取多少錢？\n");

	if(sscanf(arg,"%d",money)!=1) return notify_fail("你想提取多少金額(數字)？\n");

	if(money <1) return notify_fail("你想存多少金額(數字)？\n"); 

	world = me->money_type();

	if( !BANK_D->do_save(query("club_id"), world, -money, name, "withdraw") )
		return notify_fail(HIR"沒有這麼多存款可以提取！\n"NOR);

	me->receive_money(money);

	message_vision("$N從幫會銀行的戶口裡提取了一些錢。\n",me);
 
	me->save();

	this_object()->create();

	return 1;	
}

int do_transfer(string arg)
{
	object me;
	string name, type;
	int money,world;
 
	me=this_player();

	name = geteuid(me);

	if(!arg) return notify_fail("指令格式：transfer <數量> of <past|now|future>\n");

	if(sscanf(arg,"%d of %s", money, type)!=2) return notify_fail("指令格式：transfer <數量> of <past|now|future>\n");

	if(money <20) return notify_fail("你想存多少金額(最少20元)？\n"); 

	if(me->query("bank/"+type) < money) return notify_fail("你沒有這麼多的錢在你的私人戶口中。\n");

	switch(type)
	{
		case "past":
			world = 1;
		break;
		case "now":
			world = 2;
		break;
		case"future" :
			world = 3;
		break;
		default:
			return notify_fail("沒有這個時空存在。\n");
		break;
	}

        money = (money * 99 / 100);

        BANK_D->do_save(query("club_id"), world, money, name, "deposit");

        me->add("bank/"+type, -money);

        tell_object(me, HIW"轉帳扣掉１％的手續費。\n"NOR);

        message_vision("$N把一些錢轉帳到幫會銀行的戶口裡去。\n",me);
 
        me->save();

        this_object()->create();


	return 1;	
}

int do_list()
{
	string list;

	list = BANK_D->sort_list();

	if( !list ) return notify_fail("系統出現問題，請用 report 指令回報。\n");

	this_player()->start_more(list);

	return 1;
}
