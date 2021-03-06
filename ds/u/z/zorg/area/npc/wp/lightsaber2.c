// sword.c : an example weapon

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	set_name(HIR"光劍"NOR, ({ "lightsaber","saber" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這是"BLK"『黑武士』"NOR"常用的武器。\n");
		set("value", 150000);
		set("no_sac",1);
		set("limit_int",20);
		set("limit_str",15);
		set("no_drop",1);
		set("no_give",1);
		set("no_get",1);
		set("no_sell",1);
		set("rigidity",500);
		set("material", "laser");
		set("wield_msg", "$N從腰上拿出一把$n,突然射出一道"HIR"激光"NOR"。\n");
		set("unwield_msg", "$N將手上的$n放回腰間。\n");
	}
    init_sword(50);
	setup();
}
int query_autoload() { return 1; }
