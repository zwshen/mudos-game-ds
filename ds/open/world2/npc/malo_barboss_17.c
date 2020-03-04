#include <ansi.h>
inherit NPC;
inherit F_VENDOR;
//inherit SHOPMAN;
void create()
{
//=========================°ò¥»³]©w==========================

        set_name( "°s©±¦ÑÁó", ({ "bar boss","boss"}));
        set("long",@LONG
        ¤@­Ó·L­Dªº¨k¤H¡A¥¿¦b¹ïµÛ§A«¢¸y¡C
	==============================================
	¬d¸ßµæ³æ <list>
	¶RªF¦è <buy ª««~> <buy ¼Æ¶q ª««~>
	==============================================
LONG);
        set("level",17);
        set("gender", "¨k©Ê");
        set("race", "human");
        set("age", 33);
        set("evil",-10);			//¨¸´c«× 20 (¥¿ªºªí¨¸´c, ­tªíµ½¨})

	set("attitude", "peaceful");   //·Å©Mªº NPC¡C
	set("talk_reply","¥u­n¼p©Ð¤£¯Ê§÷®Æ¡A³o¸Ìªº±ÆÀ\\¥i¬O¤@·¥´Îªº³á!!");
	set("storeroom",__DIR__"bar_shoproom");	//ª`·N. ­n«Ø¥ß¤@­Óroom©ñªF¦è

//===========================°ÝÃD¦^µª==================================
set("inquiry/name", @LONG
  [1;36m §Ú¥s°µ©P´Â¥ý.. ½Ð¦h«ü±Ð!![m
LONG );
        setup();
      add_money("dollar", 1100);		//±aªº¿ú
      carry_object(__DIR__"../eq/cloth_pants_5")->wear();
//      carry_object(__DIR__"../eq/cloth_hat_5")->wear();
      carry_object(__DIR__"../eq/cloth_boots_5")->wear();
      carry_object(__DIR__"../eq/cloth_clothes_5")->wear();
}

void init()
{
	::init();
	add_action("do_list","list");
	add_action("do_buy","buy");
//	add_action("do_sell","sell");
}

int sort_item(object ob1, object ob2)
{
	return strcmp(base_name(ob1),base_name(ob2));
}
string item_desc(object ob)
{
	if(ob->query("skill_type")) return HIG+"ªZ¾¹"+NOR;
	else if(ob->query("armor_type")) return HIY+"¨¾¨ã"+NOR;
	else if(ob->query("heal_hp") || ob->query("heal_mp") || ob->query("heal_ap") ) return HIC+"¦^´_"+NOR;
	else return "¹D¨ã";
}

string item_list(object ob,int amount,int rule)
{
	if(rule) 
	{
	   return sprintf("  %4d%-4s  %8d .......... %4s  %s\n",
	   amount,ob->query("unit"),ob->query("value"),item_desc(ob),ob->short()
	   );
	} else
	{
	   return sprintf("  %4d      %8d .......... %4s  %s\n",
	   amount,ob->query("value"),item_desc(ob),ob->short()
	   );
	}
}
int do_list(string arg)
{
	object *goods,stroom,me;
	string list;
	int i,amount,k;
	me=this_player();
	if(!stroom=load_object(this_object()->query("storeroom"))) return 0;
	stroom->set("stroom",1);
	amount = 1;
	k=1;
	//stroom=find_object(this_object()->query("storeroom"));

	goods = all_inventory(stroom);
	//goods = F_QUANTITY->sortinv(stroom);
	list = "\n\n¢z¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢{\n";
	list +="¢x  ¦s¶q      ³æ  »ù            ºØÃþ  ¥Ø«e¥i¥HÁÊ¶Rªºµæ¦â²M³æ    ¢x\n";   
	list +="¢|¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢}\n";
	if(stringp(arg))
	{
	  list = "\n\n¢z¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢{\n";
	  list +="¢x  ½s¸¹      ³æ  »ù            ºØÃþ  ¥Ø«e¥i¥HÁÊ¶Rªºµæ¦â²M³æ    ¢x\n";   
	  list +="¢|¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢}\n";
		for(i=0; i<sizeof(goods); i++)
		{
			if(goods[i]->id(arg))
			{
				list += item_list(goods[i],k,0);
				k++;
			}
		}
			list +="\n";	
			if(i==0) return notify_fail(this_object()->query("name")+"¹ï§A»¡: ¹ï¤£°_­ò..³f³£½æ§¹¤F¡C\n");
			else me->start_more(list);
			return 1;
	}
	goods = sort_array(goods, "sort_item", this_object());
	for(i=0; i<sizeof(goods); i++)
	{
	 if( i+1 < sizeof(goods) )
	 {
	  if( base_name(goods[i])==base_name(goods[i+1]) )
	  	amount++;
	  else 
	  {
	    list+= item_list(goods[i],amount,1);
	    amount = 1;
	  }
	 } else
	 {
	    list+= item_list(goods[i],amount,1);
	 }
	}
	list +="\n";
	if(i==0) return notify_fail(this_object()->query("name")+"¹ï§A»¡: ¹ï¤£°_­ò..¦×³£¥Î§¹¤F¡C\n");
	else me->start_more(list);
	return 1;	
}

int do_buy(string arg)
{
	int amount,valus,i,world;
	object *goods,ob,me,stroom;
	string item;
	
	me=this_player();
	if(!arg) return notify_fail("§A­n¶R¤°»òªF¦è¡H\n");
	//load_object(this_object()->query("storeroom"));
	if(!stroom=load_object(this_object()->query("storeroom"))) return 0;
	goods = all_inventory(stroom);
	if(sscanf(arg,"%d %s",amount,item)==2)
	{
	 if(amount < 1) return notify_fail("¦Ü¤Ö­n¶R¤@­Ó§a¡C\n");
	 if(amount >10) return notify_fail("¤@¦¸³Ì¦h¥u¯à¶R¤Q­Ó¡C\n"); //Á×§K°j°é¹Lªø
	 for(i=0;i<amount;i++)
	 {
	  do_buy(item);
	 }
	 return 1;
	}
	
	if(ob=present(arg,stroom))
	{
	  if( (ob->query_weight()+me->query_encumbrance())>me->query_max_encumbrance() )   
 		return notify_fail("§A®³¤£°Ê³o­ÓªF¦è¤F¡C\n");
 	  if( (int)me->query_capacity() + (int)ob->query("volume") > (int)me->query_max_capacity() )
 		return notify_fail("§A¨­¤W©ñ¤£¤U³o»ò¦hªF¦è¡C\n");
 	  if(!me->can_afford(ob->query("value")))
		return notify_fail("§A¨­¤Wªº¿ú¤£°÷¡C\n");
	  valus=ob->query("value");
	  me->receive_money(-valus);
	  world = me->money_type();
	  if(world!=3) message_vision("$N¥I¤F$n"+price_string(valus,me->money_type())+", $n¥ß¨è®³¤F¤@"+ob->query("unit")+ob->name()+"µ¹$N¡C\n",me,this_object());
	  else message_vision("$N¶Ç°e¤F"+valus+"­Ó³æ¦ìªº¹q¤l¹ôµ¹$n, $n¥ß¨è®³¤F¤@"+ob->query("unit")+ob->name()+"µ¹$N¡C\n",me,this_object());
	  ob->move(me);
	  stroom->save();
	  me->save();
	  return 1;
	}
	else return notify_fail("§A·Q­n¶R¤°»ò°Ú??\n");
}
