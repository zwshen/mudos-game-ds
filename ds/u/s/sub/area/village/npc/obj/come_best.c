inherit ITEM;
inherit F_WATER;
void create()
{
        set_name("康貝特", ({ "come best","come","best" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",@LONG
一瓶綠色的康貝特，冰冰涼涼的非常好喝。
LONG);
                set("unit","瓶");
                set("value",400);
                set("heal_ap",30);
                set("water_remaining",2);
        }
     setup();
}
