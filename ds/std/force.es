// force.c

inherit SKILL;

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int damage;

	me->add("force", - factor );
	damage = (int)me->query("force")/20 + factor
		- (int)victim->query("force")/25;

	if( damage < 0 ) {
		if( !me->query_temp("weapon")
		&&	random(victim->query_skill("force")) > me->query_skill("force")/2 ) {
			damage = - damage;
			me->receive_damage( "kee", damage * 2 );
			me->receive_wound( "kee", damage );
			if( damage < 10 ) return "$N受到$n的內力反震﹐悶哼一聲。\n";
			else if( damage < 20 ) return "$N被$n以內力反震﹐「嘿」地一聲退了兩步。\n";
			else if( damage < 40 ) return "$N被$N以內力一震﹐胸口有如受到一記重鎚﹐連退了五六步﹗\n";
			else return "$N被$n的內力一震﹐眼前一黑﹐身子向後飛出丈許\﹗﹗\n";
		}
		if( damage_bonus + damage < 0 ) return - damage_bonus;
		return damage;
	}

	damage -= victim->query_temp("apply/armor_vs_force");
	if( damage_bonus + damage < 0 ) return - damage_bonus;
	if( random(me->query_skill("force")) < damage )
		return damage;
}
