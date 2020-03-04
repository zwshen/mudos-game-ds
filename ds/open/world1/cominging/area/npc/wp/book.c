#include <weapon.h>

inherit HAMMER;

void create()
{
	set_name("課本", ({ "book"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "一本充滿古文的書籍，你看也看不懂！\n");
		set("value", 150);
		set("material", "paper");
		set("limit_int",15);
		set("limit_lv",5);
		set("wield_msg", "$N拿出了一本$n，拿在手上讀了起來！！\n");
		set("unwield_msg", "$N將$n闔上，收了起來。\n");
		set("weapon_prop/int",2);
	}
	init_hammer(25);
	setup();
}