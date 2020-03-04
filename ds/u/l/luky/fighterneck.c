#include <armor.h>
#include <combat.h>
inherit SSERVER;
inherit NECK;

void create()
{
set_name("¾Ô¤h¶µ°é",({"fighter necklace","necklace"}));
set_weight(1800);
set("long","³o¬O¤@­Ó¾Ô¤h­Ìªº¶H¼xª«¡C(help necklace)¥i¥H¬d¬Ý¾Ô¤h¥i¥Îªº«ü¥O\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("material", "iron");
set("unit", "¦ê");
set("value",0);
set("no_sell",1);
set("no_drop",1);
//set("armor_prop/armor",1);          
set("limit_con",1);
set("armor_prop/armor",10);
}
setup();
}

void init()
{
 add_action("do_help","help");
 add_action("do_berserk","berserk");
}

int do_help(string arg)
{
 if(arg=="necklace")
 {
  write(
   "\n¾Ô¤h«ü¥O»¡©ú:\n"
  +"berserk: ºÆ¨g§ðÀ»\n"
  );
  return 1;
 }
 return 0;
}

int do_berserk(string arg)
{
 object me, target;
 int skill, cost;
 
 me=this_player();
 if(!me) return 0;
 if(me->start_busy()) return notify_fail("§A°Ê§@ÁÙ¨S§¹¦¨..\n");
 if(me->query_temp("berserk")) return notify_fail("§A¤£¯à³sÄò°µ³o»ò¿E¯Pªº°Ê§@.\n");
 if(!me->is_fighting())
 	return notify_fail("³o­Ó§Þ¯à¥u¯à¦b¾Ô°«®É¨Ï¥Î¡C\n");
 if(arg)
 {
  target=present(arg, environment(me));
  if(!target) return notify_fail("­n¹ï½Ö¬I®iºÆ¨g§ðÀ»??\n");
  if(!me->is_fighting(target)) return notify_fail("³o­Ó§Þ¯à¥u¯à¹ï§A¥Ø«eªº¼Ä¤H¨Ï¥Î¡C\n");
 }
 else target = offensive_target(me); 	//¦¹¨ç¼Æ»Ýinherit SSERVER;
 if(!target) return notify_fail("³o­Ó§Þ¯à¥u¯à¹ï§A¥Ø«eªº¼Ä¤H¨Ï¥Î¡C\n");
 skill=me->query_skill("berserk",1);
 // if(skill<5) return notify_fail("§Aªº§Þ¯àÁÙ¤£°÷¼ô½m\n");
 cost = 25;
 if(me->query("mp") < cost) return notify_fail("§A¥Ø«eªºÅé¤Oª¬ªpµLªk°µ¦p¦¹¼@¯Pªº°Ê§@\n");
 message_vision("\n[1;31m$N¨â²´µo¬õ, º¥º¥³´¤J¤FºÆ¨gª¬ºA...[0m\n\n",me);
 skill/=8;
 skill+=2;
 me->set_temp("berserk",1);
 me->start_busy(2);
 me->add("mp",-cost);
 call_out("do_crazy",4,me,target,skill);
 call_out("do_clean",8,me);
 return 1;
}

int do_crazy(object me,object target,int times)
{
  object weapon;
  int i;
  if(!me) return 0;
  if(target!=present(target->query("id"), environment(me)))
  {
    me->delete_temp("berserk");
    return notify_fail("¥Ø¼Ð¦ü¥G²æÂ÷¤F§Aªº§ðÀ»½d³ò..\n");
  }
  message_vision("\n[1;37m¡ã¡ã§q¡ã¡ã$N¥õ¤Ñªø¼S¶}©lµo¨g¤F!!![0m\n\n",me);
  weapon=me->query_temp("weapon");
  for(i=0;i < times ;i++)
  {
  	COMBAT_D->do_attack(me,target,weapon,TYPE_BERSERK); 
        if(weapon) weapon->attack(me,target);
  }
  COMBAT_D->report_status(target);	//¥[¤W³o¦æ¥i¥HÅã¥Ütargetªº°·±dª¬ªp
  me->improve_skill("berserk",1+random(me->query_int()/10));
  return 1;
}

int do_clean(object me)
{
 if(!me) return 0;
 me->delete_temp("berserk");
 return 1;
}

int query_autoload() { return 1; }
