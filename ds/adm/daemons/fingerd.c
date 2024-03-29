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
        return (month?month + "月":"") + (day?day + "天":"") + hour + "小時";
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
 	return name=sprintf("%-15s (夢幻時空)",name);
 if(sscanf(ip, "%d.%d.%d.%d", ip1, ip2, ip3, ip4) != 4 )
 	return "(Unknown)";

// 結合 ip_d
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
                        return name=sprintf("%-15s (加拿大)",name);
                        break;
	case 61:
			switch(ip2)
			{
			  case 16: return name=sprintf("%-15s (IS.net)",name);
			  case 70: return name=sprintf("%-15s (台灣GigaMedia)",name);
			  case 216:
			  case 217:
			  case 218:
			  case 221:
			  case 223:
			  case 225:
			  case 230: return name=sprintf("%-15s (台灣HINET)",name);
			  default: break;
			}
			break;  
        case 139:
                        if(ip2 == 175) return name=sprintf("%-15s (台灣SEEDNET)",name);
                        else if(ip2 == 223) return name=sprintf("%-15s (台灣TISNet)",name);
                        break;
        case 140:
                        switch(ip2)
                        {
                          case 2: return name=sprintf("%-15s (台灣大學)",name);
                          case 111: 
                                        if(ip3==86) return name=sprintf("%-15s (復興工商)",name);
                                        else break;
                          case 112: return name=sprintf("%-15s (台灣大學)",name);
                          case 113: return name=sprintf("%-15s (交通大學)",name);
                          case 114: return name=sprintf("%-15s (清華大學)",name);
                          case 115: return name=sprintf("%-15s (中央大學)",name);
                          case 116: return name=sprintf("%-15s (成功\大學)",name);
                          case 117: return name=sprintf("%-15s (中山大學)",name);
                         case 118: return name=sprintf("%-15s (台灣科技大學)",name);
                          case 119: return name=sprintf("%-15s (政治大學)",name);
                          case 120: return name=sprintf("%-15s (中興大學)",name);
                          case 121: return name=sprintf("%-15s (海洋大學)",name);
                          case 122: return name=sprintf("%-15s (師範大學)",name);
                          case 123: return name=sprintf("%-15s (中正大學)",name);
                          case 124: return name=sprintf("%-15s (台北科技大學)",name);
                          case 125: return name=sprintf("%-15s (雲林科技大學)",name);
                          case 126: 
                                        if(ip3==22) return name=sprintf("%-15s (新竹師院)",name);
                                        else return name=sprintf("%-15s (中華大學)",name);
                          case 127: 
                                        if(ip3 == 171 || ip3 == 172 || ip3 == 173) return name=sprintf("%-15s (台東師範學院)",name);
                                        else if(ip3 > 175 && ip3 < 187) return name=sprintf("%-15s (義守大學)",name);
                                        else break;
                          case 128: 
                                        if(ip3 < 36 ) return name=sprintf("%-15s (靜宜大學)",name);
                                        else if(ip3 == 71 ) return name=sprintf("%-15s (勤益工專)",name);
                                        else if(ip3 > 95 && ip3 < 133) return name=sprintf("%-15s (東海大學)",name);
                                        else if(ip3 == 136 || ip3 == 137) return name=sprintf("%-15s (中山醫學院)",name);
                                        else if(ip3 == 157) return name=sprintf("%-15s (明道中學)",name);
                                        else break;
                          case 129:
                                        if(ip3 == 79 ) return name=sprintf("%-15s (陽明大學)",name);
                                        else return name=sprintf("%-15s (大同工學院)",name);
                          case 130:
                                        if(ip3 == 171) return name=sprintf("%-15s (嘉義技術學院)",name);
                                        else break;
                          case 131:
                                        if(ip3 == 3) return name=sprintf("%-15s (華夏工商專校)",name);
                                        else if(ip3 == 22) return name=sprintf("%-15s (國立藝專)",name);
                                        else if(ip3 == 41) return name=sprintf("%-15s (北市師院)",name);
                                        else if(ip3 == 5 || (ip3 < 65 && ip3 > 60) ) return name=sprintf("%-15s (銘傳大學)",name);
                                        else break;
                          case 134: return name=sprintf("%-15s (逢甲大學)",name);
                          case 135: return name=sprintf("%-15s (中原大學)",name);
                          case 136: return name=sprintf("%-15s (輔仁大學)",name);
                          case 137: 
                                        if(ip3==5)
                                        {
                                                if(ip4==3 || ip4==4) return name=sprintf("%-15s (文化大學工作站)",name);
                                        }
                                        return name=sprintf("%-15s (文化大學)",name);
                          case 138: return name=sprintf("%-15s (元智大學)",name);
                          default: break;
                          
                        }
                        break;
        case 163:       
                        switch(ip2)
                        {
                                case 13: return name=sprintf("%-15s (淡江大學)",name);
                                case 14: return name=sprintf("%-15s (東吳大學)",name);
                                case 15: return name=sprintf("%-15s (高雄醫學院)",name);
                                case 16: return name=sprintf("%-15s (高雄縣教資網)",name);
                                case 17: return name=sprintf("%-15s (朝陽技術學院)",name);
                                case 19: 
                                         switch(ip3)
                                         {
                                                case 14: return name=sprintf("%-15s (高雄女中)",name);
                                                case 17: return name=sprintf("%-15s (道明中學)",name);
                                                case 33: return name=sprintf("%-15s (國光中學)",name);
                                                default: break;
                                         }
                                         break;
                                case 23: return name=sprintf("%-15s (大葉大學)",name);
                                case 25: 
                                        if(ip3 == 6) return name=sprintf("%-15s (中央警察大學)",name);
                                        else if(ip3 == 111) return name=sprintf("%-15s (長庚大學)",name);
                                        else break;
                                case 26: return name=sprintf("%-15s (台南市教資網)",name);
                                case 31:
                                case 32: return name=sprintf("%-15s (台灣HINET)",name);
                                default: break;
                        }
                        break;
        case 168:
                        if(ip2 == 70 ) return name=sprintf("%-15s (香港)",name);
                        else if(ip2 == 95 ) return name=sprintf("%-15s (台灣HINET)",name);
                        break;
        case 192:       
                        if(ip2 == 72 ) return name=sprintf("%-15s (台灣SEEDNET)",name);
                        else if(ip2 == 83 )
                        {
                                switch(ip3)
                                {
                                        case 172: return name=sprintf("%-15s (台中商專)",name);
                                        case 181: return name=sprintf("%-15s (國立體育學院)",name);
                                        default: break;
                                }
                        }
                        else if(ip2 == 192)
                        {
                                switch(ip3)
                                {
                                        case 15: return name=sprintf("%-15s (世新大學)",name);
                                        case 27: return name=sprintf("%-15s (大葉大學)",name);
                                        case 35: return name=sprintf("%-15s (中興法商)",name);
                                        case 61: return name=sprintf("%-15s (長庚大學)",name);
                                        case 68: return name=sprintf("%-15s (亞東工專)",name);
                                        case 90:
                                        case 91: return name=sprintf("%-15s (國防醫學院)",name);
                                        case 117: 
                                        case 118: 
                                        case 119: return name=sprintf("%-15s (長庚護專)",name);
                                        case 183: return name=sprintf("%-15s (暨南大學)",name);
                                        case 241: 
                                        case 247: return name=sprintf("%-15s (弘光技術學院)",name);
                                        default : break;
                                }
                        }
                        break;
        case 202:
                        if(ip2 == 43 ) return name=sprintf("%-15s (阿波羅Seeder)",name);
                        else if(ip2 == 96 ) return name=sprintf("%-15s (中國大陸)",name);
                        else if(ip2 == 103 ) return name=sprintf("%-15s (大陸湖南省)",name);
                        else if(ip2 == 145 ) return name=sprintf("%-15s (台灣大眾網路)",name);
                        else if(ip2 == 166 ) return name=sprintf("%-15s (NEC BigGlobe)",name);
                        break;
        case 203:       
                        switch(ip2)
                        {
                          case 64: 
                                        switch(ip3)
                                        {
                                                case 9: return name=sprintf("%-15s (大葉大學)",name);
                                                case 23: 
                                                case 24: 
                                                case 25: return name=sprintf("%-15s (彰化師大)",name);
                                                case 26: return name=sprintf("%-15s (台北建國中學)",name);
                                                case 34: 
                                                case 35: return name=sprintf("%-15s (慈濟護專)",name);
                                                case 48: return name=sprintf("%-15s (台北醫學院)",name);
                                                case 52: return name=sprintf("%-15s (北一女中)",name);
                                                case 79: 
                                                case 80: return name=sprintf("%-15s (慈濟醫學院)",name);
                                                case 88: return name=sprintf("%-15s (東華大學)",name);
                                                case 124: 
                                                case 129: return name=sprintf("%-15s (屏東商專)",name);
                                                case 137: return name=sprintf("%-15s (德育護專)",name);
                                                case 205: return name=sprintf("%-15s (高雄女中)",name);
                                                default : break;
                                        }
                                        break;
                          case 65: return name=sprintf("%-15s (台灣GCNet)",name);
                          case 70: return name=sprintf("%-15s (台灣新絲路)",name);
                          case 71: 
                                   if(ip3==3) return name=sprintf("%-15s (台東高商)",name);
                                   else if(ip3==85 || ip3==86) return name=sprintf("%-15s (台北醫學院)",name);
                                   else break;
                          case 72: 
                                        switch(ip3)
                                        {
                                                case 0: return name=sprintf("%-15s (南華管理學院)",name);
                                                case 16: return name=sprintf("%-15s (台東縣寶桑國中)",name);
                                                case 29:
                                                case 30: return name=sprintf("%-15s (豐原高商)",name);
                                                case 43: return name=sprintf("%-15s (台中清水國小)",name);
                                                case 59: return name=sprintf("%-15s (台北復興高中)",name);
                                                case 73:
                                                case 74:
                                                case 75:
                                                case 76:
                                                case 77:
                                                case 78: return name=sprintf("%-15s (慈濟醫學院)",name);
                                                case 178: return name=sprintf("%-15s (延平中學)",name);
                                                case 206: return name=sprintf("%-15s (光華女中)",name);
                                        }
                                        break;
                          case 80: 
                          case 85: return name=sprintf("%-15s (香港)",name);
                          case 95: return name=sprintf("%-15s (年代網路)",name);
                          case 135: return name=sprintf("%-15s (台灣D.JNet)",name);
                          case 198: return name=sprintf("%-15s (香港IMS)",name);
                          case 204: return name=sprintf("%-15s (台灣GigaMedia)",name);
                          default: break;
                        }
                        break;
        case 207:
                        if(ip2 == 176) return name=sprintf("%-15s (香港)",name);
                        break;
        case 208:
                        if(ip2 == 151) return name=sprintf("%-15s (香港)",name);
                        break;
        case 210:       
                        switch(ip2)
                        {
                         case 61: return name=sprintf("%-15s (台灣開暘)",name);
                         case 62: return name=sprintf("%-15s (阿波羅Seeder)",name);
                         case 63: return name=sprintf("%-15s (仲琦Ht.net)",name);
                         case 85: return name=sprintf("%-15s (東森寬頻)",name);
                         case 240: return name=sprintf("%-15s (台東師院)",name);
                         case 241:
                                   if(ip3==250 && ip4==18) return name=sprintf("%-15s (瑞穗國中)",name);
                         case 243: 
                         case 244: return name=sprintf("%-15s (台灣SEEDNET)",name);
                         default: break;
                        }
                        break;
	case 211:
                        switch(ip2)
                        {
			  case 72: if(ip3==115 && ip4==190) return name=sprintf("%-15s (疾風資訊)",name);
			  case 75: if(ip3==226 && ip4==130) return name=sprintf("%-15s (虎技宿網)",name);
			  default: break;
                        }
                        break;
	case 218:
			switch(ip2)
			{
				case 160:
				case 162:
				case 164:  return name=sprintf("%-15s (台灣HINET)",name);
				default: break;
			}
			break;
        default: break;
 }
 return sprintf("%-15s ",name);
}


// flag=1 可看到 ip, flag=1 看不到 ip
varargs string finger_all(int flag)
{
        object *ob;
        string msg,ps;
        int i;

        ob = users();
        ob = sort_array(users(), "sort_user", this_object());
        msg = "●──────────────────────────────────────●\n";
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
        return msg + "●──────────────────────────────────────●\n";
}

varargs string finger_user(string name,int flag)
{
        object ob;
        int birthday = 0, mud_age = 0;
         string msg, mud,name2="";

        if( sscanf(name, "%s@%s", name, mud)==2 ) {
                GFINGER_Q->send_finger_q(mud, name, this_player(1));
                return "網路指令傳送過程可能需要一些時間﹐請稍候。\n";
        }

        if(objectp(ob = find_player(name))) {
                name2 = ob->query("name");
                birthday = ob->query("birthday");
                mud_age = ob->query("mud_age");
        }

                ob = new(LOGIN_OB);
        ob->set("id", name);
        if( !ob->restore() ) return "沒有這個玩家。\n";
        if(name2=="") name2=ob->query("name");
       
        if(flag) {
        msg =  sprintf("\n英文代號﹕\t%s\n姓    名﹕\t%s\n權限等級﹕\t%s\n"
                "角色等級: \t%d\n電子郵件地址﹕\t%s\n上次連線地址﹕\t%s( %s )\n"
                "角色註冊時間: \t%s\n"
                "連線時數總和: \t%s\n\n",
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
                    msg =  sprintf("\n英文代號﹕\t%s\n姓    名﹕\t%s\n權限等級﹕\t%s\n"
                                "角色等級: \t%d\n電子郵件地址﹕\t%s\n上次連線時間﹕\t( %s )\n"
                                "角色註冊時間: \t%s\n"
                                "連線時數總和: \t%s\n\n",
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
                return chinese_flag ? "沒有這個玩家。\n" : "No such user.\n";
        if( chinese_flag ) msg =  sprintf(
                "\n英文代號﹕\t%s\n姓    名﹕\t%s\n權限等級﹕\t%s\n"
                "電子郵件地址﹕\t%s\n上次連線地址﹕\t%s( %s )\n\n",
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
                                ("\n" + ob->query("name") + "目前正在線上。\n"):
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
