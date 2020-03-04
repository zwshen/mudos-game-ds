#include <armor.h>
inherit F_HAND_EQ;
void create()
{
        set_name("葵籹得ヒ", ({ "steel bracer", "bracer" }) );
        set_weight(500);
        setup_hand_eq();

        if( !clonep() ) {
                set("unit", "蛮");
                set("value", 1200);
                set("long",@long
硂琌蛮パ葵臟籹Θ得ヒ局Τ会ㄎň縨
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

