
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("牛排",({"beefsteak"}) );
	set_weight(10);
	if( clonep() )
	set_default_object(__FILE__);
	else {
	set("long","這個牛排的熟度剛好合你的口味,可要趕快吃完,免得等會涼掉就不好吃囉。\n");
	set("unit", "塊");
	set("value",700);
	set("food_remaining",2);
	}
}
