#include <weapon.h>
#include <ansi.h>
inherit AXE;
void create()
{
   set_name(WHT "巨石斧" NOR ,({"ghost fire axe","axe"}));
   set("long","這是一把石製巨斧，看來並不輕。\n");
   set_weight(20000);   //設重量
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value",1500);
                set("volume",8);
                set("material","rock");
        }
          set("limit_con",25);
          set("limit_str",25);
          set("weapon_prop/dex",-2);
          set("weapon_prop/con",1);
         init_axe(40);
         setup();
}

