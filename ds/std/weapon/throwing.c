// throwing.c
// #pragma save_binary
#include <weapon.h>

inherit COMBINED_ITEM;
inherit F_EQUIP;

int weapon_damage(string material,int weight);

void setup()
{
	::setup();
	
	if( clonep(this_object()) ) return;
	set("skill_type", "throwing");
	if(!query("base_value") ) set("base_value", query("value"));
	if(!query("base_unit"))
	{
		if(query("unit")) set("base_unit",query("unit"));
		else set("base_unit", "��");
	}
	if(!query("unit")) set("unit","��");
	if(!query("base_weight"))
	{
		set("base_weight", weight());
	}
	if(!query("base_volume"))
	{
		if(query("volume")) set("base_volume",query("volume"));
		else set("base_volume", 1);
	}
	if( !query("actions") ) {
		set("actions", (: call_other, WEAPON_D, "query_action" :) );
		set("verbs", ({ "throw" }) );
	}
	if(!query_amount()) set_amount(1);
}

varargs void init_throwing(int damage, int flag)
{
	if(!this_object()->query("material"))
		this_object()->set("material","plant");
	damage += weapon_damage(query("material"),weight());
	set("weapon_prop/damage", damage);
	set("flag", flag);
	if(!query("limit_str"))	set("limit_str",weight()/1500);
}

int weapon_damage(string material,int weight)
{
	return 0;

}

int is_weapon() { return 1; }
