// 極光結界之術 -Luky-
// 

#define WALLNAME "極光結界"

#include <ansi.h>
#include <obj.h>
inherit SKILL;

int cast(object me, object target,string dir)
{
	if( !target ) return notify_fail("你必須指定一個方向才能施展此結界術。\n");

	if( !target->is_room())
		return notify_fail("此法術只能用於房間。\n");
	if( living (target) )
     		return notify_fail("此法術不能用於生物上！\n");
	if( environment(me)->query("no_magic") )
     		return notify_fail("這個地方不可以施法！\n");
	if( environment(me)->query_temp("wall/"+dir))
		return notify_fail("這個方向已經有結界了！\n");
	if((int)me->query("mp") < 40 )
		return notify_fail("你的法力不夠﹗\n");

	 if( me->is_busy() )
	    return notify_fail("你上一個動作還沒完成。\n");
	    
	me->add("mp", -40);
	me->start_busy(2);
	message_vision("\n[1;35m$N高舉雙手... 開始施展極光之術...[0m\n\n",me);
	call_out("do_wall",2,me,target,dir);
	return 1;
}

int do_wall(object me, object target,string dir)
{
  object env,wall1,wall2;
  string msg,other_dir,*exit,*dirs,file;
  mapping exits;
  int i;
  
  if(!me) return 0;
  if(!env = environment(me) ) return 1;
  if( env->query("no_magic") )
  {
     	tell_object(me,"這個地方不可以施法！\n");
     	return 1;
  }
  if( env->query_temp("wall/"+dir))
  {
	tell_object(me,"這個方向已經有結界了！\n");
	message_vision("$N的極光結界術施展宣告失敗。\n",me);
	return 1;
  }
	if( random(me->query_int()+20) > me->query_int() )
	{
		message_vision("$N的極光結界術施展失敗了。\n",me);
		return 1;
	}
	
	env->set_temp("wall/"+dir,WALLNAME);
	tell_room(env,"突然間一陣強光, 你看到五道極光封住了"+to_chinese(dir)+"的出口！\n");
	wall1 = new(WALL_LIGHT);
	wall1->move(env);
	wall1->set("dir",dir);
	call_out("break_wall",me->query_skill("lightwall",1)+me->query_int()*2,wall1);
	exits = target->query("exits");
	if(mapp(exits))
	{
	 file = base_name(env);
	 dirs = keys(exits);
	 exit = values(exits);
	 for(i=0;i<sizeof(exit);i++)
	 {
	  if(exit[i]==file)
	  {
	   target->set_temp("wall/"+dirs[i],WALLNAME);
	   tell_room(target,"突然間一陣強光, 你看到五道極光封住了"+to_chinese(dirs[i])+"的出口！\n");
	   wall2 = new(WALL_LIGHT);
	   wall2->move(target);
	   wall2->set("dir",dirs[i]);
	   call_out("break_wall",me->query_skill("lightwall",1)+me->query_int()*2,wall2);
	  }
	 }
	}
	me->improve_skill("lightwall",1+random(me->query_int()/6));
	return 1;
}

int break_wall(object wall)
{
	if(environment(wall))
	{
	 tell_room(environment(wall),"極光結界開始變得透明而逐漸消失了！\n");
	 environment(wall)->delete_temp("wall/"+wall->query("dir"));
	 destruct(wall);
	}
	return 1;
}