//QC : Luky
#include <ansi.h>
#define DELAY 
inherit SKILL;
inherit SSERVER;
int fo=this_player()->query_skill("force")/3;
mapping *action = ({
([
	"action": "$N一式「浪跡天涯」手持$w，以刁絕之方位殺向$n的$l",
	"damage":                fo,
	"dodge" :                20,
	"attack":                20,
	"attact_type":  "bar",
        "damage_type":  "刺傷"
        ]),
([
	"action":"$N手持$w刀招大開大合，一式「龍遊四方」砍向$n的$l",
        "damage":     15+fo,
        "dodge" :    -10,
	"attact_type":  "bar",
        "damage_type":  "砍傷"
        ]),
([
	"action":"$N雙手握住$w，殺招「青龍偃月」夾雜強烈刀風砍向$n的$l",
        "damage": 45+fo,
        "attack": 10,
	"attact_type":  "bar",
        "damage_type":  "砍傷"
]),
([
	"action":"$N縱身半天高，一招「神龍甩尾」，持$w迴身向下對準$n的$l斬去",
	"damage": 35+fo,
	"dodge" : -10,
	"attact_type":  "bar",
	"damage_type":  "劈傷"
        ]),
([
	"action":"$N的「流星追月」一出，$w的刀勢連綿不絕的往$n的$l砍去",
	"damage":  10+fo,
	"parry":  -10,
	"attact_type":  "bar",
	"damage_type":  "砍傷",
	]),

});
void delay(object me,int cost);
int exert(object me, object target, string arg)
{
 int a,c,i,j,damage,db,bd,b,d,e,da,f,roll;
 string msg,aa;
 object weapon;
 mapping type;
 weapon=me->query_temp("weapon");
 da = me->query_damage();
 db = me->query_skill("dragonblade");
 bd = me->query_skill("blade");
 f= me->query_skill("force");
 if(arg=="off" )
 {
  if( me->query_skill_mapped("blade")!="dragonblade")
   return notify_fail("你並沒有在使用遊龍刀法。\n");
  me->map_skill("blade");
  me->reset_action();
  write(YEL"你放下手中的刀，不使用遊龍刀法了。\n"NOR);
  return 1;
 }
 if(!weapon || weapon->query("skill_type")!="blade") 
  return notify_fail("不用刀，如何使出刀法？你以為你強到可以徒手發出刀氣啊？\n");
 if(bd < 45)
  return notify_fail("你的基本刀法技巧不足，如何使用遊龍刀法？\n");
 if(me->query("ap")<80 || me->query("hp")<50)
  return notify_fail("你的身體狀況不能使用此刀法。\n");
 //第二次exert
 if(me->query_skill_mapped("blade")=="dragonblade")
 {
  if( db < 80 || bd < 80 || f < 50)
   return notify_fail("你的能力還不夠，不能用遊龍刀法的絕技。\n");
  if( me->query("hp") < 40 || me->query("ap") < 150 )
   return notify_fail("你的身體狀況已經太差了，不能用遊龍刀法的絕技。\n");
  if( !target ) target = offensive_target(me);
  if( !target )	return notify_fail("你已經在使用遊龍刀法了。\n");
  //攻擊性的要特別注意要加下面兩行.
  if( !me->can_fight(target)) return me->can_fight(target);
  if( !me->is_fighting(target)) me->kill_ob(target);
  if( !target->is_fighting(me)) target->kill_ob(me);
  c = target->query_armor();
  damage = da + (db*3/2) + f + random(me->query_str()*2) + random(me->query_con()*2) + random(f/2) + random(da/2);
  damage = damage * 4 / 5;
  if( damage > 600 ) damage = 600 + random((damage-600)/4);
  if( damage <  50 ) damage = 46 + random(10);
  a=damage/150;
  if( a < 1 ) a=1;
  message_vision(HIC"\n$N將手上的"+weapon->query("name")+HIC+"揮動八方，左右迴旋，瞬間全身刀氣環繞！\n"NOR,me);
  message_vision(RED"數道氣勁儼如飛刀直向$N狂奔而去！\n\n"NOR,target);
  for(e=0;e<a;e++)
  {
   message_vision(HIY"一道刀氣飛向$N的身上！"NOR,target);
   if(random(COMBAT_D->attack_factor(me,"blade")) + (db*2/3) > random( - (COMBAT_D->dodge_factor(target,"dodge"))))
   {
    msg = HIR"結果$n被這道刀氣砍中了！\n"NOR;
    message_vision(msg, me, target);
    me->improve_skill("dragonblade",(me->query_int()/25) + random(2));
    me->improve_skill("blade",1 + random(2));
    // 增加素質對傷害的影響
    damage = (damage / a) + (a*25) + random(me->query_dex()*2/3) - (c/3);
    damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
    target->receive_damage("hp",damage,me);
    COMBAT_D->report_status(target);
    target->add_busy(random(2));
   }
   else
   {
    msg = YEL"結果被$n縱身閃開了。\n"NOR;
    message_vision(msg, me, target);
    target->improve_skill("dodge",1);
    me->improve_skill("blade",1);
   }
  }
  if(!me->is_fighting(target)) me->kill_ob(target);
  if(!target->is_fighting(me)) target->kill_ob(me);     
  me->receive_damage("ap",15+(a*13));
  me->improve_skill("blade",1);
  me->start_busy(3);
  return 1;
 }
 //fix by luky
 if(!me->skill_active( "dragonblade",(: call_other, __FILE__, "delay", me ,5:), 5))
  return notify_fail("你還在使用遊龍刀法。\n");
 me->map_skill("blade","dragonblade");
 me->reset_action();
 message_vision("\n$N手中的"+weapon->query("name")+NOR+"突然寒光一閃，$N運起了"HIC"遊龍刀法"NOR"。\n",me);
 me->receive_damage("ap",15);
 me->start_busy(2);
 return 1;
}
void delay(object me,int cost)
{
	object weapon,target;
	int roll,dex,db,f,hit,dodge,c,b,d,damage;
	dex=me->query_dex();
	db=me->query_skill("dragonblade");
	f=me->query_skill("force");
	weapon=me->query_temp("weapon");
	if(!me) return;
	if(!weapon)
	{
	 	me->map_skill("blade");
		me->reset_action();
		return;
	}
	if(weapon->query("skill_type")!="blade")
	{
	 	me->map_skill("blade");
		me->reset_action();
		return;
	}
	if(me->query_skill_mapped("blade")!="dragonblade")
	{
	 return;
	}
        if(me->query("ap")<55)
	{
	 	me->map_skill("blade");
		me->reset_action();
		tell_object(me,"\n你的內力已經不足，無法使用遊龍刀法了。\n\n");
		return ;
	}
        if( me->is_fighting() && !me->is_busy() ) 
	{
		roll = random(100);
		if( !target ) target = offensive_target(me);
                if( db>40 && roll > 59)
		{
			message_vision(CYN"$N將手中的"+weapon->query("name")+CYN+"旋轉數圈，如輪盤般向$n切去！\n"NOR,me,target);
			me->improve_skill("dragonblade",1 + (me->query_int()/10));
			me->improve_skill("blade",1 + random(2));
			c=target->query_armor();
			b=db/30;        
//必中
			for(d=0;d<b;d++)
			{
				if(random(COMBAT_D->attack_factor(me,"blade")) + (db*2/3) > random( - (COMBAT_D->dodge_factor(target,"dodge"))))
				{
		               		message_vision(HIR"$N被狠狠的切了一刀！\n"NOR,target);
                              		me->improve_skill("dragonblade",random(1)+(me->query_int()/20)); //特攻時額外增加
                               		// 增加素質對傷害的影響
					damage = (db/5) + (f/5) + (random(db+f)/5)+dex+random(dex)+random(me->query_damage()/3);
					damage = damage - (c/5) - random(c/5);
					if(damage < 20) damage = 17 + random(6);
					if(damage > 200) damage = 200 + ((damage-200)/4);
                               		damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
                               	 	target->receive_damage("hp",damage,me);
                                	COMBAT_D->report_status(target);
				}
				else
				{
				        message_vision(HIG"$N眼明手快，閃開了來勢。\n"NOR,target);	
				}
			}
			me->receive_damage("ap",20*b);
		}
		me->receive_damage("ap",4); //luky
	}
        me->skill_active( "dragonblade",(: call_other, __FILE__, "delay", me ,cost:), 5);
}
int valid_learn(object me) {	return 1;	}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me) {	return 1; }

int improve_limite(object ob)
{
        int a,b;
        if( ob->query("adv_class")==1 ) return 80;
        else return 95;  //最高練到95
}
