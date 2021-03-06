// serpentforce.c

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
	if( !environment(me)->query("resource/water") )
		return notify_fail("伏蛟功\只能在有水的地方練。\n");
	if( (int)me->query("kee") < 30 )
		return notify_fail("你的氣不夠。\n");
	if( (int)me->query("force") < 10 )
		return notify_fail("你的內力不夠");
	me->receive_damage("kee", 30);
	me->add("force", -10);
	return 1;
}

string exert_function_file(string func)
{
	return CLASS_D("beggar") + "/serpentforce/" + func;
}
