#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
	set_name("雲袍", ({ "cloud cloth","cloth" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","這件衣服特製的材質和縫製方法, 讓它變成輕而強韌\n"
                           "的高防禦力衣物, 不過看起來像是膺品..:p\n");
		set("unit", "件");
		set("value",5000);
		set("material","cloth");
		set("limit_con",5);
		set("limit_int",10);
	}
	set("armor_prop/dex",1);
	set("armor_prop/armor",8);
	set("armor_prop/shield",4);
	set("armor_prop/show_damage",1);
	setup();
}
