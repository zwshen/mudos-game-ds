#include <weapon.h>
#include <ansi.h>
inherit DAGGER;

void create()
{
        set_name(HIR"血之匕首"NOR,({"blood_dagger","dagger"}) );
        set("long","一把血紅色的匕首，看起來是用上等鋼鐵打造的，威力
並不尋常。\n");
          set_weight(1000);
          if (clonep() )
          set_default_object(__FILE__);
          else {
                 set("unit","把");
                 set("material", "iron");
               }
          set("wield_msg","$N手上血光一現，煞時想要有見血的渴望。\n");
          init_dagger(20);
          setup();        
}
