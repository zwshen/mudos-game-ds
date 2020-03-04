inherit ITEM;
inherit F_WATER;

void create()
{
        set_name("¥Õ¤z", ({ "wine",}) );
        set_weight(80);
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long", "¤@²~¯P°s¡C");
                set("unit", "²~");
        }
                set("value", 80);       
                set("heal_mp",10);      
                set("heal_ap",20);
                set("heal_hp",15);
                set("water_remaining", 4); // 9->4 by alick
       setup();
}

