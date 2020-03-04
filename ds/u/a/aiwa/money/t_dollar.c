// coin.c

inherit MONEY;

void create()
{
	set_name("現金",({"t_dollar"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "t_dollar");
		set("long", "這是現代流通中的萬元貨幣。\n");
		set("unit", "些");
		set("base_value", 10000);
		set("base_unit", "張萬元");
		set("base_weight", 1);
	}
	set_amount(1);
}

