#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
        set_name("龍頭刀" , ({ "dragon blade","blade" }) );
     set_weight(9000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("unit", "把");
      set("limit_str",8);
 set("limit_dex",5);
                              set("limit_str",5);
               set("long", "這是在刀柄處雕著龍頭的大刀，似乎威力強大，但頗為沉重。\n");
              set("value",2000);
               set("rigidity",300);
               set("material", "iron");
		set("volume",4);
        }
	init_blade(40,TWO_HANDED);
   setup();
}
