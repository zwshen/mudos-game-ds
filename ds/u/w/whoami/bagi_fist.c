//New bagi_fist by Tmr  1999/10/15 18:30
// QC: Luky 1999.10.16 14:39
//Update By Tmr 2000/5/7

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
	int a,c,i,j,k,damage,sk,lvtest,power,pcost,target_d,basicd;
	string msg;
    object weapon, wp;
	mapping type;
    
	weapon=me->query_temp("weapon");
	if(weapon && weapon->query("skill_type")!="unarmed")
		 return notify_fail("你手中拿著武器，不能使用「八極拳」吧﹗\n");
	if(arg=="off" )
	{
        if( me->query_skill_mapped("unarmed")!="bagi_fist")
            return notify_fail("你並沒有使用「八極拳」。\n");
        me->map_skill("unarmed");
        me->reset_action();
        write("技能「八極拳」已取消。\n");
        return 1;
	}

	if(me->query_skill("unarmed")<5) 
		return notify_fail("你的空手搏擊基礎不夠無法使用「八極拳」。\n");
	if(me->query("ap")<10 || me->query("hp")<10) 
		return notify_fail("你的身體狀況無法使用八極拳法。\n");

	//第二次exert
	if(me->query_skill_mapped("unarmed")=="bagi_fist")
	{
	if( !target ) target = offensive_target(me);
	if(!target)   return notify_fail("你正在使用「八極拳」。\n");
	if( environment(me) != environment(target) )
		return notify_fail("你們不是在同一格。\n");
       
        //攻擊性的要特別注意要加下面兩行.
	if(!me->can_fight(target)) return 0;
    if(target->is_corpse()) return notify_fail("看清楚，對方己經死了。\n");  // add by wilfred 解決對方是屍體的問題
	c = target->query_armor();
	sk=me->query_skill("bagi_fist");
	target_d=-COMBAT_D->dodge_factor(target,"dodge")*10/15;
	power=me->query_temp("exert_mark/bagi-power"); //暫時性的東西都只用 temp ,quit時會清掉


        if( sk > 49 && random(sk) > random(150) )
	{
        msg = HIC "$N虎喝一聲，氣運雙掌, 使出絕技「猛虎硬爬山」，狠狠地擊向$n！！\n\n" NOR ;

        damage = sk + me->query_damage();
        damage = damage + random(damage/2);
	damage = damage - c/3 - random(c/3);
        if(power > 5)
        {
            if(power < 20)  { damage=damage+damage* 1/6; pcost=5;  }
            else if(power < 40) { damage=damage+damage* 2/6; pcost=10;  } //5次
            else if(power < 60) { damage=damage+damage* 3/6; pcost=15;  } //4次
            else if(power < 80) { damage=damage+damage* 4/6; pcost=20;  } //3次
            else  { damage=damage+damage*5/6; pcost=30; } //2次
            me->add_temp("exert_mark/bagi-power",-pcost);
        }
       damage = COMBAT_D->Merits_damage(me,target,damage,"bar");

       if( userp(me) && userp(target) ) me->start_busy(2);
       else me->start_busy(1);
       me->receive_daemage("ap",50 );
       if(  damage > 0 && sk + random(sk/2) > random(target_d) )
        {
	msg += HIR "$n被$N" HIR "狠狠擊中，登時狂噴一口鮮血﹗！" NOR;
  if( objectp(wp = me->query_temp("weapon")) ) wp->attack(); // wp 損壞率 add by wilfred
        target->add_busy(1+random(2));
        message_vision(msg, me, target);
        target->receive_damage("hp",damage,me);
        if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
		tell_object(me,HIY"("+damage+")"NOR);
        if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
		tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
	message_vision("\n", me);
        COMBAT_D->report_status(target);
	}
	else    {
		msg += HIW"可是被$n" HIW "狼狽地給逃了開去.....\n" NOR;
		message_vision(msg, me, target);
	}
	if(!me->is_fighting(target)) me->kill_ob(target);
        if(!target->is_fighting(me)) target->kill_ob(me);
        return 1;
	}
        else
	{
	if( sk < 20) i=1;
	else 	if( sk < 40) i=1+random(2);
	else 	if( sk < 60) i=2+random(2);
	else 	if( sk < 80) i=2+random(3);
	else 	i=3+random(3);
        if(userp(me) && userp(target)) me->start_busy(2);
        else me->start_busy(1);
        k=0;
        basicd =sk+me->query_damage();
        for( a = 0; a < i; a++ )
        {
	if ( a > 0) msg=HIC"趁著$n"HIC"錯愕之時，$N挾著餘威又出殺招！\n"NOR;
        else msg ="";
        j=random(sizeof(action));
        type=action[j];
        msg += type["action"]+NOR+", ";
        damage = basicd/4+random(basicd/4);
        if(power>10)
        {
            if(power < 20)  { damage=damage+damage*1/8; pcost=5; }
            else if(power < 40)     { damage=damage+damage*2/8; pcost=10; }
            else if(power < 60)     { damage=damage+damage*3/8; pcost=15; }
            else            { damage=damage+damage*4/8; pcost=20; }
            me->add_temp("exert_mark/bagi-power",-pcost);
        }
        damage = damage - c/2 - random(c/2);
        damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
        if(damage<1) damage = 1+random(5);
        if( sk/2+random(sk) > random(target_d)  )	//連擊有較高的命中率
        {
            msg += HIC"結果造成$n"HIC"一處"+type["damage_type"]+"!!"NOR;
            message_vision(msg, me, target);
  if( objectp(wp = me->query_temp("weapon")) ) wp->attack(); // wp 損壞率 add by wilfred
                me->improve_skill("bagi_fist",target->query("level")/3);
                    damage=damage*(6-k)/6;
                    target->receive_damage("hp",damage,me);
                if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                        tell_object(me,HIY"("+damage+")"NOR);
                if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                        tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
                if(wizardp(me) && me->query("env/debug")) 
                        tell_object(me,"  造成"+damage+"點傷害!!\n"); 
                message_vision("\n", me);
                k++;
	}
	else        {
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
	return 1;
}

int valid_learn(object me) {    return 1;   }

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int practice_skill(object me) { return 1; }

int improve_limite(object ob)
{
	int a;
	a=ob->query_int();
	a=75+a;
	return a;
}
