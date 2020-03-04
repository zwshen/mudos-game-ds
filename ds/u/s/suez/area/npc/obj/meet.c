inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("ψ爱", ({ "meet" }) );
        set_weight(70);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "ψ爱ぃ笵ノぐ或秸\n");
                set("unit", "");
                set("value", 20);       //把σ基確翴计羆㎝埃5
                set("heal_hp",20);      //琌"heal_hp"┪琌"heal_mp",常Τ.
                set("food_remaining", 5);
        }
        setup();
}
