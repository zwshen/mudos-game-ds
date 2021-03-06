// gun.c

#include <weapon.h>
#include <ansi.h>
#ifdef AS_FEATURE
#include <dbase.h>
#else
inherit EQUIP;
#endif

int weapon_damage(string material,int weight);

void setup()
{
	::setup();
	
	if( clonep(this_object()) ) return;
	set("skill_type", "gun");
	set("can_shoot",1);
	if( !query("actions") ) {
		set("actions", (: call_other, WEAPON_D, "query_action" :) );
		set("verbs", ({ "bash", "crush" }) );
	}
}

varargs void init_gun(int damage, int flag)
{
	if(!this_object()->query("material"))
		this_object()->set("material","plant");
	damage += weapon_damage(query("material"),weight());
	set("weapon_prop/damage", damage);
	set("flag", (int)flag | EDGED );
	if(!query("limit_str"))	set("limit_str",weight()/1500);
	if(!query("max_load")) set("max_load",2);
}

int weapon_damage(string material,int weight)
{
	return 0;

}

int do_shoot(object me,object target)
{
	string msg;
	int damage;
	
	  if(!me || !target) return 0;
	  this_object()->set_temp("loaded",this_object()->query_temp("loaded")-1);
	  msg=HIW+"$N"+HIW+"用迅雷不及掩耳的速度, 突然用"+this_object()->name()+HIW+"對準$n"+HIW+"射出了一";
	  if(stringp(this_object()->query_temp("bullet/unit"))) msg+=this_object()->query_temp("bullet/unit");
		else msg+="發";
	  if(stringp(this_object()->query_temp("bullet/name"))) msg+=this_object()->query_temp("bullet/name")+"﹗\n"+NOR;
		else msg+="子彈﹗\n"+NOR;
	   if(!me->is_fighting(target)) me->kill_ob(target);
	  message_vision(msg,me,target);
	  me->start_busy(1);
	  me->improve_skill(this_object()->query("skill_type"),1+random(me->query_int()/6));
	  //check if target can dodge
	  if(COMBAT_D->attack_factor(me,this_object()->query("skill_type"))+COMBAT_D->dodge_factor(target,"dodge")+random(401) < 200 )
	  {
	   message_vision("$N迅速的往旁邊翻了兩個觔斗, 漂亮的閃過了$n的射擊。\n"+NOR,target,me);
	   target->improve_skill("dodge",1+random(target->query_int()/6));
	   if(!target->is_fighting(me)) target->kill_ob(me);
	   return 1;
	  }
	
	  damage=this_object()->query_temp("bullet/damage")+this_object()->query("weapon_prop/damage");
	  damage= damage*2/3+random(damage/2);
	  damage-=target->query_armor()/3-random(target->query_armor()/2);
	  if(damage<5) damage=random(10);
	  if(damage<1)
	  {
	   message_vision(HIW+"$N"+HIW+"把"+this_object()->query_temp("bullet/name")+HIW+"給彈開了。\n"+NOR,target);
	   if(!target->is_fighting(me)) target->kill_ob(me);
	   return 1;
	  }
	  message_vision("$N楞了一楞, 正想閃避時卻已經被"HIW"射中"NOR", "HIR"受傷不輕"NOR"。\n",target,me);
	  target->receive_damage("hp",damage,me);
	  if(random(10) == 1 ) target->receive_wound("random",random(4)+1,me);
	  COMBAT_D->report_status(target);
	  if(!target->is_fighting(me)) target->kill_ob(me);
	  return 1;

}

void attack(object me,object victim)
{
  int index, durable;
  string material;


  if( !stringp(material = this_object()->query("material")) )
  {
    error("ITEM : material 資料型態錯誤.\n");
    return;
  }

  switch(material)
  {
    case "gold"   : index = 3;
                    break;
    case "silver" : index = 4;
                    break;
    case "iron"   : index = 5;
                    break;
    case "gem"    : index = 6;
                    break;
    case "stone"  : index = 7;
                    break;
    case "wood"   : index = 8;
                    break;
    default       : index = 9;
                    break;

  }

  if( !intp(durable = this_object()->query_temp("durable_index")) )
  {
    this_object()->set_temp("durable_index",0);
    return;
  }
  this_object()->add_temp("durable_index", index);

  if(durable > 100)
  {
    this_object()->set_temp("durable_index",0);
    set_durable(this_object()->query_durable() - 1);
  }
}

int is_weapon() { return 1; }
