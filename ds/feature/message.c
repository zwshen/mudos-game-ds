// message.c
// #pragma save_binary
// ��?�ק�H: Shengsan@DS
// ��?�ק��?: 2000/05/17
#include <ansi.h>
#include <dbase.h>

#define MAX_MSG_BUFFER 300

nosave string *msg_buffer = ({});

int receive(string str)
{
	if(this_object()->query_temp("gb_player"))
	{
		str=LANGUAGE_D->Big52GB(str);
	}
	return efun::receive(str);
}

void receive_message(string msgclass, string msg)
{
	string subclass, *ch;
	string env_dir, buffer1, buffer2;	// add by shengsan

	if( !interactive(this_object()) ) {
		this_object()->relay_message(msgclass, msg);
		return;
	}
/*	
	if(this_object()->query_temp("gb_player"))
	{
		msg=LANGUAGE_D->Big52GB(msg);
	}
*/
	// add by shengsan for world message
	if( sscanf(msgclass, "world:%s:%s", buffer1, msgclass) == 2 )
	{
			if(!environment()) return;
			env_dir = base_name(environment());
			if(!wizardp(this_object()))
			{
				if( sscanf(env_dir,"/open/%s/%s",env_dir,buffer2)!=2
				|| buffer1 != env_dir )
				return;
			} else
			{
				if(msgclass[0..6]=="outdoor" && ( sscanf(env_dir,"/open/%s/%s",env_dir,buffer2)!=2
				|| buffer1 != env_dir ))
				return;
			}
	} else
	if( sscanf(msgclass, "world_channel:%s:%s", buffer1, msgclass) == 2 )
	{
			if(!environment()) return;
			env_dir = base_name(environment());
			if(!wizardp(this_object()))
			{
				if( sscanf(env_dir,"/open/%s/%s",env_dir,buffer2)!=2 || buffer1 != env_dir ) return;
				if( !pointerp(ch = query("channels")) || member_array("chat", ch)==-1 )	return;
			}
			else if( !pointerp(ch = query("channels")) || member_array("chat", ch)==-1 )	return;
	}
	// end add
	if( sscanf(msgclass, "%s:%s", subclass, msgclass)==2 )
	{
		switch(subclass)
		{
			case "channel":
				if( !pointerp(ch = query("channels"))
				||	member_array(msgclass, ch)==-1 )
					return;
				break;
			case "outdoor":
				if( !environment() || !environment()->query("outdoors") )
					return;
				// add by shengsan for ?a?ή�԰T??
				if( msgclass && msgclass!="vision"
				&& msgclass!=environment()->query("outdoors") )
					return;
				// end add
				break;
			case "dayphase":
				if( !environment() || !environment()->query("outdoors") )
					return;
				if( environment()->query("outdoors")=="universe" )
					return;
				break;
			default:
				error("Message: Invalid Subclass " + subclass + ".\n");
		}
	}

	if( query_temp("block_msg/all") || query_temp("block_msg/" + msgclass) )
		return;

	if( !query("env/edit_msg") && (in_input(this_object()) || in_edit(this_object())) )
	{
		if( sizeof(msg_buffer) < MAX_MSG_BUFFER ) msg_buffer += ({ msg });
	} else receive( msg );
}

void write_prompt()
{
	string pwd,*ex,arg,prtout,tmp;
	object env;
	if( sizeof(msg_buffer) )
	{
		if(query_temp("halt_msg_in_edit")) this_object()->delete_temp("halt_msg_in_edit");
		receive(BOLD "[��?J?ɼ?�s�T??]\n" NOR);
		for(int i=0; i<sizeof(msg_buffer); i++)
			receive(msg_buffer[i]);
		msg_buffer = ({});
	}
/*	
	if (wiz_level(this_object())>1)
	{
		pwd=this_object()->query("cwd");
                if (!pwd || pwd=="/") write("/");
                else write(pwd[0..strlen(pwd)-2]);
        }
*/

	arg = this_object()->query("dssystem/prompt/form");
	if(!stringp(arg))
	{
		if (wiz_level(this_object())>1)
			arg = "%L> ";	// ?Ův�w�]??
		else
			arg = "> ";	// ?��a�w�]??
	}
	ex = explode(arg,"");
	prtout = "";
	for(int i=0;i<sizeof(ex);i++)
	{
		if( ex[i] != "%" )
			tmp = ex[i];
		else
			if( i < sizeof(ex)-1 )
			switch(ex[++i])
			{
				// �D���w�Ѽ�?���? ?_? �Ÿ�
				default : tmp = "?_?"; break;
				// ��� % �Ÿ�
				case "%": tmp = "%"; break;
				// �ثe�ͩR�I��
				case "h": tmp = this_object()->query("hp"); break;
				// ��?j�ͩR�I��
				case "H": tmp = this_object()->query("max_hp"); break;
				// �ثe�]�k�I��
				case "m": tmp = this_object()->query("mp"); break;
				// ��?j�]�k�I��
				case "M": tmp = this_object()->query("max_mp"); break;
				// �ثe���l�I��
				case "a": tmp = this_object()->query("ap"); break;
				// ��?j���l�I��
				case "A": tmp = this_object()->query("max_ap"); break;
				// �ثe�ҳB?ɪ?
				case "T": env = environment(this_object());
					  if(!env)
					  	tmp = "��L";
					  else switch(NATURE_D->which_world(env))
					  {
					  	case 1: tmp = "?j?N"; break;
					  	case 2: tmp = "�{?N"; break;
					  	case 3: tmp = "����"; break;
					  	case 4: tmp = "���]"; break;
					  	default: tmp = "�ڤ�";
					  }
					  break;
				// �ثe?��԰?�g��??
				case "c": tmp = this_object()->query("combat_exp"); break;
				// �ثe?��g��??
				case "x": tmp = this_object()->query("exp"); break;
				// �ثe�}��
				case "l": tmp = "/cmds/usr/score"->attitude_report(this_object()->query("evil"));
					  tmp = replace_string(tmp, " ", "");
					  break;
				// ��?J����?r��
				case "~": tmp = "\n"; break;
				// �ثe?��u?@�ؿ�(???Ův�ϥ�)
				case "L":
					if (wiz_level(this_object())>1)
					{
						pwd=this_object()->query("cwd");
				                if (!pwd || pwd=="/") tmp = "/";
				                else tmp = pwd[0..strlen(pwd)-2];
				        }
				        else
				        	tmp = "?_?";
				        break;
				// �ثe?��u?@��??(???Ův�ϥ�)
				case "F":
					if (wiz_level(this_object())>1)
					{
						pwd=this_object()->query("cwf");
				                if (!pwd || pwd=="/") tmp = "/";
				                else tmp = pwd;
				        }
				        else
				        	tmp = "?_?";
				        break;	

			}
			else tmp = "?_?";
		prtout += tmp;
	}

	write( prtout );
	
}

void receive_snoop(string msg)
{
	if(this_object()->query_temp("gb_playey"))
	{
		if(this_object()->query_temp("snoop_type")=="big5") msg=LANGUAGE_D->Big52GB(msg);
	} else
	{
		if(this_object()->query_temp("snoop_type")=="gb") msg=LANGUAGE_D->GB2Big5(msg);
	}
	receive("%" + msg);
}
