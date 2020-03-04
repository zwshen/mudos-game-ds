#include <armor.h>
#include <ansi.h>
inherit NECK;
void create()
{
	set_name(HIB"八卦符令"NOR, ({ "eight necklace","necklace" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long","這個小小的八卦符令, 在平常人眼裡只有驅邪的作用,\n"
                           "但這經過特別加持過的符令, 卻可以提升對法術的防禦力。\n");
		set("unit", "條");
		set("material", "cloth");
		set("needaward",35);
	set("value",1);
	}
	set("armor_prop/wit",2);
	set("armor_prop/bio",-1);
	set("armor_prop/bar",-1);
	set("armor_prop/int",5);
	set("armor_prop/shield",25);
	setup();
}

int query_autoload() { return 1; }
