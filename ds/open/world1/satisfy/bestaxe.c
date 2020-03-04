#include <weapon.h>
#include <ansi.h>
inherit AXE;
void create()
{
	set_name(HIC"湛藍斧"NOR, ({ "best blue axe","axe" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這把巨斧十分細緻, 斧面呈天藍色, 斧刃極其鋒利,\n"
                            "是一把不可多得的好斧頭。\n");
		set("value", 20000);
//		set("no_drop",1);
		set("no_sac",1);
		set("material", "steel");
	}
    set("weapon_prop/con",2);
    set("weapon_prop/bar",1);
    init_axe(30);
    setup();
}

int query_autoload() { return 1; }