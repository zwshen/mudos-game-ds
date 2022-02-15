// name.c
// #pragma save_binary
#include <ansi.h>
#include <dbase.h>
#include <weapon.h>

static string *my_id;

void set_name(string name, string *id)
{
	set("name", name);
	set("id", id[0]);
	my_id = id;
}

int id(string str)
{
	string *applied_id;

	//if( this_player() && !this_player()->visible(this_object()) ) return 0;

	if( pointerp(applied_id = query_temp("apply/id")) 
	&&	sizeof(applied_id) ) 
		if( member_array(str, applied_id)!=-1 )
			return 1;
		else
			return 0;
			
	// If apply/id exists, this object is "pretending" something, don't
	// recognize original id to prevent breaking the pretending with "id"
	// command.

	if( pointerp(my_id) && member_array(str, my_id)!=-1 )
		return 1;
	else
		return 0;
}

string *parse_command_id_list()
{
	string *applied_id;

	if( pointerp(applied_id = query_temp("apply/id")) 
	&&	sizeof(applied_id) )
		return applied_id;
	else
		return my_id;
}

varargs string name(int raw)
{
	string str, *mask;
	
	if( !raw && sizeof(mask = query_temp("apply/name")) )
		return mask[sizeof(mask)-1];
	else {  
		if(raw)
		{
			if(stringp(str = query("name"))) return str;
		}
		
		if(query_temp("invis"))
		{
			if(this_object()->is_character()) return "�Y�H";
			else return "�Y��";
		}
		
		if(stringp(str = query("name"))) return str;
		
		return file_name(this_object());
	}
}

varargs string short(int raw)
{
	string title, nick, str, *mask, desc,ride_type;
	object ride_ob;
	if( !stringp(str = query("short")) )
		str = name(raw) + "(" + capitalize(query("id")) + ")";

	if( !this_object()->is_character() || this_object()->is_corpse() )
	{
		if(desc=this_object()->query("status_desc")) str+=" "+desc;//��ܥثe���A�Υ���
		return str;
	}

	if( !raw && sizeof(mask = query_temp("apply/short")) )
		str = (string)mask[sizeof(mask)-1];
	else {
		if( stringp(nick = query("nickname")) )
			str = sprintf("�u%s�v%s", nick, str);

		if( stringp(title = query("title")) )
			str = sprintf("%s%s%s", title,(nick?"":" "), str);
	}

	if( !raw )
	{
		if(query_temp("float")) str +="�}�B�b�Ť�";
		else if(query_temp("fly")) str +="�b�Ť�����";
		else if(query("race")=="���~") str +="";
		else if(objectp(ride_ob=query_temp("ride"))) //�ۭq�M�����
		{
			if(ride_type=ride_ob->query("ride_type")) str +=ride_type;
			else str +="���M�b"+ride_ob->name()+"�W";
		} else if(living(this_object())) str+=" ���b�o��";
		
		if(userp(this_object()))
		{
			if( query_temp("netdead") ) str += HIG " <�_�u��>" NOR;
			if( in_input(this_object()) ) str += HIC " <��J�Ҧ�>" NOR;
			if( in_edit(this_object()) ) str += HIY " <�s���ɮ�>" NOR;
			if( interactive(this_object())
			&&	query_idle( this_object() ) > 120 ) str += HIM " <�o�b��>" NOR;
		}
		
		if( !living(this_object()) ) str += HIR + query("disable_type") + NOR;
		
		if(desc=this_object()->query("status_desc")) str+=" "+desc;//��ܥثe���A�Υ���
	}

	return str;
}

varargs string long(int raw)
{
	string str, extra, *mask;
	
	if( !raw && sizeof(mask = query_temp("apply/long")) )
		str = mask[sizeof(mask)-1];
	else if( !stringp(str = query("long")) )
		str = short(raw) + "�C\n";

	if( stringp(extra = this_object()->extra_long()) )
		str += extra;

	return str;
}

varargs string item_describe(int only_name)
{
	string type,armor,race_armor_type,skill_type;
	int flag;
	object env,owner;
	if(query("equipped"))
	{
		if( (owner = environment())->is_character() )
		{
			// Find owner's Race
			switch(owner->query("race"))
			{
				case "�H��" :
				case "human" : 
						race_armor_type="armor_type";
						break;
				case "���~" :
				case "beast" :
						race_armor_type="beast_armor_type";
						break;
				case "����" :
				case "zerg" :
						race_armor_type="zerg_armor_type";
						break;
				case "����" :
				case "protoss":
						race_armor_type="protoss_armor_type";
						break;
				default :
						race_armor_type="armor_type";
			}
		} else race_armor_type = "armor_type";
	
		if(skill_type=query("skill_type"))
		{
		 if(skill_type=="parasite") type="�ͤƿĦX";
		 else
		 {
		 	flag=query("flag");
		 	if( flag & TWO_HANDED ) type="����ϥ�";
		 	else type="���ϥ�";
		 }
		} 
		else if(armor=query(race_armor_type))
		{
		 switch(armor)
		 {
		  case "shield": type="�@��˵�";
		  		 break;
		  case "head": type="�Y�W����";
		  		 break;
		  case "mask": type="�y�W����";
		  		 break;
		  case "surcoat": type="�ӤW�ܵ�";
		  		 break;
		  case "armor": type="���W�е�";
		  		 break;
		  case "cloth": type="���W���";
		  		 break;
		  case "pants": type="�U�����";
		  		 break;
		  case "boots": type="�}�W���";
		  		 break;
		  case "legging": type="�L�W���";
		  		 break;
		  case "waist": type="�y�W�j��";
		  		 break;
		  case "neck": type="��l����";
		  		 break;
		  case "finger":
		  case "ring": type="��W����";
		  		 break;
		  default: type="���W����";
		 }
		}
		else type="���˳Ƶ�";
	}
	else return sprintf("%s%s",short(),query("secured")? HIC "(�O�s)" NOR : "");
	if(!only_name)
	return sprintf("%s%s%s",
		short(),
		HIG+" ("+type+") "NOR,
		query("secured")? HIC "(�O�s)" NOR : "" );
	else 
		return sprintf("%s%s",
		HIC+"  ["+type+"]  "+NOR,
		short()
		);
}