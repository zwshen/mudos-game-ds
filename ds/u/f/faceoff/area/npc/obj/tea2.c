inherit ITEM;
inherit F_WATER;

void create()
{
        set_name("蔘茶", ({ "tea",}) );
        set_weight(80);
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long", "一壺看起來很補的蔘茶。");

                set("unit", "壺");
        }

                set("value", 300);
                set("heal_mp",30);      
                set("heal_ap",30);
                set("water_remaining", 10);
       setup();
}

