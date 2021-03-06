#include <ansi.h>
inherit SKILL;
inherit SSERVER;

mapping *action = ({
([
	"action": "$N使出一式「"HIM"驚鴻現世間"NOR"」,持$w飛天而下,朝$n劈去",
	"damage":                50,
	"dodge" :               -30,
        "damage_type":  "劈傷"
        ]),
([
	"action":"$N方位急旋, 一招「"HIW"日月星辰變"NOR"」,$w瞬間化成四道劍勢,
四道劍氣直射向$n",
        "damage":    35,
        "dodge" :    30,
        "damage_type":  "刺傷"
        ]),
([
	"action":"$N使出「"HIY"一劍動河山"NOR"」,手中握住$w, 發出強大劍氣射向$n",
        "damage": 30,
        "damage_type":  "刺傷"
]),
([
	"action":"$N摧化劍氣, 一式殺招『"HIW"轟雷吟震天"NOR"』,$w的劍刃上下顫動,形成一片電網
封住$n的退路,無數的劍氣刺向$n的各大要穴",
	"damage": 80,
	"dodge" : -30,
	"damage_type":  "刺傷"
        ]),
([
	"action":"$N運出「"HIC"冰雪徹骨寒"NOR"」一招, $w劍芒之中隱透淡淡寒氣襲向$n",
	"damage":  50,
	"dodge":   20,
	"damage_type":  "凍傷"
	]),
([
	"action":"$N使出一招「"HIR"炙陽烈如焰"NOR"」,$N將烈火之氣灌於$w之中, 再翻$w迴旋,
劃出火紅劍氣攻向$n"+NOR,
	"damage":  60,
	"dodge":  -10,
	"damage_type":  "燒傷"
	]),
([
	"action":"$N使出「"HIG"氣芒似虹彎"NOR"」,$N手中$w驟然一轉, 迴身向前劃出
強大氣芒, 直攻向$n",
	"damage":  50,
	"damage_type":  "刺傷"
	]),
([
	"action":"$N全身抖動, 功\力\凝於$w之中, 極招『"HIM"狂"HIC"滅"HIR"破"HIG"龍"HIW"斬"NOR"』一式發出強大劍氣,
狠狠的往$n狂劈而去",
	"damage": 90,
	"dodge":  -10,
	"damage_type":  "嚴重砍傷"
	]),
});

int exert(object me, object target,string dir)
{
	int damage,c,str,a,i,j;
	string msg;
	mapping type;
	object weapon;
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	target->is_corpse()
	||	target->is_ghost())
	{
		return notify_fail("封雷絕劍只能對生物使用。\n");
	}
	if(environment(me)->query("no_fight") || environment(me)->query("no_kill"))
		return notify_fail("這裡禁止戰鬥﹗\n");
	if((int)me->query("mp") < 40 || (int)me->query("hp") < 20)
		return notify_fail("你目前的身體狀況無法使用這麼劇烈的武功\﹗\n");
	if(!weapon=me->query_temp("weapon")) return notify_fail("沒有武器如何施展劍招﹗\n");
	if(weapon->query("skill_type")!="sword") return notify_fail("封雷劍法必須配合劍使用﹗\n");
	if(userp(me) && userp(target))	//攻擊的一定要設定
	{
	  if(me->query("level") < 5 ) return notify_fail("你目前的等級不可以攻擊玩家﹗\n");
	  if(target->query("level") < 5 ) return notify_fail("你不可以攻擊如此低等級的玩家﹗\n");
	  if(me->query("level") > target->query("level") + 5 ) return notify_fail("你不可以攻擊等級相差太多的玩家﹗\n");
	  if(me->query("level") < target->query("level") - 5 ) return notify_fail("你不可以攻擊等級相差太多的玩家﹗\n");
	}
	
	message_vision(HIW"$N運起封雷劍訣, 劍光如閃電般激射而出﹗﹗\n\n"NOR,me);
	c = target->query_armor();
        
      if(random(me->query_skill("thundersword"))> 50 && me->query("hp")<me->query("max_hp")/2)
      {
      	msg = HIC "$N使出封雷絕劍必殺技『狂雷劍 驚日月』﹐\n毀天滅地的威力攻向$n!!﹐";
	damage = me->query_skill("thundersword") + me->query_str() * 4 + me->query("mp");
	damage -= random(target->query_armor());
	if(damage<150) damage=100+random(80);
	me->start_busy(1);
        if( 22 + random(me->query_skill("thundersword")) > 44 )
        {
		msg += "結果$p被$P重重劈中﹗\n" NOR;
		target->start_busy(2);
                target->receive_damage("hp",damage,me);
	} else {
		msg += "可是被$p給閃了開去。\n" NOR;
	}
	message_vision(msg, me, target);
      }
      else
      {
	i=me->query_skill("thundersword")/12;
	if(i>10) i=10;
	if(i<1) i=1;
	
	for( a=0; a<i; a++ )
	{
		j=random(sizeof(action));
		type=action[j];
		msg = type["action"]+NOR+", ";
		msg = replace_string( msg, "$w", weapon->name() );
		damage = (me->query_str()+me->query_skill("thundersword"))-random(c);
		damage += type["damage"];
        	if( damage < 1 ) damage = random(20);
		if( random(me->query_dex()+me->query_skill("thundersword")/2) > random(target->query_dex()+target->query_skill("dodge")/2)+type["dodge"]
		 && damage>0)
		{
			msg += HIR"結果造成$n一處"+type["damage_type"]+"!!\n"NOR;
			message_vision(msg, me, target);
                	target->receive_damage("hp",damage,me);
		} else {
			msg += "可是被$n給閃了開去。\n";
			message_vision(msg, me, target);
			target->improve_skill("dodge",1);
		}
	 }
       }
	COMBAT_D->report_status(target);
	message_vision("\n",me);
	me->improve_skill("thundersword",1+me->query_int()/10);
	if(!me->is_fighting(target)) me->kill_ob(target);
	if(!target->is_fighting(me)) target->kill_ob(me);
	me->start_busy(2);
	me->add("hp",-20);
	me->add("mp",-40);
	return 1;
}
