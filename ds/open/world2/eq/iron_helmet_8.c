#include <armor.h>
inherit HEAD;

void create()
{
	set_name("鐵製頭盔",({"iron helmet","helmet"}) );
	set("long",@LONG
這是一頂十分堅固的鐵製頭盔。
LONG);
	set_weight(2470);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material","cloth");
		set("unit", "頂");
	}
        set("armor_prop/armor",8);
        setup();
        set("value",910);
        set("volume", 4);
}
int query_autoload() { return 1; }