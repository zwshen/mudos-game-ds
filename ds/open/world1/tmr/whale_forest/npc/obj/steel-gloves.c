#include <armor.h>
inherit F_HAND_EQ;
void create()
{
        set_name("鋼製腕甲", ({ "steel bracer", "bracer" }) );
        set_weight(500);
        setup_hand_eq();

        if( !clonep() ) {
                set("unit", "雙");
                set("value", 1200);
                set("long",@long
這是一雙由鋼鐵製成的腕甲，擁有頗佳的防禦能力。
long
                );
                set("wear_as", "hand_eq");
                set("apply_armor/hand_eq", ([
                        "armor": 3,
                        "str":1,
                        "parry":5,
                ]));
        }
        setup();
}

