inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name( "獸肉" , ({ "animal meat","meat", "_BEEF_MEAT_" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("value", 80);
                set("long", "這是一片血淋淋的生獸肉。\n");
                set("unit", "片");
                set("food_remaining", 5); 
                set("heal_hp",10);   
                set("heal_ap",10);    
        }
        setup();
}


