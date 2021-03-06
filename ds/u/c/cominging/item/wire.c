// 排線.c added by comingin@DS 2000.7.2
// 快出國了, 幫 wilfred 改一些表單 ( ps. 好像還是不怎麼好看 ).
// 把 where 改成 qwhere, 避免與原 where.c 重覆.
// 排線.c by wilfred@DS 2000.6.19
// 功用陸續增刪中
// 目前功用為 Where: 查看線上玩家的狀態 members: 線上全幫會人員 invis: 上線自動隱形

#include <ansi2.h>
#include <mudlib.h>
#include <command.h>

#define CLUB_ID_DRAGON "dragon"
#define CLUB_NAME_DRAGON "狂龍幫"
#define CLUB_ID_SKY "sky"
#define CLUB_NAME_SKY "天地會"
#define CLUB_ID_MOON "moon"
#define CLUB_NAME_MOON "月族"

inherit ITEM;

int do_invis();
string show_level(object user,string temp_club_name1,string temp_club_id1);
string query_ips(object *all_ppl, object current_ppl);
string query_status(object user);
void reply(object me, string msg);

static int dead_ppl = 0, j = 0;

void create()
{
	set_name(CYN"排線"NOR, ({"wire"}));
	set("long",HIC"一條普通的排線，通常是用來傳輸硬碟的資料，一般市面上都有賣。\n"NOR""WHT"◎可用指令◎"HIW"Qwhere  members  invis xset"NOR);
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit","條");
		set("value",1);
	}
	setup();
}

int query_autoload() { return 1; }

void init()
{
	add_action("do_where","qwhere");
	add_action("do_amembers","members");
	add_action("do_invis","invis");
	add_action("do_xset", "xset"); // 用來設定選項的
	if( !this_player()->query_temp("invis") ) do_invis();
}

int do_xset(string arg)
{
	object me = this_player();

	if( !arg ) return notify_fail("錯誤！可以用 xset ? 來查詢可設定的選項.\n");
	switch(arg)
	{
		case "no_ip": // 在 qwhere 中不顯示 ip
			if( !query("qno_ip") ) // 如果有 qno_ip
			{ set("qno_ip", 1); reply(me, "不顯示 ip"); }
			else
			{ delete("qno_ip"); reply(me, "顯示 ip"); }
			break;
		case "no_wizard": // 在 qwhere 中不顯示 wizard
			if( !query("qno_wiz") )
			{ set("qno_wiz", 1); reply(me, "不顯示巫師"); }
			else
			{ delete("qno_wiz"); reply(me, "顯示巫師"); }
			break;
		case "?":
			reply(me, "目前可用的有 no_ip, no_wiz");
			break;
		default:
			reply(me, "錯誤！可以用 xset ? 來查詢可設定的選項");
	}
	return 1;
}

void reply(object me, string msg)
{
	tell_object(me, name()+"回應："+ msg + "。\n");
}

int do_invis()
{
	object me = this_player();
	if( !me->query_temp("invis") )
	{
		write(WHT"你消失了，有如輕煙般飄散.....\n");
		me->set_temp("invis",(int)SECURITY_D->get_wiz_level(me));
		return 1;
	}
	if( me->query_temp("invis") )
	{
		write(HIC"你的身形漸漸浮現出來....\n"NOR);
		me->delete_temp("invis");
		return 1;
	}
}

int do_where()
{
	int i, user_amount, idle, wiz;
	object *user_list, user_location;
	string status1, status2, status3, status4;
	string temp_lv, msg = "";

	j = 0;
	dead_ppl = 0;

//	user_list = children("/obj/user");
//	user_list = sort_array(user_list, "sort_user", this_object());

//	user_amount = sizeof(user_list) - 1;
	user_list = users();
	user_amount = sizeof(user_list);

	if( !query("qno_wiz") )  // 先列出 wizard
		for(i=0;i<user_amount;i++)
		{
			if( wizardp(user_list[i]) )
			{
				j++;
				msg += query_status(user_list[i]);
			}
		}

	for(i=0;i<user_amount;i++) // 再列出 player
	{
		if( !wizardp(user_list[i]) )
		{
			j++;
			msg += query_status(user_list[i]);
		}
	}

	msg += sprintf("\n目前線上共有 "HIC"%d"NOR" 名使用者，其中有 "HIR"%d"NOR" 名斷線中。\n",user_amount,dead_ppl);
	this_player()->start_more(msg);
	return 1;
}

string query_ips(object *all_ppl, object current_ppl)
{
	string ip,temp_ip;
	int i;

	if(! ip = query_ip_number(current_ppl)) return "無";
	for(i=0;i<sizeof(all_ppl);i++)
	{
		if(all_ppl[i] == current_ppl) continue;
		temp_ip = query_ip_number(all_ppl[i]);
		if( ip == temp_ip ) return HIC+ip+HIR" [有 Multi-Login 的嫌疑]"NOR;
	}
	return ip;
}

string query_status(object user)
{
	object user_location;
	string msg = "", status1, status2, status3, status4 , status5 = "", ran;
	int idle;

	// 判斷狀態.

	if( user->query_temp("netdead") == 1 )
	{
		user_location = find_object("/obj/void.c");
		idle = 0;
		status4 = HIG"(斷線中)"NOR;
		dead_ppl++;
	}

	if( !user->query_temp("netdead") )
	{
		user_location = environment(user);
		if( userp(user) )
			idle = query_idle(user);
		else idle = 0;
		status4 = "";
	}

	if( in_input(user) )  status1 = NOR""WHT"[輸入]"NOR;
		else  status1 = "";
	if( in_edit(user) ) status2 = NOR""YEL"[編輯]"NOR;
		else status2 = "";
	if( idle > 60 )
		status3 = sprintf( NOR""CYN"(發呆了 %d 分鐘)"NOR, idle/60);
	else status3 = "";
	if( user->query_temp("invis") > 0 )
		status4 = NOR""BLU"[隱形]"NOR;
	if( user->query_temp("hide") > 0 )
		status4 += HBK"(躲藏)"NOR;
	if( user->is_inactive() )
		status4 += NOR""HIW"[閒置]"NOR;
	if( user->query("putjail_position") )
		status4 += HIY" [坐牢中]"NOR;
	if( user->query_temp("killer") )
		status4 += HIR" [殺人犯]"NOR;

	// end.

	msg += sprintf("(%2d) %-12s"NOR" %s(%s) "NOR" %s(%s)\n"NOR,
		j,
		((wizardp(user)) ? HIW : "") + SECURITY_D->get_status(user),
		(string)user->query("name"),
		(string)user->query("id"),
		(user_location) ? (string)user_location->query("short") : HIR"這個人不知道在那裡耶！"NOR,
		(user_location) ? (string)file_name(user_location) : "");

	switch(random(2)) // 加入 random 的空白, 太整齊的列表不好看..:Q
	{
		case 1:
			ran = " ";
			break;
		case 0:
			ran = "";
			break;
	}

	if( !query("qno_ip") ) 
		msg += sprintf("       " + ran + MAG"-> %15s 連線。"NOR, query_ips(users(),user));

	if ( (status1!="") || (status2!="") || (status3!="") || (status4!="") || (status5!="") )
		msg += sprintf(GRN"%s　狀態"NOR"：%s%s%s%s%s\n", 
			((query("qno_ip")) ? ("       " + ran) : ""), status1, status2, status3, status4, status5);
//	else if( status1 == "" && status2 == "" && status3 == "" && status4 == "" )
//		msg += sprintf(HIG" 狀態"NOR"：無。\n");
	else if( !query("qno_ip") ) msg += "\n"NOR;
	return msg;
}

int do_amembers()
{
  object *users,me;
  string str,*list,temp_club_name,temp_club_id;
  int i,ppl_cnt,idle,loop;
  me=this_player();

  for(loop=0;loop<3;loop++)
  {
    switch(loop)
    {
      case 0 : temp_club_id = CLUB_ID_DRAGON;
               temp_club_name = CLUB_NAME_DRAGON;
               break;
      case 1 : temp_club_id = CLUB_ID_SKY;
               temp_club_name = CLUB_NAME_SKY;
               break;
      case 2 : temp_club_id = CLUB_ID_MOON;
               temp_club_name = CLUB_NAME_MOON;
               break;
    }
    users = CLUB_D->find_online_members(temp_club_id);

    str = "◎ "+temp_club_name+": \n";
    str += "─────────────────────────────────────\n";

    users = sort_array(users, "sort_member", this_object());

    ppl_cnt = 0;
    i = sizeof(users);
    while( i-- )
    {
      // Skip those users in login limbo.
      if(!me->visible(users[i]) && wizardp(users[i]) ) continue;
      str = sprintf("%s%12s%-16s %s(%s)",
        str,
        show_level(users[i],temp_club_name,temp_club_id),
        RANK_D->query_level(users[i]),
        users[i]->name(1),
        users[i]->query("id"),
      );
      if(users[i]->query_temp("killer")) str+=HIR" [殺人犯]"NOR;
      idle=query_idle(users[i]);
      if(users[i]->query_temp("invis")) str+=HIB"(隱形)"NOR;
      if(users[i]->query_temp("hide")) str+=HBK"(躲藏)"NOR;
      if(users[i]->query_temp("netdead")) str+=HIG"<斷線中>"NOR;
      if(idle>60) str +=sprintf(HIY" (發呆%d分鐘)"NOR,idle/60);
      str +=sprintf("\n"NOR);
      ppl_cnt++;
    }
    str += "─────────────────────────────────────\n";
    str = sprintf("%s目前共有 %d 位成員在線上.\n", str, ppl_cnt);
    this_player()->start_more(str);
  }
  return 1;
}

string show_level(object user,string temp_club_name1,string temp_club_id1)
{
  int level,rank;
  mapping info;
  string str;
  if(wizardp(user)) return "【榮譽會員】"+temp_club_name1+"特級顧問  ";
  level=user->query("level");
  if(level>100)  str = "【????????】";
  else if(level<11)      str = "【第 "+chinese_number(level)+" 級】";
  else if(level<21)      str = "【第"+chinese_number(level)+"級】";
  else if(level%10==0)   str = "【第"+chinese_number(level)+"級】";
  else str = "【"+chinese_number(level)+"級】";

  info=CLUB_D->query_member_info(temp_club_id1,getuid(user));

  rank=info["level"];
  if(temp_club_id1 == "dragon")
  {
    switch(rank)
    {
      case 6 : str+= temp_club_name1+"龍頭老大  "; break;
      case 5 : str+= temp_club_name1+"副幫主    "; break;
      case 4 : str+= temp_club_name1+"長老      "; break;
      case 3 : str+= temp_club_name1+"超級護法  "; break;
      case 2 : str+= info["info1"]+"分堂主    "; break;
      default :  if(info["info1"]!="無")
                 {
                   str+=info["info1"]+"堂員      "; break;
                 } 
                 else str+= temp_club_name1+"一般幫眾  ";
    }
  }
  else
  {
    switch(rank)
    {
      case 5 : str+= temp_club_name1+"幫主      "; break;
      case 4 : str+= temp_club_name1+"副幫主    "; break;
      case 3 : str+= temp_club_name1+"護法      "; break;
      case 2 : str+= info["info1"]+ "分堂主    "; break;
      default :  if(info["info1"]!="無")
                 {
                   str+=info["info1"]+"堂員      "; break;
                 } 
                 else str+= temp_club_name1+"一般幫眾  ";
    }
  }
  return str;
}

