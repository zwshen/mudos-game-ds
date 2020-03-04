// message.c
//#pragma save_binary
// 程э: Shengsan@DS
// 程эら戳: 2000/05/17
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
				// add by shengsan for 癟
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
		receive(BOLD "[块既癟]\n" NOR);
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
			arg = "%L> ";	// 畍箇砞
		else
			arg = "> ";	// 產箇砞
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
				// 獶ず﹚把计陪ボ ?_? 才腹
				default : tmp = "?_?"; break;
				// 陪ボ % 才腹
				case "%": tmp = "%"; break;
				// ヘ玡ネ㏑翴计
				case "h": tmp = this_object()->query("hp"); break;
				// 程ネ㏑翴计
				case "H": tmp = this_object()->query("max_hp"); break;
				// ヘ玡臸猭翴计
				case "m": tmp = this_object()->query("mp"); break;
				// 程臸猭翴计
				case "M": tmp = this_object()->query("max_mp"); break;
				// ヘ玡ず玪翴计
				case "a": tmp = this_object()->query("ap"); break;
				// 程ず玪翴计
				case "A": tmp = this_object()->query("max_ap"); break;
				// ヘ玡┮矪
				case "T": env = environment(this_object());
					  if(!env)
					  	tmp = "店礚";
					  else switch(NATURE_D->which_world(env))
					  {
					  	case 1: tmp = ""; break;
					  	case 2: tmp = "瞷"; break;
					  	case 3: tmp = "ゼㄓ"; break;
					  	case 4: tmp = "Н臸"; break;
					  	default: tmp = "冠ほ";
					  }
					  break;
				// ヘ玡驹矮竒喷
				case "c": tmp = this_object()->query("combat_exp"); break;
				// ヘ玡竒喷
				case "x": tmp = this_object()->query("exp"); break;
				// ヘ玡皚犁
				case "l": tmp = "/cmds/usr/score"->attitude_report(this_object()->query("evil"));
					  tmp = replace_string(tmp, " ", "");
					  break;
				// 础传︽じ
				case "~": tmp = "\n"; break;
				// ヘ玡ヘ魁(畍ㄏノ)
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
				// ヘ玡郎(畍ㄏノ)
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
