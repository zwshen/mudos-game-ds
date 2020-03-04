#include <armor.h>

inherit F_ARMOR;

void create()
{
        set_name("鯊皮盔甲", ({ "shark armor", "armor" }) );
        set_weight(15000);
        setup_armor();

        if( !clonep() ) {
                set("unit", "套");
                set("value", 1000);
                set("long", 
"這是一套用鯊魚皮做成的盔甲，你還聞得到上頭殘留的血腥味。\n"
                );
                set("wear_as", "armor");
                set("apply_armor/armor", ([
                        "armor": 15,
                        "dodge": -10,
                        "str":1,
                        "dex":-1,
                ]));
        }

        setup();
}

