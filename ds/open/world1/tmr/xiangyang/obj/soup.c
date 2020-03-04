// soup.c

inherit ITEM;
inherit F_LIQUID;
#include <ansi.h>
void create()
{
	set_name(HIG"³¥µæ´ö¸J"NOR, ({"soup"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "¤@¸J·sÂA³¥µæ°µªº´ö¡C\n");
		set("unit", "¸J");
		set("value", 80);
        set("max_liquid", 4);
    }

    // because a container can contain different liquid
    // we set it to contain tea at the beginning
    set("liquid", ([
        "type": "water",
        "name": "³¥µæ´ö",
        "remaining": 6,
        "drunk_supply": 15,
    ]));
}
