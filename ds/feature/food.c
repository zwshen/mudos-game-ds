// food.c

#include <dbase.h>
#include <name.h>

void init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
          string msg;
	int hp,mp,ap,k=0;
	object ob;
	if( !this_object() ) return 0;
	if(!arg)
	{
		notify_fail("你想吃什麼??\n");
		return 0;
	}
	if( !this_object()->id(arg) ) return 0;
	if(!this_object()->query("no_get")) //不是放在地上的
	{
		ob=present(arg,this_player());
		if(ob != this_object()) return 0;
	}
	if( this_player()->is_busy() )
		return notify_fail("你上一個動作還沒有完成。\n");
	if( !query("food_remaining") )
		return notify_fail( name() + "已經沒什麼好吃的了。\n");
	hp=query("heal_hp");
	mp=query("heal_mp");
	ap=query("heal_ap");
//	if(!hp && !mp && !ap)
//		return notify_fail( "未知的食物回復類型。(需設定 \"heal_hp\"或\"heal_mp\"或\"heal_ap\")\n");
	if( hp || mp || ap )
	{
		if( hp && this_player()->query("hp") < this_player()->query("max_hp") ) k++;
		if( ap && this_player()->query("ap") < this_player()->query("max_ap") ) k++;
		if( mp && this_player()->query("mp") < this_player()->query("max_mp") ) k++;
		if(k==0) return notify_fail("你已經吃太飽了﹐再也塞不下任何東西了。\n");
		if( query("eat_func") )	 // This allows customization of drinking effect.無限制食用
		{
			message_vision("$N吃了幾口" + name() + "。\n", this_player());
			if(this_player()->query("level") > query("eat_func"))
		  		write("你覺得肚子有點怪怪的。\n");
			else
			{
		  		if(hp)
				{
					this_player()->receive_heal("hp", hp);
				}
				if(mp)
				{
		 			this_player()->receive_heal("mp", hp);
				}
				if(ap)
				{
					this_player()->receive_heal("ap", ap);
				}
			  	write("你覺得一股力量流入了你的身體。\n");
			}
			return 1;
		}
		if(hp)
		{
			this_player()->receive_heal("hp", hp);
		}
		if(mp)
		{
			this_player()->receive_heal("mp", mp);
		}
		if(ap)
		{
			this_player()->receive_heal("ap", ap);
		}
	}

	if( this_player()->is_fighting() ) this_player()->add_block(1);

	set("value", 0);
	add("food_remaining", -1);
	if( !query("food_remaining") )
	{
		if(!msg=query("finish_eat_msg")) msg="$N拿起$n剩下的部分, 大口吞了下去。\n";
		message_vision(msg, this_player(),this_object());
		query("food/function");
		this_object()->finish_eat();
		if(this_object()) destruct(this_object());
		return 1;
	} else
	{
		if(!msg=query("eat_msg")) msg="$N拿起$n吃了幾口。\n";
		query("food/function");
		message_vision(msg, this_player(),this_object());
	}
	return 1;
}

int is_food() { return 1; }
