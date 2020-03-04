#include <path.h>
#include <ansi.h>
#include <dbase.h>
inherit ROOM;
#define STOREDROOM __DIR__"temp/potion"
object stroom;
void create()
{
set("light",1);
set("short","[1;31m¸¦ªkÃÄ§½[m");
set("long",@LONG

  ³o¸Ì¬O¥»ÂíµÛ¦WªºÃÄ§½¡M¬üÄRªº¤k¦ÑÁó¥¿¦£µÛ¾ã²z®à
¤l¡C³o¸Ì¨ÑÀ³¦U¦¡ªºÃÄ¤ô¡M¤u¤H­Ì¤]±`±`¨Ó¶i³fÁÈ¿ú¡C

  ¢y¡Ä          ¢z¢w¢w¢w¢w¢w¢w¢{            ¡Ä¢j
  ¢¬¢¨¢j        ¢x¸¦ ªk ÃÄ §½ ¢x          ¢y¢©¢­
¢¬¢¬¢¨¢j      ¡Ä¢|¢w¢w O¢w¢w¢w¢}¡Ä        ¢y¢©¢­¢­
¢i¢¬¢¨¢j      ¢©¢­    /Y\     ¢¬¢¨        ¢y¢©¢­¢i
¢i¢¬¢¨¢j      ¢i¢©¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¢¨¢i        ¢y¢©¢­¢i
¢i¢¬¢¬¡Ã¡Ã¡Ã¡Ã¢ª¢i¢i¢i¢i¢i¢i¢i¢i¢«¡Ã¡Ã¡Ã¡Ã¡Ã¢­¢­¢i
¢i¢¬            ¢ª¢i¢i¢i¢i¢i¢i¢«              ¢­¢i
¡Ã                                              ¡Ã
LONG
);
 set("light",1);
set("exits",([
"north" : __DIR__"pearl_10",
]));
set("objects",([
__DIR__"npc/tifa":1,
]));
 set("no_clean_up", 0);
setup();
load_object("/u/p/pudon/war2/ass");
load_object("/u/p/pudon/war2/tking");
load_object("/u/p/pudon/war2/squire");
}

void init()
{
//greeting();
add_action("do_vendor_list","list");
add_action("do_buy","buy");
add_action("do_supply","supply");
}

int do_vendor_list()
{
object *goods,stroom,npc;
mixed amount;
string list, *name;
int i,cost,level,maxlv;
npc=find_living("tifa");
load_object(STOREDROOM);
if(!npc)
return notify_fail(HIY"¦ÑÁó®Q¤£¦b, §A¤£¯à¶RªF¦è¡C\n"NOR);
stroom=find_object(STOREDROOM);
goods = all_inventory(stroom);
list = "§A¥i¥HÁÊ¶R¤U¦C³o¨ÇªF¦è:           ÁÊ¶R¼Æ¶q            ¿ú \n";   
 list += "==========================================================\n";
	for(i=0; i<sizeof(goods); i++)
	          { 
		list += sprintf("%-15s ¡R           %-7d          %-7d   \n",
goods[i]->name()+"("+goods[i]->query("id")+")",goods[i]->query("amount"),goods[i]->query("value")
			 );
			 }
	write(list);
	return 1;	
}
int do_buy(string arg)
{
 int amount;
 string item;
 object *goods,ob,ob2,npc;
 npc=find_living("tifa");
 if(!arg) return 0;
 if(!npc)
  return notify_fail(HIY"¦ÑÁó®Q¤£¦b, §A¤£¯à¶RªF¦è¡C\n"NOR);
 load_object(STOREDROOM);
 stroom=find_object(STOREDROOM);
 goods = all_inventory(stroom);
 if(this_player()->is_fighting())
  return notify_fail("§A¥¿¦b¾Ô°«¡C\n");
 if(sscanf(arg,"%d %s",amount,item)==2)
 {
  if(!objectp(ob=present(item,stroom)))
   return notify_fail("§Ú­Ì¨S½æ³oºØªFªF§r!?\n");
  if(ob=present(item,stroom))
  {
   if(ob->query_amount()<1)
    return notify_fail("³oºØÃÄ¤ô½æ§¹¤F¡C\n");
   if(this_player()->query("coin")<ob->query("value")*amount)
    return notify_fail("·F¹À....¨S¿úÁÙ´±¨Ó³o¸Ì¶RªF¦è¡C\n");
   if ( (ob->query_weight()*amount+this_player()->query_encumbrance())>this_player()->query_max_encumbrance() )
    return notify_fail("§Aªº¤O¶q¤£°÷,µLªk®³ªF¦è¡C\n");
   ob2=new(base_name(ob));
   ob2->set_amount(amount);
   if(ob2->query_amount()>ob->query("amount"))
    return notify_fail("¥»©±ªº³oºØÃÄ¤ô¨S³o»ò¦h¡C\n");
   ob->add("amount",-amount);
   ob2->delete("no_sell");
   ob2->delete("secured");
   ob2->move(this_player());
   ob->delete("secured");
   ob->delete("no_sell");
   this_player()->add("coin",-ob->query("value")*amount);
   this_player()->save();
   stroom->save();
   if(npc->query("lv")>0)
   {
    npc->add("income",ob->query("value")*amount);
    npc->add("total",ob->query("value")*amount);
    npc->save();
   }
   message_vision("$N¶R¤F "+amount+" "+ob->query("unit")+ob->name()+"¡C\n",this_player());
  } else 
  return notify_fail("§Ú­Ì¨S½æ³oºØªF¦è¡C\n");
  return 1;
 }
 if(ob=present(arg,stroom))
 {
  if(ob->query("amount")<1)
   return notify_fail("³oÃÄ¤ô½æ§¹¤F¡C\n");
  if ( (ob->query_weight()+this_player()->query_encumbrance())>this_player()->query_max_encumbrance() )   
   return notify_fail("§Aªº¤O¶q¤£°÷,µLªk®³ªF¦è¡C\n");
  if(this_player()->query("coin")<ob->query("value"))
   return notify_fail("·F¹À....¨S¿úÁÙ´±¨Ó³o¸Ì¶RªF¦è¡C\n");
  this_player()->add_temp("cmds",1);
  this_player()->add("coin",-ob->query("value"));
  if(npc->query("lv")>0)
  {
   npc->add("income",ob->query("value"));
   npc->add("total",ob->query("value"));
   npc->save();
  }
  stroom->save();
  message_vision("$N¶R¤F 1 "+ob->query("unit")+ob->name()+"¡C\n",this_player());
  ob2=new(base_name(ob));
  ob2->delete("no_sell");
  ob2->delete("secured");
  ob2->move(this_player());
  ob->add("amount",-1);
  ob->delete("secured");
  ob->delete("no_sell");
  this_player()->save();
  stroom->save();
 }
 else return notify_fail("¨S½æ³oºØªF¦è\n");
 return 1;
}

int do_supply(string arg)
{
 object *goods,ob,ob2,npc,obj;
 int valu,exp,v,lck;
 load_object(STOREDROOM);
 stroom=find_object(STOREDROOM);
 npc=find_living("tifa");
 if(!npc)
  return notify_fail(HIY"¦ÑÁó®Q¤£¦b, §A¤£¯à¸É³f.\n"NOR);
 if(!arg) return notify_fail("§A­n¸É¤°»ò³f\n");
 if(this_player()->query("class")!="worker")
  return notify_fail("§A¤£¯à¸É³f\n");
 if(this_player()->query_temp("supply"))
  return notify_fail("§AÁÙ¦b¸É³f\n");
 this_player()->add_temp("cmds",1);
 this_player()->set_temp("supply",1);
 goods = all_inventory(stroom);
 if(obj=present(arg,this_player()))
 if(arg=="green algae")
 {
  if(obj=present(arg,this_player()))
  if(!obj->query("supply"))
   return notify_fail("§Ú­Ì¤£¦¬³oªF¦è\n");
  if(!obj)
   return notify_fail(HIY"§A¨­¤W¨S¦³³o¼Ëª««~\n"NOR);
  valu=obj->query("value");
  v=random(v);
  valu=valu+v;
  valu = 800 + random(400);
  if(this_player()->query("lck")<random(this_player()->query("level")*10))
  exp = 9000 + random(4000);
  else
   exp = 6800 + random(3000);
  arg="green potion";
  if(ob=present(arg,stroom))
  {
   if(ob->query("amount")>90)
    return notify_fail("¥Ø«e¤£»Ý­n¸É³f¤F\n");
   message_vision("[1;32m$N±q»·¤è°e¨Ó"+obj->name()+"[1;32mÀò±o"+valu+"ªT»ÉªOªº¹S³Ò[0m\n",this_player());
   message_vision("[1;32m$N[1;32m¦b³Ò²Öªº®È³~¤¤Àò±o"+exp+"ÂI¸gÅç­È[0m\n",this_player());
   ob2=new(base_name(ob));
   ob2->set("amount",1);
   ob->add("amount",10);
   this_player()->add("coin",valu);
   this_player()->add("exp",exp);
   if(npc->query("lv")>0)
   {
    npc->add("pay",valu);
    npc->add("total",npc->query("income")-npc->query("pay"));
    npc->set("profit",npc->query("total")-npc->query("capital"));
    npc->save();
   }
   this_player()->save();
   destruct(obj);
   return 1;
  }
 }
 if(obj=present(arg,this_player()))
 if(arg=="coco bean")
 {
  if(obj=present(arg,this_player()))
  if(!obj->query("supply"))
   return notify_fail("§Ú­Ì¤£¦¬³oªF¦è\n");
  if(!obj)
   return notify_fail("§A¨­¤W¨S¦³³f\n");
  valu=obj->query("value");
  v=random(v);
  valu=valu+v;
  valu=1500+random(550);
  exp=obj->query("value");
  lck=this_player()->query("lck")*this_player()->query("level");
  if(this_player()->query("lck")>random(this_player()->query("level")*10))
   exp=5300+random(5300);
  else
   exp=10600+random(5300);
  arg="caca potion";
  if(ob=present(arg,stroom))
  {
   if(ob->query("amount")>90)
    return notify_fail("¥Ø«e¤£»Ý­n¸É³f¤F\n");
   ob2=new(base_name(ob));
   ob2->set("amount",1);
   ob->add("amount",10);
   ob2->delete("no_sell");
   ob->delete("secured");
   message_vision("[1;32m$N±q»·¤è°e¨Ó"+obj->name()+"[1;32mÀò±o"+valu+"ªT»ÉªOªº¹S³Ò[0m\n",this_player());
   message_vision("[1;32m$N¦b³Ò²Öªº®È³~¤¤Àò±o"+exp+"ÂI¸gÅç­È[0m\n",this_player());
   this_player()->add("coin",valu);
   if(npc->query("lv")>0)
   {
    npc->add("pay",valu);
    npc->add("total",-valu);
    npc->save();
   }
   this_player()->add("exp",exp);
   this_player()->save();
   stroom->save();
   npc->save();
   if(obj->query_amount()<1)
    destruct(obj);
   else
    obj->add_amount(-1);
   return 1;
  }
  return 1;
 }
 else return notify_fail("¨S³oºØªF¦è\n");
}
