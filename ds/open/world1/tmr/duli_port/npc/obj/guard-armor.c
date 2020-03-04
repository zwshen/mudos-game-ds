#include <armor.h>

inherit F_ARMOR;

void create()
{
        set_name("警用盔甲", ({ "police armor", "armor" }) );
        set_weight(15000);
        setup_armor();

        if( !clonep() ) {
                set("unit", "套");
                set("value", 550);
                set("long", 
"這是一套警用的厚重盔甲，由於使用較高級的金屬材料，在防禦上也比較有效果。\n"
                );
                set("wear_as", "armor");
                set("apply_armor/armor", ([
                        "armor": 12,
                        "dodge": -5,
                        "parry": 2,
                ]));
        }

        setup();
}
