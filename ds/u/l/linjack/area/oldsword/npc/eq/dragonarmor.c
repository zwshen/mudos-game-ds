#include <armor.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit ARMOR;
void create()
{
	set_name(HIC"天龍戰甲"NOR, ({ "dragon armor","armor" }) );
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","這件鎧甲重量不差, 不過防禦力出奇的高, 很適合拿來作戰\n"
                           "用, 不過江湖上少見這種高級的戰甲, 但穿在身上仍有點不舒服.\n");
		set("unit", "件");
		set("value",40000);
		set("material","steel");
		set("limit_con",40);
		set("limit_int",10);
		set("replica_ob",__DIR__"heavyarmor.c");
	}
	set("armor_prop/dex",-3);
	set("armor_prop/dodge",-10);
	set("armor_prop/shield",25);
	set("armor_prop/armor", 45);
	setup();
}
