#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("皮衣",({"furrier"}) );
	set("long","一件牛皮所縫製而成的皮衣，看來滿耐穿的。\n");
        set_weight(1200);
	if (clonep() )
		set_default_object(__FILE__);
	else {
		set("volume",3);
		set("unit","件");
		set("value",200);
          set("armor_prop/armor",3);
	}
	setup();
}

