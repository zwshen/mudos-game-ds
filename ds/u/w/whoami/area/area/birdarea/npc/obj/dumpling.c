inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("肉包子", ({ "dumpling" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一個熱騰騰的牛肉包子，看來滿好吃的樣子。\n");
                set("unit", "個");
                set("value", 60);  
                set("food_remaining",2);
                set("heal_hp",20);  
        }
}
