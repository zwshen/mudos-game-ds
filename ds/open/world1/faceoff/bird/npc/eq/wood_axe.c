#include <weapon.h>
#include <ansi.h>
inherit AXE;
void create()
{
	set_name("木柄斧", ({ "wood axe","axe" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "一把看來很輕的斧頭。\n");
		set("material", "wood");
	}
    init_axe(5);
    setup();
}

