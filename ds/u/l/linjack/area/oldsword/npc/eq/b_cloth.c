#include <armor.h>
inherit CLOTH;
void create()
{
	set_name("袈裟", ({ "buddhist cloth","cloth" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","這是一件佛家子弟修道有成之後, 通常都會穿上的\n"
                           "長袍, 蠻厚重的, 穿上後有些不便於快速行動.\n");
		set("unit", "件");
		set("value",1000);
		set("material", "linen");
	}
	set("armor_prop/dex",-1);
	set("armor_prop/int",1);
	set("armor_prop/armor",3);
	set("armor_prop/shield",5);
	set("armor_prop/show_damage",1);
	setup();
}
