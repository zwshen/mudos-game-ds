// «æ±Ï§Ş¥©(livesaving)  
// ¥~¬ìÂå¥Í 

#include <ansi.h>
inherit SKILL;
int exert(object me, object target)
{
        if(!objectp(present("first aid box",me) ) ) 
                return notify_fail("§A±o¥ı¦³±ÏÅ@¤u¨ã¡C\n");
	if( !target ) target = me;
	if( !living (target) )
     		return notify_fail("³o¤£¬O¥Íª«³á¡I\n");
	if((int)me->query("ap") < 10 )
		return notify_fail("§Aªº¤º«lÂI¼Æ¤£°÷¡T\n");
	 if( me->query_temp("ex_sav") )
	    return notify_fail("§A¥¿¦b¬Iªk¡C\n");
	me->add("ap", -10);
	me->set_temp("ex_sav"); 
	me->start_busy(2);
	message_vision("\n $N®³¥X±ÏÅ@¤u¨ã¨ÓÀ°$n¥]²Ï¶Ë¤f..\n\n",me, target);
	call_out("do_heal",2,me,target);
return 1;
}

int do_heal(object me, object target)
{
  if(!me) return 0;
  if(target!=present(target->query("id"), environment(me)))
  {
    me->delete_temp("ex_sav");
    return notify_fail("¹ï¶H¦ü¥G¤£¦b³o¸Ì¡C\n");
  }
	message_vision("$n¨­¤Wªº¶Ë¤f´_¦X¤F¡C\n",me, target);
// ¤£ª¾¦³¨S¼g¿ù
me->improve_skill("livesaving",20+random(10));
	target->receive_curing("head", random(me->query_skill("livesaving")/10));
	target->receive_curing("body", random(me->query_skill("livesaving")/10));
	target->receive_curing("left_arm", random(me->query_skill("livesaving")/10));
	target->receive_curing("right_arm", random(me->query_skill("livesaving")/10));
	target->receive_curing("left_leg", random(me->query_skill("livesaving")/10));
	target->receive_curing("right_leg", random(me->query_skill("livesaving")/10));
	me->delete_temp("ex_sav");
	return 1;
}

