#include <weapon.h>
inherit WHIP;
void create()
{
    set_name("釣竿",({"fishing rod","rod"}));
    set("long","這是一支釣魚用的釣竿。\n");
    set_weight(2100);
    if( clonep() )
       set_default_object(__FILE__);
    else {
       set("unit", "支");
   set("material", "wood");
		set("value",300);
    }
init_whip(15);
    setup();
}

