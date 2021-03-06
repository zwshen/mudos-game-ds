// close.c

#include <room.h>
#include <box.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	mapping doors;
	string *dirs, dir, key, mykey,dest;
	int i;
	object *inv, env,keyob,obj;
	
	if( !arg ) return notify_fail("你要開什麼鎖﹖\n");

	env = environment(me);
	if(!env) return 0;
	
	if( sscanf(arg, "%s with %s", dest, key)==2 )
	{
		if(!keyob=present(key, me)) return notify_fail("你身上並沒 "+key+"。\n");
		if(obj=present(dest, env))
		{
			if(obj->is_box())
			{
				switch(obj->query_cover_status())
				{
					case COVER_NONE : return notify_fail(obj->name()+"並沒有地方可以讓你開鎖。\n");
					case COVER_OPENED : return notify_fail(obj->name()+"的"+obj->query("cover_name")+"已經是開著的啦。\n");
					case COVER_SMASHED : return notify_fail(obj->name()+"的"+obj->query("cover_name")+"都已經壞了還開什麼鎖?!\n");
				}
				switch(obj->query_lock_status())
				{
					case LOCK_NONE : return notify_fail(obj->name()+"並沒有地方可以讓你開鎖。\n");
					case LOCK_OPENED : return notify_fail(obj->name()+"的"+obj->query("cover_name")+"並沒有上鎖。\n");
					case COVER_SMASHED : return notify_fail(obj->name()+"的鎖已經壞了無法打開。\n");
				}
				
				if(obj->open_lock(keyob)==1)
				{
					message_vision("『..喀啦!!』$N用"+keyob->name()+"將$n的鎖打開了。\n",me,obj);
					return 1;
				} else return notify_fail("『..啪!!』你似乎把"+obj->name()+"的鎖給弄壞了。\n");
			} else return notify_fail("那個東西沒有辦法讓你開鎖。\n");
		}
	}
	doors = env->query_doors();
	if( mapp(doors) )
	{
		dirs = keys(doors);
		if( member_array(arg, dirs)!=-1 ) dir = arg;
		else for(i=0; i<sizeof(dirs); i++)
			if( arg==doors[dirs[i]]["name"] || member_array(arg, doors[dirs[i]]["id"])!=-1 )
			{
				dir = dirs[i];
				break;
			}
		if( !dir ) return notify_fail("這個方向沒有門。\n");
			
		if( doors[dir]["status"] == DOOR_SMASHED )
	        	return notify_fail("這個" + doors[dir]["name"] + "已經壞了。\n");
		if( doors[dir]["status"] == DOOR_OPENED  )
			return notify_fail( doors[dir]["name"] + "已經是開著的了。\n");
		if( !(doors[dir]["status"] == DOOR_LOCKED)  ) 
            		return notify_fail(doors[dir]["name"] + "並沒有上鎖。\n");
		key=env->query_door(dir,"key");
		if(!key ) return notify_fail("你沒合適的鑰匙開鎖!\n");
		if(!keyob)
		{
			if(env->query("free_lock/"+dir))
			{
        	 			if(env->unlock_door(dir))
        	 			{
	       	   		 		message_vision("『..喀.啦!!.』"+"$N將" + doors[dir]["name"] + "的鎖打開了。\n", me);
	       	   				return 1;
		 			}	
			}
			
			inv = all_inventory(me);
			for(i=0;i<sizeof(inv);i++)
			{
				mykey=inv[i]->query("door");
	        		if(mykey==key)  
	        		{
	        	 		if(env->unlock_door(dir))
	        	 		{
		       	   		 	message_vision("『..喀.啦!!.』"+"$N用"+inv[i]->query("name")+"將" + doors[dir]["name"] + "的鎖打開了。\n", me);
		       	   			return 1;
			 		}
				}
			}
			return notify_fail("你沒合適的鑰匙開鎖。\n");
		} else
		{
			mykey=keyob->query("door");
			if(mykey==key)
			{
	        		if(env->unlock_door(dir))
	        		{
			 		message_vision("『..喀.啦!!.』"+"$N用"+inv[i]->query("name")+"將" + doors[dir]["name"] + "的鎖打開了。\n", me);
					return 1;
				} else return notify_fail("你無法成功\的將"+doors[dir]["name"]+"的鎖打開。\n");
			}
			else return notify_fail("你的"+keyob->name()+"與門上的鎖並不符合。\n");	
		}
	} else return notify_fail("這裡沒有門。\n");
	return 0;
}

int help(object me)
{
        write(@HELP
        
  指令格式 : unlock <door||方向> with <鑰匙>
  指令格式 : unlock <物品> with <鑰匙>
 
  這個指令可以讓你用鑰匙開鎖.
 
HELP
    );
    return 1;
}
