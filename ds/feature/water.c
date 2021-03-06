// water.c

#include <dbase.h>
#include <name.h>

void init()
{
	add_action("do_drink", "drink");
}

int do_drink(string arg)
{
	string type,msg;
	int hp,mp,ap,k=0;
	object ob;
	if( !this_object()->id(arg) ) return 0;
	if(!arg)
	{
		notify_fail("你想喝什麼??\n");
		return 0;
	}
	
	if(!this_object()->query("no_get")) //不是放在地上的
	{
		ob=present(arg,this_player());
		if(ob != this_object()) return 0;
	}
	
	if( this_player()->is_busy() )
		return notify_fail("你上一個動作還沒有完成。\n");
	if( !query("water_remaining") )
		return notify_fail( name() + "已經沒什麼可以喝了。\n");
	hp=query("heal_hp");
	mp=query("heal_mp");
	ap=query("heal_ap");
//	if(!hp && !mp && !ap)
//		return notify_fail( "未知的飲料回復類型。(需設定 \"heal_hp\"或\"heal_mp\"或\"heal_mp\")\n");
	if( hp || mp || ap )
	{
		if( hp && this_player()->query("hp") < this_player()->query("max_hp") ) k++;
		if( ap && this_player()->query("ap") < this_player()->query("max_ap") ) k++;
		if( mp && this_player()->query("mp") < this_player()->query("max_mp") ) k++;
		if(k==0) return notify_fail("你已經喝太多了﹐再也喝不下任何飲料了。\n");
		if( query("eat_func") )	 // 無限制飲用
		{
			message_vision("$N喝了幾口" + name() + "裡的水。\n", this_player());
			if(this_player()->query("level") > query("eat_func"))
				write("你覺得水很清涼。\n");
			else
			{
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
	add("water_remaining", -1);
	
	if( !query("water_remaining") )
	{
		if(!msg=query("finish_drink_msg")) msg="$N一口氣把剩下的$n喝個精光。\n";
		message_vision(msg, this_player(),this_object());
		// This allows customization of drinking effect.
		query("water/function");
		this_object()->finish_eat();
		if(this_object()) destruct(this_object());
	} else 
	{
		if(!msg=query("drink_msg")) msg="$N拿起$n喝了幾口。\n";
		message_vision(msg, this_player(),this_object());
		// This allows customization of drinking effect.
		query("water/function");
	}
	return 1;
}

int is_water() { return 1; }
