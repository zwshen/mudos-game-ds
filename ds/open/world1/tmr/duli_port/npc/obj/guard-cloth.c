#include <armor.h>

inherit F_CLOTH;

void create()
{
        set_name("綠色制服", ({ "guard cloth", "cloth" }) );
        set_weight(2000);
        setup_cloth();

        if( !clonep() ) {
                set("unit", "件");
                set("value", 250);
                set("long", 
                "這是一件專門給警衛穿的制服，胸前口袋還有一個「警」的字樣。\n"
                );
                set("wear_as", "cloth");
                set("apply_armor/cloth", ([
                        "armor": 3,
                ]));
        }

        setup();
}

