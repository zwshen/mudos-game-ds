#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
	set_name("布衣", ({ "cloth" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","一件極其簡陋的布衣.\n");
		set("unit", "件");
		set("material", "cloth");
		set("armor_prop/shield",2);
		set("armor_prop/armor", 2);
	}
	setup();
}
