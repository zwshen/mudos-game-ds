#include <ansi.h>
inherit SKILL;
inherit SSERVER;

mapping *action = ({
(["action": "$N使出一式「驚鴻現世間」,持$w飛天而下,朝$n的$l劈去",
"damage":                60,
"dodge" :               -30,
                "damage_type":  "劈傷"
        ]),
(["action":"$N方位急旋, 一招「日月星辰變」,$w瞬間化成四道劍勢,
四道劍氣直射向$n的$l",
                "damage":    40,
                "dodge" :    30,
                "attack":    30,
                "damage_type":  "刺傷"
        ]),
(["action":"$N使出「一劍動河山」,手中握住$w, 發出強大劍氣射向$n的$l",
                "damage": 60,
                "parry": -10,
]),
(["action":"$N摧化劍氣, 一式殺招『轟雷吟震天』,$w的劍刃上下顫動,形成一片電網
封住$n的退路,無數的劍氣刺向$n的各大要穴",
"damage": 100,
"attack": -40,
"dodge" : -30,
"damage_type":  "刺傷"
        ]),
(["action":"$N運出「冰雪徹骨寒」一招, $w劍芒之中隱透淡淡寒氣襲向$n的$l",
"damage":  50,
"dodge":   20,
"attack": -20,
"damage_type":  "刺傷"
	]),
(["action":"$N使出一招「炙陽烈如焰」,$N將烈火之氣灌於$w之中, 再翻$w迴旋,
劃出火紅劍氣攻向$n",
"damage":  60,
"dodge":  -10,
"attack": -10,
"parry":  -10,
"damage_type":  "刺傷"
	]),
(["action":"$N使出「氣芒似虹彎」,$N手中$w驟然一轉, 迴身向前劃出
強大氣芒, 直攻向$n的$l",
"damage":  50,
"attack": -20,
"damage_type":  "刺傷"
	]),
(["action":"$N全身抖動, 功\力\凝於$w之中, 極招『狂滅破龍斬』一式發出強大劍氣,
狠狠的往$n的$l狂劈而去",
"damage": 144,
"dodge":  -10,
"attack":  10,
"damage_type":  "刺傷"
	]),
});
void attack(object me,object target,string msg)
{
	int damage,damage2,c,str,a,hp,mp;
	me = this_player();
	if( !target ) target = offensive_target(me);
	hp = me->query("hp");
	mp = me->query("mp");
	msg = HIY"$N使出封雷絕劍必殺技﹐九道毀天滅地的劍氣攻向$n!!"NOR;
	c = target->query_temp("apply/armor");
        if ( c > 50 ) c = 50;
	damage2 = 75 + random(26);
	if (random(this_player()->query_skill("thundersword")) < 66 || hp < 200 || mp < 300 ) return;
	message_vision(msg, me, target);
	for ( a=0; a<8; a++ )
	{
		damage = (this_player()->query_skill("thundersword"))-(c/2);
        	if ( damage < 35 ) damage = 30 + random(6);
		if( 33 + random(this_player()->query_skill("thundersword")) > 66 ) {
			msg = HIC"$P一劍劈向$p, 結果$p被$P重重劈中$l!!\n"NOR;
			message_vision(msg, me, target);
                	target->add("hp",-damage);
			COMBAT_D->report_status(target,1);
		} else {
			msg = YEL"$P一劍劈向$p, 可是被$p給閃了開去。\n"NOR;
			message_vision(msg, me, target);
		}
	}
	if( 33 + random(this_player()->query_skill("thundersword")) > 56 ) {
		msg = HIC"$P一劍狂劈向$p, 結果$p被$P狠狠劈中$l!!\n"NOR;
		message_vision(msg, me, target);
               	target->add("hp",-damage);
		COMBAT_D->report_status(target,1);
	} else {
		msg = YEL"$P一劍劈向$p, 可是被$p給閃了開去。\n"NOR;
		message_vision(msg, me, target);
	}
	me->start_busy(1);
	me->add("hp",-20);
	me->add("mp",-40);
}
int valid_learn(object me)
{
        object ob;

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
	return notify_fail("你沒有拿劍，如何練封雷絕劍？\n");

	if( (int)me->query("max_mp") < 300 || (int)me->query("mp") < 100 )
	return notify_fail("你的內力不夠﹐沒有辦法練封雷絕劍。\n"); 
       return 1;
}
int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry";
}
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("dex")<40)  
	if( (int)me->query("int")<30)
		return notify_fail("你的能力不夠,不適合學這門劍法。\n");
        me->add("mp",-50);
        write("你按著所學練了一遍劍招。\n");
        return 1;
}

string perform_action_file(string action)
{

   return "/daemon/skill/thundersword/" + action;
}
