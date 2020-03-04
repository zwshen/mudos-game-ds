#include <armor.h>

inherit WAIST;

void create()
{
	set_name("¥É¨Ø",({"jade"}) );
	set("long","¤@ªT¥Î¥ÉÀJµZ¦Ó¦¨ªº¥É¨Ø¡C\n");
      set_weight(200);
        set("unit","ªT");
	if (clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","ªT");
        set("value",80);           
		set("material","jade");
		set("armor_prop/armor",1);
	}
	setup();
}
