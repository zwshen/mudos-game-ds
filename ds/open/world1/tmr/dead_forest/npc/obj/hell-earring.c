#include <armor.h>

inherit F_FINGER_EQ;

void create()
{
        set_name("地獄之耳", ({ "hell earring", "earring" }) );
        set_weight(100);
        setup_finger_eq();

        if( !clonep() ) {
                set("unit", "枚");
                set("value", 5000);
                set("long",@LONG
這是一枚用徹體黝黑的獅骨所做成的耳環。
LONG
                );
                set("wear_as", "earring_eq");
                set("apply_armor/earring_eq", ([
                        "armor" : 1,
                        "cor" : 1,
                ]));
        }

        setup();
}
