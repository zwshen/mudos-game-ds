// 書本
inherit ITEM;

void create()
{
	set_name("性愛前奏曲",({"book22222"}) );
	set("long","一本黃色書刊耶。\n");
	set_weight(300);
	if(clonep() )
		set_default_object(__FILE__);
	else
	{
		set("material","paper");
		set("unit","本");
	}
	set("bookauthor","shengsan");	// 書本作者
	set("bookkind",({ "all","sex","性愛","性","情趣" }));	// 書本種類
	set("bookno",22222);	// 書本號碼
	setup();
	set("value",1);
}

int is_book()
{
	return 1;
}
