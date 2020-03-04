// cookie.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("翴み", ({ "cookie" }) );
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "癬ㄓ芞翴み\n");
                set("unit", "");
                set("value", 0);       //把σ基確翴计羆㎝埃5
                set("heal_hp",10);      //琌"heal_hp"┪琌"heal_mp",常Τ.
                set("heal_mp",10);
                set("food_remaining", 2);
        }
        setup();
}

