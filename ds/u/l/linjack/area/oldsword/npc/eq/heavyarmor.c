#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
	set_name(HIC"全身戰鎧"NOR, ({ "full armor","armor" }) );
	set_weight(30000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","這件鎧甲異常的笨重，雖然十分適合用在軍事戰場上面, 但\n"
                           "因為太過笨重, 是沒人穿這種戰甲來行走江湖路的.\n");
		set("unit", "件");
		set("value",9999);
		set("material","steel");
		set("limit_con",40);
		set("limit_int",10);
	}
	set("armor_prop/dex",-5);
	set("armor_prop/dodge",-30);
	set("armor_prop/shield",5);
	set("armor_prop/armor", 38);
	setup();
}
