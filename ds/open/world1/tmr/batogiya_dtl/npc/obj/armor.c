#include <armor.h>

inherit F_ARMOR;

void create()
{
    set_name("青銅護甲", ({ "bronze armor", "armor" }) );
    set_weight(11000);
    setup_armor();

    if( !clonep() ) {
        set("unit", "件");
        set("value", 600);
        set("long", "一件青銅製成的護甲，看起來相當沉重，但是可以保護你的生命安全。");
        set("wear_as", "armor");
        set("apply_armor/armor", ([
            "armor": 10,
        ]));
    }

    setup();
}

