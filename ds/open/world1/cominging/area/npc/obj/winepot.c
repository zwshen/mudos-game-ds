#include <ansi.h>
inherit ITEM;
inherit F_WATER;

void create()
{
	set_name(YEL"一瓶瓶的酒甕"NOR,({"wine bodega","wine","bodega"}));
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","一整甕的酒在裡面懸蕩，你可以試著用(potation)喝喝看。\n");
		set("unit","堆");
		set("no_get",1);
		set("no_sac",1);
		set("value",1);
//		set("heal_mp",random(10));
//		set("heal_ap",1+random(10));
//		set("water_remaining",30);
	}
	setup();
}