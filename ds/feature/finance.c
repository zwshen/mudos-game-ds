// finance.c
// can_afford() checks if this_object() can afford a price, it returns:
//
//	0:	cannot afford.
//	1:	can afford with proper money(coins).
//	因為加上自動換幣的功能....所以原本無法兌換的傳回值已經用不到了......
//
//
//
// int receive_money(amount)
// 請用這個來做得錢(付錢)的動作∼ amount 為所得到的錢 (當 amount > 0 )
// 若 amount 為負值則為 付錢
//
//
//
// #pragma save_binary

int money_type()
{
	string env_dir, buffer1, buffer2;
        if(!environment()) return 0;
        env_dir = base_name(environment());
        
        if(sscanf(env_dir,"/open/%s/%s",buffer1,buffer2)!=2)
        {
        	return 0;
        }
        
        switch(buffer1)
        {
        	case "world1": return 1;
        	case "world2": return 2;
        	case "world3": return 3;
        	default: return 0;
        }
        
	return 0;

}

int money_count(int flag)
{
	int total=0;
	object coin;
        string env_dir, buffer1, buffer2;

        env_dir = base_name(environment());
        if(sscanf(env_dir,"/open/%s/%s",buffer1,buffer2)!=2)
        {
        	return 0;
        }
        
        switch(buffer1)
        {
        	case "world3": return this_object()->query("bank/future");
        	
        	case "world2": 
        			if( coin = present("dollar",this_object()) )
        			{
        				total += coin->value();
        				if(flag) destruct(coin);
        			}
        			return total;
        			break;
        	case "world1": 
				if(coin = present("past_money",this_object()))
        			{
        				total += coin->value();
        				if(flag) destruct(coin);
        			}
        			return total;
        			break;
        	default: return 0;
        }
	return total;
}

int can_afford(int amount)
{
	int total;

	total = money_count(0);
	if( total >= amount )
	{
		return 1;	//傳回 1 表示有足夠的錢幣來付款
	}
	else
	{
		return 0;	//傳回 0 表示錢幣不足
	}
}

int receive_money(int amount)
{
	int total,type;
          object coin;
        
	type = money_type();
	
	if(amount>0)
	{
		if(type == 3)
		{
			this_object()->add("bank/future",amount);
			return amount;
		}
	
		if(type == 2)
		{
			coin = new("/obj/money/dollar.c");
			coin->set_amount( amount );
                        if(coin->can_move(this_object())!=1) // ! -> !=1 by alickyuen因can_move會return msg.
			{
				write("你要先丟掉一些東西才拿的動喔!!\n");
				//coin->move(environment());
				return 0;
			} else coin->move(this_object());
			return amount;
		}

		coin = new("/obj/money/coin.c");
		coin->set_amount( amount );
                        if(coin->can_move(this_object())!=1) // ! -> !=1 by alickyuen因can_move會return msg.
		{
			write("你要先丟掉一些東西才拿的動喔!!\n");
			//coin->move(environment());
			return 0;
		} else coin->move(this_object());
		return amount;
	}
	
	total = money_count(0);
	total += amount;

	money_count(1);	//加上flag = 1 表示清除金錢
	if( total < 0 ) return -1;
	if( total == 0) return 0;
	if(type == 3)
	{
		this_object()->set("bank/future",total);
		return amount;
	}
	
	if(type == 2)
	{
		coin = new("/obj/money/dollar.c");
		coin->set_amount( total );
		if(!coin->move(this_object())) coin->move(environment());
		return amount;
	}

	coin = new("/obj/money/coin.c");
	coin->set_amount( total );
	if(!coin->move(this_object())) coin->move(environment());
	return amount;
}


