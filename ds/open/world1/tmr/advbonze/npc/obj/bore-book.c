inherit ITEM;

void set_warname(string id)
{
	set("long",query("long")+"\n試鍊者："+id +"    妙見緘");
        set("owner_user",id);
}

void create()
{
	set_name("般若心經",({"bore book","book","_BUDDHA_WAR_BOOK_"}) );
	set_weight(80);
	set("long",@long
一本般若心經，你翻了翻幾頁，竟都是梵文寫成的經文，你一個字也
看不懂。
long
);
	if(clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit","本");
		set("value",0);
	}
	setup();
}
