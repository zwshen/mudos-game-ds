#include <ansi.h>
#include <path.h>
//inherit F_CLEAN_UP;
#include <dbase.h>
#include <ansi.h>
inherit ITEM;
#define STOREDROOM LUKY+"pearl/temp/auto"
object stroom;
void create()
{
object ob, obj;
seteuid(getuid());
set_name("自動販賣機",({"automat"}));
set("unit", "台");
set("incoin",0);
set("long",@LONG
這是一台自動販賣機。上面有幾個按鈕... (使用方法請打help automat)

 0.退幣  1. 純喫茶(300元)  2. 缺貨  3. 缺貨

LONG
);
set("no_sac", 1);
set("no_get", 1);
set_max_encumbrance(9999999);
setup();
}


void init()
{
add_action("do_vendor_list","list");
add_action("do_insert","insert");
add_action("do_press","press");
}

int do_vendor_list(string arg)
{
object *goods,stroom;
mixed amount;
string list, *name;
int i,cost,level,maxlv;
load_object(STOREDROOM);
stroom=find_object(STOREDROOM);
goods = all_inventory(stroom);
list = "你可以選擇下列這些物品:           購買數量          價錢 \n";
list += "==========================================================\n";
for(i=0; i<sizeof(goods); i++)
 {
  list += sprintf("%d %-22s ﹕        %7d         %7d   \n",
  (i+1),goods[i]->short(),goods[i]->query("amount"),goods[i]->query("value")
  );
 } 
write("[販賣機裡面還有 "+query("incoin")+" 枚銅幣]\n\n");
write(list);
return 1;
}

int do_insert(string arg)
{
object automat,me;
int coins;
if(!arg) return notify_fail("格式: insert <數字> \n");
if(sscanf(arg, "%d", coins)==1)
 {
  automat=this_object();
  me=this_player();
  if(me->query("coin")<coins) return notify_fail("你身上沒有這麼多銅幣\n");
  if(automat->query("incoin")>100000) return notify_fail("販賣機裝不下更多錢了\n");
  add("incoin",coins);
  me->add("coin",-coins);
  message_vision("$N從口袋掏出了"+coins+"個銅板投到自動販賣機裡面\n",this_player());
  return 1;
 }
 return notify_fail("格式: insert <數字> \n");
}

int do_press(string arg)
{
 object *goods,box,ob,obj,me;
 string str,file;
 int button, cost, amount, i;
 me=this_player();
 box=this_object();
 load_object(STOREDROOM);
 stroom=find_object(STOREDROOM);
 goods = all_inventory(stroom);
 if(!arg) return notify_fail("要按什麼按鈕? \n格式: press <數字> \n");
 if(sscanf(arg, "%d", button)==1)
 {
  if(button==0) 
  {
   if(query("incoin")>0)
   {
    obj=new("/obj/money/coin");
    obj->set_amount(query("incoin"));
    obj->move(box);
    message_vision("$N按下退幣鈕, 一陣嘩啦的聲音, 取物口掉出"+query("incoin")+"個銅幣來\n",me);
    set("incoin",0);
    return 1;
   }
   return notify_fail("你按了退幣鈕... 可是什麼事情都沒有發生.\n");
  }
  if(button==1) arg="green tea"; 
  else if(button==2) return notify_fail("都已經寫[缺貨中]了你還按?\n");
  else if(button==3) return notify_fail("都已經寫[缺貨中]了你還按?\n");
  else return notify_fail("沒有這個按鈕.\n");
  ob=present(arg,stroom);
  if(!ob) return notify_fail("找不到這個東西! 請聯絡巫師.\n");
  cost=ob->query("value");
  amount=query("incoin")/ob->query("value");
  if(amount>ob->query("amount")) amount=ob->query("amount");
  if(ob->query("amount")<1) return notify_fail("這東西賣完了\n");
  if(amount<1) return notify_fail("販賣機沒有反應..可能是投的錢不夠\n");
  for(i=0;i<amount;i++)
  {
   ob->add("amount",-1);
   box->add("incoin",-cost);
   if(obj=present("green tea",box))
   {
    obj->add_amount(1);
   } else
   {
    obj=new(base_name(ob));
    obj->move(box);
   }
  }
  message_vision("$N按下販賣機上的按鈕, 咕隆一聲,取物口滾出"+amount+obj->query("unit")+"$n來\n",me,ob);
  return 1;
 }
 return notify_fail("要按什麼按鈕? \n格式: press <數字> \n");
}
