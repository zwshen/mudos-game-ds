// coin.c

inherit MONEY;

void create()
{
	set_name("古幣", ({"coin", "coins", "past_money" }));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "coin");
		set("long", "這是古代流通中的貨幣, 是以純銅打造而成的。\n");
		set("unit", "些");
		set("material", "copper"); //銅製品
		set("base_value", 1);
		set("base_unit", "枚");
		set("base_weight", 1);
		set("base_volume", 0.0002);
	}
	set_amount(100000);
}


