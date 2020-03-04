#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
	set_name(HIR"鬼頭刃"NOR, ({ "ghost blade","blade" }) );
	set_weight(9000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這是一把刀柄上刻有一個鬼頭的刀, 看來有一股神秘的力量。\n");
		set("material", "blacksteel");
		set("value",2000);
		set("limit_str",10);
	}
    set("weapon_prop/int",1);
    init_blade(18);
    setup();
}

