inherit ITEM;
inherit F_WATER;

void create()
{
        set_name("啤酒", ({ "beer" }) );
        set_weight(60);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "啤酒, 用大麥釀造而成。\n");
                set("unit", "袋");
                set("value", 16);       
                set("heal_mp",20);     
                set("water_remaining", 3);
        }
        setup();
}


