#include <armor.h>

inherit F_ARMOR;

void create()
{
        set_name("魔獸戰甲", ({ "evil-monster armor", "armor" }) );
        set_weight(15000);
        setup_armor();

        if( !clonep() ) {
                set("unit", "套");
                set("value", 1500);
                set("long", 
"這似乎是傳說中的魔獸常穿的戰甲，你可以明顯感覺到戰甲上傳出的邪氣。\n"
                );
                set("wear_as", "armor");
                set("apply_armor/armor", ([
                        "armor": 8,
                ]));
        }

        setup();
}

