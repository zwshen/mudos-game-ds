#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
	set_name("灰色勁裝" ,({ "grey cloth","cloth" }) );
	set("long","這是件官兵統一穿著的制服。\n");
	if ( clonep() )
		set_default_object(__FILE__);
	else {
set("volume",3);
		set_weight(2500);
		set("material", "cloth");
		set("unit", "件" );
		set("value",1000);
	}
	set("armor_prop/armor", 10);
	setup();
}
