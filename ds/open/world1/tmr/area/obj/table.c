//table.c
inherit  ITEM;
void  create()
{
	set_name("石桌",({"table"}));
	set_weight(200000);
        set("long","這是張大理石製的桌子。\n");
	if(clonep()) set_default_object(__FILE__);
	else
	{
		set("unit",  "張");
		set("material",  "stone");
		set("value",  2000);
		set("no_get",  1);
		set("amount",30);
	}
	setup();
}

string long()
{
	string str,temp;
    str="這是張大理石製的桌子。\n\n";
	if(environment()) temp=environment()->show_game();
	if(strlen(temp)>2) str+=temp;
	return str;
}
