inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name("紅豆月餅", ({ "bean moon cake","cake" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "這是一個在中秋節才能買得到的月餅哦，這種口味能夠恢復你的生命力。\n");
                set("unit", "個");
                set("value",500);
                set("heal_hp",50);
                set("food_remaining",2);
        }
     setup();
}

