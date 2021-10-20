// fingerd.c
// #pragma save_binary

#include <net/dns.h>

void create() { seteuid( getuid() ); }

string age_string(int time)
{
        int month, day, hour;

          time = time /3600;
        hour = time % 24;
          time = time/24;
        day = time % 30;
        month = time / 30;
        return (month?month + "��":"") + (day?day + "��":"") + hour + "�p��";
}

varargs string process_ip_name(object ob,int flag)
{
 string ip,name, *netc_key;
 mapping netcoff;
 int ip1,ip2,ip3,ip4;

 if(!ob)
 	return "";
 if(!ip = query_ip_number(ob))
 	return "";
 if( getuid(ob) == "shengsan" || getuid(ob) == "luky")
 	ip = "???.???.???.???";
 if(flag)
 	name=ip;
 else
 	name="";
 if(ip == "127.0.0.1" || ip == "???.???.???.???")
 	return name=sprintf("%-15s (�ڤۮɪ�)",name);
 if(sscanf(ip, "%d.%d.%d.%d", ip1, ip2, ip3, ip4) != 4 )
 	return "(Unknown)";

// ���X ip_d
 if( mapp(netcoff = IP_D->query_ip()) )
 {
 	netc_key = keys(netcoff);
        for(int i=0;i<sizeof(netc_key);i++)
                if( netcoff[netc_key[i]] == ip )
                        return name = sprintf("%-15s (" + netc_key[i] + ")", name);
 }
// end

 switch(ip1)
 {
        case 24:       
                        return name=sprintf("%-15s (�[���j)",name);
                        break;
	case 61:
			switch(ip2)
			{
			  case 16: return name=sprintf("%-15s (IS.net)",name);
			  case 70: return name=sprintf("%-15s (�x�WGigaMedia)",name);
			  case 216:
			  case 217:
			  case 218:
			  case 221:
			  case 223:
			  case 225:
			  case 230: return name=sprintf("%-15s (�x�WHINET)",name);
			  default: break;
			}
			break;  
        case 139:
                        if(ip2 == 175) return name=sprintf("%-15s (�x�WSEEDNET)",name);
                        else if(ip2 == 223) return name=sprintf("%-15s (�x�WTISNet)",name);
                        break;
        case 140:
                        switch(ip2)
                        {
                          case 2: return name=sprintf("%-15s (�x�W�j��)",name);
                          case 111: 
                                        if(ip3==86) return name=sprintf("%-15s (�_���u��)",name);
                                        else break;
                          case 112: return name=sprintf("%-15s (�x�W�j��)",name);
                          case 113: return name=sprintf("%-15s (��q�j��)",name);
                          case 114: return name=sprintf("%-15s (�M�ؤj��)",name);
                          case 115: return name=sprintf("%-15s (�����j��)",name);
                          case 116: return name=sprintf("%-15s (���\\�j��)",name);
                          case 117: return name=sprintf("%-15s (���s�j��)",name);
                         case 118: return name=sprintf("%-15s (�x�W��ޤj��)",name);
                          case 119: return name=sprintf("%-15s (�F�v�j��)",name);
                          case 120: return name=sprintf("%-15s (�����j��)",name);
                          case 121: return name=sprintf("%-15s (���v�j��)",name);
                          case 122: return name=sprintf("%-15s (�v�d�j��)",name);
                          case 123: return name=sprintf("%-15s (�����j��)",name);
                          case 124: return name=sprintf("%-15s (�x�_��ޤj��)",name);
                          case 125: return name=sprintf("%-15s (���L��ޤj��)",name);
                          case 126: 
                                        if(ip3==22) return name=sprintf("%-15s (�s�ˮv�|)",name);
                                        else return name=sprintf("%-15s (���ؤj��)",name);
                          case 127: 
                                        if(ip3 == 171 || ip3 == 172 || ip3 == 173) return name=sprintf("%-15s (�x�F�v�d�ǰ|)",name);
                                        else if(ip3 > 175 && ip3 < 187) return name=sprintf("%-15s (�q�u�j��)",name);
                                        else break;
                          case 128: 
                                        if(ip3 < 36 ) return name=sprintf("%-15s (�R�y�j��)",name);
                                        else if(ip3 == 71 ) return name=sprintf("%-15s (�ԯq�u�M)",name);
                                        else if(ip3 > 95 && ip3 < 133) return name=sprintf("%-15s (�F���j��)",name);
                                        else if(ip3 == 136 || ip3 == 137) return name=sprintf("%-15s (���s��ǰ|)",name);
                                        else if(ip3 == 157) return name=sprintf("%-15s (���D����)",name);
                                        else break;
                          case 129:
                                        if(ip3 == 79 ) return name=sprintf("%-15s (�����j��)",name);
                                        else return name=sprintf("%-15s (�j�P�u�ǰ|)",name);
                          case 130:
                                        if(ip3 == 171) return name=sprintf("%-15s (�Ÿq�޳N�ǰ|)",name);
                                        else break;
                          case 131:
                                        if(ip3 == 3) return name=sprintf("%-15s (�خL�u�ӱM��)",name);
                                        else if(ip3 == 22) return name=sprintf("%-15s (������M)",name);
                                        else if(ip3 == 41) return name=sprintf("%-15s (�_���v�|)",name);
                                        else if(ip3 == 5 || (ip3 < 65 && ip3 > 60) ) return name=sprintf("%-15s (�ʶǤj��)",name);
                                        else break;
                          case 134: return name=sprintf("%-15s (�{�Ҥj��)",name);
                          case 135: return name=sprintf("%-15s (����j��)",name);
                          case 136: return name=sprintf("%-15s (�����j��)",name);
                          case 137: 
                                        if(ip3==5)
                                        {
                                                if(ip4==3 || ip4==4) return name=sprintf("%-15s (��Ƥj�Ǥu�@��)",name);
                                        }
                                        return name=sprintf("%-15s (��Ƥj��)",name);
                          case 138: return name=sprintf("%-15s (�����j��)",name);
                          default: break;
                          
                        }
                        break;
        case 163:       
                        switch(ip2)
                        {
                                case 13: return name=sprintf("%-15s (�H���j��)",name);
                                case 14: return name=sprintf("%-15s (�F�d�j��)",name);
                                case 15: return name=sprintf("%-15s (������ǰ|)",name);
                                case 16: return name=sprintf("%-15s (�������и��)",name);
                                case 17: return name=sprintf("%-15s (�¶��޳N�ǰ|)",name);
                                case 19: 
                                         switch(ip3)
                                         {
                                                case 14: return name=sprintf("%-15s (�����k��)",name);
                                                case 17: return name=sprintf("%-15s (�D������)",name);
                                                case 33: return name=sprintf("%-15s (�������)",name);
                                                default: break;
                                         }
                                         break;
                                case 23: return name=sprintf("%-15s (�j���j��)",name);
                                case 25: 
                                        if(ip3 == 6) return name=sprintf("%-15s (����ĵ��j��)",name);
                                        else if(ip3 == 111) return name=sprintf("%-15s (�����j��)",name);
                                        else break;
                                case 26: return name=sprintf("%-15s (�x�n���и��)",name);
                                case 31:
                                case 32: return name=sprintf("%-15s (�x�WHINET)",name);
                                default: break;
                        }
                        break;
        case 168:
                        if(ip2 == 70 ) return name=sprintf("%-15s (����)",name);
                        else if(ip2 == 95 ) return name=sprintf("%-15s (�x�WHINET)",name);
                        break;
        case 192:       
                        if(ip2 == 72 ) return name=sprintf("%-15s (�x�WSEEDNET)",name);
                        else if(ip2 == 83 )
                        {
                                switch(ip3)
                                {
                                        case 172: return name=sprintf("%-15s (�x���ӱM)",name);
                                        case 181: return name=sprintf("%-15s (�����|�ǰ|)",name);
                                        default: break;
                                }
                        }
                        else if(ip2 == 192)
                        {
                                switch(ip3)
                                {
                                        case 15: return name=sprintf("%-15s (�@�s�j��)",name);
                                        case 27: return name=sprintf("%-15s (�j���j��)",name);
                                        case 35: return name=sprintf("%-15s (�����k��)",name);
                                        case 61: return name=sprintf("%-15s (�����j��)",name);
                                        case 68: return name=sprintf("%-15s (�ȪF�u�M)",name);
                                        case 90:
                                        case 91: return name=sprintf("%-15s (�꨾��ǰ|)",name);
                                        case 117: 
                                        case 118: 
                                        case 119: return name=sprintf("%-15s (�����@�M)",name);
                                        case 183: return name=sprintf("%-15s (�[�n�j��)",name);
                                        case 241: 
                                        case 247: return name=sprintf("%-15s (�����޳N�ǰ|)",name);
                                        default : break;
                                }
                        }
                        break;
        case 202:
                        if(ip2 == 43 ) return name=sprintf("%-15s (���iùSeeder)",name);
                        else if(ip2 == 96 ) return name=sprintf("%-15s (����j��)",name);
                        else if(ip2 == 103 ) return name=sprintf("%-15s (�j����n��)",name);
                        else if(ip2 == 145 ) return name=sprintf("%-15s (�x�W�j������)",name);
                        else if(ip2 == 166 ) return name=sprintf("%-15s (NEC BigGlobe)",name);
                        break;
        case 203:       
                        switch(ip2)
                        {
                          case 64: 
                                        switch(ip3)
                                        {
                                                case 9: return name=sprintf("%-15s (�j���j��)",name);
                                                case 23: 
                                                case 24: 
                                                case 25: return name=sprintf("%-15s (���Ʈv�j)",name);
                                                case 26: return name=sprintf("%-15s (�x�_�ذꤤ��)",name);
                                                case 34: 
                                                case 35: return name=sprintf("%-15s (�O���@�M)",name);
                                                case 48: return name=sprintf("%-15s (�x�_��ǰ|)",name);
                                                case 52: return name=sprintf("%-15s (�_�@�k��)",name);
                                                case 79: 
                                                case 80: return name=sprintf("%-15s (�O����ǰ|)",name);
                                                case 88: return name=sprintf("%-15s (�F�ؤj��)",name);
                                                case 124: 
                                                case 129: return name=sprintf("%-15s (�̪F�ӱM)",name);
                                                case 137: return name=sprintf("%-15s (�w�|�@�M)",name);
                                                case 205: return name=sprintf("%-15s (�����k��)",name);
                                                default : break;
                                        }
                                        break;
                          case 65: return name=sprintf("%-15s (�x�WGCNet)",name);
                          case 70: return name=sprintf("%-15s (�x�W�s����)",name);
                          case 71: 
                                   if(ip3==3) return name=sprintf("%-15s (�x�F����)",name);
                                   else if(ip3==85 || ip3==86) return name=sprintf("%-15s (�x�_��ǰ|)",name);
                                   else break;
                          case 72: 
                                        switch(ip3)
                                        {
                                                case 0: return name=sprintf("%-15s (�n�غ޲z�ǰ|)",name);
                                                case 16: return name=sprintf("%-15s (�x�F���_��ꤤ)",name);
                                                case 29:
                                                case 30: return name=sprintf("%-15s (�׭찪��)",name);
                                                case 43: return name=sprintf("%-15s (�x���M����p)",name);
                                                case 59: return name=sprintf("%-15s (�x�_�_������)",name);
                                                case 73:
                                                case 74:
                                                case 75:
                                                case 76:
                                                case 77:
                                                case 78: return name=sprintf("%-15s (�O����ǰ|)",name);
                                                case 178: return name=sprintf("%-15s (��������)",name);
                                                case 206: return name=sprintf("%-15s (���ؤk��)",name);
                                        }
                                        break;
                          case 80: 
                          case 85: return name=sprintf("%-15s (����)",name);
                          case 95: return name=sprintf("%-15s (�~�N����)",name);
                          case 135: return name=sprintf("%-15s (�x�WD.JNet)",name);
                          case 198: return name=sprintf("%-15s (����IMS)",name);
                          case 204: return name=sprintf("%-15s (�x�WGigaMedia)",name);
                          default: break;
                        }
                        break;
        case 207:
                        if(ip2 == 176) return name=sprintf("%-15s (����)",name);
                        break;
        case 208:
                        if(ip2 == 151) return name=sprintf("%-15s (����)",name);
                        break;
        case 210:       
                        switch(ip2)
                        {
                         case 61: return name=sprintf("%-15s (�x�W�}�z)",name);
                         case 62: return name=sprintf("%-15s (���iùSeeder)",name);
                         case 63: return name=sprintf("%-15s (��aHt.net)",name);
                         case 85: return name=sprintf("%-15s (�F�˼e�W)",name);
                         case 240: return name=sprintf("%-15s (�x�F�v�|)",name);
                         case 241:
                                   if(ip3==250 && ip4==18) return name=sprintf("%-15s (���J�ꤤ)",name);
                         case 243: 
                         case 244: return name=sprintf("%-15s (�x�WSEEDNET)",name);
                         default: break;
                        }
                        break;
	case 211:
                        switch(ip2)
                        {
			  case 72: if(ip3==115 && ip4==190) return name=sprintf("%-15s (�e����T)",name);
			  case 75: if(ip3==226 && ip4==130) return name=sprintf("%-15s (��ޱJ��)",name);
			  default: break;
                        }
                        break;
	case 218:
			switch(ip2)
			{
				case 160:
				case 162:
				case 164:  return name=sprintf("%-15s (�x�WHINET)",name);
				default: break;
			}
			break;
        default: break;
 }
 return sprintf("%-15s ",name);
}


// flag=1 �i�ݨ� ip, flag=1 �ݤ��� ip
varargs string finger_all(int flag)
{
        object *ob;
        string msg,ps;
        int i;

        ob = users();
        ob = sort_array(users(), "sort_user", this_object());
        msg = "���w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";
        if(flag==2)
        {
                for(i=0; i<sizeof(ob); i++)
                {
                        if( this_player() && !this_player()->visible(ob[i]) ) continue;
                        if( !ob[i]->query("name") ) continue;
                        ps="";
                        msg = sprintf("%s%-14s %-14s %-14s %-30s %s\n",
                                msg, ob[i]->name(1), getuid(ob[i]),
                                age_string( (int)ob[i]->query("mud_age")), query_ip_name(ob[i]) ,ps);
                }
        }
         else
        {
                for(i=0; i<sizeof(ob); i++)
                {
                        if( this_player() && !this_player()->visible(ob[i]) ) continue;
                        if( !ob[i]->query("name") ) continue;
                        ps="";
                        msg = sprintf("%s%-14s %-14s %-14s %-30s %s\n",
                                msg, ob[i]->name(1), ob[i]->query("id"),
                                age_string( (int)ob[i]->query("mud_age")), process_ip_name(ob[i],flag) ,ps);
                }
        }
        return msg + "���w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";
}

varargs string finger_user(string name,int flag)
{
        object ob;
        int birthday = 0, mud_age = 0;
         string msg, mud,name2="";

        if( sscanf(name, "%s@%s", name, mud)==2 ) {
                GFINGER_Q->send_finger_q(mud, name, this_player(1));
                return "�������O�ǰe�L�{�i��ݭn�@�Ǯɶ��M�еy�ԡC\n";
        }

        if(objectp(ob = find_player(name))) {
                name2 = ob->query("name");
                birthday = ob->query("birthday");
                mud_age = ob->query("mud_age");
        }

                ob = new(LOGIN_OB);
        ob->set("id", name);
        if( !ob->restore() ) return "�S���o�Ӫ��a�C\n";
        if(name2=="") name2=ob->query("name");
       
        if(flag) {
        msg =  sprintf("\n�^��N���R\t%s\n�m    �W�R\t%s\n�v�����šR\t%s\n"
                "���ⵥ��: \t%d\n�q�l�l��a�}�R\t%s\n�W���s�u�a�}�R\t%s( %s )\n"
                "������U�ɶ�: \t%s\n"
                "�s�u�ɼ��`�M: \t%s\n\n",
                ob->query("id"),
                name2,
                SECURITY_D->get_status(name),
                ob->query("level"),
                ob->query("email"),
                ob->query("last_from"),
                ctime( ob->query("last_on") ),
                                ctime( birthday ),                                                                                
                        age_string( mud_age )
        );
    }
        else  {
                    msg =  sprintf("\n�^��N���R\t%s\n�m    �W�R\t%s\n�v�����šR\t%s\n"
                                "���ⵥ��: \t%d\n�q�l�l��a�}�R\t%s\n�W���s�u�ɶ��R\t( %s )\n"
                                "������U�ɶ�: \t%s\n"
                                "�s�u�ɼ��`�M: \t%s\n\n",
                                ob->query("id"),
                                name2,
                                SECURITY_D->get_status(name),
                                ob->query("level"),
                                ob->query("email"),
                                ctime( ob->query("last_on") ),
                                                ctime( birthday ),                                                                                
                                        age_string( mud_age )
                        );
        }
            destruct(ob);
        return msg;
}












varargs string remote_finger_user(string name, int chinese_flag)
{
        object ob, body;
        string msg;

        ob = new(LOGIN_OB);
        ob->set("id", name);
        if( !ob->restore() )
                return chinese_flag ? "�S���o�Ӫ��a�C\n" : "No such user.\n";
        if( chinese_flag ) msg =  sprintf(
                "\n�^��N���R\t%s\n�m    �W�R\t%s\n�v�����šR\t%s\n"
                "�q�l�l��a�}�R\t%s\n�W���s�u�a�}�R\t%s( %s )\n\n",
                ob->query("id"),
                ob->query("name"),
                SECURITY_D->get_status(name),
                ob->query("email"),
                ob->query("last_from"),
                ctime(ob->query("last_on"))
        );
        else msg =  sprintf(
                "\nName\t: %s\nStatus\t: %s\nEmail\t: %s\nLastOn\t: %s( %s )\n\n",
                capitalize(ob->query("id")),
                SECURITY_D->get_status(name),
                ob->query("email"),
                ob->query("last_from"),
                ctime(ob->query("last_on"))
        );
        if( body = find_player(name) ) {
                if( !this_player() || this_player()->visible(body) )
                        msg += chinese_flag ?
                                ("\n" + ob->query("name") + "�ثe���b�u�W�C\n"):
                                ("\n" + capitalize(name) + " is currently connected.\n");
        }

        destruct(ob);
        return msg;
}

object acquire_login_ob(string id)
{
        object ob;

        if( ob = find_player(id) ) {
                // Check if the player is linkdead
                if( ob->query_temp("link_ob") )
                        return ob->query_temp("link_ob");
        }
        ob = new(LOGIN_OB);
        ob->set("id", id);
        return ob->restore() ? ob : 0;
}

int sort_user(object ob1, object ob2)
{
	if( getuid(ob1) == "shengsan" || getuid(ob1) == "luky")
		return -1;
	else
        	return strcmp(query_ip_number(ob1),query_ip_number(ob2));
}
