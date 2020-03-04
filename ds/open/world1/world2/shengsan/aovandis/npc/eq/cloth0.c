
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("花格襯衫",({"lattice shirth","shirth"}) );
	set("long","這是一件有著花色格子圖樣的襯衫。\n");
	set_weight(1300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "件");
		set("value",230);
        }
        setup();
}

int query_autoload() { return 1; }
