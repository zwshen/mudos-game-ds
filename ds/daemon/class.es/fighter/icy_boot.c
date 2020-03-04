// icy_boot.c

#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
	set_name( HIC "§j³·´Ý¶³¹u" NOR, ({ "icy boots", "boots" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "¥ó");
		set("value", 8000);
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("armor_prop/dodge", 5);
	}
	setup();
}
