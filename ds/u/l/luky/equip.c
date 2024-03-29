//	equip.c
// #pragma save_binary
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
			this_object()->query("name") + "["+base_name(this_object())+"] 沒有環境無法裝備. at:" + ctime(time()) + "\n" );
		return 0;
	}
	if( !owner->is_character() ) return 0;
	
	// If already worn, just recognize it.
	if( query("equipped") ) return 1;

	// Find owner's Race
	switch(owner->query("race"))
	{
		case "人類" :
		case "human" : 
				race_armor_prop="armor_prop";
				race_armor_type="armor_type";
				break;
		case "野獸" :
		case "beast" :
				race_armor_prop="beast_armor_prop";
				race_armor_type="beast_armor_type";
				break;
		case "妖魔" :
		case "monster" :
				race_armor_prop="monster_armor_prop";
				race_armor_type="monster_armor_type";
				break;
		case "異型" :
		case "zerg" :
				race_armor_prop="zerg_armor_prop";
				race_armor_type="zerg_armor_type";
				break;
		case "神族" :
		case "protoss":
				race_armor_prop="protoss_armor_prop";
				race_armor_type="protoss_armor_type";
				break;
		case "機械人":
		case "機器人":
		case "robot" :
				race_armor_prop="robot_armor_prop";
				race_armor_type="robot_armor_type";
				break;
		case "美達人":
		case "meda":
				race_armor_prop="meda_armor_prop";
				race_armor_type="meda_armor_type";
				break;
		default :
		return notify_fail("這"+this_object()->query("unit")+this_object()->name()+"並不適合"+owner->query("race")+"使用。\n");
	}

	// Check if we have "armor_prop" defined.
	if( !mapp(armor_prop = query(race_armor_prop)) )
		return notify_fail("這"+this_object()->query("unit")+this_object()->name()+"並不知道該如何使用。\n");
		
	//損壞??
	if( this_object()->is_broken() ) 
		return notify_fail("這"+this_object()->query("unit")+this_object()->name()+"已經損壞了。\n");
	if( this_object()->query_temp("no_energy") ) 
		return notify_fail("這"+this_object()->query("unit")+this_object()->name()+"已經沒有能量了。\n");	
	// Check if twohand all used
	if(weapon=owner->query_temp("weapon"))
	{
	 	flag = weapon->query("flag");
		if( flag & TWO_HANDED )
		{
			if( query(race_armor_type)=="shield" )
			return notify_fail("你必須先空出一隻手才能裝備"+this_object()->name()+"。\n");
		}
		if(owner->query_temp("secondary_weapon"))
		{
			if( query(race_armor_type)=="shield" )
			return notify_fail("你必須先空出一隻手才能裝備"+this_object()->name()+"。\n");
		}
	}
	
	type = query(race_armor_type);
	if( armor=owner->query_temp("armor/" + type) )
		return notify_fail("你必須先卸下"+armor->name()+"，才能裝備"+this_object()->name()+"。\n");

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
			this_object()->query("name") + "["+base_name(this_object())+"] 沒有環境無法裝備. at:" + ctime(time()) + "\n" );	
		return 0;
	}
	if( !owner->is_character() ) return 0;
	
	// Find owner's Race
	switch(owner->query("race"))
	{
		case "人類" :
		case "human" : 
				race_weapon_prop="weapon_prop";
				break;
		case "野獸" :
		case "beast" :
				race_weapon_prop="beast_weapon_prop";
				break;
		case "妖魔" :
		case "monster" :
				race_weapon_prop="monster_weapon_prop";
				break;
		case "異型" :
		case "zerg" :
				race_weapon_prop="zerg_weapon_prop";
				break;
		case "神族" :
		case "protoss":
				race_weapon_prop="protoss_weapon_prop";
				break;
		case "機械人":
		case "機器人":
		case "robot" :
				race_weapon_prop="robot_weapon_prop";
				break;
		case "美達人":
		case "meda":
				race_weapon_prop="meda_weapon_prop";
				break;
		default :
		return notify_fail("這"+this_object()->query("unit")+this_object()->name()+"並不適合"+owner->query("race")+"使用。\n");
	}
	
	// If already wielded, just recognize it.
	if( query("equipped") ) return 1;

	// Check if we have "weapon_prop" defined.
	if( !mapp(weapon_prop = query(race_weapon_prop)) )
		return notify_fail("你不知道這"+this_object()->query("unit")+this_object()->name()+"要如何當作武器使用。\n");

	//損壞??
	if( this_object()->is_broken() ) 
		return notify_fail("這"+this_object()->query("unit")+this_object()->name()+"已經損壞了。\n");
	if( this_object()->query_temp("no_energy") ) 
		return notify_fail("這"+this_object()->query("unit")+this_object()->name()+"已經沒有能量了。\n");	
	flag = query("flag");

	if( flag & TWO_HANDED ) {
		if( owner->query_temp("weapon")
		||	owner->query_temp("secondary_weapon")
		||	owner->query_temp("armor/shield") )
			return notify_fail("想裝備"+this_object()->name()+"必須要先空出雙手。\n");
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
				tell_object(owner,"["+this_object()->query("name")+"已設定為副武器]\n");
			// If we can switch our old weapon to secondary weapon ?
			} else if( (int)old_weapon->query("flag") & SECONDARY ) {
				old_weapon->unequip();
				owner->set_temp("weapon", this_object());
				old_weapon->wield();

			// We need unwield our old weapon before we can use this one.
			} else
				return notify_fail("你必須先放下"+old_weapon->name()+"才能裝備"+this_object()->name()+"。\n");

		// We have both hands wearing something.
		} else
			return notify_fail("你必須空出一隻手才能使用"+this_object()->name()+"。\n");
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
		return notify_fail("你目前並沒有裝備"+this_object()->name()+"。\n");
	
	// Find owner's Race
	switch(owner->query("race"))
	{
		case "人類" :
		case "human" : 
				race_armor_prop="armor_prop";
				race_armor_type="armor_type";
				race_weapon_prop="weapon_prop";
				break;
		case "野獸" :
		case "beast" :
				race_armor_prop="beast_armor_prop";
				race_armor_type="beast_armor_type";
				race_weapon_prop="beast_weapon_prop";
				break;
		case "異型" :
		case "zerg" :
				race_armor_prop="zerg_armor_prop";
				race_armor_type="zerg_armor_type";
				race_weapon_prop="zerg_weapon_prop";
				break;
		case "神族" :
		case "protoss":
				race_armor_prop="protoss_armor_prop";
				race_armor_type="protoss_armor_type";
				race_weapon_prop="protoss_weapon_prop";
				break;
		default :
		return notify_fail("這"+this_object()->query("unit")+this_object()->name()+"並不適合"+owner->query("race")+"使用。\n");
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


