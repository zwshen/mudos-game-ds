// attack.c
// #pragma save_binary
#include <ansi.h>
#include <dbase.h>
#include <origin.h>
#include <skill.h>

#define MAX_OPPONENT	4

nosave object *enemy = ({});
nosave string *killer = ({});
nosave object *members = ({});

// prototypes
object *query_members() { return members; }
object *query_enemy() { return enemy; }
string *query_killer() { return killer; }
void clean_up_member();

varargs int can_fight(object ob)
{
	object env1,env2,owner;
	if(!ob) return 0;
	if(this_object()->is_busy() || sizeof(this_object()->query_temp("is_busy")) ) return notify_fail("�A�{�b���b���C\n");
	
	if(!this_object()->visible(ob)) return notify_fail("�o�̨S���o�ӤH�C\n");
	if(ob->query_temp("killer")) return 1;

	env1=environment(this_object());
	env2=environment(ob);
	if(env1!=env2) return notify_fail("�o�̨S���o�ӤH�C\n");
	if(env1->query("no_fight") || env1->query("no_kill"))
	{
		return notify_fail("�o�̤���@�ԡT\n");
	}
	
	if(member_array(ob, enemy)!=-1) return 1;
	
	if(ob->is_ghost()) return notify_fail("	���èS������C\n");
        if(this_object()->is_ghost()) return notify_fail("�A�{�b�٬O����a�C\n");
	if(ob==this_object()) return notify_fail("�� suicide ���O�|�����:P�C\n");
	if(!ob->is_character()) return notify_fail("��褣�O�ͪ��a�C\n");
	if(ob->query("no_kill") || ob->query("no_fight")) return notify_fail("�A���i�H�������ͪ��T\n");
		
	if( userp(ob) && (userp(this_object()) || owner = this_object()->query("creater")) )	//�������@�w�n�]�w
	{
	  if(!owner) owner=this_object();
	  
	  if(owner->query("level") < 5 )
	  {
	  	if(owner!=this_object()) tell_object(owner,"�A�ثe�����Ť��i�H�������a�T\n");
	  	return notify_fail("�A�ثe�����Ť��i�H�������a�T\n");
	  }
	  
	  if(ob->query("level") < 5 
	  || ob->query("level")>owner->query("level")+5
	  || ob->query("level")<owner->query("level")-5)	//add by luky
	  {
	  	if(owner!=this_object()) tell_object(owner,"�A���i�H���������Ū����a�T\n");
	  	return notify_fail("�A���i�H���������Ū����a�T\n");
	  }
	  
	  if(ob->query_temp("netdead") && (!ob->query_temp("killer")))
	  {
	  	if(owner!=this_object()) tell_object(owner,"��������w�g�_�u�����a�T\n");
	  	return notify_fail("��������w�g�_�u�����a! \n");
	  }
	  
	  if( wizardp(ob) && !wizardp(owner) ) return notify_fail("�ثe�T��a�M�Ův�i��԰�! \n");
	  if( !wizardp(ob) && wizardp(owner) ) return notify_fail("�Ův�Ф��n�����@�몱�a! \n");
	}

	return 1;
}

int add_members(object ob)
{
	if( member_array(ob, members) !=-1 ) return 0;

	members += ({ ob });
	return 1;

}

varargs int is_member(object ob)
{
 	if( !ob ) return sizeof(members) > 0;

	return member_array(ob, members)!=-1;
}

int remove_members(object ob)
{
	if( member_array(ob, members) ==-1 ) return 0;

	members -= ({ ob });
	return 1;
}
//this function called by COMBAT_D
int combine_attack(object target,object* group,string type)
{
	int i;
	object *eff_member = ({});

	if(sizeof(group)<2) return 0;
	
	//��X�����s���P����H��
	for(i=0;i<sizeof(group);i++)
	{
	 if(this_object() == group[i]->query_team_leader()) eff_member +=({group[i]});
	}
	
	if(sizeof(eff_member)<2) return 0;
 
	return COMBINE_D->exert_combine(this_object(),target,eff_member,type);
}


// This function returns 1 if we are fighting anyone (or with ob)
varargs int is_fighting(object ob)
{
	if( !ob ) return sizeof(enemy) > 0;

	return member_array(ob, enemy)!=-1;
}

// This function returns 1 if we are fighting anyone (or with ob)
varargs int is_killing(string id)
{
	if( !id ) return sizeof(killer) > 0;

	return member_array(id, killer)!=-1;
}

//This function starts fight between this_object() and ob
void fight_ob(object ob)
{
	if(!ob || ob==this_object()) return;

	set_heart_beat(1);

	if( member_array(ob, enemy)==-1 ) 
		enemy += ({ ob });
}

// This function starts killing between this_object() and ob
void kill_ob(object ob)
{
	if(!ob || ob==this_object()) return;
	if( member_array(ob->query("id"), killer)==-1 )
	{
		killer += ({ ob->query("id") });
		if(userp(this_object()) && userp(ob))
		log_file( "pk", "[" + geteuid(this_object()) + "] attack " + ob->short(1) +" on " + ctime(time()) + "\n" );
		tell_object(ob, HIR + this_object()->name() + "��M�}�l�����A�T\n" NOR);
	}
	
	//fight_ob(ob);
	if( member_array(ob, enemy)==-1 ) enemy += ({ ob });
	set_heart_beat(1);
}

void clean_up_member()
{
	int i;
	if( sizeof(members) > 0 ) {
		for(i=0; i<sizeof(members); i++) {
			if( !objectp(members[i])
			||	(!living(members[i]) ) )
				members[i] = 0;
		}
		members -= ({ 0 });
	}

}

void clean_up_enemy()
{
	int i;
	if( sizeof(enemy) > 0 ) {
		for(i=0; i<sizeof(enemy); i++) {
			if( !objectp(enemy[i])
			||	environment(enemy[i])!=environment()
			||	(!living(enemy[i]) && !is_killing(enemy[i]->query("id"))) )
				enemy[i] = 0;
		}
		enemy -= ({ 0 });
	}
}

// This function checks if the current opponent is available or
// select a new one.
object select_opponent()
{
	object victim,defender;
	int which;

	if( !sizeof(enemy) ) return 0;

	which = random(MAX_OPPONENT);

	if(which < sizeof(enemy)) victim= enemy[which] ;
	else victim = enemy[0];
	if(defender=victim->query_temp("defender"))
	{
	 if(environment(defender)==environment()
	    && defender->can_fight(this_object()) ) return defender;
	}
	return victim;
}

// Stop fighting ob.
int remove_enemy(object ob)
{
	if( is_killing(ob->query("id")) ) return 0;

	enemy -= ({ ob });
	return 1;
}

// Stop killing ob.
int remove_killer(object ob)
{
	if( is_killing(ob->query("id")) ) {
		killer -= ({ ob->query("id") });
		remove_enemy(ob);
		return 1;
	}

	return remove_enemy(ob);
}

// Stop all fighting, but killer remains.
void remove_all_enemy()
{
	for(int i=0; i<sizeof(enemy); i++) {
		// We ask our enemy to stop fight, but not nessessary to confirm
		// if the fight is succeffully stopped, bcz the fight will start
		// again if our enemy keeping call COMBAT_D->fight() on us.
		if( objectp(enemy[i]) ) enemy[i]->remove_enemy(this_object());
		enemy[i] = 0;;
	}

	enemy = ({});
}

// Stop all fighting and killing.
void remove_all_killer()
{
	killer = ({});
	enemy -= ({ 0 });

	for(int i=0; i<sizeof(enemy); i++)
		if( enemy[i]->remove_killer(this_object()) )
			enemy[i] = 0;;

	enemy -= ({ 0 });
}

// ��譱����l��
void stop_attack()
{
	killer = ({});
	enemy = ({});
}

// reset_action()
//
// This function serves as a interface of F_ATTACK and wielded, worn objects.
// When the living's fighting action need update, call this function.
//
void reset_action()
{
	object ob;
	string type, skill;

	if( ob = query_temp("weapon") )
		type = ob->query("skill_type");
	else 
		type = "unarmed";
	//���ݬݦ��S������skill��map_skill
	if( stringp(skill = query_skill_mapped(type)) )
	{
		// If using a mapped skill, call the skill daemon.
		set("actions", (: call_other, SKILL_D(skill), "query_action" :) );
	}
	else if(mapp(SKILL_D(type)->query_action())) //�b�ݬݰ�skill���S��action
	{
		set("actions", (: call_other, SKILL_D(type), "query_action" :) );
	}
	else //�̫�浹�Z���B�zaction
	{
		// Else, let weapon handle it.
		if( ob ) set("actions", ob->query("actions",1) );
		else set("actions", query("default_actions",1) );
	}
}

// This is called in heart_beat() to perform attack action.
int attack()
{
	object opponent;

	clean_up_enemy();
	//clean_up_member();
	opponent = select_opponent();
	if( objectp(opponent) ) {
		set_temp("last_opponent", opponent);
		COMBAT_D->fight(this_object(), opponent);
		return 1;
	} else
		return 0;
}

//
// init() - called by MudOS when another object is moved to us.
//
void init()
{
	object ob;
	string vendetta_mark;

	// We check these conditions here prior to handle auto fights. Although
	// most of these conditions are checked again in COMBAT_D's auto_fight()
	// function, these check reduces lots of possible failure in the call_out
	// launched by auto_fight() and saves some overhead.
	if(	is_fighting()
	||	!living(this_object())
	||	!(ob = this_player()) 
	||	environment(ob)!=environment()
	||	!living(ob)
	||	ob->query_temp("linkdead") 	//�_�u
	||	!this_object()->visible(ob)
	||	this_object()->query_temp("sleeping") //�εۤF
	)
		return;
	if( !userp(this_object()) && userp(ob)) this_object()->set_heart_beat(1);
	
	// Now start check the auto fight cases.
	if( userp(ob) && is_killing(ob->query("id")) )
	{
		COMBAT_D->auto_fight(this_object(), ob, "hatred");
		return;
	} else if( stringp(vendetta_mark = query("vendetta_mark"))
	&& ob->query("vendetta/" + vendetta_mark) )
	{
		COMBAT_D->auto_fight(this_object(), ob, "vendetta");
		return;
	} else if( userp(ob) && (string)query("attitude")=="aggressive" )
	{
		COMBAT_D->auto_fight(this_object(), ob, "aggressive");
		return;
	} else if( userp(ob) && (string)query("attitude")=="killer" )
	{
		COMBAT_D->auto_fight(this_object(), ob, "killer");
		return;
	}
	/*
	 else if( random((int)query("bellicosity") / 40) > (int)query("cps") ) {
		COMBAT_D->auto_fight(this_object(), ob, "berserk");
		return;
	} 
	*/
}

//
// �ˬd�O�_���b�� ob �԰�
// by Shengsan
//
int is_fighting_ob(object ob)
{
	int i;
	int yes = 0;
	for(i=0; i<sizeof(enemy); i++)
	{
		if( objectp(enemy[i]) && enemy[i] == ob )
		{
			if( wizardp(this_object()) && this_object()->query("env/debug") )
			{
				tell_object(this_object(),enemy[i]->query("name")+"���b��A�԰�, �L���s���O "+i+"\n");
			}
			yes = 1;
			i = sizeof(enemy);
		}
	}
	if(yes!=1 && wizardp(this_object()) && this_object()->query("env/debug") )
		tell_object(this_object(),query("name")+"�èS���b��"+ob->query("name")+"�԰�...\n");
	return yes;
}

//
// ob �ѱϹ��( �o�Ӫ��� this_object() )
// by Shengsan
//
int relieve(object ob)
{
	object attacker;
	int i;

	if(!sizeof(enemy))
	{
		if( wizardp(ob) && ob->query("env/debug") )
		{
			tell_object(ob,"enemy���S����ơT\n");
		}
		return 0;
	}
	if( wizardp(ob) && ob->query("env/debug") )
	{
		tell_object(ob,"enemy�Ӽ�: "+sizeof(enemy)+"\n");
		for(i=0; i<sizeof(enemy); i++)
		{
			if( objectp(enemy[i]) )
				write(i+". "+enemy[i]->query("name")+"\n");
		}
	}
	if( objectp(enemy[0]) )		// ���wenemy�����Ĥ@�ӤH
		attacker = enemy[0];
	else
	{
		if( wizardp(ob) && ob->query("env/debug") )
		{
			tell_object(ob,"enemy�����Ĥ@����ƨä��O����T\n");
		}
		return 0;
	}

	if( wizardp(ob) && ob->query("env/debug") )
	{
		tell_object(ob,"�ѱϤH: "+ob->query("name")+"\n");
		tell_object(ob,"�Q�ѱϪ�(�Q�������H): "+query("name")+"\n");
		tell_object(ob,"������: "+attacker->query("name")+"\n");
	}


	attacker->remove_killer(this_object());
	this_object()->remove_killer(attacker);
	attacker->kill_ob(ob);

	return 1;
}