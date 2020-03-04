// coin.c

inherit MONEY;

void create()
{
	set_name("現金", ({"h_dollar"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "h_dollar");
		set("long", "這是現代流通中的百元貨幣。\n");
		set("unit", "些");
		set("base_value", 100);
		set("base_unit", "張百元");
		set("base_weight", 1);
	}
	set_amount(1);
}

