inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name("柚子果肉", ({ "fruit" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一個多汁，甜美的果肉。\n");
                set("unit", "個");
                set("value",200);
                set("heal_hp",30);
                set("food_remaining",2);
        }
     setup();
}
