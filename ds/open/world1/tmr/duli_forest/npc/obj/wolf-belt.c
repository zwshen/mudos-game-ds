#include <armor.h>

inherit F_WAIST_EQ;

void create()
{
          set_name("狼子帶", ({ "wolf belt", "belt","_OBJ_ID_WOLF_BELT_" }) );
        set_weight(300);
        setup_waist_eq();

        if( !clonep() ) {
                set("unit", "條");
                set("value", 150);
                set("long", "這是一條織有野狼圖案的腰帶。\n");
                set("wear_as", "waist_eq");
                set("apply_armor/waist_eq", ([
                                        "cor": 1,
                ]));
        }

        setup();
}


