#include <ansi.h>
#include <weapon.h>
inherit AXE;
void create()
{
        set_name( MAG "通天斧" NOR , ({ "tung tian axe","axe" }) );
        set_weight(14000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("unit", "把");
                set("limit_str",10);
               set("long", "這是一把巨大的斧頭，上頭有青天白雲的圖案。\n");
                  set("value",3000);
		set("volume",5);
               set("material", "iron");
        }
    init_axe(40);
   setup();
}
