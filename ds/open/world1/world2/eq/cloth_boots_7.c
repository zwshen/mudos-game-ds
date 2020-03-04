#include <armor.h>
inherit BOOTS;

void create()
{
	set_name("훫쾧푖",({"basketball boots","boots"}) );
	set("long",@LONG
쿽촑�@찬♪↙↘†쩧�~ず훫쾧푖좧
LONG
);
	set_weight(3200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "cloth");
		set("unit", "찬");
	}
	set("value",1670);
	set("armor_prop/armor", 7);
	setup();
	set("volume", 4);
}

int query_autoload() { return 1; }
