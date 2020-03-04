inherit ITEM;
inherit F_WATER;

void create()
{
        set_name("石雕水池", ({ "pot" }) );
        set_weight(9900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("no_get",1);
		set("no_sac",1);
                set("long", "一個雕刻精緻的水池，固定在地上，給過往口渴的人飲用。\n");
                set("unit", "座");
                set("value", 20);
                set("drink_msg", "$N低頭在石雕水池喝了幾口•\n");
                  set("heal_ap",10+random(5));
                  set("heal_mp",10+random(5));
                  set("heal_hp",10+random(5));
                  set("water_remaining",300);          
        }
}

