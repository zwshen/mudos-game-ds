#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
	set_name(HIB"高級激光劍"NOR,({"laser sword","sword"}));
	set_weight(15000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這是市面上流行的高級激光劍\n");
		set("value", 9000);
		set("material", "iron");
	}
     init_sword(30);
	setup();
}