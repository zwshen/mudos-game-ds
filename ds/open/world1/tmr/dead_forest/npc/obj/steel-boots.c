#include <armor.h>

inherit F_FEET_EQ;

void create()
{
        set_name("精鋼長靴", ({ "steel boots", "boots" }) );
        set_weight(2500);
        setup_feet_eq();

        if( !clonep() ) {
                set("unit", "雙");
                set("value", 2500);
                set("long",@long
這是一雙精鋼打造的長靴，造型樸素大方，非常地堅固耐穿。
long
                );
                set("wear_as", "feet_eq");
                set("apply_armor/feet_eq", ([
                        "armor": 10,
                        "dex": -1,
                ]));
        }

        setup();
}
