inherit ITEM;
inherit F_WATER;
void create()
{
        set_name("白靈湯", ({ "white soul-soup","soup" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "由紫陽山上所補捉的白蛇，燉起來香氣四溢，增益心氣。\n");
                set("unit","碗");
                    set("value",300);
           set("heal_ap",40);
                set("water_remaining",5);
        }
     setup();
}

