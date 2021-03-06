//標準銀行(錢莊)人員繼承檔	- by Luky -
//
//	只要NPC繼承此檔, 即可利用以下方式變成銀行人員或錢莊老闆
//
// void init() 
// {
//   add_action("do_deposit","deposit");
//   add_action("do_withdraw","withdraw");
// }
// 
//  1. 這裡的 do_deposit,do_withdraw是固定的, 但是後面的指令字串可以自訂.
//  2. 未來不用做銀行. 交易都是直接由戶頭轉換電子幣.
//
#include <dbase.h>
#include <ansi.h>
inherit F_VENDOR;
string args;

void create()
{
	seteuid(getuid());
}

int do_deposit(string arg)
{
 object me;
 int money,world;
 
 me=this_player();
 if(!arg) return notify_fail("你要存多少錢？\n");
 if(sscanf(arg,"%d",money)!=1) return notify_fail("你想存多少金額(數字)？\n");
 if(money <1) return notify_fail("你想存多少金額(數字)？\n"); 
 if(!me->can_afford(money)) return notify_fail(this_object()->name()+"對你說: 您給我的錢數目不夠喔..。\n");
 world = me->money_type();
 if(!world) return notify_fail("你所在的空間並不是開放區域, 無法判斷貨幣種類。\n");
 if(world==3) return notify_fail("這個時代用不到銀行。\n");
 me->receive_money(-money);
 if(world==1)
 {
  if(!me->query("bank/past")) message_vision("$n幫$N開了一個新戶頭。\n",me,this_object());
  me->add("bank/past",money);
 }
 else
 {
  if(!me->query("bank/now")) message_vision("$n幫$N開了一個新戶頭。\n",me,this_object());
  me->add("bank/now",money);
 }

 message_vision("$N給了$n一些錢, $n立刻把錢存放到安全的地方。\n",me,this_object());
 
 me->save();
 return 1;	
}

int do_withdraw(string arg)
{
 object me;
 int money,world;
 
 me=this_player();
 if(!arg) return notify_fail("你想提出多少錢？\n");
 if(sscanf(arg,"%d",money)!=1) return notify_fail("你想提領多少金額(數字)？\n");
 if(money <1) return notify_fail("你想提領多少金額(數字)？\n");
 world = me->money_type();
 if(!world) return notify_fail("你所在的空間並不是開放區域, 無法判斷貨幣種類。\n");
 if(world==3) return notify_fail("這個時代沒有錢可以領。\n");
 if(world==1)
 {
  if(me->query("bank/past")<money) return notify_fail(this_object()->name()+"對你說: 大爺..你的戶頭裡沒這麼多錢喔。\n"); 
  message_vision("$N向$n提領了一些存款出來。\n",me,this_object());
  if(me->receive_money(money))  me->add("bank/past",-money);
 }
 else
 {
  if(me->query("bank/now")<money) return notify_fail(this_object()->name()+"對你說: 抱歉, 你的存款沒有這麼多。\n"); 
  message_vision("$N向$n提領了一些存款出來。\n",me,this_object());
  if(me->receive_money(money)) me->add("bank/now",-money);
 }

 me->save();
 return 1;	
}


int is_bankman()
{
	return 1;
}