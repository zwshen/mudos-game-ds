#include <armor.h>
inherit WAIST;

void create()
{
	set_name("彩虹腰帶" ,({ "rainbow belt" , "belt" }) );
	set("long","一條看起來顏色十分鮮豔的腰帶，像是一條彩虹一般。\n");
	set_weight(600);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "條" );
		set("value" , 500);
		set("armor_prop/armor", 5);
	}
	setup();
}
