#include <weapon.h>

inherit F_BLADE;

void create()
{
        set_name("屠刀", ({ "butcher knife", "knife" }) );
        set_weight(2500);
        setup_blade( 1, 10, 10,0);

        if( !clonep() ) {
                set("wield_as", ({"blade","secondhand blade"}));
                set("unit", "把");
                set("value", 1200);
                set("rigidity", 50);
                set("long",@LONG
這是一把廚師常用的屠刀，大都只是製刀工廠機器打磨出來的。
LONG
                );
        }
        setup();
}
