// sword.c : an example weapon

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	set_name(HIC"電光劍"NOR, ({ "laiser sword","sword" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這是未來常用的武器。\n");
		set("value", 400);
		set("material", "platminum");
		set("wield_msg", "$N按下"HIC"電光劍"NOR"的鈕,突然射出一把劍。\n");
		set("unwield_msg", "$N將手上的"HIC"電光劍"NOR"收藏起來。\n");
	}
    init_sword(250);
	setup();
}
void init()
{
	add_action("do_remove","remove");	
}

int do_remove(object traget)
{
	object weapon;
//	query_temp("weapon");  
	weapon=this_player()->query_temp("weapon");
	weapon->unequip(); 
	weapon->move(environment(this_player()));  
	return 1;	

}
