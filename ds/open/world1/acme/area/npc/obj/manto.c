inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name("饅頭", ({ "manto" }) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一個香噴噴、熱騰騰的饅頭。\n");
                set("unit", "個");
                   set("value",60);
                  set("heal_hp",10);
               set("food_remaining",2);
        }
     setup();
}
