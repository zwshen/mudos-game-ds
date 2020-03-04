inherit ITEM;

void create()
{
	set_name("年獸獎券",({"year paper","paper"}) );
	set_weight(100);
	set("long",@long
一張獎券，由年獸主持的年終抽獎活動中抽來的。	
long
);
	if(clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit","張");
		set("value",1);
	        set("volume",1);
                set("material","paper");
	}
	setup(); 
}

void set_level(int i)
{
	string arg;
	arg ="一張獎券，由年獸主持的年終抽獎活動中抽來的。\n";
	arg+="上頭印了"+chinese_number(i)+"個硃砂大◎印。\n";
	this_object()->set("long",arg);
	this_object()->set("level",i);

	return;
}