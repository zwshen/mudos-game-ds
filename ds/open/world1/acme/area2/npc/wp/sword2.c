#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
                set_name( HIB "鬼王劍" NOR , ({ "ghost king sword","sword" }) );
      set_weight(12000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("limit_str",15);
               set("limit_dex",10);
		set("volume",3);
               set("unit", "把");
               set("long", "這是一把散發著陰氣的妖劍。\n");
             set("value",3500);
               set("material", "iron");
        }
    init_sword(45);
   setup();
}
