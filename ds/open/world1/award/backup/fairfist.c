#include <weapon.h>
#include <ansi.h>
inherit FIST;
void create()
{
	set_name("鐵骨爪", ({ "iron fist","fist" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "對");
		set("long", "這對鐵爪十分鋒利, 在徒手作戰時可以增加不少的\n"
                            "攻擊火力。\n");
		set("needaward",15);
		set("material", "silver");
	set("value",1);
	}
    set("weapon_prop/con",1);
    set("weapon_prop/str",2);
    init_fist(30);
    setup();
}

int query_autoload() { return 1; }
