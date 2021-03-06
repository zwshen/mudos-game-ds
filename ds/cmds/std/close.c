// close.c

#include <room.h>
#include <box.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	mapping doors;
          string *dirs, dir;
	int i,code;
	object env,obj;
	
	if( !arg ) return notify_fail("你要關閉什麼﹖\n");
	env=environment(me);
	if(!env) return 0;
	
	if(obj=present(arg, env))
	{
		if(obj->is_box())
		{
			code=obj->close_cover();
			switch(code)
			{
				case 1:	
					message_vision("$N把$n的"+obj->query("cover_name")+"關上了。\n",me,obj);
					return 1;
					break;
				case COVER_NONE: return notify_fail(obj->name()+"並沒有蓋\子。\n");
				case COVER_CLOSED: return notify_fail(obj->name()+"的"+obj->query("cover_name")+"已經是關著的。\n");
				case COVER_SMASHED: return notify_fail(obj->name()+"的"+obj->query("cover_name")+"已經壞了。\n");
				default:
					return notify_fail("出了點問題了!請找巫師幫忙解決!!\n 錯誤代號: open_lock="+code+"\n");
			}
        } else return notify_fail("你要把"+obj->name()+"關上!?\n");
	}
	
	doors = env->query_doors();
	if( mapp(doors) )
	{
		dirs = keys(doors);
		if( member_array(arg, dirs)!=-1 ) dir = arg;
		else for(i=0; i<sizeof(dirs); i++)
			if( arg==doors[dirs[i]]["name"] || member_array(arg, doors[dirs[i]]["id"])!=-1 ) {
				dir = dirs[i];
				break;
			}
		if( !dir ) return notify_fail("這個方向沒有門。\n");
		if( doors[dir]["status"] == DOOR_SMASHED )
	        	return notify_fail("這個" + doors[dir]["name"] + "已經壞了。\n");

		if( !(doors[dir]["status"] == DOOR_OPENED) )
			return notify_fail( doors[dir]["name"] + "已經是關著的了。\n");

		if( env->close_door(dir) ) {
			message_vision("$N將" + doors[dir]["name"] + "關上。\n", me);
			return 1;
		} 
	} else return notify_fail("這裡沒有門。\n");

	return 0;
}

int help(object me)
{
        write(@HELP
指令格式 : close <door> 或 <方向>
 
這個指令可以讓你關上門.
 
HELP
    );
    return 1;
}
