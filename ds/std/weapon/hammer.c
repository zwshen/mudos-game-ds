// hammer.c
// #pragma save_binary
#include <weapon.h>

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
	set("skill_type", "hammer");
	if( !query("actions") ) {
		set("actions", (: call_other, WEAPON_D, "query_action" :) );
		set("verbs", ({ "bash", "crush", "slam" }) );
	}
}

varargs void init_hammer(int damage, int flag)
{
	if(!this_object()->query("material"))
		this_object()->set("material","plant");
	damage += weapon_damage(query("material"),weight());
	set("weapon_prop/damage", damage);
	set("flag", flag );
	if(!query("limit_str"))	set("limit_str",weight()/1500);
}

int weapon_damage(string material,int weight)
{
	return 0;

}

void attack(object me,object victim)
{
  int index, durable;
  string material;


  if( !stringp(material = this_object()->query("material")) )
  {
    error("ITEM : material ��ƫ��A���~.\n");
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
