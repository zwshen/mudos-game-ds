#include <armor.h>
inherit LEGGING;
void create()
{
	set_name("護腿", ({ "leggings" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","一雙普通武者練武時套在腿部的東西, 保護關節及腿不受傷。\n");
		set("unit", "雙");
		set("value",500);
		set("material", "linen");
		set("limit_int",5);
	}
	set("armor_prop/armor",2);
	set("armor_prop/shield",1);
	set("armor_prop/dex",1);
	setup();
}
