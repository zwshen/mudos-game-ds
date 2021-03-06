#include <ansi.h>
inherit NPC;
inherit F_VENDOR;
//inherit SHOPMAN;
void create()
{
//=========================基本設定==========================

        set_name( "周朝富", ({ "cook zhou","zhou","cook"}));
        set("long",@LONG
        一個瘦瘦的中年男人，面帶笑容看著你。
	==============================================
	賣東西 <sell 肉品> <sell 數量 肉品>
	==============================================
LONG);
        set("level",21);
        set("title","[1;33m大廚[m");
        set("gender", "男性");
        set("race", "human");
        set("age", 45);
        set("evil",-10);			//邪惡度 20 (正的表邪惡, 負表善良)

	set("attitude", "peaceful");   //溫和的 NPC。
	set("talk_reply","如果你有新鮮的肉品，可以賣(sell)給我喔!!");
	set("storeroom",__DIR__"bar_shoproom");	//注意. 要建立一個room放東西

//===========================問題回答==================================
set("inquiry/name", @LONG
  [1;36m 我叫做周朝富.. 請多指教!![m
LONG );
        setup();
      add_money("dollar", 1100);		//帶的錢
      carry_object(__DIR__"../eq/cloth_pants_5")->wear();
      carry_object(__DIR__"../eq/cloth_hat_5")->wear();
      carry_object(__DIR__"../eq/cloth_boots_5")->wear();
      carry_object(__DIR__"../eq/cloth_clothes_5")->wear();
      carry_object(__DIR__"../wp/iron_blade_22")->wield();
}

void init()
{
	::init();
//	add_action("do_list","list");
//	add_action("do_buy","buy");
	add_action("do_sell","sell");
}

int do_sell(string arg)
{
	object ob,*inv,obj,ob1,me,*goods,stroom;
	string item;
	int valu,i,amount,world;
	me=this_player();
	if(!stroom=load_object(this_object()->query("storeroom"))) return 0;
	if(!arg) return notify_fail("你要賣什麼東西？\n");
	if(sscanf(arg,"%d %s",amount,item)==2) // AMOUNT
	{
	  if(amount<1) return notify_fail("你要賣幾個啊？\n");
	  if(amount>10) return notify_fail("一次最多賣十個。\n");
	  for(i=0;i<amount;i++)
	  {
	  	do_sell(item);
	  }
	 return 1;
	} //END of AMOUNT
	 if(!ob=present(arg,me)) return notify_fail("你沒有這樣東西。\n");
	if(!ob->is_meat() )
	{
		return notify_fail(this_object()->name()+"搖搖頭說: 我只收肉類。\n");
		if( ob->query("name") == "腐爛的屍體" ) return notify_fail(this_object()->name()+"搖搖頭說: 這魚已經不新鮮了。\n");
	}
 	if(ob->query("secured"))
 		return notify_fail("請先解除保存狀態。\n");
 	if( ob->query("no_drop") )
 		return notify_fail("這個東西很特別, 你還是自己保管好了。\n");
 	if( ob->query("no_sell"))
 		return notify_fail("我不收購這種東西。\n");
 	if( ob->is_character() && !ob->is_corpse()) return notify_fail("我不收購活的東西。\n");
 	if(ob->query("equipped"))
 		return notify_fail("請先卸除下來好嗎？\n");
	if(ob->query("gender")=="fish")
	{
		ob->set("value",50);
		ob1=new_ob(__DIR__"../obj/fish_soup_120");
		if(!ob1) return notify_fail("我不收購這種東西。\n");
	}
	else
	if(!ob1=new_ob(__DIR__"../obj/"+ob->query("cook"))) return notify_fail(this_object()->name()+"搖搖頭說: 這種肉我不會料理。\n");
 	valu=ob->query("value");
 	if( valu<20 )
		 return notify_fail("這東西不值錢。\n");
	arg = ob->query("id");
	
	valu=valu*4/5;
	world = me->money_type();
	if(world!=3) message_vision("$N賣了一"+ob->query("unit")+ob->query("name")+"給$n, $n給了$N"
		+price_string(valu,me->money_type())+"。\n",me,this_object());
	else message_vision("$N賣了一"+ob->query("unit")+ob->query("name")+"給$n, $n將"
		+valu+"個單位的電子幣存入$N的帳號之中。\n",me,this_object());
	me->receive_money(valu);
	ob1->move(stroom);
	destruct(ob);
	goods = all_inventory(stroom);
	if(sizeof(goods)>100)
	{
		for(i=100;i<sizeof(goods);i++)	destruct(goods[i]);
	}
	me->save();
	return 1;
}
