#include <ansi.h>
#include <weapon.h>
inherit STAFF;
void create()
{
        set_name("手杖",({"staff","staff"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("unit", "把");
               set("long", "這是一把用來撐著走路用的手杖，尤其走山路時特別好用。\n");
set("value",800);
               set("limit_str",1);
               set("limit_con",1);
		set("volume",3);
               set("material", "wood");
        }
init_staff(8);
   setup();
}
