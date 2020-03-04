//eeman, ªk³N­n¥[ delay §A¤£ª¾¹D¶Ü??
// ÁÙ¦³ÂåÀø§Ş¯à¤£¬O¥Î¦b§Aªº¾Ô°«¹ï¶H¨­¤Wªº, ¥Î¤£¨ìSSERVER

#include <ansi.h>
inherit SKILL;
int cast(object me, object target)
{
	if( !target ) target = me;

	if( !target
	||	!target->is_character()
	||	target->is_corpse())
		return notify_fail("§A­n¹ï½Ö¬I®i³o­Óªk³N¡S\n");
	if( !living (target) )
     		return notify_fail(HIY"³o¤£¬O¥Íª«³á¡I\n"NOR);

	if((int)me->query("mp") < 5 )
		return notify_fail("§Aªºªk¤O¤£°÷¡T\n");

	 if( me->query_temp("cast") )
	    return notify_fail("§A¥¿¦b¬Iªk¡C\n");
	    
	me->add("mp", -5);
	me->set_temp("cast","heal");
	me->start_busy(2);
	message_vision("\n[1;35m$N±NÂù¤â©ñ¦b$nªºÂùªÓ, ¤f¤¤°áµÛÂåÀø©G¤å..[0m\n\n",me);
	call_out("do_heal",2,me,target);
}

int do_heal(object me, object target)
{
  string msg;
  
  if(!me) return 0;
  if(target!=present(target->query("id"), environment(me)))
  {
    me->delete_temp("cast");
    return notify_fail("¹ï¶H¦ü¥G²æÂ÷¤F§Aªº¬Iªk½d³ò..\n");
  }
	if( random(me->query("max_mp")) < 30 )
	{
		write("§A¥¢±Ñ¤F¡C\n");
		return 1;
	}

	msg = HIM "$NªºÂù¤â¤@¦X¡M$n¨­®Çº¥º¥»E°_¤@¹Îµµ¥ú¡T\n\n" NOR;

	msg += "$n¨­¤Wªº³Ğ¶Ëº¥º¥«ì´_¤F¡C\n";

	message_vision(msg, me, target);
	me->improve_skill("berserk",1+random(me->query_int()/10));
	target->receive_heal("hp", 50);

	me->delete_temp("cast");
	return 1;
}

