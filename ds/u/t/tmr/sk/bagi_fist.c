//New bagi_fist by Tmr 	1999/10/15 18:30
#include <ansi.h>
inherit SKILL;
inherit SSERVER;

void delay(object me,int cost);

mapping *action = ({
        ([
        "action": "$N左腳跨出成半弓馬步，變左拳為掌，一式「左橫打」,\n  向$n的腰眼擊去",
        "damage":                10,
        "dodge" :                20,
        "attact_type":  "bar",  // 設定技能的攻擊種類
                                // 種類有 生物(bio) 獸性(bar)
                                // 魔法(wit)心靈(sou)科技(tec)
            "damage_type":  "劈傷",
        ]),

        ([
        "action": "$N一式「推窗」，左足大步前進，\n  逼進$n身前，左右掌用力擊向$n的胸口",
        "damage":                15,
        "dodge" :                10,
        "parry" :               -20,
        "attact_type":  "bar",
            "damage_type":  "撞傷",
        ]),

        ([
        "action": "$N使出一式「採摟勾拌」右掌畫弧內翻，\n  左掌向斜前方延伸擊向$n",
        "damage":                8,
        "dodge" :                -10,
        "parry" :                20,
        "attact_type":  "bar",
        "damage_type":  "劈傷",
        ]),

        ([
        "action": "$N猛地旱地拔蔥，一式「連環腳」，雙腳前後踢向$n",
        "damage":                13,
        "dodge" :                10,
        "parry" :                -25,
        "attact_type":  "bar",
        "damage_type":  "踢傷",
        ]),

        ([
        "action": "$N馬步一坐，一式「反砸」，左拳自上方往前斜方畫一大弧，\n  狠狠地捶向$n肩膀",
        "damage":                10,
        "dodge" :                10,
        "parry" :                20,
        "attact_type":  "bar",
        "damage_type":  "捶傷",
        ]),

        ([
        "action": "$N一連向前大跨三步，一式"+ HIY "「鐵山靠」" NOR + "扭腰轉身，\n  氣運後背奮力向$n撞去",
        "damage":                17,
        "dodge" :                10,
        "parry" :                -10,
        "attact_type":  "bar",
        "damage_type":  "撞傷",
        ]),
        
        ([
        "action": "$N曲肘沉馬，左腳往前重跨一步，一式「挑打頂肘」尤如槍刺擊向$n胸口",
        "damage":                12,
        "dodge" :                -10,
        "parry" :                20,
        "attact_type":  "bar",
        "damage_type":  "撞傷",
        ]),

        ([
        "action": "$N一式「掛塌」，左掌內、外虛晃幾轉，右掌登時向斜前下方打向$n下腰盤",
        "damage":                12,
        "dodge" :                -10,
        "parry" :                20,
        "attact_type":  "bar",
        "damage_type":  "擊傷",
        ]),

        ([
        "action": "$N使出「大纏絲」，雙手左、右不停地牽引著$n尤如層層絲綁",
        "damage":                10,
        "dodge" :                -10,
        "parry" :                10,
        "attact_type":  "bar",
        "damage_type":  "瘀傷",
        ]),

        ([
        "action": "$N左步前跨，右手凌空由身後往前畫一大圓，一式「落步砸」，\n  砸向$n上盤二大要害",
        "damage":                14,
        "dodge" :                -20,
        "parry" :                -10,
        "attact_type":  "bar",
        "damage_type":  "捶傷",
        ]),
});


int exert(object me, object target, string arg)
{
	int a,c,i,j,k,damage,sk,lvtest,power,pcost;
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
	if(me->query("ap")<10 || me->query("hp")<10) return notify_fail("你的身體狀況無法使用八極拳法。\n");

	//第二次exert
	if(me->query_skill_mapped("unarmed")=="bagi_fist")
	{
	  if( !target ) target = offensive_target(me);
	  if(!target) 	return notify_fail("你正在使用「八極拳」。\n");
	   
	   //攻擊性的要特別注意要加下面兩行.
	   if(!me->can_fight(target))
		return me->can_fight(target);
	  c = target->query_armor();
	  sk=me->query_skill("bagi_fist");

	  if( sk > 49 && random(sk) > random(150) )
	  {
      	   msg = HIC "$N虎喝一聲，氣運雙掌, 使出絕技「猛虎硬爬山」，狠狠地擊向$n的胸口！！\n\n" NOR ;

		damage = sk+me->query_str()+me->query_damage();

//採用horse-steps 所額外積存的bagi-power 來附加特攻威力。
//捨棄原採用 horse-setps LV 計算方式。
//bagi-power 最滿為1000。（首要條件horse-steps= 100)。 by Tmr

		power=me->query("bagi-power");
		if(power>10)
		{
		if(power < 100) 	{damage=damage+damage* 1/10; pcost=5;  }
		else if(power <250) 	{damage=damage+damage* 3/10; pcost=25;  }  //六次
		else if(power < 500) 	{damage=damage+damage* 5/10; pcost=60;}   //三次
		else if(power < 800) 	{damage=damage+damage* 7/10; pcost=150;} //二次
		else 			{damage=damage*2;    	       pcost=200;} //一次
		me->add("bagi-power",-pcost);
		if(wizdarp(me) )
			tell_object(me,"bagi-power -> "+me->query("bagi-power") +"\n");
		}
	   damage = damage - c/2 - random(target->query_skill("parry")/2+target->query_skill("dodge") /2 );

//不給最低傷害力
//	   if(damage < 30) damage=30+random(me->query_str()/2);

	   if(userp(me) && userp(target) ) me->start_busy(2);
	   else me->start_busy(1);

           if(  damage => 0 && random(sk) > 40 )
           {
		msg += HIR "$n的胸口被$N狠狠擊中，登時狂噴一口鮮血﹗！\n" NOR;
		target->start_busy(random(3));
		// 增加素質對傷害的影響
		damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
		target->receive_damage("hp",damage,me);
		if(wizardp(me)) printf("%d\n",damage);
	}
	else
	{
	  msg += HIW"可是被$n狼狽地給逃了開去，但$n也嚇地汗流滿面。\n" NOR;
	}
	   if(!me->is_fighting(target)) me->kill_ob(target);
	   if(!target->is_fighting(me)) target->kill_ob(me);
	   message_vision(msg, me, target);
               COMBAT_D->report_status(target);
	   me->receive_daemage("ap",30 );
	   return 1;
         }
         else
	{
	    i=random(sk/20)+1;
	    if(i>5) i=5;
	    if(i<1) i=1;

	    if(userp(me) && userp(target)) me->start_busy(2);
	    else me->start_busy(1);

	    for( a=0; a<i; a++ )
	    {
		if(a> 0) msg=HIC"趁著$n錯愕之時，$N挾著餘威又出殺招！\n"NOR;
		else msg ="";
		j=random(sizeof(action));
		type=action[j];
		msg += type["action"]+NOR+", ";

		damage = me->query_damage()/2+me->query_str()/2+sk/3+type["damage"];

//採用horse-steps 所額外積存的bagi-power 來附加特攻威力。
//捨棄原採用 horse-setps LV 計算方式。
// bagi-power 最滿為1000。（首要條件horse-steps= 100)。 by Tmr
		if(power>10)
		{
		if(power < 300) 	{damage=damage+damage* 1/10; pcost=5;}
		else if(power < 500) 	{damage=damage+damage*3/10; pcost=10;}
		else if(power < 800) 	{damage=damage+damage*5/10; pcost=20;}
		else 			{damage=damage+damage*8/10;   pcost=35;}
		me->add("bagi-power",-pcost);
		}

//不給最低傷害力
//        	if( damage < 1 ) damage = random(20);

			// 增加素質對傷害的影響
		damage = COMBAT_D->Merits_damage(me,target,damage,"bar");

		if( random(COMBAT_D->attack_factor(me,"unarmed")) > random(-COMBAT_D->dodge_factor(target,"dodge"))+type["dodge"]  && damage>0)
		k=0;
		if( damage > 0 )
		{
			msg += HIC"結果造成$n"HIC"一處"+type["damage_type"]+"!!\n"NOR;
			message_vision(msg, me, target);
 	    		me->improve_skill("bagi_fist",target->query("level")/3);
	            if(wizardp(me)) printf("%d\n",damage);
                	target->receive_damage("hp",damage,me);
                	k++;
		}
		 else
		{
			msg += "可是被$n給閃了開去。\n";
			message_vision(msg, me, target);
			target->improve_skill("dodge",1);
		}
	    }
	    if(k) COMBAT_D->report_status(target);
	    me->receive_damage("ap",i*8);
          }
	if(!me->is_fighting(target)) me->kill_ob(target);
 	if(!target->is_fighting(me)) target->kill_ob(me);
	me->improve_skill("bagi_fist",1+random(me->query_int()/2));
            me->improve_skill("unarmed",1+random(me->query_int()/2));
	return 1;
	}
	if(!me->skill_active( "bagi_fist",(: call_other, __FILE__, "delay", me ,5:), 10))
		return notify_fail("你結束八極拳的動作還沒完成。\n");

	me->map_skill("unarmed", "bagi_fist");
	me->reset_action();
	message_vision("\n"HIC"$N微一凝神，鼻尖、指尖和足尖三尖相對，開始運起「八極拳」心法！\n"NOR,me);
    	me->receive_damage("ap",5);
	me->start_busy(1);
//	me->start_call_out( (: call_other, __FILE__, "delay", me ,5:), 10);
	return 1;
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
	a=75+a;
	return a;
}
