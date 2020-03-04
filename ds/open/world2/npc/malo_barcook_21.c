#include <ansi.h>
inherit NPC;
inherit F_VENDOR;
//inherit SHOPMAN;
void create()
{
//=========================°ò¥»³]©w==========================

        set_name( "©P´Â´I", ({ "cook zhou","zhou","cook"}));
        set("long",@LONG
        ¤@­Ó½G½Gªº¤¤¦~¨k¤H¡A­±±a¯º®e¬ÝµÛ§A¡C
	==============================================
	½æªF¦è <sell ¦×«~> <sell ¼Æ¶q ¦×«~>
	==============================================
LONG);
        set("level",21);
        set("title","[1;33m¤j¼p[m");
        set("gender", "¨k©Ê");
        set("race", "human");
        set("age", 45);
        set("evil",-10);			//¨¸´c«× 20 (¥¿ªºªí¨¸´c, ­tªíµ½¨})

	set("attitude", "peaceful");   //·Å©Mªº NPC¡C
	set("talk_reply","¦pªG§A¦³·sÂAªº¦×«~¡A¥i¥H½æ(sell)µ¹§Ú³á!!");
	set("storeroom",__DIR__"bar_shoproom");	//ª`·N. ­n«Ø¥ß¤@­Óroom©ñªF¦è

//===========================°ÝÃD¦^µª==================================
set("inquiry/name", @LONG
  [1;36m §Ú¥s°µ©P´Â´I.. ½Ð¦h«ü±Ð!![m
LONG );
        setup();
      add_money("dollar", 1100);		//±aªº¿ú
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
	if(!arg) return notify_fail("§A­n½æ¤°»òªF¦è¡H\n");
	if(sscanf(arg,"%d %s",amount,item)==2) // AMOUNT
	{
	  if(amount<1) return notify_fail("§A­n½æ´X­Ó°Ú¡H\n");
	  if(amount>10) return notify_fail("¤@¦¸³Ì¦h½æ¤Q­Ó¡C\n");
	  for(i=0;i<amount;i++)
	  {
	  	do_sell(item);
	  }
	 return 1;
	} //END of AMOUNT
	 if(!ob=present(arg,me)) return notify_fail("§A¨S¦³³o¼ËªF¦è¡C\n");
	if(!ob->is_meat() )
	{
		return notify_fail(this_object()->name()+"·n·nÀY»¡: §Ú¥u¦¬¦×Ãþ¡C\n");
		if( ob->query("name") == "»GÄêªº«ÍÅé" ) return notify_fail(this_object()->name()+"·n·nÀY»¡: ³o³½¤w¸g¤£·sÂA¤F¡C\n");
	}
 	if(ob->query("secured"))
 		return notify_fail("½Ð¥ý¸Ñ°£«O¦sª¬ºA¡C\n");
 	if( ob->query("no_drop") )
 		return notify_fail("³o­ÓªF¦è«Ü¯S§O, §AÁÙ¬O¦Û¤v«OºÞ¦n¤F¡C\n");
 	if( ob->query("no_sell"))
 		return notify_fail("§Ú¤£¦¬ÁÊ³oºØªF¦è¡C\n");
 	if( ob->is_character() && !ob->is_corpse()) return notify_fail("§Ú¤£¦¬ÁÊ¬¡ªºªF¦è¡C\n");
 	if(ob->query("equipped"))
 		return notify_fail("½Ð¥ý¨ø°£¤U¨Ó¦n¶Ü¡H\n");
	if(ob->query("gender")=="fish")
	{
		ob->set("value",50);
		ob1=new_ob(__DIR__"../obj/fish_soup_120");
		if(!ob1) return notify_fail("§Ú¤£¦¬ÁÊ³oºØªF¦è¡C\n");
	}
	else
	if(!ob1=new_ob(__DIR__"../obj/"+ob->query("cook"))) return notify_fail(this_object()->name()+"·n·nÀY»¡: ³oºØ¦×§Ú¤£·|®Æ²z¡C\n");
 	valu=ob->query("value");
 	if( valu<20 )
		 return notify_fail("³oªF¦è¤£­È¿ú¡C\n");
	arg = ob->query("id");
	
	valu=valu*4/5;
	world = me->money_type();
	if(world!=3) message_vision("$N½æ¤F¤@"+ob->query("unit")+ob->query("name")+"µ¹$n, $nµ¹¤F$N"
		+price_string(valu,me->money_type())+"¡C\n",me,this_object());
	else message_vision("$N½æ¤F¤@"+ob->query("unit")+ob->query("name")+"µ¹$n, $n±N"
		+valu+"­Ó³æ¦ìªº¹q¤l¹ô¦s¤J$Nªº±b¸¹¤§¤¤¡C\n",me,this_object());
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
