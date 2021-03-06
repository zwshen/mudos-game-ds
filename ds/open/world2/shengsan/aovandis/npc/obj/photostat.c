// 圖書館電腦	In room121.c
#include <path.h>
#define Base_Copy_Value	5

inherit ITEM;

object bookroom;

void create()
{
	set_name("圖書館影印機",({"library photostat","photostat"}) );
	set("long",@LONG
這台影印機看起來非常的高級(影印費大概也不便宜)，如果需要
影印資料，找它就沒錯了。

	copy [欲拷貝的紙張或雜誌名稱] [份數]
LONG
	);
	set_weight(15000);
	if(clonep() )
		set_default_object(__FILE__);
	else
	{
		set("value",75000);
		set("unit","台");   //luky
	}
	set("no_get",1);
	set("no_sac",1);

	setup();
}

void init() 
{
	add_action("do_copy","copy");
}

int do_copy(string arg)
{
	object me,ob,ob2;
	int i,no,value;
	string papername,filename;

	me = this_player();

	if(!arg)
		return notify_fail("copy [欲拷貝的紙張或雜誌名稱] [份數]\n");
	if(sscanf(arg,"%d",no))
		return notify_fail("copy [欲拷貝的紙張或雜誌名稱] [份數]\n");
	if(!sscanf(arg,"%s %d",papername,no))
	{
		papername = arg;
		no = 1;
	}
	if( no > 10 )
		return notify_fail("抱歉...本影印機一次只能拷貝十份以內的份數...\n");

	value = Base_Copy_Value * no;

	if(ob=present(papername,me))
	{
		if(!ob->can_copy())
		{
			write(ob->query("name")+"並不能在這裡拷貝喔！\n");
			return 1;
		}

		if( me->can_afford(value)!=1 )
		{
			write("你帶的錢不夠喔！\n");
			return 1;
		}

		me->receive_money(-value);
		message_vision("$N將"+F_VENDOR->price_string(value,me->money_type())+"投入$n裡。\n",me,this_object());

		if(sscanf(base_name(ob),"%s_c",filename)==1)
			filename = base_name(ob);
		else
			filename = base_name(ob)+"_c";

		for(i=0;i<no;i++)
		{

			ob2 = new(filename);
			if( ob2->can_move(me) )
			{
				if(ob2->move(me))
					message_vision("$N為$n拷貝了一份" + ob2->query("name") + "。\n", this_object(), me);
				else if(ob2->move(environment(me)))
					message_vision("$N為$n拷貝了一份" + ob2->query("name") + "，不過因為$n拿不住而掉落至地面上。\n", this_object(), me);
				else
				{
					destruct(ob2);
					message_vision("挖哩勒...$N居然被$n玩壞了。\n", this_object(), me);
				}
			}
			else if(ob2->move(environment(me)))
				message_vision("$N為$n拷貝了一份" + ob2->query("name") + "，不過因為$n拿不住而掉落至地面上。\n", this_object(), me);
			else
			{
				destruct(ob2);
				message_vision("挖哩勒...$N居然被$n玩壞了。\n", this_object(), me);
			}
		}	
	}
	else
		write("你並沒有 "+ papername +" 喔!!\n");
	return 1;

}