// celestial.c

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{
	if( (int)me->query("bellicosity") < (int)me->query_skill("celestial") * 50 )
		return notify_fail("你的殺氣不夠﹐無法領悟更高深的天邪神功\。\n");

	return 1;
}

int practice_skill(object me)
{
	return notify_fail("天邪神功\只能用學的﹐或是從運用(exert)中增加熟練度。\n");
}

string exert_function_file(string func)
{
	return CLASS_D("fighter") + "/celestial/" + func;
}

