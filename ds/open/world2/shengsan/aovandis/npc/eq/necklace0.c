
#include <armor.h>

inherit NECK;

void create()
{
	set_name("翡翠項鍊",({"jade necklace","necklace"}));
	set("long",@LONG
這條項鍊是由許多的綠色的翡翠串成的，鮮明的光澤讓人愛不釋手。
LONG
	);
	set_weight(850);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "gem");
		set("unit", "串");
		set("value",725);
		set("armor_prop/shield",2);
	}
	setup();
}
