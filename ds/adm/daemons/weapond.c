// weapond.c
// #pragma save_binary
#include <ansi.h>
#include <combat.h>

mapping weapon_actions = ([
	"hit": ([
		"damage_type":	"�ˮ`",
		"action":		"$N����$w�M�ĤO���A�V$n��$l",
		"parry":		20,
		"attact_type":  "bar",
		]),
	"slash": ([
		"damage_type":	"�ζ�",
		"action":		"$N����$w�M�٦V$n��$l",
		"parry":		20,
		"attact_type":  "bar",
		]),
	"slice": ([
		"damage_type":	"����",
		"action":		"$N��$w��$n��$l��h",
		"dodge":		20,
		"attact_type":  "bar",
		]),
	"chop": ([
		"damage_type":	"����",
		"action":		"$N��$w�µ�$n��$l�A�N�L�h",
		"parry":		-20,
		"attact_type":  "bar",
		]),
	"hack": ([
		"action":		"$N���R$w�M���$n��$l�@�}�ì�",
		"damage_type":	"����",
		"damage":		30,
		"dodge":		30,
		"attact_type":  "bar",
		]),
	"thrust": ([
		"damage_type":	"���",
		"action":		"$N��$w��$n��$l��h",
		"dodge":		15,
		"parry":		-15,
		"attact_type":  "bar",
		]),
	"pierce": ([
		"action":		"$N��$w��$n��$l�����a�@Ѷ",
		"damage_type":	"���",
		"dodge":		-30,
		"parry":		-30,
		"attact_type":  "bar",
		]),
	"whip": ([
		"action":		"$N�N$w�@���M��$n��$l��h",
		"damage_type":	"�@��",
		"dodge":		-20,
		"parry":		30,
		"attact_type":  "bar",
		]),
	"impale": ([
		"action":		"$N��$w��$n��$l���W�L�h",
		"damage_type":	"���",
		"dodge":		-10,
		"parry":		-10,
		"attact_type":  "bar",
		]),
	"bash": ([
		"action":		"$N���R$w�M��$n��$l�ΤO�@��",
		"damage_type":	"���",
		"post_action":	(: call_other, __FILE__, "bash_weapon" :),
		"attact_type":  "bar",
		]),
	"crush": ([
		"action":		"$N�����|�_$w�M��$n��$l���Y�{�U",
		"damage_type":	"�{��",
		"post_action":	(: call_other, __FILE__, "bash_weapon" :),
		"attact_type":  "bar",
		]),
	"slam": ([
		"action":		"$N�ⴤ$w�M���S�����M�r�a���$n��$l���F�L�h",
		"damage_type":	"���",
		"post_action":	(: call_other, __FILE__, "bash_weapon" :),
		"attact_type":  "bar",
		]),
	"grab": ([
		"action":		"$N�R�ʾU�Q��$w�M�ƨg�a���$n��$l�@�}�r��",
		"damage_type":	"���",
		"post_action":	(: call_other, __FILE__, "bash_weapon" :),
		"attact_type":  "bar",
		]),
	"punch": ([
		"action":		"$N��C����, �f�����O, �r�M�µ�$n��$l�s�o�T��",
		"damage_type":	"���",
		"post_action":	(: call_other, __FILE__, "bash_weapon" :),
		"attact_type":  "bar",
		]),
	"throw": ([
		"action":		"$N�N$w���$n��$l�g�F�L�h",
		"damage_type":	"���",
		"post_action":	(: call_other, __FILE__, "throw_weapon" :),
		"attact_type":  "bar",
		]),
	"parasite1": ([
		"action":		"$N�l���F$w����q�A���$n��$l�R�F�@������",
		"damage":	10,
		"hit":		15,
		"damage_type":	"�G�k",
		"post_action":	(: call_other, __FILE__, "parasite_decay" :),
		"attact_type":  "bio",
		]),
	"parasite2": ([
		"action":		"$N�N$w����q�Ƭ�����W���i�A�g��$n��$l",
		"damage":	15,
		"hit":		5,
		"damage_type":	"�_��",
		"post_action":	(: call_other, __FILE__, "parasite_decay" :),
		"attact_type":  "bio",
		]),
	"parasite3": ([
		"action":		"$N�N�w�w�l��$w����q�A�ݤf�r�w�p�l�u��g�V$n��$l",
		"damage":	20,
		"dodge":		10,
		"damage_type":	"���",
		"post_action":	(: call_other, __FILE__, "parasite_decay" :),
		"attact_type":  "bio",
		]),
]);

varargs mapping query_action()
{
	string verb, *verbs;

	verbs = previous_object()->query("verbs");

	if( !pointerp(verbs) ) return weapon_actions["hit"];
	else {
		verb = verbs[random(sizeof(verbs))];
		if( !undefinedp(weapon_actions[verb]) ) return weapon_actions[verb];
		else return weapon_actions["hit"];
	}	
}

void parasite_decay(object me, object victim, object weapon, int damage)
{
	if( objectp(weapon) )
	{
		if( (int)weapon->query("energy") < 2 )
		{
			weapon->unequip();
			tell_object(me, "\n�A�餺��" + weapon->query("name") + "��q�w�g�Χ��F�T\n\n");
			weapon->set_temp("no_energy",1);
		}
		weapon->add("energy",-1);
	}
}

void throw_weapon(object me, object victim, object weapon, int damage)
{
	if( objectp(weapon) ) 
	{
		if( (int)weapon->query_amount()==1 ) {
			weapon->unequip();
			tell_object(me, "\n�A��" + weapon->query("name") + "�Χ��F�T\n\n");
		}
		weapon->add_amount(-1);
	}
}

void bash_weapon(object me, object victim, object weapon, int damage)
{
	object ob;
	int wap, wdp;

	if( objectp(weapon)
	&&	damage==RESULT_PARRY
	&&	ob = victim->query_temp("weapon") ) {
		wap = (int)weapon->weight() / 200
			+ (int)weapon->query("rigidity")
			+ (int)me->query_str();
		wdp = (int)ob->weight() / 200
			+ (int)ob->query("rigidity")
			+ (int)victim->query_str();
		wap = random(wap);
		if( wap > 2 * wdp ) {
			message_vision(HIW "$Nı�o��f�@�}�o��, " + ob->name() + "�Q�_�����b�a�W�T\n" NOR,
				victim);
			ob->unequip();
			ob->move(environment(victim));
			victim->reset_action();
		} else if( wap > wdp ) {
			message_vision("$Nı�o�⤤��" + ob->name() + "�@�_�M�t�@�I�N�n��⸨�a�T\n",
				victim);
		} else if( wap > wdp / 2 ) {
			message_vision("$N��" + weapon->name() + "�M$n��" + ob->name()
				+ "�r�P�����M�n�X�ƹD���P�C\n", me, victim);
		}
	}
}
