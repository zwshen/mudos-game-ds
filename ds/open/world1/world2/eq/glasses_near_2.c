#include <armor.h>
#include <ansi.h>
inherit MASK;
void create()
{
	set_name("近視眼鏡", ({ "nearsightedness glasses","glasses" }) );
	set("long",@LONG
這是一副近視三百度的近視眼鏡。
LONG
);
	set_weight(580);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "副");
		set("material", "glass");
	}
	set("armor_prop/armor",2);
//	set("armor_prop/show_damage",1);
	setup();
	set("value",650);
}

int query_autoload() { return 1; }
