#include <weapon.h>
inherit BOW;

void create()
{
        set_name("杉木弓",({"wooden bow","bow"}));
        set("long","這是一把杉木製的弓，可(shoot)射出箭。\n");
        set_weight(5000);
            if( clonep() )
               set_default_object(__FILE__);
        else {
        set("unit", "把");
        set("value",690);
        set("volume",3);
        set("material","wood");
        }
        set("monster_weapon_prop/damage", 20);
        init_bow(20);
        setup();
}
