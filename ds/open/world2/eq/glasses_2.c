#include <armor.h>
#include <ansi.h>
inherit MASK;
void create()
{
	set_name("太陽眼鏡", ({ "sunglasses" }) );
	set("long",@LONG
這一副太陽眼鏡的顏色相當深，可以降低強光對眼睛的傷害。
LONG
);
	set_weight(650);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "副");
		set("material", "glass");
	}
	set("armor_prop/armor",2);
//	set("armor_prop/show_damage",1);
	setup();
	set("value",700);
}

//int query_autoload() { return 1; }
