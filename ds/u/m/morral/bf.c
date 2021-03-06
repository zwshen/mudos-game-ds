#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void delay(object me,int cost);
mapping *action = ({
	([
	"action": "$N左腳跨出成半弓馬步，變左拳為掌，一式「左橫打」,\n  向$n的腰眼擊去",
	"damage":                10,
	"dodge" :                20,
            "damage_type":  "劈傷",
        ]),

	([
	"action": "$N一式「推窗」，左足大步前進，\n  逼進$n身前，左右掌用力擊向$n的胸口",
	"damage":                15,
	"dodge" :                10,
	"parry" :               -20,
            "damage_type":  "撞傷",
        ]),

	([
	"action": "$N使出一式「採摟勾拌」右掌畫弧內翻，\n  左掌向斜前方延伸擊向$n",
	"damage":                8,
	"dodge" :                -10,
	"parry" :                20,
        "damage_type":  "劈傷",
        ]),

	([
	"action": "$N猛地旱地拔蔥，一式「連環腳」，雙腳前後踢向$n",
	"damage":                13,
	"dodge" :                10,
	"parry" :                -25,
        "damage_type":  "踢傷",
        ]),

	([
	"action": "$N馬步一坐，一式「反砸」，左拳自上方往前斜方畫一大弧，\n  狠狠地捶向$n肩膀",
	"damage":                10,
	"dodge" :                10,
	"parry" :                20,
        "damage_type":  "捶傷",
        ]),

	([
	"action": "$N一連向前大跨三步，一式"+ HIY "「鐵山靠」" NOR + "扭腰轉身，\n  氣運後背奮力向$n撞去",
	"damage":                17,
	"dodge" :                10,
	"parry" :                -10,
        "damage_type":  "撞傷",
        ]),
	
	([
	"action": "$N曲肘沉馬，左腳往前重跨一步，一式「挑打頂肘」尤如槍刺擊向$n胸口",
	"damage":                12,
	"dodge" :                -10,
	"parry" :                20,
	"damage_type":  "撞傷",
	]),

	([
	"action": "$N一式「掛塌」，左掌內、外虛晃幾轉，右掌登時向斜前下方打向$n下腰盤",
	"damage":                12,
	"dodge" :                -10,
	"parry" :                20,
	"damage_type":  "擊傷",
	]),

	([
	"action": "$N使出「大纏絲」，雙手左、右不停地牽引著$n尤如層層絲綁",
	"damage":                10,
	"dodge" :                -10,
	"parry" :                10,
	"damage_type":  "瘀傷",
	]),

	([
	"action": "$N左步前跨，右手凌空由身後往前畫一大圓，一式「落步砸」，\n  砸向$n上盤二大要害",
	"damage":                14,
	"dodge" :                -20,
	"parry" :                -10,
	"damage_type":  "捶傷",
	]),
});

int exert(object me, object target, string arg)
{
	int a,c,i,j,damage;
	int hs;   
	string msg;
	object weapon;
	mapping type;
	
	weapon=me->query_temp("weapon");
	if(weapon)
	{
		if(weapon->query("skill_type")!="unarmed") return notify_fail("你手中拿著武器，不能使用「八極拳」吧﹗\n");
	}
	if(arg=="off" )
	{
		if( me->query_skill_mapped("unarmed")!="bagi_fist")
			return notify_fail("你並沒有使用「八極拳」。\n");
		me->map_skill("unarmed");
		me->reset_action();
		write("技能「八極拳」已取消。\n");
		return 1;
	}

	if(me->query_skill("unarmed")<5) return notify_fail("你的空手搏擊基礎不夠無法使用「八極拳」。\n");
	if(me->query("mp")<10 || me->query("hp")<10) return notify_fail("你的身體狀況無法使用八極拳法。\n");
	//第二次exert
	if(me->query_skill_mapped("unarmed")=="bagi_fist")
	{
	  if( !target ) target = offensive_target(me);
	  if(!target) 	return notify_fail("你正在使用「八極拳」。\n");
	   
	   //攻擊性的要特別注意要加下面兩行.
	   if(!me->can_fight(target))
		return me->can_fight(target);
	  
	  c = target->query_armor();

	  hs=me->query_skill("horse-steps");
	  if(hs>79) hs+=hs/3+random(hs/2);

	  if(me->query_skill("bagi_fist") > random(200) && me->query_skill("bagi_fist") > 49 )
	  {
      	   msg = HIC "\n$N虎喝一聲，氣運雙掌, 使出絕技「猛虎硬爬山」，狠狠地擊向$n的胸口！！\n\n" NOR ;
	   damage = me->query_skill("bagi_fist") + hs;
	   damage =  damage/2 + random(damage) + me->query_damage();
	   damage -= random(target->query_armor());
	   if(damage<60) damage=60+random(me->query_str());
	   me->start_busy(2);
           if(random(me->query_skill("bagi_fist")) > 30 )
           {
		msg += HIR "結果$n的胸口被$N狠狠擊中，登時狂噴一口鮮血﹗\n" NOR;
		target->start_busy(3);
	        target->receive_damage("hp",damage,me);
                COMBAT_D->report_status(target);
	   }
	    else
	   {
	    msg += HIW"可是被$n狼狽地給逃了開去，但$n也嚇地汗流滿面。\n" NOR;
	   }
	   if(!me->is_fighting(target)) me->kill_ob(target);
	   if(!target->is_fighting(me)) target->kill_ob(me);
	   message_vision(msg, me, target);
	   me->receive_daemage("mp",30);
           return 1;
          }
          else
          {
	    i=random(me->query_skill("bagi_fist")/20)+1;
	    if(i>5) i=5;
	    if(i<1) i=1;

	    for( a=0; a<i; a++ )
	    {
		if(a>0) message_vision(HIC"\n趁著$n錯愕之時，$N挾著餘威又出殺招！\n"NOR,me,target);
		j=random(sizeof(action));
		type=action[j];
		msg = type["action"]+NOR+", ";
		damage = (me->query_damage()+me->query_skill("bagi_fist")/2)+hs/3-random(c*3)/2;
		damage += type["damage"];
        	if( damage < 1 ) damage = random(20);
		if( random(me->query_dex()*2+me->query_skill("bagi_fist")/2) > random(target->query_dex()*2+target->query_skill("dodge")/2)+type["dodge"]
		 && damage>0)
		{
			msg += HIC"結果造成$n"HIC"一處"+type["damage_type"]+"!!\n"NOR;
			message_vision(msg, me, target);
 	    		me->improve_skill("bagi_fist",target->query("level")/3);
                	target->receive_damage("hp",damage,me);
                	COMBAT_D->report_status(target);
		}
		 else
		{
			msg += "可是被$n給閃了開去。\n";
			message_vision(msg, me, target);
			target->improve_skill("dodge",1);
		}
	    }
	    me->receive_damage("mp",i*7);
	    me->start_busy(1);
          }
          if(!me->is_fighting(target)) me->kill_ob(target);
	  if(!target->is_fighting(me)) target->kill_ob(me);
          me->improve_skill("bagi_fist",1+random(me->query_int()/2));
          me->improve_skill("unarmed",1+random(me->query_int()/2));
	  return 1;
	}

	me->map_skill("unarmed", "bagi_fist");
	me->reset_action();
	message_vision("\n"HIC"$N微一凝神，登時鼻尖、指尖和足尖三尖相對，開始運起「八極拳」心法！\n"NOR,me);
	me->receive_damage("mp",5);
	me->start_busy(1);
        me->start_call_out( (: call_other, __FILE__, "delay", me ,5:), 10);
	return 1;
}

void delay(object me,int cost)
{
	object weapon;
	if(!me) return;
	weapon=me->query_temp("weapon");
	if(weapon)
	{
		if(weapon->query("skill_type")!="unarmed")
		{
	 	 me->map_skill("unarmed");
		 me->reset_action();
		 return;
		}
	}
	
	if(me->query_skill_mapped("unarmed")!="bagi_fist")
	{
	 return;
	}
	
	if(me->query("mp")<5)
	{
	 	me->map_skill("unarmed");
		me->reset_action();
		tell_object(me,"\n你的體力不夠，無法繼續使用八極拳。\n");
		return ;
	}
	if( me->is_fighting() ) me->receive_damage("mp",5); //luky
        me->start_call_out( (: call_other, __FILE__, "delay", me ,cost:), 10);
}

int valid_learn(object me) {	return 1;	}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me) {	return 1; }
