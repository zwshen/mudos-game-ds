#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
 	string msg;
        int damage;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『月影心眼流 雷破』只能對戰鬥中的對手使用。\n");
	if( me->query("hp") < 250 || me->query("mp") < 200 )
                return notify_fail("你的體力或生命力已經不夠了.\n");
	msg = HIC "$N退後一步，巨喝一聲，『月影心眼流 雷破』應聲使出﹐\n$N手上發出大光芒擊向$n!!﹐";
	damage = me->query_skill("moonthunder") + me->query("str") * 3 +me->query("dex") * 2 + me->query("mp");
	me->start_busy(3);
        me->add("mp",-140);
        me->add("hp",-100);
    if( 22 + random(me->query_skill("thundersword")) > 44 ) {
		msg += "結果$p被$P應聲擊中﹗\n" NOR;
		target->start_busy(1);
                target->add("hp",-damage+random(400));
	} else {
		msg += "在千鈞一髮之際，$p閃了開去。\n" NOR;
	}
	message_vision(msg, me, target);
    COMBAT_D->report_status(target,1);

	return 1;
}
