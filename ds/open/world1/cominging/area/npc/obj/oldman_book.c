inherit ITEM;

void create()
{
	set_name("小冊子", ({ "book", "wu_lin_me_gei" }));
	set("long", "這是一本小冊子, 上面記載著許\多武功\. \n");
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "本");
		set("value", 1);
		set("no_sell", 1);
		set("no_sac", 1);
	}
	setup();
}