
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("小蛋糕",({ "small cake","small","cake" }) );
	set_weight(350);
	if( clonep() )
	set_default_object(__FILE__);
	else {
	set("long","這個小蛋糕做得蠻精緻的。\n");
	set("unit", "塊");
	}
        set("heal_mp",9);
        set("heal_ap",21);
	set("value",30);
	set("food_remaining",1);
 setup();
}
