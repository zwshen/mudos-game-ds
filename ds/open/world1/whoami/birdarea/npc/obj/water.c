inherit ITEM;
inherit F_WATER;

void create()
{
        set_name("山泉水", ({ "water" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一瓶裝有山泉水的瓶子。\n");
                set("unit", "瓶");
                set("value", 180);       
                set("heal_mp",30);      
                 set("water_remaining", 3+random(5));
        }
}

