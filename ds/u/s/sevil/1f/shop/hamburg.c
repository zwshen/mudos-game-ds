// hamburg.c

inherit shop;
inherit F_FOOD;

void create()
{
    set_name("大漢堡", ({ "hamburg" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一個香噴噴、熱騰騰的大燒包。\n");
		set("unit", "個");
		set("value", 40);	//參考價格為回復點數總和除以5
		set("heal_hp",10);	//可以是"heal_hp"或是"heal_mp",也可以都有.
		set("heal_mp",10);
		set("food_remaining", 3);
	}
	setup();
}
