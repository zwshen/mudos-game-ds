#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
	set_name(HIR"烈"NOR"戰袍" ,({ "fight cloth","cloth" }) );
	set("long","一件由皇帝所賜的戰袍，顏色像是火一般。\n");
	set_weight(1200);
	if ( clonep() )
		set_default_object(__FILE__);
	else {
set("volume",3);
        set("material","silk");
		set("unit", "件" );
		set("value", 1100);
		set("armor_prop/armor", 7);
	}
	setup();
}
