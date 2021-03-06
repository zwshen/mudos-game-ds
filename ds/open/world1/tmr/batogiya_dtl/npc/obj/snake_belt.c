#include <armor.h>

inherit F_WAIST_EQ;

void create()
{
    set_name("蛇皮腰帶", ({ "snake's skin belt", "belt"}) );
    set_weight(300);
    setup_waist_eq();

    if( !clonep() ) {
        set("unit", "條");
        set("value", 5000);
        set("long", "一條蛇皮製作而成的腰帶，上頭刻著一排看不懂的文字。\n");
        set("wear_as", "waist_eq");
        set("apply_armor/waist_eq", ([
            "int" : 2,
            "armor": 1,
        ]));
    }
    setup();
}
