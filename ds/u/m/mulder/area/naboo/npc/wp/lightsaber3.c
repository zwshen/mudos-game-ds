// sword.c : an example weapon

#include <weapon.h>
#include <ansi.h>
inherit FORK;
inherit F_UNIQUE;

void create()
{
	set_name(HIR"雙刃光劍"NOR, ({ "sith double lightsaber","pike" }) );
	set_weight(18000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這是"HIR"『赤武神』"NOR"的專用武器。\n");
		set("value", 150000);
		set("no_sac",1);
		set("limit_int",20);
		set("limit_str",15);
		set("no_drop",1);
		set("no_get",1);
		set("no_sell",1);
		set("rigidity",500);
		set("material", "blacksteel");
		set("wield_msg", "$N從腰上拿出一把$n,突然頭尾分別射出兩道"HIR"激光"NOR"。\n");
		set("unwield_msg", "$N將手上的$n放回腰間。\n");
		set("replica_ob",__DIR__"lightsaber4");
	}
    init_fork(80);
	setup();
}
int query_autoload() { return 1; }
