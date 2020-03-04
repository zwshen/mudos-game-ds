#include <armor.h>
#include <ansi.h>
inherit NECK;
void create()
{
	set_name("佛珠", ({ "rosary" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","這是一般佛門弟子或佛教徒會佩帶的佛珠.\n");
		set("unit", "串");
		set("value",300);
		set("material","wood");
	}
	set("armor_prop/armor",1);
	set("armor_prop/int",2);
	set("armor_prop/show_damage",1);
	setup();
}
