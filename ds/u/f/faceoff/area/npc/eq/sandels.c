#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
	set_name("硬革草鞋", ({ "sandels","boots" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","這草鞋的外面有加一層硬皮, 增加對地的磨擦力.\n");
		set("unit", "件");
		set("material", "fur");
		set("armor_prop/shield",1);
		set("armor_prop/armor",2);
	}
	setup();
}
