#include <ansi.h>
#include <weapon.h>
inherit FIST;
void create()
{
        set_name( GRN "鬼爪" NOR , ({ "ghost claw","claw" }) );
      set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("unit", "個");
               set("long", "這是一個透著綠氣的鬼爪。\n");
          set("value",2000);
		set("volume",2);
               set("limit_str",6);
      	       set("limit_dex",5);
               set("limit_int",4);
               set("limit_con",8);
               set("material", "iron");
        }
    init_fist(30);
   setup();
}
