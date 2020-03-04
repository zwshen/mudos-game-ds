
#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
set_name(HIG"夜"HIR"靈"HIY"玉"NOR,({ "Jade of Night Spirit" , "sword"}));
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
set("long", "這是天草四郎的佩劍，紫刃青鋒，是其當年斬殺夜靈牙羅取其元玉所鑄成\n");
		set("value", 400);
		set("material", "steel");
set("wield_msg", "$N冷然地笑著，$n大綻光芒落入$N的手�堙C\n");
set("unwield_msg", "一陣刺目光芒後$n消失無蹤。\n");
	}
init_sword(35);
	setup();
}
