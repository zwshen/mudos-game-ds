#include <armor.h>
#include <ansi.h>

inherit WRISTS;

void create()
{
	set_name(HIC"藍藍的天專用護臂"NOR,({"bluesky wrists","wrists"}) );
	set("long","這是藍藍的天專用護臂。\n");
	set_weight(2800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "對");
		set("material", "steel");
//		set("value",1800);
		set("armor_prop/armor", 10);
        	set("armor_prop/dodge", 10);
	}
	setup();
}

int query_autoload() { return 1; }
