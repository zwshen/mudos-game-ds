//update by linjack 99.10.19
//QC : Luky [10.21.1999]
#include <ansi.h>
#define DELAY 
inherit SKILL;
inherit SSERVER;
string *adv_attack = ({
 "$N雙手握住刀柄，力貫刀鋒的一招『"HIC"開雲破日"NOR"』硬狠狠的劈出一道刀氣殺向$n，\n",
 "$N加快腳步，以極快的速度旋繞$n，以出奇不意的一式『"HIR"愁雲慘霧"NOR"』攻向$n，\n",
});
mapping *action = ({
([
	"action": "$N以「一式開雲霧」一招，手持$w躍至空中，往$n的額頭劈去",
	"damage":                12,
	"dodge" :               -10,
	"attact_type":  "bar",
        "damage_type":  "劈傷"
        ]),
([
	"action":"$N身形急轉，一式「飛舞浪雲波」，手中$w搖晃不定的攻向$n",
        "damage":     6,
        "dodge" :    20,
	"attact_type":  "bar",
        "damage_type":  "劈傷"
        ]),
([
	"action":"$N使出「刀迴蕩天開」，$w繞$N一圈再一個箭步衝向$n橫劈而去",
        "damage": 10,
        "attack": 10,
	"attact_type":  "bar",
        "damage_type":  "砍傷"
]),
([
	"action":"$N跳上空中，一招「青雲天際翔」，由上而下的舞動$w砍向$n",
	"damage": 15,
	"dodge" : -20,
	"attact_type":  "bar",
	"damage_type":  "砍傷"
        ]),
([
	"action":"$N運勁於$w之上，赫然是殺招「雲海波濤震」，手中$w帶動強大勁力攻向$n",
	"damage":  20,
	"parry":  -20,
	"attact_type":  "bar",
	"damage_type":  "劈傷",
	]),
([
	"action":"$N手持$w，身形搖擺\不\定，「雲影隨風轉」一招以精妙絕倫的方位攻向$n",
	"damage":   5,
	"dodge":   20,
        "parry":   20,
        "attack":  20,
	"attact_type":  "bar",
	"damage_type":  "劈傷",
	]),
});
void delay(object me,int cost);
int exert(object me, object target, string arg)
{
 int a,c,i,j,damage,cb,bd,b,d,e,da,cf,roll;
 string msg,aa;
 object weapon;
 mapping type;
 weapon=me->query_temp("weapon");
 da = me->query_damage();
 cb = me->query_skill("cloudblade");
 bd = me->query_skill("blade");
 cf = me->query_skill("cloudforce");
 if(arg=="off" )
 {
  if( me->query_skill_mapped("blade")!="cloudblade")
   return notify_fail("你沒有在使用向雲刀法吧。\n");
  me->map_skill("blade");
  me->reset_action();
  write(CYN"你收起刀勢，喘了口氣，不使用向雲刀法了。\n"NOR);
  return 1;
 }
 if(!weapon || weapon->query("skill_type")!="blade") 
  return notify_fail("不用刀，如何使出刀法？你以為你強到可以徒手發出刀氣啊？\n");
 if(bd < 5)
  return notify_fail("那麼差勁的基本刀法，如何能貫通向雲刀法於其中呢？\n");
 if(me->query("ap")<15 || me->query("hp")<10)
  return notify_fail("你不夠力了吧。\n");
 //第二次exert
 if(me->query_skill_mapped("blade")=="cloudblade")
 {
  if( cb < 25 || bd < 25 )
   return notify_fail("你的技巧還不純熟，不能用向雲刀法的絕技。\n");
  if( me->query("hp") < 20 || me->query("ap") < 30 )
   return notify_fail("你的身體狀況已經太差了，不能用向雲刀法的絕技。\n");
  if( !target ) target = offensive_target(me);
  if( !target )	return notify_fail("你已經在使用向雲刀法了。\n");
  //攻擊性的要特別注意要加下面兩行.
  if( !me->can_fight(target)) return me->can_fight(target);
  if( !me->is_fighting(target)) me->kill_ob(target);
  if( !target->is_fighting(me)) target->kill_ob(me);
  c = target->query_armor();
  d = random(sizeof(adv_attack));
  msg = adv_attack[d];
  //用特攻的敘述sizeof做出不同結果
  if( d == 0 )
  {
   damage = (da/2) + (cb/2) + (cf/2) + random(16);
   damage = damage - (c/2) - random(c/2);
   if( damage > 180 ) damage = 180 + random((damage-180)/4);
   if( damage <  20 ) damage = 17 + random(8);
   if(random(COMBAT_D->attack_factor(me,"blade")) + cb/3 > random( - (COMBAT_D->dodge_factor(target,"dodge"))))
   {
    roll = random(100);
    msg += HIY"\n結果$n ---- "HIC"中招了"HIY"！\n\n"NOR;
    message_vision(msg, me, target);
    me->improve_skill("cloudblade",2 + (me->query_int()/8) + random(2));
    me->improve_skill("blade",2 + random(2));
    // 增加素質對傷害的影響
    damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
    target->receive_damage("hp",damage,me);
    COMBAT_D->report_status(target);
    if( cb > 50 && bd > 55 && roll > 60 )
    {
     message_vision(HIM"$N見$n被一陣攻擊後亂了陣腳，趁勢再追補一刀！\n"NOR,me,target);
     me->improve_skill("cloudblade",2 + (me->query_int()/10));
     me->improve_skill("blade",2 + random(2));
     COMBAT_D->do_attack(me,target,me->query_temp("weapon"),2);
     COMBAT_D->report_status(target);
		if( cb > 80 && bd > 90 && roll > 72)
     {
      message_vision(HIM"$N見$n被一陣攻擊後亂了陣腳，趁勢再追補一刀！\n"NOR,me,target);
      me->improve_skill("cloudblade",3+(me->query("lv")/5));
      me->improve_skill("blade",(me->query("lv")/4));
      COMBAT_D->do_attack(me,target,me->query_temp("weapon"),4);
      COMBAT_D->report_status(target);
     }
    }
    target->start_busy(1);
    me->start_busy(2);
   }
   else
   {
    msg += HIY"\n結果$n ---- "CYN"沒中招"HIY"∼\n\n"NOR;
    message_vision(msg, me, target);
    target->improve_skill("dodge",1);
    me->start_busy(2);
    me->improve_skill("blade",1);
   }
   if(!me->is_fighting(target)) me->kill_ob(target);
   if(!target->is_fighting(me)) target->kill_ob(me);     
   me->receive_damage("ap",14+random(7));
   me->improve_skill("blade",1);
   return 1;
  }
  else if( d == 1 )
  {
   damage = (da/3) + random(cb/4) + (cb/4) + (cf/2) + random(11);
   damage = damage - (c/3) - random(c*2/3);
   if( damage > 130 ) damage = 130 + random((damage-130)/3);
   if( damage <  15 ) damage = 14 + random(5);
   if(random(me->query_dex()*2+cb/3)+25 > random(target->query_dex()*2+target->query_skill("dodge")/2))
   {
    roll = random(100);
    msg += HIC"\n$n閃錯了一個方位，中招了！\n\n"NOR;
    message_vision(msg, me, target);
    me->improve_skill("cloudblade",2 + (me->query_int()/8) + random(2));
    me->improve_skill("blade",1+random(2));
    // 增加素質對傷害的影響
    damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
    target->receive_damage("hp",damage,me);
    COMBAT_D->report_status(target);
    if( cb > 60 && bd > 70 && roll > 65)
    {
     message_vision(HIR"$N見$n身形稍有停滯，馬上又劈出凌厲的一刀！\n"NOR,me,target);
     me->improve_skill("cloudblade",2 + (me->query_int()/10));
     me->improve_skill("blade",2 + random(2));
     COMBAT_D->do_attack(me,target,me->query_temp("weapon"),4);
     COMBAT_D->report_status(target);
    }
    me->start_busy(1);
   }
   else
   {
    msg += CYN"\n可是竟被$n窺破死角，閃開了這招。\n\n" NOR;
    message_vision(msg, me, target);
    target->improve_skill("dodge",1);
    me->start_busy(2);
    target->start_busy(1);
   }
   if(!me->is_fighting(target)) me->kill_ob(target);
   if(!target->is_fighting(me)) target->kill_ob(me);     
   me->receive_damage("ap",12+random(9));
   me->improve_skill("blade",2);
   return 1;
  } 
 }
 //fix by luky
 if(!me->skill_active( "cloudblade",(: call_other, __FILE__, "delay", me ,5:), 5))
  return notify_fail("你還在用向雲刀法中呢。\n");
 me->map_skill("blade","cloudblade");
 me->reset_action();
 message_vision("\n$N拿起手中的"+weapon->query("name")+NOR+"揮動幾下，使起"HIG"向雲刀法"NOR"。\n",me);
 me->receive_damage("ap",10);
 me->start_busy(2);
 return 1;
}
void delay(object me,int cost)
{
	object weapon,target;
	int roll;
	if(!me) return;
	weapon=me->query_temp("weapon");
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
	if(me->query_skill_mapped("blade")!="cloudblade")
	{
	 return;
	}
        if(me->query("ap")<15)
	{
	 	me->map_skill("blade");
		me->reset_action();
		tell_object(me,"\n你的內力已經渙散，無法再使用向雲刀法。\n\n");
		return ;
	}
        if( me->is_fighting() ) 
	{
		roll = random(100);
		if( !target ) target = offensive_target(me);
		if( me->query_skill("cloudblade")>30 && me->query_skill("blade") > 35 && roll > 50 && !me->is_busy() && !me->is_block())
		{
			message_vision(CYN"$N身形一轉，突然對$n發出第"+YEL+"二"+CYN+"刀攻擊！\n"NOR,me,target);
			me->improve_skill("cloudblade",1 + (me->query_int()/10));
			me->improve_skill("blade",1 + random(2));
			COMBAT_D->do_attack(me,target,me->query_temp("weapon"),3);
			COMBAT_D->report_status(target);
            		if( me->query_skill("cloudblade")>50 && me->query_skill("blade") > 60 && roll > 68)
			{
				message_vision(HIC"$N身形一轉，突然對$n發出第"+HIY+"三"+HIC+"刀攻擊！\n"NOR,me,target);
				me->improve_skill("cloudblade",2 + (me->query_int()/10));
				me->improve_skill("blade",2 + random(2));
				COMBAT_D->do_attack(me,target,me->query_temp("weapon"),2);
				COMBAT_D->report_status(target);
               		 	if( me->query_skill("cloudblade")>75 && me->query_skill("blade") > 90 && roll > 80)
				{
					message_vision(HIG"$N身形一轉，瞬間對$n發出最高段的第"+HIR+"四"+HIG+"刀攻擊！\n"NOR,me,target);
					me->improve_skill("cloudblade",3 + (me->query_int()/5));
					me->improve_skill("blade",4 + random(4));
					COMBAT_D->do_attack(me,target,me->query_temp("weapon"),4);
					COMBAT_D->report_status(target);
					me->receive_damage("ap",25);				
				}
				me->receive_damage("ap",15);
			}
			me->receive_damage("ap",7);
		}
		me->receive_damage("ap",4); //luky
	}
        me->skill_active( "cloudblade",(: call_other, __FILE__, "delay", me ,cost:), 5);
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
        if( ob->query("class1")!="向雲堂" ) return 15;  //配合入門的quest用
        else if( ob->query("adv_class")==1 ) return 85;   //沒有一轉之前只能練到85
        else return 95;  //最高練到95
}
