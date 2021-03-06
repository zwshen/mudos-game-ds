#include <ansi.h>
inherit SKILL;
inherit SSERVER;
string *adv_attack = ({
 HIY"$N怒喝一聲，斬龍訣中的『驚』字訣瞬間包挾強大劍氣射向$n,"NOR,
 HIY"$N劃出四道劍氣，以詭異的『變』字訣從不同方位攻向$n,"NOR,
 HIY"$N將劍氣貫注於地，以『動』字訣倏地將劍氣挑起殺向$n,"NOR,
 HIY"$N身躍空中，引用強大內力摧動『雷』字訣劈向$n,"NOR,
 HIW"$N回身猛地一轉，寒氣運行，一招『寒』字訣殺向$n,"NOR,
 HIW"$N大喝一聲，勁走全身，一口氣在劍上凝聚『燄』字訣殺向$n,"NOR,
 HIW"$N四散劍氣，直取中路，一式『芒』字訣劃向$n,"NOR,
 HIW"$N匯聚十成功\力\，『斬』字訣硬狠狠的劈向$n,"NOR,
});
mapping *action = ({
([
	"action": "$N使出一式「"HIM"驚鴻現世間"NOR"」,持$w飛天而下,朝$n劈去",
	"damage":                30,
	"dodge" :               -20,
	"attact_type":  "bar",	// 設定技能的攻擊種類
				// 種類有 生物(bio) 獸性(bar)
				// 魔法(wit)心靈(sou)科技(tec)
        "damage_type":  "劈傷"
        ]),
([
	"action":"$N方位急旋, 一招「"HIW"日月星辰變"NOR"」,$w瞬間化成四道劍勢,
四道劍氣直射向$n",
        "damage":    20,
        "dodge" :    20,
	"attact_type":  "bar",
        "damage_type":  "刺傷"
        ]),
([
	"action":"$N使出「"HIY"一劍動河山"NOR"」,手中握住$w, 發出強大劍氣射向$n",
        "damage": 25,
	"attact_type":  "bar",
        "damage_type":  "刺傷"
]),
([
	"action":"$N摧化劍氣, 一式殺招『"HIW"轟雷吟震天"NOR"』,$w的劍刃上下顫動,形成一片電網
封住$n的退路,無數的劍氣刺向$n的各大要穴",
	"damage": 45,
	"dodge" : -20,
	"attact_type":  "bar",
	"damage_type":  "刺傷"
        ]),
([
	"action":"$N運出「"HIC"冰雪徹骨寒"NOR"」一招, $w劍芒之中隱透淡淡寒氣襲向$n",
	"damage":  30,
	"dodge":   10,
	"attact_type":  "bar",
	"damage_type":  "凍傷"
	]),
([
	"action":"$N使出一招「"HIR"炙陽烈如焰"NOR"」,$N將烈火之氣灌於$w之中, 再翻$w迴旋,
劃出火紅劍氣攻向$n"+NOR,
	"damage":  35,
	"dodge":  -15,
	"attact_type":  "bar",
	"damage_type":  "燒傷"
	]),
([
	"action":"$N使出「"HIG"氣芒似虹彎"NOR"」,$N手中$w驟然一轉, 迴身向前劃出
強大氣芒, 直攻向$n",
	"damage":  30,
	"attact_type":  "bar",
	"damage_type":  "刺傷"
	]),
([
	"action":"$N全身抖動, 功\力\凝於$w之中, 極招『"HIM"狂"HIC"滅"HIR"破"HIG"龍"HIW"斬"NOR"』一式發出強大劍氣,
狠狠的往$n狂劈而去",
	"damage": 60,
	"dodge":  -10,
	"attact_type":  "bar",
	"damage_type":  "嚴重砍傷"
	]),
});
void delay(object me,int cost);
int exert(object me, object target, string arg)
{
 int a,c,i,j,damage,th,sd,b,d,e,da;
 string msg,aa;
 object weapon;
 mapping type;
 weapon=me->query_temp("weapon");
 da = me->query_damage();
 th = me->query_skill("thundersword");
 sd = me->query_skill("sword");
 if(arg=="off" )
 {
  if( me->query_skill_mapped("sword")!="thundersword")
   return notify_fail(HIG"你現在並沒有在使用"HIR"斬龍訣.\n"NOR);
  me->map_skill("sword");
  me->reset_action();
  write(HIB"你深吸一口氣, 調整體內翻湧的內息, 停止使用"HIR"斬龍訣.\n"NOR);
  return 1;
 }
 if(!weapon || weapon->query("skill_type")!="sword") 
  return notify_fail(RED"斬龍訣"GRN"必須用劍方能使出.\n"NOR);
 if(me->query_skill("sword")<45)
  return notify_fail(GRN"你的基本劍術還太差勁, 不能用"RED"斬龍訣.\n"NOR);
 if(me->query("ap")<60 || me->query("hp")<30)
  return notify_fail(GRN"你現在的狀況太差了, 不能用"RED"斬龍訣.\n"NOR);
 //第二次exert
 if(me->query_skill_mapped("sword")=="thundersword")
 {
  if( !target ) target = offensive_target(me);
  if(!target) 	return notify_fail(GRN"你已經運行斬龍訣了.\n"NOR);
  //攻擊性的要特別注意要加下面兩行.
  if(!me->can_fight(target)) return me->can_fight(target);
  if( !me->is_fighting(target)) me->kill_ob(target);
  if( !target->is_fighting(me)) target->kill_ob(me);
  c = target->query_armor();
  if(th > random(300) && sd > 60 && me->query("ap")>100 )
  {
   b = th/10;
   b = (b/2) + (random(b)/2) + 1;
   if(b>8) b=8;
   if(b<1) b=1;
   for( e=0;e<b;e++)
   {
    if(e<1) message_vision(HIC"\n$N運起斬龍訣極招『封雷八字訣』電射向$n而去!!!\n\n"NOR,me,target);
    d = random(sizeof(adv_attack));
    msg = adv_attack[d];
    damage = th + sd;
    damage =  (damage/3) + ((da*3)/2);
    damage -= (c/2) + (random(c)/2);
    if(damage<40) damage=30+random(20);
    if(damage>120) damage=80+random(40);
    if(random(me->query_dex()*2+th/3) > random(target->query_dex()*2+target->query_skill("dodge")/2) && damage>0 )
    {
     msg += HIG"結果造成$n一處嚴重的傷害!!\n"NOR;
     message_vision(msg, me, target);
     me->improve_skill("thundersword",random(3));
	// 增加素質對傷害的影響
	damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
     target->receive_damage("hp",damage,me);
     COMBAT_D->report_status(target);
    }
    else
    {
     msg += GRN"但是卻被$n閃開了。\n" NOR;
     message_vision(msg, me, target);
     target->improve_skill("dodge",1);
    }
   }
   if(!me->is_fighting(target)) me->kill_ob(target);
   if(!target->is_fighting(me)) target->kill_ob(me);     
   me->receive_damage("ap",8*b);
   me->improve_skill("sword",1);
   return 1;
  }
  else
  {
   message_vision(CYN"$N瞬間舞動眼花撩亂的劍招包圍了$n!\n"NOR,me,target);
   damage = (th/5) + (sd/5) + (da/5);
   damage = (random(damage)/2) + damage/2;
   damage -= (random(c)/2);
   if( damage < 5 ) damage = random(10);
   if( random(me->query_dex()*2+sd/3) > random(target->query_dex()*2+target->query_skill("dodge")/2) && damage>0)
   {
    msg = HIC"結果造成$n身上多處割傷, 並且擾亂了$n的行動!!\n"NOR;
    message_vision(msg, me, target);
    me->improve_skill("thundersword",target->query("level")/5);
	// 增加素質對傷害的影響
	damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
    target->receive_damage("hp",damage,me);
    COMBAT_D->report_status(target);
	target->start_busy(2);
   }
   else
   {
    msg = CYN"可是給$n識破$N的破綻, 輕輕的避了開去。\n";
    message_vision(msg, me, target);
    target->improve_skill("dodge",1);
    target->start_busy(1);
	me->start_busy(2);
   }
   me->receive_damage("ap",15);
   me->start_busy(1);
   if(!me->is_fighting(target)) me->kill_ob(target);
   if(!target->is_fighting(me)) target->kill_ob(me);
   me->improve_skill("thundersword",1+random(me->query_int()/4));
   me->improve_skill("sword",1+random(me->query_int()/4));
   return 1;
  }
 }
 
 //fix by luky
 if(!me->skill_active( "thundersword",(: call_other, __FILE__, "delay", me ,6:), 10))
          return notify_fail("你收功\的動作還沒完成。\n");
 
 me->map_skill("sword","thundersword");
 me->reset_action();
 message_vision("\n"HIW"$N深吸了一口氣, 勁運起"HIR"斬龍訣。\n"NOR,me);
 me->receive_damage("ap",10);
 me->start_busy(1);
 //me->start_call_out( (: call_other, __FILE__, "delay", me ,6:), 10);
 return 1;
}
void delay(object me,int cost)
{
	object weapon;
	if(!me) return;
	weapon=me->query_temp("weapon");
	if(!weapon)
	{
	 	me->map_skill("sword");
		me->reset_action();
		return;
	}
	if(weapon->query("skill_type")!="sword")
	{
	 	me->map_skill("sword");
		me->reset_action();
		return;
	}
	if(me->query_skill_mapped("sword")!="thundersword")
	{
	 return;
	}
    if(me->query("ap")<40)
	{
	 	me->map_skill("sword");
		me->reset_action();
		tell_object(me,HIW"\n你的體力已經不夠施展"HIR"斬龍訣"HIW"了。\n"NOR);
		return ;
	}
    if( me->is_fighting() ) me->receive_damage("ap",8); //luky
        //me->start_call_out( (: call_other, __FILE__, "delay", me ,cost:), 10);
    me->skill_active( "thundersword",(: call_other, __FILE__, "delay", me ,cost:), 10);
}
int valid_learn(object me) {	return 1;	}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me) {	return 1; }

int improve_limite(object ob)
{
        int a;
        a=ob->query_int();
        a=40+a;
        return a; 
}
