#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
	set_name(HIR"可口可樂-鎧甲"NOR, ({ "CocaCola","armor" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","這件寶甲外層隱透白光, 如同月暈, 不知有何奇效....\n");
		set("unit", "件");
		set("material", "steel");
		set("no_drop",1);
		set("no_sac",1);
		set("value",34000);
		set("armor_prop/con",1);
		set("armor_prop/dex",2);
		set("armor_prop/int",1);
		set("armor_prop/dodge",5);
		set("armor_prop/shield",10);
		set("armor_prop/armor", 10);
	}
	setup();
}

int query_autoload() { return 1; }