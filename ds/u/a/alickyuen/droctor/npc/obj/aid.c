#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("急救箱", ({ "first aid box","box" }) );
	set_weight(600);
	if( clonep() ) set_default_object(__FILE__);
	else
	{
		set("value",1000);
		set("unit","個");
                set("long",
                        "一個急救箱，提供給醫生來進行急救時用。\n");
	}
	setup();
}



                