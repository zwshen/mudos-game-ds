inherit ITEM;
void create()
{
	set_name("金沙",({ "golden sand","sand" }));
	set_weight(1000);

	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long","一種從不知何處撈起來的物質，似乎除了賣掉還想不出什麼功\用。\n");
		set("unit","堆");
		set("value",100);
	}
	setup();
}