#include <armor.h>
inherit LEGGING;
void create()
{
	set_name("生鏽的脛甲" ,({ "rusty leggings","leggings" }) );
	set("long","這只是一雙生鏽的脛甲。\n");
	set_weight(2000);
	if ( clonep() )
		set_default_object(__FILE__);
	else
	{
	set("material", "leather");
	set("volume",5);
	set("unit", "雙");
	set("value",100);
	}
	set("armor_prop/armor",1);
	setup();
}
