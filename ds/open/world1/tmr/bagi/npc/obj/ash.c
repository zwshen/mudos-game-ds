inherit ITEM;

void create()
{
	set_name("焦灰",({"ash"}) );
	set_weight(10);
	set("long","一堆焦灰，已看不清原來的樣子。\n");
	if(clonep() )
		set_default_object(__FILE__);
	else
	{
	set("unit","堆");
	set("value",0);
	set("no_sac",1);
	}
	setup();
}