
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name( "牛肉乾" , ({ "beef meat","meat", "_BEEF_MEAT_" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("value", 80);
                set("long", "這是一片好吃的牛肉乾。\n");
                set("unit", "片");
                set("food_remaining", 5); 
                set("heal_ap",10);   
                  set("heal_mp",10);   
        }
        setup();
}

