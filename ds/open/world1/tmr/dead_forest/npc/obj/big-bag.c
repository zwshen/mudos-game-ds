// bag.c

inherit ITEM;

void create()
{
        set_name("大麻布袋", ({ "big bag", "bag" }));
        set_weight(700);
        set_max_encumbrance(50000);
        if( !clonep() ) {
                set("unit", "隻");
                set("value", 30);
                set("long", "一隻麻布口袋，看來可以裝不少東西。\n");
        }
        setup();
}

int accept_object() { return 1; }

