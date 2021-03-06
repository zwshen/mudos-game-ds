// open.c

#include <room.h>
#include <box.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	mapping doors;
	string *dirs, dir;
	int i,code;
	object env,obj;
	
	if( !arg ) return notify_fail("你要打開什麼﹖\n");
	
	env = environment(me);
	if(!env) return 0;
	if(obj=present(arg, env))
	{
		if(obj->is_box())
		{
			code=obj->open_cover();
			switch(code)
			{
				case 1:	
					message_vision("$N把$n的"+obj->query("cover_name")+"打開了。\n",me,obj);
					return 1;
					break;
				case COVER_NONE: return notify_fail(obj->name()+"並沒有蓋\子。\n");
				case COVER_OPENED: return notify_fail(obj->name()+"的"+obj->query("cover_name")+"已經是開著的。\n");
				case COVER_SMASHED: return notify_fail(obj->name()+"的"+obj->query("cover_name")+"已經壞了。\n");
				case LOCK_CLOSED: return notify_fail(obj->name()+"的"+obj->query("cover_name")+"被鎖住了沒辦法打開。\n");
				default:
					return notify_fail("出了點問題了!請找巫師幫忙解決!!\n 錯誤代號: open_lock="+code+"\n");
			}
		} else return notify_fail("你要打開"+obj->name()+"﹖\n");
	}

	doors = env->query_doors();
	if( mapp(doors) ) {
		dirs = keys(doors);
		if( member_array(arg, dirs)!=-1 ) dir = arg;
		else for(i=0; i<sizeof(dirs); i++)
			if( arg==doors[dirs[i]]["name"] || member_array(arg, doors[dirs[i]]["id"])!=-1 )
			{
				dir = dirs[i];
				break;
			}
		if( !dir ) return notify_fail("這個方向沒有門。\n");
		if( doors[dir]["status"]==DOOR_LOCKED  ) 
			return notify_fail(doors[dir]["name"] + "是鎖著的。\n");
		if( doors[dir]["status"] == DOOR_OPENED )
			return notify_fail( doors[dir]["name"] + "已經是開著的了。\n");

		if( env->open_door(dir) ) {
			message_vision("$N將" + doors[dir]["name"] + "打開。\n", me);
			return 1;
		}
	} else return notify_fail("這裡沒有門。\n");
	
	return 0;
}

int help(object me)
{
        write(@HELP
指令格式 : open <door> 或 <方向>
 
這個指令可以讓你打開門.
 
HELP
    );
    return 1;
}
