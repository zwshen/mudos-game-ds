
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("小麵包", ({ "small bread","small","bread" }) );
	set_weight(10);
	if( clonep() )
	set_default_object(__FILE__);
	else {
	set("long","嗯...好香的麵包。\n");
	set("unit", "塊");
	set("value",10);
	set("food_remaining",2);
	}
}
