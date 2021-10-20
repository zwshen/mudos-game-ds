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
	HIW "$N�M$n���H�ۨ����~�����M�ߨ襴�F�_�ӡT\n" NOR,
	HIW "$N�M$n�@�I���M�G�ܤ����N���F�_�ӡT\n" NOR,
});

string *winner_msg = ({
	CYN "\n$N����@���M���ۻ��D�R�����T\n\n" NOR,
	CYN "\n$N�ӤF�o�ۡM�V���D�}�T�ءM���D�R�����T\n\n" NOR,
});

void create()
{
	seteuid(getuid());
	set("name", "�԰����F");
	set("id", "combatd");
}

string damage_msg(int damage, string type)
{
	string str;

//	return "�y�� " + damage + " �I" + type + "�C\n";

	if( damage == 0 ) return NOR "���G�O�D�Ӥp�èS���y���ˮ`�C\n";

	switch( type ) {
	case "����":
	case "�ζ�":
		if( damage < 10 ) str =  "���G�u�y�����L�����ˡC";
		else if( damage < 20 ) str = "���G�ΥX�@�D�Ӫ����岪�C";
		else if( damage < 40 ) str = "���X�F�@�D�ˤf�T";
		else if( damage < 60 ) str = "�ΥX�F�@�D��O�O���ˤf�T";
		else if( damage < 120 ) str = "�d�U�F�@�D�S���S�`���ˤf�T";
		else str = "�y���@�D�`�Ψ������i�ȶˤf�T�T";
		break;
	case "���":
		if( damage < 10 ) str =  "���G�u�y�����L�����ˡC";
		else if( damage < 20 ) str = "���G��X�@�Ӷˤf�C";
		else if( damage < 40 ) str = "���G��X�@�Ӥj�ˤf�T";
		else if( damage < 60 ) str = "���G��X�@�ӫܲ`���ˤf�T";
		else if( damage < 120 ) str = "���G��X�@�Ӧ���U�k����]�K�T";
		else str = "�uť���@�n�G�z�M�A���q�F���a�T�T";
		break;
	case "���":
		if( damage < 10 ) str =  "���G�u�y�����L�����ˡC";
		else if( damage < 20 ) str = "���G�y���@�Ƿ�ˡC";
		else if( damage < 40 ) str = "���G�y�����p���ˮ`�T";
		else if( damage < 60 ) str = "$n�h�o�t�I���F�X�ӡT";
		else if( damage < 120 ) str = "���G$n�u�z�v�a�@�n�R�X�@�j�f�A��T";
		else str = "�u�y�v�a�@�n���T�M$n�f�R�A�學�F�X�h�T�T";
		break;
	default:
		if( !type ) type = "�ˮ`";
		if( damage < 5 ) str =  "���G�u�O�j�j�y�����L��";
		else if( damage < 10 ) str = "�y���@�I";
		else if( damage < 20 ) str = "�y���@�B";
		else if( damage < 40 ) str = "�y���᭫��";
		else if( damage < 60 ) str = "�y���Y����";
		else if( damage < 90 ) str = "�y���۷��Y����";
		else if( damage < 120 ) str = "�y���D�`�Y����";
		else if( damage < 150 ) str = "�y�����i���Ϫ�";
		else if( damage < 180 ) str = "�y���L�P�ۤ��Y��";
		else str =  "�y���|�@�L����";
		str += type + "�T";
	}
	
//	str += sprintf("(%s%d)"NOR,HIR,damage);
	return str;
}

string eff_status_msg(int ratio)
{
	if( ratio==100 ) return HIG "�믫�ܦn�M���W�@�I�ˤ]�S���C" NOR;
	if( ratio > 90 ) return HIG "���G���F�I���ˡC" NOR;
	if( ratio > 80 ) return HIY "���W���@�Ǥp�ˤf�C" NOR;
	if( ratio > 70 ) return HIY "���W���X�B�ˤf�M���L���G�ä�ê�ơC" NOR;
	if( ratio > 60 ) return HIY "���W���X�B�j�ˤf�M�ݰ_�Ӫ��p���Ӧn�C" NOR;
	if( ratio > 50 ) return HIM "�𮧲ʭ��M�ʧ@���áM�ݨӨ��Ф����C" NOR;
	if( ratio > 40 ) return HIM "�w�g�˲��ֲ֡M���b�j�O�伵�ۤ��ˤU�h�C" NOR;
	if( ratio > 30 ) return HIR "���F�۷����ˡM�u�ȷ|���ͩR�M�I�C" NOR;
	if( ratio > 20 ) return HIR "�w�g���˹L���M���G�֤���F�C" NOR;
	if( ratio > 10  ) return RED "�V���O��M�w�g�a�a�@���F�C" NOR;
	return RED "�w�g�˦b��y�����M�H�ɳ��i���_��C" NOR;
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

	if( ob->query("mp") < ob->query("max_mp")/10 )	//mp�ѤU1/10�|��z
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

  factor = skill_power(ob, attack_skill, SKILL_USAGE_ATTACK);	//�ޯ�R���ץ�(0-50)
  factor += ob->query_temp("apply/hit");			//�Z���R���ץ�(-50 ~ 50)
  factor += ob->query_temp("spell/hit");			//�k�N�R���ץ�(-50 ~ 50)
  factor += ob->query_dex()*2;					//dex �R���ץ�(0-200)
  if(ob->query_temp("detect"))
   factor += ob->query_temp("detect")*10;			//�����ץ�
  if(ob->query("wound/hand") )
   factor= factor - (factor * ob->query("wound/hand") )/110;	//wound�ץ�
  return factor;
}

varargs int dodge_factor(object ob,string dodge_skill)
{
  int factor;
  factor = 0;
  if( !living(ob) ) return 0;

  factor -= skill_power(ob, dodge_skill, SKILL_USAGE_DEFENSE);	//�ޯ�{���ץ�(0-50)
  factor -= ob->query_dex()*2;					//dex �{���ץ�(0-200)
  if(ob->query_temp("invis"))
   factor -= ob->query_temp("invis")*10;			//�����ץ�
  if(ob->query_temp("fly")) factor -= 25;			//����ץ�
  else if(ob->query_temp("float")) factor -= 10;		//�}�B�ץ�
  if( ob->query("wound/foot") )
   factor= factor - (factor * ob->query("wound/foot") )/110;	//wound�ץ�
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

	//��O��
	if(me->query("env/superman"))
	{
	 //tell_object(me,"COMBATD�I�s combine_attack()��!\n");
	 if(me->combine_attack(victim)) return 1;
	}
	else
	if(random(6)==1) 
	{
		//tell_object(me,"COMBATD�I�s combine_attack()��!\n");
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
  result = "" + action["action"] + "�T";
  if(weapon)
  if(arrayp(weapon_msg=weapon->query("combat_msg"))) result=""+weapon_msg[random(sizeof(weapon_msg))]+ "�T";
	//
	// (2) ��l���v�å[�H�ץ��H�P�_�O�_��R��
	//
  heavy=0;
  miss=0;	
  hitrole=random(HITROLE);			// random�Ʀr�V�C �ݩʧޯ�v�T�V�j

  if(attack_type == TYPE_HEAVY) heavy=1;
  else if(hitrole > HITHEAVY ) heavy=1; 		//heavy �R���n�`
	else if(hitrole < HITMISS ) miss=1;		//miss  �Y������

  if( wizardp(me) && me->query("env/debug") )	//debug message 1
  message_vision("  ��l�R�����v:"+hitrole+"\n",me);

  if( objectp(weapon) )	attack_skill = weapon->query("skill_type");
	else		attack_skill = "unarmed";

  limbs = victim->query("limbs");
  limb = limbs[random(sizeof(limbs))];

  hitrole += attack_factor(me,attack_skill);

  hitrole += dodge_factor(victim,"dodge");

  if(attack_type==TYPE_BERSERK) hitrole-=hitrole/10; 	//Berserk �h���������C�R���v
  else if(attack_type==TYPE_QUICK) hitrole+=hitrole/10; //Quick �ֳt�����W�[�R���v

  if( wizardp(me) && me->query("env/debug") )		//debug message 2
  message_vision("  �R���ץ�:"+attack_factor(me,attack_skill)
  +"  �{���ץ�:"+dodge_factor(victim,"dodge")+"\n"
  +"  ����TYPE�ץ����G:"+hitrole+"\n"
  ,me);
 
  if( victim->is_busy() ) hitrole+=hitrole/5;

	//
	// (3) Fight!
	//     �p�Ghitrole > 100 �Y���R��, <100 �h�S���R��
	//     ��heavy==1 �ɥ��w�R��, ��miss==1�� ���w����B�|�]�����~�ӳy��busy
	//
	
  if( ( !heavy && ( hitrole < THACO ) && !victim->query_temp("unconcious") ) || miss )  // victim�{�����\
  {
	dodge_skill = victim->query_skill_mapped("dodge");
	if( !dodge_skill ) dodge_skill = "dodge";
	result += SKILL_D(dodge_skill)->query_dodge_msg(limb);
	
	//�W�[�g��ȻP�ޯ�
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

  } else	//victim�{������
    {
		//
		//	(4) �ˬdvictim�O�_��۬[����
		//

	if( victim->query_temp("armor/shield") )	//��⦳�޵P
	{
		parry_skill = "block";
	}
	else
	{
	  if( victim->query_temp("weapon") )	//��⦳�Z��
	  {
		parry_skill = "parry";
	  }
	   else	//���S���Z��
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

	//victim�۬[���\

	if( ( !heavy && ( hitrole < THACO ) && !victim->query_temp("unconcious") ) || miss )
	{
			// change to SKILL_D(parry_skill) after added parry msg to those
			// martial arts that can parry.

		if(parry_skill=="block")
		result += SKILL_D("block")->query_block_msg(victim->query_temp("armor/shield"));	
		else
		result += SKILL_D("parry")->query_parry_msg(victim->query_temp("weapon"));	//�۬[�T��

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
			//	(5) �R���ĤHvictim�Bvictim�۬[����, �}�l�p��ˮ`��
			//

		damage = me->query_damage();
		damage = damage/2 + random(damage/2);
		
		if( action["damage"] )
		{
			if(action["damage"]>100) action["damage"]=100;
			if(action["damage"]<-99) action["damage"]=-99;
			damage += action["damage"] * damage / 100;	//skill�ĪG�ץ�[]%
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
			//	(6) �����ĤH�ˮ`
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
	//	(7) �W�[�԰����m�ȻP�ޯ�
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
  //	(8) ��ܾ԰��T��
  //
  
  if(heavy) result = HIM+"(�ĤO�@��)"+NOR+result;
  else if(miss) result = HIM+"(���ߤ�í)"+NOR+result;
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

  result_me = replace_string( result_me, "$N", "�A" );
  result_me = replace_string( result_me, "$n", victim->query("name") );
  result_me = replace_string( result_me, "$p", victim->query("name") );
  result_victim=result+HIR+result_damage+NOR;
  result_victim = replace_string( result_victim, "$N", me->query("name") );
  result_victim = replace_string( result_victim, "$n", "�A" );
  result_victim = replace_string( result_victim, "$p", "�A" );
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
		tell_object(me, sprintf( HIG "  �ڤ�R��!!(HITROLE�R%d) �M�Ĥ���ˡR%d\n" NOR,
			hitrole, damage));
  }
  if( wizardp(victim) && victim->query("env/debug") )
  {
		tell_object(victim, sprintf( HIY "  �Ĥ�R��!!(HITROLE�R%d)�M�ڤ���ˡR%d\n" NOR,
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
	if(me->query("env/report")) report_status(victim, damage);	//set report 1 �i�H�ݨ�report
	if( victim->is_busy() ) victim->interrupt_me(me);
	if( (!me->is_killing(your["id"])) && (!victim->is_killing(my["id"])) )	//only fight
	{
	  if( victim->query("hp") < victim->query("max_hp")/2 )	//����ѤU 1/2 HP �Y����
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
		message_vision("$N�@�������M�S�X�F�}��T\n", me);
		do_attack(victim, me, victim->query_temp("weapon"), TYPE_QUICK);
	}
	 else
	  {
		message_vision("$N��$n�������~�M�X���o�ʧ����T\n", victim, me);
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
	message_vision("$N�Τ@�ز��˪����������ۦb�����C�@�ӤH�C\n", me);

	if(	(int)me->query("force") > (random(bellicosity) + bellicosity)/2 ) return;

	if( bellicosity > (int)me->query("score") 
	&&	!wizardp(obj) ) {
		message_vision("$N���$n�ܹD�R" + RANK_D->query_self_rude(me)
			+ "�ݧA��b�ܤ������M�h���a�C\n", me, obj);
		me->kill_ob(obj);
	} else {
		message_vision("$N���$n�ܹD�R�ޡT" + RANK_D->query_rude(obj)
			+ "�M" + RANK_D->query_self_rude(me) + "���Q��H���[�M���ڪ����a�T\n",
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
			message_vision("\n  $N�u�˦b�a�W, ���f�F�X�U...�C\n\n  $N���F�C\n\n", ob);
			break;
		case "unconcious":
			message_vision("\n  $N�}�U�@�Ӥ�í, ���˦b�a�W, �𮧶V�ӶV�L�z�F�C\n\n", ob);
			ob->set_temp("unconcious",1);
			break;
		case "revive":
			message_vision("\n$  N�C�C�C�}�����M�M���F�L�ӡC\n\n", ob);
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
//�U���ˬd�Q���̬O�_�����a
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
		
		if( userp(killer) )		//PK�T��
		{
		 CHANNEL_D->do_channel(this_object(), "rumor",
			sprintf(RED"�i����%s������R����H�g -%s- ����W�C", victim->name(1), killer->name(1)));
		}
		 else CHANNEL_D->do_channel(this_object(), "rumor",
			sprintf(RED"%s"RED"�Q%s"RED"�����F�C", victim->name(1), killer->name(1)));
	} 
	 else
	  {
		killer->add("MKS", 1);
		bls = 1;
	  }

	// NPC got 10 times of bellicosity than user.
//	killer->add("bellicosity", bls * (userp(killer)? 1: 10));	//�W�[����

	if( stringp(vmark = victim->query("vendetta_mark")) )
	killer->add("vendetta/" + vmark, 1);
	if(userp(killer))
	{
		if( killer->query("evil") <999 && killer->query("evil") > -999 ) //�}���ܴ�
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
        	  tell_object(killer,"  �A�o�� "+(int)victim->query("exp")/vlevel+" �I�g���!\n" );
		}
		if(!userp(victim) && victim->query("war_score"))
		{
		 killer->add("war_score",victim->query("war_score"));
		 tell_object(killer,HIW"  �A�o��@�Ǿԥ\\!\n"NOR);
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
