// rice.c

inherit ITEM;
inherit F_FOOD;
#include <ansi.h>

void create()
{
	set_name(HIR"°ª¸d¦Ì¶º"NOR, ({ "rice", "mi fan" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "¤@¸J­»¼Q¼Qªº°ª¸d¦Ì¶º¡C\n");
		set("unit", "¸J");
		set("value", 80);
		set("food_remaining", 4);
		set("food_supply", 10);
		set("material", "rice");
	}
	setup();
}

