inherit ITEM;
void create()
{
	set_name("童玩",({ "toy" }));
	set_weight(1000);

	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long","一個小孩子玩的玩具。\n");
		set("unit","個");
		set("value",50);
	}
	setup();
}