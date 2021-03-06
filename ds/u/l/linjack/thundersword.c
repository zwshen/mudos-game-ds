#include <ansi.h>;
inherit SKILL;

mapping *action = ({
(["action": "$N使出一式「驚鴻現世間」,持$w飛天而下,朝$n的$l劈去",
"damage":               120,
"dodge" :               -30,
                "damage_type":  "劈傷"
        ]),
(["action":"$N方位急旋, 一招「日月星辰變」,$w瞬間化成四道劍勢,\n
四道劍氣直射向$n的$l",
                "damage":    50,
                "dodge" :    50,
                "attack":    50,
                "damage_type":  "刺傷"
        ]),
(["action":"$N使出「一劍動河山」,手中握住$w, 發出強大劍氣\n射向$n的$l",
                "damage": 100,
                "dodge": 10,
]),
(["action":"$N摧化劍氣, 一式「轟雷吟震天」,$w的劍刃上下顫動,\n形成一片電網
封住$n的退路,無數的劍氣刺向$n的各大要穴",
"damage": 160,
"attack": -40,
"dodge" : -20,
"damage_type":  "刺傷"
        ]),
(["action":"$N運出「狂沙萬里路」一招狂掃向$n,$w化成無影之劍向$n刺去",
"damage":  80,
"dodge":   50,
"damage_type":  "刺傷"
	]),
(["action":"$N使出殺招「驚日一劍狂雷震」,$w中蘊含五式奧妙向$n刺去",
"damage": 200,
"dodge":  -50,
"attack": -50,
"damage_type":  "刺傷"
	]),
});

int valid_learn(object me)
{
        object ob;

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
	return notify_fail("你沒有拿劍，如何練封雷絕劍？\n");

	if( (int)me->query("max_mp") < 500 )
	return notify_fail("你的內力不夠﹐沒有辦法練封雷絕劍。\n"); 
       return 1;
}
int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry" || usage=="unarmed";
}
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
if( (int)me->query("dex")<50)
if( (int)me->query("int")<50)
return notify_fail("你的能力不夠,不適合學這門劍法。\n");
        me->add("mp",-50);
        write("你按著所學練了一遍劍招。\n");
        return 1;
}

string perform_action_file(string action)
{
	return "/daemon/skill1/thundersword/" + action;
}
