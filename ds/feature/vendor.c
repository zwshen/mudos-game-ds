// vendor.c
// #pragma save_binary
#include <dbase.h>

int buy_object(object me, string what)
{
	string ob;

	if( stringp(ob = query("vendor_goods/" + what)) )
		return ob->query("value");
	else
		return 0;
}

void compelete_trade(object me, string what)
{
	string ob_file;
	object ob;

	if( stringp(ob_file = query("vendor_goods/" + what)) )
	{
		ob = new(ob_file);
		ob->move(me);
		message_vision("$N向$n買下一" + ob->query("unit") + ob->query("name") + "。\n",
			me, this_object() );
	}
}

string price_string(int v,int time)
{
	if(time == 1)
	{
		return v + "枚古幣";
	}
	else if(time == 2)
	{
		return v + "枚金幣";
	}
	else if(time == 3)
	{
		return v + "點補給配額";
	}
	else return v + "個貨幣(此時空貨幣尚未定義)";
	
}

int do_vendor_list(string arg)
{
	mapping goods;
	string list, *name;
	int i;

	if( !mapp(goods = query("vendor_goods")) ) return 0;
	if( arg && !this_object()->id(arg) ) return 0;
	name = keys(goods);
	list = "你可以購買下列這些東西﹕\n";
	for(i=0; i<sizeof(name); i++)
		list += sprintf("%-30s﹕%s\n",
			name[i],
			price_string(goods[name[i]]->query("value"),this_object()->money_type()));
	write(list);
	return 1;	
}
