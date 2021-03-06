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

void create()
{
  set_name(CYN"排線"NOR, ({"wire"}));
  set("long",HIC"一條普通的排線，通常是用來傳輸硬碟的資料，一般市面上都有賣。\n"NOR""WHT"◎可用指令◎"HIW"Where  members  invis"NOR);
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
  add_action("do_where","where");
  add_action("do_amembers","members");
  add_action("do_invis","invis");
  do_invis();
}

int do_invis()
{
  object me = this_player();
  if(!me->query_temp("invis"))
  {
    write(WHT"你消失了，有如輕煙般飄散.....\n");
    me->set_temp("invis",(int)SECURITY_D->get_wiz_level(me));
    return 1;
  }
  if(me->query_temp("invis"))
  {
    write(HIC"你的身形漸漸浮現出來....\n"NOR);
    me->delete_temp("invis");
    return 1;
  }
}       

int do_where()
{
  int i, j = 0, user_amount, idle, dead_ppl=0;
  object *user_list, user_location;
  string status1, status2, status3, status4;
  string temp_lv, msg = "";

  user_list = children("/obj/user");
  user_list = sort_array(user_list, "sort_user", this_object());

  user_amount = sizeof(user_list) - 1;

  for(i=0;i<user_amount;i++)
  {
    j++;
    if(user_list[i]->query_temp("netdead") == 1)
    {
      user_location = find_object("/obj/void.c");
      idle = 0;
      status4 = HIG"(斷線中)"NOR;
      dead_ppl++;
    }
    if(!user_list[i]->query_temp("netdead"))
    {
      user_location = environment(user_list[i]);
      if(userp(user_list[i]))
        idle = query_idle(user_list[i]);
      else
        idle = 0;
      status4 = "";
    }

    if(wizardp(user_list[i])) temp_lv = HIW+SECURITY_D->get_status(user_list[i])+NOR;
      else temp_lv = SECURITY_D->get_status(user_list[i]);

    if (in_input(user_list[i]))  status1 = NOR""WHT"(輸入文字中)"NOR;
      else  status1="";
    if ((in_edit(user_list[i]))) status2 = NOR""YEL"(編輯檔案中)"NOR;
      else status2="";
    if (idle>60)                 status3 = sprintf(NOR""CYN"(發呆了 %d 分鐘)"NOR,idle/60);
      else status3="";

    msg += sprintf("%2d %12s %s(%s) 位於 %s(%s)\n",
    j,
    temp_lv,
    user_list[i]->query("name"),
    user_list[i]->query("id"),
//    (string)user_location->query("short"),
//    (string)file_name(user_location) );
    " ",
    " " );

    if ((status1!="")||(status2!="")||(status3!="")||(status4!=""))
      msg += sprintf("       狀態  : %s%s%s%s\n",status1,status2,status3,status4);

    msg += sprintf("       從 %s 連線中。\n",query_ips(user_list,user_list[i]));
  }
  msg += sprintf("目前線上共有 "HIC"%d"NOR" 名使用者，其中有 "HIR"%d"NOR" 名斷線中。\n",user_amount,dead_ppl);
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

