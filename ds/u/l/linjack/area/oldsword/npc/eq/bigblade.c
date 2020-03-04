#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
	set_name("雙手大刀", ({ "two-handed great blade","blade" }) );
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這把刀總長近六尺, 奇重無比, 不過仍然十分鋒利, 臂力強大者也\n"
                            "需雙手方可提動此刀, 若是臂力稍弱者, 恐怕連令它出鞘的能力也沒有。\n");
		set("value", 5000);
		set("material", "steel");
		set("limit_skill",25);
		set("limit_str",35);
		set("limit_con",25);
        }
    set("weapon_prop/dex",-3);
    set("weapon_prop/int",-3);
    set("weapon_prop/hit",-5);
    init_blade(60,TWO_HANDED);
    setup();
}
