#include <weapon.h>
inherit WHIP;
void create()
{
    set_name("竹鞭",({"bamboo whip","whip"}));
    set_weight(3000);
    if( clonep() )
       set_default_object(__FILE__);
    else {
		set("unit", "支");
		set("material", "wood");
		set("long",@LONG
這是一支用竹子削成的竹鞭。
LONG);
    }
	init_whip(5);
    	setup();
	set("value",300);
	set("volume", 6);
}

