
#include <weapon.h>

inherit DAGGER;

void create()
{
        set_name("尺匕",({"dagger"}) );
          set_weight(1500);
        if (clonep() )
                set_default_object(__FILE__);
        else {
        set("long","一尺長的匕首，但還不夠格稱為一把短劍。\n");
       set("material","copper");
              set("unit","把");
      set("value",800);
        }
              set("wield_msg","$N手上一晃，拿起了一把$n當武器。\n");
          init_dagger(10);
        setup();        
}