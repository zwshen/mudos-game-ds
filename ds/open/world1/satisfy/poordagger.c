#include <weapon.h>
#include <ansi.h>
inherit DAGGER;
void create()
{
	set_name("小刀", ({ "knife" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "支");
		set("long", "真是一把粗製濫造的短刀.......不過殺殺小動物可以勉強用。\n");
		set("value", 1000);
//		set("no_drop",1);
		set("no_sac",1);
		set("material", "iron");
	}
    set("weapon_prop/hit",10);
    init_dagger(5);
    setup();
}

int query_autoload() { return 1; }