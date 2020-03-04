// guild.c§ï¦Ûvendor.c
#include <dbase.h>
inherit ROOM;
#include <ansi.h>
#define STOREDROOM __DIR__"temp/store1"
object stroom;
void create()
{
set("light",1);
set("short","[1;33mªüº¸¥[´µ¹D¨ã«Î[m");
set("long",@LONG
§A¨«¶i¤@®a¤Q¤À¼e´¯ªº°Ó©±¡A¨â®Çªº¬Á¼þÂd©ñ¤F¦UºØ§Î§Î¦â¦âªº¹D¨ã
©M¸Ë³Æ¡A¥¿¤¤¶¡¬O¤@­Ó¥|¤è§ÎªºÂdÂi¡A¤W­±¦³­Ó»ù¥Øªí¡A§A¥i¥H¥Î[[1;36mlist[m]
¨Ó¬Ý¬Ý¦³¨º¨ÇªFªF¡A¦A¦Ò¼{¬Ý¬Ý­n¤£­n¶R[[1;36mbuy[m]¡C
LONG
);
set("light",1);
set("exits",([
"south" : __DIR__"pearl_18",
]));
set("objects",([
__DIR__"npc/buddy": 1,
]));
setup();
}

void init()
{
add_action("do_vendor_list","list");
add_action("do_buy","buy");
add_action("do_supply","supply");
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
if(arg=="shield"){ //if loop
list =  "§A¥i¥HÁÊ¶R¤U¦C³o¨ÇªF¦è:           ÁÊ¶R¼Æ¶q          »ù¿ú \n";
list += "==========================================================\n";
for(i=0; i<sizeof(goods); i++)
{    //for loop
printf("%s\n",goods[i]->query("name"));
printf("%s\n",goods[i]->short());
if(goods[i]->query("id")!=arg) continue;
printf("%s\n",goods[i]->query("short"));
list += sprintf("%-22s ¡R          %7d         %7d   \n",
goods[i]->short(),goods[i]->query("amount"),goods[i]->query("value")
);
   }// for loop
} else {    //else loop
list = "§A¥i¥HÁÊ¶R¤U¦C³o¨ÇªF¦è:           ÁÊ¶R¼Æ¶q          »ù¿ú \n";
list += "==========================================================\n";
 for(i=0; i<sizeof(goods); i++)
 {
  list += sprintf("%-22s ¡R        %7d         %7d   \n",
  goods[i]->short(),goods[i]->query("amount"),goods[i]->query("value")
  );
 } //for loop
} // else loop
write(list);
return 1;
}
int do_buy(string arg)
{
object *goods,ob,ob2;
if(!arg) return 0;
load_object(STOREDROOM);
stroom=find_object(STOREDROOM);
goods = all_inventory(stroom);
if(ob=present(arg,stroom))
{
if ( (ob->query_weight()+this_player()->query_encumbrance())>this_player()->query_max_encumbrance() )
 return notify_fail("§Aªº¤O¶q¤£°÷,µLªk®³ªF¦è\n");
if(this_player()->query("coin")<ob->query("value"))
return notify_fail("·F¹À....¨S¿úÁÙ´±¨Ó³o¸Ì¶RªF¦è\n");
if(ob->query("amount")<1)
return notify_fail("³oªF¦è½æ§¹¤F\n");
this_player()->add("coin",-ob->query("value"));
message_vision("$N¶R¤F"+ob->name()+"\n",this_player());
if(ob->query("amount"))
 {
  ob2=new(base_name(ob));
  ob2->set("amount",1);
  ob2->move(this_player());
  ob->add("amount",-1);
 }
else
ob->move(this_player());
return 1;
}
else return notify_fail("¨S³oºØªF¦è\n");
}

int do_supply(string arg)
{
object *goods,ob,ob2,npc,obj;
int valu,exp,v,lck;
load_object(STOREDROOM);
stroom=find_object(STOREDROOM);
if(!arg) return notify_fail("§A­n¸É¤°»ò³f\n");
if(this_player()->query("class")!="worker")
return notify_fail("§A¤£¯à¸É³f\n");
goods = all_inventory(stroom);
if(obj=present(arg,this_player()))
if(arg=="wood")
{
if(obj=present(arg,this_player()))
if(!obj->query("supply"))
return notify_fail("§Ú­Ì¤£¦¬³oªF¦è\n");
if(!obj)
 return notify_fail("§A¨­¤W¨S¦³³f\n");
valu=obj->query("value");                           
v=random(v);
valu=valu+v;
valu=50+random(20);
exp=obj->query("value");
lck=this_player()->query("lck")*this_player()->query("level");
if(this_player()->query("lck")>random(this_player()->query("level")*10))
exp=200+random(100);
else
exp=100+random(100);
exp=(int)exp;
arg="torch";
if(ob=present(arg,stroom))    
{
if(ob->query("amount")>90)
return notify_fail("¥Ø«e¤£»Ý­n¸É³f¤F\n");
message_vision(HIY"$N±q»·¤è°e¨Ó"+obj->name()+"Àò±o"+valu+"ªT»ÉªOªº¹S³Ò\n"NOR,this_player());
message_vision("$N¦b³Ò²Öªº®È³~¤¤Àò±o"+exp+"ÂI¸gÅç­È\n",this_player());
this_player()->add("coin",valu);
this_player()->add("exp",exp);
ob2=new(base_name(ob));
ob2->set("amount",1);
ob->add("amount",10);
ob->delete("secured");
ob->delete("out");
destruct(obj);
return 1;
}           
else return notify_fail("¨S³oºØªF¦è\n");
}
 else return notify_fail("§A¨­¤W¨S¦³³o¼ËªF¦è\n");
} 
