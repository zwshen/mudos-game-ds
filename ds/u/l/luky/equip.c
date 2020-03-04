//	equip.c
#pragma save_binary
#include <dbase.h>
#include <weapon.h>

int wear()
{
	object owner,weapon,armor;
	mapping armor_prop, applied_prop;
	string *apply, type,race_armor_prop,race_armor_type;
	int flag;
	
	// Only character object can wear armors.
	owner = environment();
	if(!owner) 
	{
		log_file( "debug", "/feature/equip.c ERROR in wear():\n"+
			this_object()->query("name") + "["+base_name(this_object())+"] �S�����ҵL�k�˳�. at:" + ctime(time()) + "\n" );
		return 0;
	}
	if( !owner->is_character() ) return 0;
	
	// If already worn, just recognize it.
	if( query("equipped") ) return 1;

	// Find owner's Race
	switch(owner->query("race"))
	{
		case "�H��" :
		case "human" : 
				race_armor_prop="armor_prop";
				race_armor_type="armor_type";
				break;
		case "���~" :
		case "beast" :
				race_armor_prop="beast_armor_prop";
				race_armor_type="beast_armor_type";
				break;
		case "���]" :
		case "monster" :
				race_armor_prop="monster_armor_prop";
				race_armor_type="monster_armor_type";
				break;
		case "����" :
		case "zerg" :
				race_armor_prop="zerg_armor_prop";
				race_armor_type="zerg_armor_type";
				break;
		case "����" :
		case "protoss":
				race_armor_prop="protoss_armor_prop";
				race_armor_type="protoss_armor_type";
				break;
		case "����H":
		case "�����H":
		case "robot" :
				race_armor_prop="robot_armor_prop";
				race_armor_type="robot_armor_type";
				break;
		case "���F�H":
		case "meda":
				race_armor_prop="meda_armor_prop";
				race_armor_type="meda_armor_type";
				break;
		default :
		return notify_fail("�o"+this_object()->query("unit")+this_object()->name()+"�ä��A�X"+owner->query("race")+"�ϥΡC\n");
	}

	// Check if we have "armor_prop" defined.
	if( !mapp(armor_prop = query(race_armor_prop)) )
		return notify_fail("�o"+this_object()->query("unit")+this_object()->name()+"�ä����D�Ӧp��ϥΡC\n");
		
	//�l�a??
	if( this_object()->is_broken() ) 
		return notify_fail("�o"+this_object()->query("unit")+this_object()->name()+"�w�g�l�a�F�C\n");
	if( this_object()->query_temp("no_energy") ) 
		return notify_fail("�o"+this_object()->query("unit")+this_object()->name()+"�w�g�S����q�F�C\n");	
	// Check if twohand all used
	if(weapon=owner->query_temp("weapon"))
	{
	 	flag = weapon->query("flag");
		if( flag & TWO_HANDED )
		{
			if( query(race_armor_type)=="shield" )
			return notify_fail("�A�������ťX�@����~��˳�"+this_object()->name()+"�C\n");
		}
		if(owner->query_temp("secondary_weapon"))
		{
			if( query(race_armor_type)=="shield" )
			return notify_fail("�A�������ťX�@����~��˳�"+this_object()->name()+"�C\n");
		}
	}
	
	type = query(race_armor_type);
	if( armor=owner->query_temp("armor/" + type) )
		return notify_fail("�A���������U"+armor->name()+"�A�~��˳�"+this_object()->name()+"�C\n");

	owner->set_temp("armor/" + type, this_object());
	apply = keys(armor_prop);
	applied_prop = owner->query_temp("apply");
	if( !mapp(applied_prop) ) applied_prop = ([]);
	for(int i = 0; i<sizeof(apply); i++)
		if( undefinedp(applied_prop[apply[i]]) )
			applied_prop[apply[i]] = armor_prop[apply[i]];
		else
			applied_prop[apply[i]] += armor_prop[apply[i]];
	owner->set_temp("apply", applied_prop);
	set("equipped", "worn");
	owner->set("heart_modify",1);
	if(!owner->is_fighting()) owner->heart_beat();
	return 1;
}

int wield()
{
	object owner, old_weapon;
	mapping weapon_prop;
	string *apply, type,race_weapon_prop;
	int flag;

	// Only character object can wear armors.
	owner = environment();
	if(!owner) 
	{
		log_file( "debug", "/feature/equip.c ERROR in wield():\n"+
			this_object()->query("name") + "["+base_name(this_object())+"] �S�����ҵL�k�˳�. at:" + ctime(time()) + "\n" );	
		return 0;
	}
	if( !owner->is_character() ) return 0;
	
	// Find owner's Race
	switch(owner->query("race"))
	{
		case "�H��" :
		case "human" : 
				race_weapon_prop="weapon_prop";
				break;
		case "���~" :
		case "beast" :
				race_weapon_prop="beast_weapon_prop";
				break;
		case "���]" :
		case "monster" :
				race_weapon_prop="monster_weapon_prop";
				break;
		case "����" :
		case "zerg" :
				race_weapon_prop="zerg_weapon_prop";
				break;
		case "����" :
		case "protoss":
				race_weapon_prop="protoss_weapon_prop";
				break;
		case "����H":
		case "�����H":
		case "robot" :
				race_weapon_prop="robot_weapon_prop";
				break;
		case "���F�H":
		case "meda":
				race_weapon_prop="meda_weapon_prop";
				break;
		default :
		return notify_fail("�o"+this_object()->query("unit")+this_object()->name()+"�ä��A�X"+owner->query("race")+"�ϥΡC\n");
	}
	
	// If already wielded, just recognize it.
	if( query("equipped") ) return 1;

	// Check if we have "weapon_prop" defined.
	if( !mapp(weapon_prop = query(race_weapon_prop)) )
		return notify_fail("�A�����D�o"+this_object()->query("unit")+this_object()->name()+"�n�p����@�Z���ϥΡC\n");

	//�l�a??
	if( this_object()->is_broken() ) 
		return notify_fail("�o"+this_object()->query("unit")+this_object()->name()+"�w�g�l�a�F�C\n");
	if( this_object()->query_temp("no_energy") ) 
		return notify_fail("�o"+this_object()->query("unit")+this_object()->name()+"�w�g�S����q�F�C\n");	
	flag = query("flag");

	if( flag & TWO_HANDED ) {
		if( owner->query_temp("weapon")
		||	owner->query_temp("secondary_weapon")
		||	owner->query_temp("armor/shield") )
			return notify_fail("�Q�˳�"+this_object()->name()+"�����n���ťX����C\n");
		owner->set_temp("weapon", this_object());
	} else {

		// If we are are using any weapon?
		if( !(old_weapon = owner->query_temp("weapon")) )
			owner->set_temp("weapon", this_object());

		else // If we still have a free hand? 
		if( !owner->query_temp("secondary_weapon")
		&&	!owner->query_temp("armor/shield") 
		&&	!(old_weapon->query("flag") & TWO_HANDED))
		{

			// If we can wield this as secondary weapon?
			if(flag & SECONDARY) {
				owner->set_temp("secondary_weapon", this_object());
				set("co_equipped","wielded");
				tell_object(owner,"["+this_object()->query("name")+"�w�]�w���ƪZ��]\n");
			// If we can switch our old weapon to secondary weapon ?
			} else if( (int)old_weapon->query("flag") & SECONDARY ) {
				old_weapon->unequip();
				owner->set_temp("weapon", this_object());
				old_weapon->wield();

			// We need unwield our old weapon before we can use this one.
			} else
				return notify_fail("�A��������U"+old_weapon->name()+"�~��˳�"+this_object()->name()+"�C\n");

		// We have both hands wearing something.
		} else
			return notify_fail("�A�����ťX�@����~��ϥ�"+this_object()->name()+"�C\n");
	}

	apply = keys(weapon_prop);
	for(int i = 0; i<sizeof(apply); i++)
		owner->add_temp("apply/" + apply[i], weapon_prop[apply[i]]);

	owner->reset_action();
	set("equipped", "wielded");
	
	owner->set("heart_modify",1);
	if(!owner->is_fighting()) owner->heart_beat();
	
	return 1;
}

int unequip()
{
	object owner,second_wp;
	mapping prop, applied_prop;
	string *apply, equipped,race_armor_prop,race_weapon_prop,race_armor_type;

	if( !(owner = environment())->is_character() ) return 0;

	if( !stringp(equipped = query("equipped")) )
		return notify_fail("�A�ثe�èS���˳�"+this_object()->name()+"�C\n");
	
	// Find owner's Race
	switch(owner->query("race"))
	{
		case "�H��" :
		case "human" : 
				race_armor_prop="armor_prop";
				race_armor_type="armor_type";
				race_weapon_prop="weapon_prop";
				break;
		case "���~" :
		case "beast" :
				race_armor_prop="beast_armor_prop";
				race_armor_type="beast_armor_type";
				race_weapon_prop="beast_weapon_prop";
				break;
		case "����" :
		case "zerg" :
				race_armor_prop="zerg_armor_prop";
				race_armor_type="zerg_armor_type";
				race_weapon_prop="zerg_weapon_prop";
				break;
		case "����" :
		case "protoss":
				race_armor_prop="protoss_armor_prop";
				race_armor_type="protoss_armor_type";
				race_weapon_prop="protoss_weapon_prop";
				break;
		default :
		return notify_fail("�o"+this_object()->query("unit")+this_object()->name()+"�ä��A�X"+owner->query("race")+"�ϥΡC\n");
	}
	if( equipped=="wielded" )
	{
		if( (object)owner->query_temp("weapon") == this_object() )
		{
			owner->delete_temp("weapon");
                 	if( second_wp=(object)owner->query_temp("secondary_weapon"))
                 	{
                 		second_wp->unequip();
                 		second_wp->wield();
                 	}
		}
		else if( (object)owner->query_temp("secondary_weapon") == this_object() )
			{
				owner->delete_temp("secondary_weapon");
			}
		prop = query(race_weapon_prop);
		owner->reset_action();
	} else if( equipped=="worn" ) {
		owner->delete_temp("armor/" + query(race_armor_type) );
		prop = query(race_armor_prop);
	}

	apply = keys(prop);
	applied_prop = owner->query_temp("apply");
	for(int i = 0; i<sizeof(apply); i++)
		// To support array apply, we cannot add_temp() here.
		applied_prop[apply[i]] -= prop[apply[i]];

	delete("equipped");
	if(stringp(query("co_equipped"))) delete("co_equipped");
	
	owner->set("heart_modify",1);
	//if(!owner->is_fighting()) owner->heart_beat();
	
	return 1;
}

