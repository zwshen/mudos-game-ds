#include <armor.h>

inherit HEAD;

void create()
{
    set_name("土司羽帽", ({ "toast hat", "hat" }) );
    set_weight(500);
	set("long","相當罕見的帽子，是土人族群中荒野土司的花冠大羽毛帽。");

	if ( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("volume",3);
		set("unit", "頂");
		set("value", 1200);
	}
	setup();
}

