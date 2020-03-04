#include <weapon.h>
inherit FORK;

void create()
{
	set_name("長戟", ({ "long halbert" , "halbert" }) );
	set_weight(3400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", 
			"一把沉重的武器，需要有一定的膂力才拿的起來，斧鋒處似乎有些鈍"
			"，不過攻擊力不怎麼的影響。\n");
       set("value",1750);
		set("weapon_prop/hit", 8);
	set("material","steel");
		set("limit_str",13);
	}
	set("wield_msg", "$N裝備起一把$n，有些拿不起來的樣子。\n");
	init_fork(30);
	setup();
}
