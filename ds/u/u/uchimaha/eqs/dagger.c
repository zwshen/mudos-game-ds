#include <weapon.h>
#include <ansi.h>
inherit DAGGER;

void create()
{
        set_name(HIW"便便"HIC"匕首"NOR,({"blood_dagger","dagger"}) );
        set("long","一把沾有便便的匕首。\n");
          set_weight(5000);
        if (clonep() )
                set_default_object(__FILE__);
        else {
              set("unit","把");
      set("value",800);
        }
              set("wield_msg",HIC"$N小心翼翼的把把手上的便便擦掉才握上。\n"NOR);
          init_dagger(10000);
        setup();        
}
