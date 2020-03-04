#include <weapon.h>
#include <ansi.h>
inherit AXE;
void create()
{
	set_name("雙刃闊斧", ({ "broad axe","axe" }) );
	set_weight(13000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "這柄斧頭左右都有闊刃, 而且尖端還有一根短錐, 份量不輕, 想要\n"
                            "單手拿起它似乎不太可能, 不過雙手揮舞此斧殺敵的威力十分驚人。\n");
		set("value", 2500);
		set("material", "steel");
		set("limit_skill",30);
		set("limit_str",40);
		set("limit_con",15);
        }
    set("weapon_prop/dex",-2);
    set("weapon_prop/hit",-15);
    init_blade(50,TWO_HANDED);
    setup();
}
