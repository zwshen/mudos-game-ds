#include <ansi.h>
#include <armor.h>
inherit F_AUTOLOAD;
inherit SHIELD;
object user;
void create()
{
set_name("[1;37m¤­¨~¬P¤§¬Þ[0m",({"five_star shield","shield"}) );
set("long","¤@­±¥Ñ®ü©³¤õ¤s©¥¿i¦¨ªº¤­¨¤§Î¬ÞµP,¤W­±ÁôÁô¬ù¬ù³z¥X¸t¼äªº¥ú¨~¡C\n");
set_weight(3650);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("material","aerolite"); //¹k¥Û(aerolite)
set("armor_type","shield");
set("unit", "­±");
set("value",6150);
//set("armor_prop/defense",5);
set("armor_prop/str",-3);
set("armor_prop/int",2);
set("armor_prop/wis",1);
set("limit_lv",45);
set("level",45);
//set("armor_prop/armor",95);
set("wear_msg","$N±N$n°ªÁ|¹LÀY, ³¬°_²´·ú¸Û¤ßÃ«§i..\n$n¤Æ¬°¤@ªÑ¥ú²y¥]³ò¦í$N!!\n");
set("unequip_msg", "$N©ñ¤U¤â¤¤ªº$n, ¨­®Ç¯¬ºÖªº¥ú¨~º¥º¥®ø¥¢ªºµL¼vµLÂÜ¡C\n");
        }
        setup();
user=this_player();
}

int query_autoload() { return 1; }

void init()
{
 add_action("do_wear","wear");
 add_action("do_remove","remove");
}

int do_remove(string str)
{
 user = this_player();
 if(str=="shield" || str=="all" )
 {
  user->delete_temp("magic_shield");
  set_heart_beat(0);
 }
 return 0;
}

int do_wear(string str)
{
 user = this_player();
 
 if(str=="shield" ) 
 {
  if(user->query("level")<45) return notify_fail ("§Aªºµ¥¯Å¤£°÷¡C\n");;
  set_heart_beat(1);
  user->set_temp("magic_shield",1);
 }
 return 0;
}

void heart_beat()
{
object user;
int heal,tmp;
user = this_player();
if(!user) return ;
if(query("equipped") && !user->query_temp("magic_shield")) user->set_temp("magic_shield",1);
if(!query("equipped") && user->query_temp("magic_shield")) user->set_temp("magic_shield",0);
if(user->is_fighting() && query("equipped") )
{
 if(user->query("max_mp") > user->query("mp") )
 {
  if(random(user->query("lck")) > 40 || random(20) < 4 ) 
   {
   heal = random(20) + (int)user->query("int")/4 + 1 ;
   tmp = user->query("max_mp");
   tmp -= user->query("mp");
   if(heal > tmp) heal = tmp;
   user->add("mp", heal);
   message_vision("\n$N[1;38mµo¥X¤@¹D¸t¼äªº¥ú¨~¼W±j¤F$n[1;38mªºÅ]¤O¡T[0m\n",this_object(),user);
   }
    return;
  }
 }
return;
}