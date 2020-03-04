#include <armor.h>

inherit F_CLOTH;

void create()
{
        set_name("野獸皮衣", ({ "monster cloth", "cloth" }) );
        set_weight(2000);
        setup_cloth();

        if( !clonep() ) {
                set("unit", "件");
                set("value", 300);
                set("long", "這是一件不知用什麼野獸皮做成的皮衣。\n");
                set("wear_as", "cloth");
                set("apply_armor/cloth", ([
                        "armor": 2,
                ]));
        }

        setup();
}

