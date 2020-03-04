// hairpin.c

#include <armor.h>

inherit F_HEAD_EQ;

void create()
{
        set_name("黃色頭巾", ({ "yellow cap", "cap" }));
        set_weight(200);
        setup_head_eq();
        if( !clonep() ) {
                set("unit", "條");
                set("value", 100);
                set("long", "一條沾滿風沙的頭巾。\n");
                set("wear_as", "head_eq");
                set("apply_armor/head_eq/armor", 2);
        }
        setup();
}

