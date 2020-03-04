// manto.c

inherit COMBINED_ITEM;
inherit F_FOOD;

void create()
{
	set_name("白饅頭", ({ "manto" }));
	if( !clonep() ) {
		set("unit", "堆");
		set("base_unit", "個");
		set("base_value", 10);
		set("base_weight", 100);
		set("food_stuff", 80);
		set("long", "一個香噴噴的白饅頭，握在手裡頭有種感動的感覺。\n");
	}
	setup();
}

