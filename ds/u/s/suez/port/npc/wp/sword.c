#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("短劍",({"short sword","sword"}) );
        set_weight(1500);
        if (clonep() )
                set_default_object(__FILE__);
        else {
         set("long","短劍是很容易上手的武器，適合初期冒險者使用。\n");
         set("material","iron");
         set("unit","把");
         set("value",500);
        }
        set("wield_msg","$N從劍鞘中拿出一把$n當武器。\n");
        init_sword(10);
        setup();        
}
