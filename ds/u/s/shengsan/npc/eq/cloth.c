#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name(HIC"藍藍的天專用衣服"NOR,({"blueksy cloth","cloth"}));
	set("long","這是一件藍藍的天專用衣服。\n");
	set_weight(420);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "fur");
		set("unit", "件");
//		set("value",4200);
        	set("armor_prop/armor", 10);
		set("armor_prop/dodge", 10);
	}
	setup();
}

int query_autoload() { return 1; }
