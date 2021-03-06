// transfer.c

#include <ansi.h>

inherit SSERVER;

int exert(object me, object target)
{
	int force, trans;

	if( !target || target==me || !living(target) )
		return notify_fail("你要將真氣傳給誰﹖\n");

	if( (string)me->query_skill_mapped("force") != target->query_skill_mapped("force") )
		return notify_fail(target->name() + "所使用的內功\和你不同。\n");

	if( (int)me->query("force") <= (int)me->query("max_force") )
		return notify_fail("你的真氣不足。\n");

	force = me->query("force") - me->query("max_force");

	if( force/2 < 1 ) return notify_fail("你的真氣不足。\n");
	me->add("force", - force / 2 );
	message_vision("$N將手掌貼在$n背心﹐運氣將體內真氣傳送過去。\n", me, target);
	if( random(force/3) > (int)me->query_skill("force") )
		return notify_fail("你失敗了。\n");
	target->add("force", force/3);
	write("Ok.\n");
	tell_object(target, HIY "你覺得一股熱氣從" + me->name() + "的手掌傳了過來。\n" NOR);
	return 1;
}
