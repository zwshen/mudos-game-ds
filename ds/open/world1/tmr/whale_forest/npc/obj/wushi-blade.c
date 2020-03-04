#include <weapon.h>

inherit F_BLADE;

void create()
{
        set_name("長武士刀", ({ "wu-shi blade" , "blade" }) );
        set_weight(5000);
        setup_blade( 3 , 8, 90, 0);

        if( !clonep() ) {
                set("wield_as",({ "blade" }) );
                set("unit", "把");
                set("value", 4000 );
                set("rigidity", 120);
                set("long", "這是一把長逾尺的武士刀，刀鋒異常銳利，看的出來殺傷力不低。\n");
       }
        set("apply_weapon/blade", ([
                        "str" : 1,
                    ]) );
        setup();
}

