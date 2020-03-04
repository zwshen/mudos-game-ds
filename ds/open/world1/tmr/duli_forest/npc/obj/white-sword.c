#include <weapon.h>

inherit F_SWORD;

void create()
{
        set_name("白色長劍", ({ "white long sword", "sword" }) );
        set_weight(7000);
        setup_sword(2, 11, 60, 4);

        if( !clonep() ) {
                set("wield_as", "sword");
                set("unit", "把");
                set("value", 1500);
                set("rigidity", 60);
                set("apply_weapon/sword", ([
                        "damage":5,
                        "str":1,
                ]));
                                set("long", @LONG
這是一把頗為沉甸的白色長劍，銳利的劍鋒配著白色的劍柄，更增
添幾份森寒。
LONG
);
        }
        setup();
}

