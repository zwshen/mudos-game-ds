
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("軟糖", ({ "soft sweets","soft","sweets" }) );
	set_weight(160);
	if( clonep() )
	set_default_object(__FILE__);
	else {
	set("long","好吃可口的軟糖。\n");
	set("unit", "顆");
	}
        set("heal_mp",15);
	set("value",15);
	set("food_remaining",1);
 setup();
}
