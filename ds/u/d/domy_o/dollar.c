// coin.c

inherit MONEY;

void create()
{
	set_name("金幣",({"golden dollar","dollar"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "dollar");
		set("long", "由純金打造而成的錢幣, 是現代流通中的貨幣。\n");
		set("unit", "些");
		set("base_value", 1);
		set("base_unit", "枚");
		set("base_weight", 1);
	}
	set_amount(1);
}


