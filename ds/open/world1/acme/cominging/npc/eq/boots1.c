#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
	set_name(HIG"趐子屐"NOR,({ "shea-gei boots","boots","shea-gei" }) );
    set("long","一雙師傅精心製做的鞋子，外層還包了些銀箔。\n");
	set_weight(2500);
	if ( clonep() )
		set_default_object(__FILE__);
	else {
        set("material", "skin");
set("volume",2);
		set("unit", "件" );
		set("value", 2600);
		set("armor_prop/armor", 9);
		set("armor_prop/shield", 6);
	}
	setup();
}
