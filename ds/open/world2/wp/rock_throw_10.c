#include <weapon.h>
inherit THROWING;
void create()
{
        set_name("石頭",({"stone"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
	        set("base_unit", "顆");
	        set("unit", "堆");
		set("base_volume",1);
		set("base_weight",300);
		set("material", "rock");
	set("long",@LONG
一顆雞蛋般大小的石頭。
LONG);
	}
	init_throwing(10);
	setup();
        set("value",30);
        set("volume", 1);
        set_amount(1);
}
