
#include <armor.h>
inherit WRISTS;

void create()
{
	set_name("運動護臂",({"sport wrists","wrists"}) );
	set("long",@LONG
這是一對橡膠製的護臂，用來避免運動可能造成的擦傷。
LONG
);
	set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "對");
		set("material", "rubber");
	}
	set("auto_set",2);
	setup();
}

//int query_autoload() { return 1; }
