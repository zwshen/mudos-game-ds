// ·¥¥úµ²¬É¤§³N -Luky-
// 

#define WALLNAME "·¥¥úµ²¬É"

#include <ansi.h>
#include <obj.h>
inherit SKILL;

int cast(object me, object target,string dir)
{
	if( !target ) return notify_fail("§A¥²¶·«ü©w¤@­Ó¤è¦V¤~¯à¬I®i¦¹µ²¬É³N¡C\n");

	if( !target->is_room())
		return notify_fail("¦¹ªk³N¥u¯à¥Î©ó©Ð¶¡¡C\n");
	if( living (target) )
     		return notify_fail("¦¹ªk³N¤£¯à¥Î©ó¥Íª«¤W¡I\n");
	if( environment(me)->query("no_magic") )
     		return notify_fail("³o­Ó¦a¤è¤£¥i¥H¬Iªk¡I\n");
	if( environment(me)->query_temp("wall/"+dir))
		return notify_fail("³o­Ó¤è¦V¤w¸g¦³µ²¬É¤F¡I\n");
	if((int)me->query("mp") < 40 )
		return notify_fail("§Aªºªk¤O¤£°÷¡T\n");

	 if( me->is_busy() )
	    return notify_fail("§A¤W¤@­Ó°Ê§@ÁÙ¨S§¹¦¨¡C\n");
	    
	me->add("mp", -40);
	me->start_busy(2);
	message_vision("\n[1;35m$N°ªÁ|Âù¤â... ¶}©l¬I®i·¥¥ú¤§³N...[0m\n\n",me);
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
     	tell_object(me,"³o­Ó¦a¤è¤£¥i¥H¬Iªk¡I\n");
     	return 1;
  }
  if( env->query_temp("wall/"+dir))
  {
	tell_object(me,"³o­Ó¤è¦V¤w¸g¦³µ²¬É¤F¡I\n");
	message_vision("$Nªº·¥¥úµ²¬É³N¬I®i«Å§i¥¢±Ñ¡C\n",me);
	return 1;
  }
	if( random(me->query_int()+20) > me->query_int() )
	{
		message_vision("$Nªº·¥¥úµ²¬É³N¬I®i¥¢±Ñ¤F¡C\n",me);
		return 1;
	}
	
	env->set_temp("wall/"+dir,WALLNAME);
	tell_room(env,"¬ðµM¶¡¤@°}±j¥ú, §A¬Ý¨ì¤­¹D·¥¥ú«Ê¦í¤F"+to_chinese(dir)+"ªº¥X¤f¡I\n");
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
	   tell_room(target,"¬ðµM¶¡¤@°}±j¥ú, §A¬Ý¨ì¤­¹D·¥¥ú«Ê¦í¤F"+to_chinese(dirs[i])+"ªº¥X¤f¡I\n");
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
	 tell_room(environment(wall),"·¥¥úµ²¬É¶}©lÅÜ±o³z©ú¦Ó³vº¥®ø¥¢¤F¡I\n");
	 environment(wall)->delete_temp("wall/"+wall->query("dir"));
	 destruct(wall);
	}
	return 1;
}