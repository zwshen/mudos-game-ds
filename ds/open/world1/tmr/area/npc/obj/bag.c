inherit ITEM;
inherit F_WATER;

void create()
{
        set_name("水袋", ({ "water bag","bag" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一個牛皮製的袋子，內頭裝的可解渴的清水。\n");
                set("unit", "瓶");
                set("value", 20);       
                set("heal_mp",5);      
                 set("water_remaining", 5);
        }
}
