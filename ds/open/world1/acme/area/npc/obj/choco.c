inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name("情人巧克力", ({ "melting chocolate","chocolate" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一個心形的巧克力，看起來十分好吃。\n");
                set("unit", "個");
                set("value",1000);
                set("heal_ap",100);
                set("food_remaining",1);
        }
     setup();
}
