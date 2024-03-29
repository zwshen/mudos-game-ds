// combatd.c

//#pragma optimize all
// #pragma save_binary
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_DBASE;
void delete_killer(object ob);

string *catch_hunt_msg = ({
	HIW "$N和$n仇人相見分外眼紅﹐立刻打了起來﹗\n" NOR,
	HIW "$N和$n一碰面﹐二話不說就打了起來﹗\n" NOR,
});

string *winner_msg = ({
	CYN "\n$N雙手一拱﹐笑著說道﹕承讓﹗\n\n" NOR,
	CYN "\n$N勝了這招﹐向後躍開三尺﹐笑道﹕承讓﹗\n\n" NOR,
});

void create()
{
	seteuid(getuid());
	set("name", "戰鬥精靈");
	set("id", "combatd");
}

string damage_msg(int damage, string type)
{
	string str;

//	return "造成 " + damage + " 點" + type + "。\n";

	if( damage == 0 ) return NOR "結果力道太小並沒有造成傷害。\n";

	switch( type ) {
	case "斲傷":
	case "割傷":
		if( damage < 10 ) str =  "結果只造成輕微的擦傷。";
		else if( damage < 20 ) str = "結果割出一道細長的血痕。";
		else if( damage < 40 ) str = "劃出了一道傷口﹗";
		else if( damage < 60 ) str = "割出了一道血淋淋的傷口﹗";
		else if( damage < 120 ) str = "留下了一道又長又深的傷口﹗";
		else str = "造成一道深及見骨的可怕傷口﹗﹗";
		break;
	case "刺傷":
		if( damage < 10 ) str =  "結果只造成輕微的擦傷。";
		else if( damage < 20 ) str = "結果刺出一個傷口。";
		else if( damage < 40 ) str = "結果刺出一個大傷口﹗";
		else if( damage < 60 ) str = "結果刺出一個很深的傷口﹗";
		else if( damage < 120 ) str = "結果刺出一個血肉糢糊的血窟窿﹗";
		else str = "只聽見一聲慘嚎﹐鮮血濺了滿地﹗﹗";
		break;
	case "瘀傷":
		if( damage < 10 ) str =  "結果只造成輕微的擦傷。";
		else if( damage < 20 ) str = "結果造成一些瘀傷。";
		else if( damage < 40 ) str = "結果造成不小的傷害﹗";
		else if( damage < 60 ) str = "$n痛得差點哭了出來﹗";
		else if( damage < 120 ) str = "結果$n「哇」地一聲吐出一大口鮮血﹗";
		else str = "「砰」地一聲巨響﹐$n口吐鮮血飛了出去﹗﹗";
		break;
	default:
		if( !type ) type = "傷害";
		if( damage < 5 ) str =  "結果只是勉強造成輕微的";
		else if( damage < 10 ) str = "造成一點";
		else if( damage < 20 ) str = "造成一處";
		else if( damage < 40 ) str = "造成頗重的";
		else if( damage < 60 ) str = "造成嚴重的";
		else if( damage < 90 ) str = "造成相當嚴重的";
		else if( damage < 120 ) str = "造成非常嚴重的";
		else if( damage < 150 ) str = "造成不可挽救的";
		else if( damage < 180 ) str = "造成無與倫比的嚴重";
		else str =  "造成舉世無雙的";
		str += type + "﹗";
	}
	
//	str += sprintf("(%s%d)"NOR,HIR,damage);
	return str;
}

string eff_status_msg(int ratio)
{
	if( ratio==100 ) return HIG "精神很好﹐身上一點傷也沒有。" NOR;
	if( ratio > 90 ) return HIG "似乎受了點輕傷。" NOR;
	if( ratio > 80 ) return HIY "身上有一些小傷口。" NOR;
	if( ratio > 70 ) return HIY "身上有幾處傷口﹐不過似乎並不礙事。" NOR;
	if( ratio > 60 ) return HIY "身上有幾處大傷口﹐看起來狀況不太好。" NOR;
	if( ratio > 50 ) return HIM "氣息粗重﹐動作散亂﹐看來受創不輕。" NOR;
	if( ratio > 40 ) return HIM "已經傷痕累累﹐正在勉力支撐著不倒下去。" NOR;
	if( ratio > 30 ) return HIR "受了相當重的傷﹐只怕會有生命危險。" NOR;
	if( ratio > 20 ) return HIR "已經受傷過重﹐似乎快不行了。" NOR;
	if( ratio > 10  ) return RED "混身是血﹐已經奄奄一息了。" NOR;
	return RED "已經倒在血泊之中﹐隨時都可能斷氣。" NOR;
}

varargs void report_status(object ob, int effective)
{
	message_vision( "( $N" + eff_status_msg(
		(int)ob->query("hp") * 100 / (int)ob->query("max_hp") ) + " )\n", ob);
}

varargs string status(object ob, int effective)
{
 return ob->name()+eff_status_msg((int)ob->query("hp") * 100 / (int)ob->query("max_hp") );
}

// This function calculates the combined skill/combat_exp power of a certain
// skill. This value is used for A/(A+B) probability use.
varargs int skill_power(object ob, string skill, int usage)
{
	int power;

	if( !living(ob) ) return 0;

	power = ob->query_skill(skill);

	if( ob->query("mp") < ob->query("max_mp")/10 )	//mp剩下1/10會減弱
		power = power*4/5 ;

	power += ob->query("combat_exp")/1500;
	power /= 2;
	return power;
}

varargs int attack_factor(object ob,string attack_skill)
{
  int factor;
  factor = 0;
  if( !living(ob) ) return 0;

  factor = skill_power(ob, attack_skill, SKILL_USAGE_ATTACK);	//技能命中修正(0-50)
  factor += ob->query_temp("apply/hit");			//武器命中修正(-50 ~ 50)
  factor += ob->query_temp("spell/hit");			//法術命中修正(-50 ~ 50)
  factor += ob->query_dex()*2;					//dex 命中修正(0-200)
  if(ob->query_temp("detect"))
   factor += ob->query_temp("detect")*10;			//偵測修正
  if(ob->query("wound/hand") )
   factor= factor - (factor * ob->query("wound/hand") )/110;	//wound修正
  return factor;
}

varargs int dodge_factor(object ob,string dodge_skill)
{
  int factor;
  factor = 0;
  if( !living(ob) ) return 0;

  factor -= skill_power(ob, dodge_skill, SKILL_USAGE_DEFENSE);	//技能閃躲修正(0-50)
  factor -= ob->query_dex()*2;					//dex 閃躲修正(0-200)
  if(ob->query_temp("invis"))
   factor -= ob->query_temp("invis")*10;			//隱身修正
  if(ob->query_temp("fly")) factor -= 25;			//飛行修正
  else if(ob->query_temp("float")) factor -= 10;		//漂浮修正
  if( ob->query("wound/foot") )
   factor= factor - (factor * ob->query("wound/foot") )/110;	//wound修正
  return factor;
}
// do_attack()
//
// Perform an attack action. This function is called by fight() or as an
// interface for some special utilize in quests.
//
varargs int do_attack(object me, object victim, object weapon, int attack_type)
{
	mapping my, your, action;
	string limb, *limbs, result, result_damage,result_me,result_victim;
	string attack_skill, dodge_skill, parry_skill;
	mixed foo;
	mapping weapon_msg;
	int hitrole, heavy, miss;
	int damage, damage_bonus;

	//協力技
	if(me->query("env/superman"))
	{
	 //tell_object(me,"COMBATD呼叫 combine_attack()中!\n");
	 if(me->combine_attack(victim)) return 1;
	}
	else
	if(random(6)==1) 
	{
		//tell_object(me,"COMBATD呼叫 combine_attack()中!\n");
		if(me->combine_attack(victim)) return 1;
	}

  result_damage="";
  my = me->query_entire_dbase();
  your = victim->query_entire_dbase();

	//
	// (1) Find out what action the offenser will take.
	//

  action = me->query("actions");

  if( !mapp(action) )
  {
	me->reset_action();
	action = me->query("action");
	if( !mapp(action) )
	{
		CHANNEL_D->do_channel( this_object(), "sys", sprintf("%s(%s): bad action = %O",
					me->name(1), me->query("id"), me->query("actions", 1)));
		return 0;
	}
  }
  result = "" + action["action"] + "﹗";
  if(weapon)
  if(arrayp(weapon_msg=weapon->query("combat_msg"))) result=""+weapon_msg[random(sizeof(weapon_msg))]+ "﹗";
	//
	// (2) 初始機率並加以修正以判斷是否能命中
	//
  heavy=0;
  miss=0;	
  hitrole=random(HITROLE);			// random數字越低 屬性技能影響越大

  if(attack_type == TYPE_HEAVY) heavy=1;
  else if(hitrole > HITHEAVY ) heavy=1; 		//heavy 命中要害
	else if(hitrole < HITMISS ) miss=1;		//miss  嚴重失手

  if( wizardp(me) && me->query("env/debug") )	//debug message 1
  message_vision("  初始命中機率:"+hitrole+"\n",me);

  if( objectp(weapon) )	attack_skill = weapon->query("skill_type");
	else		attack_skill = "unarmed";

  limbs = victim->query("limbs");
  limb = limbs[random(sizeof(limbs))];

  hitrole += attack_factor(me,attack_skill);

  hitrole += dodge_factor(victim,"dodge");

  if(attack_type==TYPE_BERSERK) hitrole-=hitrole/10; 	//Berserk 多次攻擊降低命中率
  else if(attack_type==TYPE_QUICK) hitrole+=hitrole/10; //Quick 快速攻擊增加命中率

  if( wizardp(me) && me->query("env/debug") )		//debug message 2
  message_vision("  命中修正:"+attack_factor(me,attack_skill)
  +"  閃躲修正:"+dodge_factor(victim,"dodge")+"\n"
  +"  攻擊TYPE修正結果:"+hitrole+"\n"
  ,me);
 
  if( victim->is_busy() ) hitrole+=hitrole/5;

	//
	// (3) Fight!
	//     如果hitrole > 100 即為命中, <100 則沒有命中
	//     當heavy==1 時必定命中, 而miss==1時 必定失手且會因為失誤而造成busy
	//
	
  if( ( !heavy && ( hitrole < THACO ) && !victim->query_temp("unconcious") ) || miss )  // victim閃躲成功
  {
	dodge_skill = victim->query_skill_mapped("dodge");
	if( !dodge_skill ) dodge_skill = "dodge";
	result += SKILL_D(dodge_skill)->query_dodge_msg(limb);
	
	//增加經驗值與技能
	if( ( random(your["level"] + my["level"]) >= your["level"] ) && ( !userp(victim) || !userp(me) ) )
	{
		your["combat_exp"] += 1+my["level"]/25;
		victim->improve_skill(dodge_skill, random( your["int"]/2 ) + 1 +my["level"]/3);
		if( dodge_skill != "dodge" )
		victim->improve_skill("dodge", random( your["int"]/2 ) + 1 +my["level"]/3);
	}
	
	// This is for NPC only. NPC have chance to get exp when fail to hit.
	if( ( hitrole > EXPCO ) && !userp(me) )
	{
		my["combat_exp"] += 1+your["level"]/25;
		me->improve_skill(attack_skill, 1+random(my["int"]/2)+your["level"]/3);
	}
	if(miss && !me->is_busy()) me->start_busy(random(2)+1);
	damage = RESULT_DODGE;

  } else	//victim閃躲失敗
    {
		//
		//	(4) 檢查victim是否能招架攻擊
		//

	if( victim->query_temp("armor/shield") )	//對手有盾牌
	{
		parry_skill = "block";
	}
	else
	{
	  if( victim->query_temp("weapon") )	//對手有武器
	  {
		parry_skill = "parry";
	  }
	   else	//對手沒有武器
	   {
		parry_skill = "unarmed";
	   }
	}
	
	hitrole = random(HITROLE);
	if( parry_skill == "unarmed" )
		hitrole -= skill_power(victim, parry_skill, SKILL_USAGE_DEFENSE)/2;
	else
		hitrole -= skill_power(victim, parry_skill, SKILL_USAGE_DEFENSE);
	hitrole += skill_power(me, attack_skill, SKILL_USAGE_ATTACK);
	hitrole -= victim->query_temp("apply/parry");
	hitrole += me->query_str()*3;
	hitrole -= victim->query_str()*3;
	if( victim->is_busy() )  hitrole+= hitrole/5;

	//victim招架成功

	if( ( !heavy && ( hitrole < THACO ) && !victim->query_temp("unconcious") ) || miss )
	{
			// change to SKILL_D(parry_skill) after added parry msg to those
			// martial arts that can parry.

		if(parry_skill=="block")
		result += SKILL_D("block")->query_block_msg(victim->query_temp("armor/shield"));	
		else
		result += SKILL_D("parry")->query_parry_msg(victim->query_temp("weapon"));	//招架訊息

		if( ( random(your["level"]-my["level"]) < random(2) ) && ( !userp(victim) || !userp(me) ) )
		{
				your["combat_exp"] += 1+my["level"]/25;
				victim->improve_skill(parry_skill, 1+random(your["int"]/3)+my["level"]/3);
		}
		
		damage = RESULT_PARRY;

	}
	 else
	  {
			//	
			//	(5) 命中敵人victim且victim招架失敗, 開始計算傷害值
			//

		damage = me->query_damage();
		damage = damage/2 + random(damage/2);
		
		if( action["damage"] )
		{
			if(action["damage"]>100) action["damage"]=100;
			if(action["damage"]<-99) action["damage"]=-99;
			damage += action["damage"] * damage / 100;	//skill效果修正[]%
		}

		if( weapon )
		{
			foo = weapon->hit_ob(me, victim, damage_bonus);
			if( stringp(foo) ) result += foo;
			else if(intp(foo) ) damage_bonus += foo;
		}
		 else
		  {
			foo = me->hit_ob(me, victim, damage_bonus);
			if( stringp(foo) ) result += foo;
			else if(intp(foo) ) damage_bonus += foo;
		  }

		if( damage_bonus > 0 )
			damage += (damage_bonus + random(damage_bonus))/2;

			//
			//	(6) 給予敵人傷害
			//

		damage -= (int)(victim->query_armor()*3+random(victim->query_armor()*2))/5;
		if(heavy) damage+=damage/2;
		if(damage <0 )
		{
		 if(random(me->query_str()) < me->query_str()/2) damage=0;
		 else damage=1+random(me->query_str())/3;
		}
		
		if(damage > 0 )
		{
		 damage = victim->receive_damage("hp", damage, me );
		 if(victim->query_temp("power_exert")>0 && random(2)) victim->add_temp("power_exert",-1);
		 if(victim->query_temp("power_cast")>0 && random(2)) victim->add_temp("exert_power",-1);
		}
		 result_damage +=damage_msg(damage, action["damage_type"]);

	}
  } 
  
  	//
	//	(7) 增加戰鬥熟練值與技能
	//

	if( !userp(me) || !userp(victim) )
	{
		if( random(your["level"] + my["level"]) >= my["level"] )
		{
			my["combat_exp"] += 1 + your["level"]/25;
			my["exp"] += random(your["level"]-my["level"]+2);
			me->improve_skill("combat", 1+random(my["int"]/2)+your["level"]/3);
			me->improve_skill(attack_skill, 1+random(my["int"]/2)+your["level"]/3);
			if(me->query_skill_mapped(attack_skill))
			me->improve_skill(me->query_skill_mapped(attack_skill), 1+random(my["int"]/2)+your["level"]/3);
		}
	
		if( random(your["level"] + my["level"]) >= your["level"] )
		{
			your["combat_exp"] += 1 + my["level"]/25;
			victim->improve_skill("combat", 1+random(your["int"]/2)+my["level"]/3);
		}
	}
  
  //
  //	(8) 顯示戰鬥訊息
  //
  
  if(heavy) result = HIM+"(奮力一擊)"+NOR+result;
  else if(miss) result = HIM+"(重心不穩)"+NOR+result;
  result = replace_string( result, "$l", limb );
  result_damage = replace_string( result_damage, "$l", limb );
  if( objectp(weapon) )
  {
	result = replace_string( result, "$w", weapon->name() );
        result_damage = replace_string( result_damage, "$w", weapon->name() );
  }
  else if( stringp(action["weapon"]) )
  {
	result = replace_string( result, "$w", action["weapon"] );
	result_damage = replace_string( result_damage, "$w", action["weapon"] );
  }
  result_me=result+HIY+result_damage+NOR;

  result_me = replace_string( result_me, "$N", "你" );
  result_me = replace_string( result_me, "$n", victim->query("name") );
  result_me = replace_string( result_me, "$p", victim->query("name") );
  result_victim=result+HIR+result_damage+NOR;
  result_victim = replace_string( result_victim, "$N", me->query("name") );
  result_victim = replace_string( result_victim, "$n", "你" );
  result_victim = replace_string( result_victim, "$p", "你" );
  if(damage>0)
  {
   if(me->query_temp("show_damage")
    || me->query_temp("apply/show_damage") ) result_me+=sprintf("(%s%d"NOR")\n",HIY,damage);
 	else result_me+="\n";
   if(victim->query_temp("show_damage")
    || victim->query_temp("apply/show_damage")  ) result_victim+=sprintf("(%s%d"NOR") (%d/%d)\n",HIR,damage,your["hp"],your["max_hp"]);
	else result_victim+="\n";
  }
  //message_vision(result, me, victim );
  if( wizardp(me) && me->query("env/debug") )
  {
		tell_object(me, sprintf( HIG "  我方命中!!(HITROLE﹕%d) ﹐敵方受傷﹕%d\n" NOR,
			hitrole, damage));
  }
  if( wizardp(victim) && victim->query("env/debug") )
  {
		tell_object(victim, sprintf( HIY "  敵方命中!!(HITROLE﹕%d)﹐我方受傷﹕%d\n" NOR,
			hitrole, damage));
  }
  tell_object(me,result_me);
  tell_object(victim,result_victim+"\n");
  result+=CYN+result_damage+NOR+"\n";
  result = replace_string( result, "$N", me->query("name")  );
  result = replace_string( result, "$n", victim->query("name") );
  result = replace_string( result, "$p", victim->query("name") );
  tell_room(environment(me),result,({ me, victim }));


  if( damage > 0 )
  {
	if(me->query("env/report")) report_status(victim, damage);	//set report 1 可以看到report
	if( victim->is_busy() ) victim->interrupt_me(me);
	if( (!me->is_killing(your["id"])) && (!victim->is_killing(my["id"])) )	//only fight
	{
	  if( victim->query("hp") < victim->query("max_hp")/2 )	//打到剩下 1/2 HP 即停戰
	  {
		victim->remove_enemy(me);
		me->remove_enemy(victim);
		me->set_temp("stop_fight",victim);
		message_vision( winner_msg[random(sizeof(winner_msg))], me, victim);
	  }
	}
	if( damage > victim->query("max_hp")/7 )
	{
	 damage_bonus = random(13);
	 switch(damage_bonus)
	 {
	  case 1 :	victim->receive_wound("head", random(7), me );
	 		break;
	  case 2 :	victim->receive_wound("hand", random(7), me );
	 		break;
	  case 3 :	victim->receive_wound("foot", random(7), me );
	 		break;
	  case 4 :	victim->receive_wound("body", random(7), me );
	 		break;
	  default:      break;
	 }
	}
  }

  if( functionp(action["post_action"]) )
	evaluate( action["post_action"], me, victim, weapon, damage);

	// See if the victim can make a riposte.

  if( attack_type==TYPE_REGULAR && damage < 1 && random(20) < 2)
  {
	if( random(your["dex"]) > random(my["dex"]) )
	{
		message_vision("$N一擊不中﹐露出了破綻﹗\n", me);
		do_attack(victim, me, victim->query_temp("weapon"), TYPE_QUICK);
	}
	 else
	  {
		message_vision("$N見$n攻擊失誤﹐趁機發動攻擊﹗\n", victim, me);
		do_attack(victim, me, victim->query_temp("weapon"), TYPE_RIPOSTE);
	  }
  } 

}


void fight(object me, object victim)
{
        object ob,weapon;

        if( !living(me) ) return;
        
        if(victim->query_temp("stop_fight")==me)
        {
         victim->delete_temp("stop_fight");
         me->remove_enemy(victim);
         return;
        }

        // If victim is busy or unconcious, always take the chance to make an attack.
        if( victim->is_busy()) 
        //|| !living(victim)  
        {
                me->set_temp("guarding", 0);
                do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);

        // Else, see if we are brave enough to make an aggressive action.
        } else if(!me->query_temp("cast")) {
                me->set_temp("guarding", 0);
        do_attack(me, victim, me->query_temp("weapon"), TYPE_REGULAR);
        if(weapon=me->query_temp("weapon"))
        weapon->attack(me,victim);
        } else return;

        // Make sure the victim had noticed the attack.
        if( !victim->is_fighting(me) ) victim->fight_ob(me);
}
//	auto_fight()
//
//	This function is to start an automatically fight. Currently this is
//	used in "aggressive", "vendetta", "hatred", "berserk" fight.
//
void auto_fight(object me, object obj, string type)
{
	// Don't let NPC autofight NPC.
	if( !userp(me) && !userp(obj) ) return;

	// Because most of the cases that we cannot start a fight cannot be checked
	// before we really call the kill_ob(), so we just make sure we have no 
	// aggressive callout wating here.
	if( me->query_temp("looking_for_trouble") ) return;
	me->set_temp("looking_for_trouble", 1);

	// This call_out gives victim a chance to slip trough the fierce guys.
	call_out( "start_" + type, 0, me, obj);
}

void start_berserk(object me, object obj)
{
	int bellicosity;

	if( !me || !obj ) return;			// Are we still exist( not becoming a corpse )?

	me->set_temp("looking_for_trouble", 0);

	if(	me->is_fighting(obj)			// Are we busy fighting?
	||	!living(me)				// Are we capable for a fight?
	||	environment(me)!=environment(obj)	// Are we still in the same room?
	||	environment(me)->query("no_fight") 	// Are we in a peace room?
	)	return;

	bellicosity = (int)me->query("bellicosity");
	message_vision("$N用一種異樣的眼神掃視著在場的每一個人。\n", me);

	if(	(int)me->query("force") > (random(bellicosity) + bellicosity)/2 ) return;

	if( bellicosity > (int)me->query("score") 
	&&	!wizardp(obj) ) {
		message_vision("$N對著$n喝道﹕" + RANK_D->query_self_rude(me)
			+ "看你實在很不順眼﹐去死吧。\n", me, obj);
		me->kill_ob(obj);
	} else {
		message_vision("$N對著$n喝道﹕喂﹗" + RANK_D->query_rude(obj)
			+ "﹐" + RANK_D->query_self_rude(me) + "正想找人打架﹐陪我玩兩手吧﹗\n",
			me, obj);
		me->fight_ob(obj);
	}
}

void start_hatred(object me, object obj)
{
	if( !me || !obj ) return;			// Are we still exist( not becoming a corpse )?

	me->set_temp("looking_for_trouble", 0);

	if(	me->is_fighting(obj)			// Are we busy fighting?
	||	!living(me)				// Are we capable for a fight?
	||	environment(me)!=environment(obj)	// Are we still in the same room?
	||	environment(me)->query("no_fight") 	// Are we in a peace room?
	)	return;

	// We found our hatred! Charge!
	message_vision( catch_hunt_msg[random(sizeof(catch_hunt_msg))], me, obj);
	me->kill_ob(obj);
}

void start_vendetta(object me, object obj)
{
	if( !me || !obj ) return;			// Are we still exist( not becoming a corpse )?

	me->set_temp("looking_for_trouble", 0);

	if(	me->is_fighting(obj)			// Are we busy fighting?
	||	!living(me)				// Are we capable for a fight?
	||	environment(me)!=environment(obj)	// Are we still in the same room?
	||	environment(me)->query("no_fight") 	// Are we in a peace room?
	)	return;

	// We found our vendetta opponent! Charge!
	me->kill_ob(obj);
}

void start_aggressive(object me, object obj)
{
	if( !me || !obj ) return;			// Are we still exist( not becoming a corpse )?

	me->set_temp("looking_for_trouble", 0);

	if(	me->is_fighting(obj)			// Are we busy fighting?
	||	!living(me)				// Are we capable for a fight?
	||	environment(me)!=environment(obj)	// Are we still in the same room?
	||	environment(me)->query("no_fight") 	// Are we in a peace room?
	)	return;

	// We got a nice victim! Kill him/her/it!!!
	me->kill_ob(obj);
}

// This function is to announce the special events of the combat.
// This should be moved to another daemon in the future.
void announce(object ob, string event)
{
	switch(event)
	{
		case "dead":
			message_vision("\n  $N攤倒在地上, 抽慉了幾下...。\n\n  $N死了。\n\n", ob);
			break;
		case "unconcious":
			message_vision("\n  $N腳下一個不穩, 昏倒在地上, 氣息越來越微弱了。\n\n", ob);
			ob->set_temp("unconcious",1);
			break;
		case "revive":
			message_vision("\n$  N慢慢睜開眼睛﹐清醒了過來。\n\n", ob);
			ob->delete_temp("unconcious");
			break;
	}
}

void winner_reward(object killer, object victim)
{
	killer->defeated_enemy(victim);
}

void killer_reward(object killer, object victim)
{
	int bls,vlevel;
	string vmark;

	// Call the mudlib killer apply.
	killer->killed_enemy(victim);
//下面檢查被殺者是否為玩家
	if( userp(victim) && !wizardp(victim))
	{
		if(userp(killer) && !victim->query_temp("killer"))
		{
		 killer->add_temp("killer",1);
		 call_out("delete_killer", 1800, killer );
		}
		killer->add("PKS", 1);
		victim->clear_condition();
		// Give the death penalty to the dying user.
		victim->set("bellicosity", 0);
		victim->add("combat_exp", -(int)victim->query("combat_exp") / 10);
		victim->add("exp", -(int)victim->query("exp") / 10);
		victim->delete("vendetta");
		if( victim->query("thief") )
			victim->set("thief", (int)victim->query("thief") / 2);
		if( victim->query_temp("killer") )
			victim->add_temp("killer", -1);
		if( (int)victim->query("potential") > (int)victim->query("learned_points"))
			victim->add("potential",
				((int)victim->query("learned_points") - (int)victim->query("potential"))/2 );
		victim->skill_death_penalty();
		victim->save();
		bls = 1;
		
		if( userp(killer) )		//PK訊息
		{
		 CHANNEL_D->do_channel(this_object(), "rumor",
			sprintf(RED"可憐的%s不幸喪命於殺人狂 -%s- 的手上。", victim->name(1), killer->name(1)));
		}
		 else CHANNEL_D->do_channel(this_object(), "rumor",
			sprintf(RED"%s"RED"被%s"RED"殺死了。", victim->name(1), killer->name(1)));
	} 
	 else
	  {
		killer->add("MKS", 1);
		bls = 1;
	  }

	// NPC got 10 times of bellicosity than user.
//	killer->add("bellicosity", bls * (userp(killer)? 1: 10));	//增加殺氣

	if( stringp(vmark = victim->query("vendetta_mark")) )
	killer->add("vendetta/" + vmark, 1);
	if(userp(killer))
	{
		if( killer->query("evil") <999 && killer->query("evil") > -999 ) //陣營變換
		{
		  if( victim->query("evil") > 0 || victim->query("evil") < 0 )	
	  	  {
		 	killer->add("evil",-victim->query("evil")/3);
	  	  }
		}
		if(!userp(victim) || !wizardp(victim))
		{
		  vlevel+=killer->query("level")-victim->query("level");
		  if(vlevel>0) vlevel = vlevel + 13;
		  else vlevel = vlevel/2 + 13;
		  if(vlevel<8) vlevel = 8;
		  killer->add("exp", (int)victim->query("exp") / vlevel);
        	  tell_object(killer,"  你得到 "+(int)victim->query("exp")/vlevel+" 點經驗值!\n" );
		}
		if(!userp(victim) && victim->query("war_score"))
		{
		 killer->add("war_score",victim->query("war_score"));
		 tell_object(killer,HIW"  你得到一些戰功\!\n"NOR);
		}
		killer->save();   	
	}	
}

void delete_killer(object killer)
{
 remove_call_out("delete_killer");
 if(!killer) return ;
 if( killer->query_temp("killer") > 0 )
 {
 	killer->add_temp("killer",-1);
	call_out("delete_killer", 1800, killer );
 } else
 return ;
}
