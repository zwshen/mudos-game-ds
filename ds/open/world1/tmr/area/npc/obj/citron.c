inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("西瓜", ({ "citron" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一顆碧綠的西瓜，看來肉多汁溢的模樣，令人食指大動。\n");
                set("unit", "顆");
                set("value", 30);  
                set("food_remaining",3);
                set("heal_hp",3);  
            set("heal_mp",3);
        }
}

