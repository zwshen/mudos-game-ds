#include <ansi.h>
#include <weapon.h>

inherit FIST;

void create()
{
        set_name(HIY"六陽融雪爪"NOR,({"sun-snow-fist","fist"}) );
        set("long",
"一把看來金芒四射的利爪，摸在手裡頗為炙燙。\n"
);
        set_weight(2000);
        if (clonep() )
                     set_default_object(__FILE__);
        else {
        set("unit","個");
          set("value",3000);
        set("material","gold");
		set("volume",2);
        set("limit_str",10);
          set("limit_level",14);
        }
	init_fist(38);
setup();
}

