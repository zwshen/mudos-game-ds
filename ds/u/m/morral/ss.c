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
		return notify_fail("『狂雷劍 驚日月』只能對戰鬥中的對手使用。\n");
	if( me->query("hp") < 200 || me->query("mp") < 160 )
                return notify_fail("你的體力或生命力已經不夠了.\n");
	msg = HIC "$N使出封雷絕劍必殺技『狂雷劍 驚日月』﹐\n毀天滅地的威力攻向$n!!﹐";
	damage = me->query_skill("thundersword") + me->query("str") * 4 + me->query("mp");
	me->start_busy(3);
        me->add("mp",-100);
        me->add("hp",-80);
    if( 22 + random(me->query_skill("thundersword")) > 44 ) {
		msg += "結果$p被$P重重劈中﹗\n" NOR;
		target->start_busy(1);
                target->add("hp",-damage+random(400));
	} else {
		msg += "可是被$p給閃了開去。\n" NOR;
	}
	message_vision(msg, me, target);
    COMBAT_D->report_status(target,1);

	return 1;
}
