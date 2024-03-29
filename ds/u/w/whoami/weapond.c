// weapond.c
// #pragma save_binary
#include <ansi.h>
#include <combat.h>

mapping weapon_actions = ([
	"hit": ([
		"damage_type":	"傷害",
		"action":		"$N揮動$w﹐奮力的劈向$n的$l",
		"parry":		20,
		"attact_type":  "bar",
		]),
	"slash": ([
		"damage_type":	"割傷",
		"action":		"$N揮動$w﹐斬向$n的$l",
		"parry":		20,
		"attact_type":  "bar",
		]),
	"slice": ([
		"damage_type":	"斲傷",
		"action":		"$N用$w往$n的$l砍去",
		"dodge":		20,
		"attact_type":  "bar",
		]),
	"chop": ([
		"damage_type":	"斲傷",
		"action":		"$N的$w朝著$n的$l劈將過去",
		"parry":		-20,
		"attact_type":  "bar",
		]),
	"hack": ([
		"action":		"$N揮舞$w﹐對準$n的$l一陣亂砍",
		"damage_type":	"斲傷",
		"damage":		30,
		"dodge":		30,
		"attact_type":  "bar",
		]),
	"thrust": ([
		"damage_type":	"刺傷",
		"action":		"$N用$w往$n的$l刺去",
		"dodge":		15,
		"parry":		-15,
		"attact_type":  "bar",
		]),
	"pierce": ([
		"action":		"$N的$w往$n的$l狠狠地一捅",
		"damage_type":	"刺傷",
		"dodge":		-30,
		"parry":		-30,
		"attact_type":  "bar",
		]),
	"whip": ([
		"action":		"$N將$w一揚﹐往$n的$l抽去",
		"damage_type":	"鞭傷",
		"dodge":		-20,
		"parry":		30,
		"attact_type":  "bar",
		]),
	"impale": ([
		"action":		"$N用$w往$n的$l直戳過去",
		"damage_type":	"刺傷",
		"dodge":		-10,
		"parry":		-10,
		"attact_type":  "bar",
		]),
	"bash": ([
		"action":		"$N揮舞$w﹐往$n的$l用力一鎚",
		"damage_type":	"瘀傷",
		"post_action":	(: call_other, __FILE__, "bash_weapon" :),
		"attact_type":  "bar",
		]),
	"crush": ([
		"action":		"$N高高舉起$w﹐往$n的$l當頭砸下",
		"damage_type":	"砸傷",
		"post_action":	(: call_other, __FILE__, "bash_weapon" :),
		"attact_type":  "bar",
		]),
	"slam": ([
		"action":		"$N手握$w﹐眼露兇光﹐猛地對準$n的$l揮了過去",
		"damage_type":	"瘀傷",
		"post_action":	(: call_other, __FILE__, "bash_weapon" :),
		"attact_type":  "bar",
		]),
	"grab": ([
		"action":		"$N舞動銳利的$w﹐瘋狂地對準$n的$l一陣猛抓",
		"damage_type":	"瘀傷",
		"post_action":	(: call_other, __FILE__, "bash_weapon" :),
		"attact_type":  "bar",
		]),
	"punch": ([
		"action":		"$N放低身體, 卯足全力, 猛然朝著$n的$l連發三拳",
		"damage_type":	"瘀傷",
		"post_action":	(: call_other, __FILE__, "bash_weapon" :),
		"attact_type":  "bar",
		]),
	"throw": ([
		"action":		"$N將$w對準$n的$l射了過去",
		"damage_type":	"刺傷",
		"post_action":	(: call_other, __FILE__, "throw_weapon" :),
		"attact_type":  "bar",
		]),
	"parasite1": ([
		"action":		"$N吸收了$w的能量，對準$n的$l吐了一片酸霧",
		"damage":	10,
		"hit":		15,
		"damage_type":	"腐蝕",
		"post_action":	(: call_other, __FILE__, "parasite_decay" :),
		"attact_type":  "bio",
		]),
	"parasite2": ([
		"action":		"$N將$w的能量化為高能超音波，射往$n的$l",
		"damage":	15,
		"hit":		5,
		"damage_type":	"震傷",
		"post_action":	(: call_other, __FILE__, "parasite_decay" :),
		"attact_type":  "bio",
		]),
	"parasite3": ([
		"action":		"$N將緩緩吸收$w的能量，胸口毒針如子彈般射向$n的$l",
		"damage":	20,
		"dodge":		10,
		"damage_type":	"刺傷",
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
			tell_object(me, "\n你體內的" + weapon->query("name") + "能量已經用完了﹗\n\n");
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
			tell_object(me, "\n你的" + weapon->query("name") + "用完了﹗\n\n");
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
			message_vision(HIW "$N覺得虎口一陣發麻, " + ob->name() + "被震的落在地上﹗\n" NOR,
				victim);
			ob->unequip();
			ob->move(environment(victim));
			victim->reset_action();
		} else if( wap > wdp ) {
			message_vision("$N覺得手中的" + ob->name() + "一震﹐差一點就要脫手落地﹗\n",
				victim);
		} else if( wap > wdp / 2 ) {
			message_vision("$N的" + weapon->name() + "和$n的" + ob->name()
				+ "猛烈相擊﹐迸出數道火星。\n", me, victim);
		}
	}
}
