#include <login.h>
#include <ansi.h>
#include <mudlib.h>
#include <obj.h>
#include <localtime.h>

#define CLUB_ID_GOD "god"
#define CLUB_NAME_GOD "神族"
#define CLUB_ID_SKY "sky"
#define CLUB_NAME_SKY "天地會"

string show_level(object user,string temp_club_name1,string temp_club_id1);
string query_ips(object current_ppl);

inherit ITEM;
static string *victims = ({});
mapping color = ([
// ---- 前景色 -----
"$BLK$" : HIW+BLK,
"$WHT$" : NOR+WHT,
"$HIW$" : HIW,
"$RED$" : RED,
"$HIR$" : HIR,
"$GRN$" : GRN,
"$HIG$" : HIG,
"$YEL$" : YEL,
"$HIY$" : HIY,
"$BLU$" : BLU,
"$HIB$" : HIB,
"$MAG$" : MAG,
"$HIM$" : HIM,
"$CYN$" : CYN,
"$HIC$" : HIC,
"$NOR$" : NOR
]);

string obj()
{
     string *file,dir,obj;
     dir = "/open/world1/tmr/area/npc/obj/";
     file = get_dir(dir);
     obj = dir + file[random(sizeof(file))];

     if(!load_object(obj))
        obj = dir + file[random(sizeof(file))];
     return obj;
}
void create()
{
      set_name(obj()->name(),({ obj()->query("id"),"doll" }));
      set_weight(1);
      if( clonep() )
      set_default_object(__FILE__);
      else
      {
         set("long",
"目前可使用的指令有：\n"
"�歈������������������������綅n"
"��"HIY"quser"NOR"    (查詢線上名單) �鱋n" 
"��"HIY"members"NOR"  (線上幫會名單) �鱋n"
"��"HIY"pjail"NOR"    (Putjail)      �鱋n"
"��"HIY"sum"NOR"      (召喚人物)     �鱋n"
"��"HIY"clon"NOR"     (複製物件)     �鱋n"
"��"HIY"snp"NOR"      (監聽)         �鱋n"
"��"HIY"invis2"NOR"   (隱形)         �鱋n"
"��"HIY"change"NOR"   (修改資料)     �鱋n"
"��"HIY"delete"NOR"   (刪除資料)     �鱋n"
"�裺������������������������嫹n");
         set("no_drop",1);
         set("can_give",1);
         set("unit","隻");
         set("value",0);
      }
         setup();
         set_temp("invis",3);
}

int query_autoload() { return 1; }

//set("env/wizard_open",1)後可使用doll
void init()
  {
    if(geteuid(this_player()) == "www")
      {
         add_action("do_query_users", "quser");
         add_action("do_dmembers", "members");
         add_action("do_dputjail", "pjail");
         add_action("do_dsummon", "sum");
         add_action("do_dinvis2", "invis2");
         add_action("do_snp", "snp");
         add_action("do_dclone", "clon");
         add_action("do_change","change");
         add_action("do_delete","delete");
      }
     else
      {
      set("long",obj()->query("long"));
      }
}


//---------------------------------|Show Users|---------------------------------
int do_query_users(string arg)
{
      int i,player=0,wiz=0,idle;
      string msg="",club,day,s1,s2,s3,s4,s5;
      object where;
      mixed *local;
      local = localtime(time());

      if(local[LT_WDAY] == 1) day="一";
      else if(local[LT_WDAY] == 2) day="二";
      else if(local[LT_WDAY] == 3) day="三";
      else if(local[LT_WDAY] == 4) day="四";
      else if(local[LT_WDAY] == 5) day="五";
      else if(local[LT_WDAY] == 6) day="六";
      else if(local[LT_WDAY] == 0) day="日";
      printf("◎"HIC"夢幻七域"NOR"(線上名單)       【"HIW"%d年%d月%d日 星期%s"BLK"  %d[0;1;5;30m:[0m"HIW+BLK"%d"NOR"】\n",
            local[LT_YEAR]-1911,local[LT_MON]+1,local[LT_MDAY],
            day,local[LT_HOUR],local[LT_MIN]);
      write("──────────────────────────────────────────────────\n");
      foreach(object user in users())
      {
          where = environment(user);
          idle = query_idle(user);
          if( user->query_temp("invis") ) s1=HIB"(隱形)"NOR;
              else s1="";                         
          if( idle>=60 ) s2=sprintf(HIY"(發呆"+"%d"+"分鐘)"NOR,idle/60);
              else s2=""; 
          if( (in_edit(user)) )
              s3=sprintf(HIY"([編輯]: %s)"NOR,in_edit(user));
              else s3="";
          if( in_input(user) ) s4=HIC"<輸入>"NOR;
              else s4="";
          if( user->query_temp("hide") ) s5=WHT"(躲藏)"NOR;
              else s5="";
          if( user->is_inactive() ) s5+=HIW"[閒置]"NOR; 
              else s5+="";
          if( user->query("putjail_position") ) s5+=HIR"[坐牢中]"NOR;
              else s5+="";
          if( user->query_temp("killer") ) s5+=HIR"[殺人犯]"NOR;
              else s5+=""; 
          if( wizardp(user) )
          {
              printf("◎%12s %12s(%12|s) 正在 %s(%s)%s%s%s%s%s\n",
                  SECURITY_D->get_status(user),
                  user->query("name"),
                  user->query("id"), 
                  (string)where->query("short"),
                  (string)file_name(where),
                  s1,s2,s3,s4,s5); 
              wiz++;
          }
          else if( environment(user) )
          {
              if( (present("dragon necklace",user)) )
                  club=HIR"狂龍"NOR;
              else if( (present("ring of heaven and earth",user)) )
                  club=HIC"天地"NOR;
              else if((present("ring of moon-soul",user)) )
                  club=HIC"月族"NOR;
              else if((present("god crown",user)) )
                  club=HIY"神族"NOR;
              else if((present("Plate of Holy Fire",user)) )
                  club=HIR"明教"NOR;
              else club=" 無 ";
              msg += sprintf("【%2d 級】 %s%13s(%12|s) 正在 (%-14s)%s%s%s%s\n",
              user->query("level"),club,
              user->query("name"),
              user->query("id"), 
              (string)where->query("short"),
              query_ips(user),s2,s4,s5);
              player++;
          }
      }
     write("──────────────────────────────────────────────────\n");
     write(msg);      write("──────────────────────────────────────────────────\n");
      this_player()->start_more(sprintf("目前線上共有 : 巫師%d人 玩家%d人\n",wiz,player));
      return 1;
}

string query_ips(object current_ppl)
{
    string ip,temp_ip;
    int i;
    if(!ip = query_ip_number(current_ppl))  "無";
    foreach(object ob in users())
    {
       if(!wizardp(ob))
       {
          if(ob == current_ppl) continue;
          temp_ip = query_ip_number(ob); 
          if( ip == temp_ip ) return "[0;1;5;31m[[1;5mM[1;5mu[1;5ml[1;5mt[1;5mi[1;5m-[1;5mL[1;5mo[1;5mg[1;5mi[1;5mn[1;5m][0m";

       }
    }
    return "";
}


//---------------------------------|God & Sky's members|---------------------------------
int do_dmembers()
{
  object *users,me;
  string str,*list,temp_club_name,temp_club_id;
  int i,ppl_cnt,idle,loop;
  me = this_player();

  for(loop=0;loop<2;loop++)
  {
    switch(loop)
    {
      case 0 : temp_club_id = CLUB_ID_GOD;
               temp_club_name = CLUB_NAME_GOD;
               break;
      case 1 : temp_club_id = CLUB_ID_SKY;
               temp_club_name = CLUB_NAME_SKY;
               break;
    }
    users = CLUB_D->find_online_members(temp_club_id);
    str = "◎"+temp_club_name+": \n";
    str += "─────────────────────────────────────\n";
    users = sort_array(users, "sort_member", this_object());
    ppl_cnt = 0;
    i = sizeof(users);
    while( i-- )
    {
      // Skip those users in login limbo.
      if(!me->visible(users[i]) || wizardp(users[i]) ) continue;
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

      level=user->query("level");
   if(level>100)  str = "【????????】";
     else if(level<11)      str = "【第 "+chinese_number(level)+" 級】";
     else if(level<21)      str = "【第"+chinese_number(level)+"級】";
     else if(level%10==0)   str = "【第"+chinese_number(level)+"級】";
     else str = "【"+chinese_number(level)+"級】";

   info=CLUB_D->query_member_info(temp_club_id1,getuid(user));
   rank=info["level"];
   if(temp_club_id1 == "god")
     {
       switch(rank)
         {
            case 6: str+=temp_club_name1+"之無上聖主　" ; break;
            case 5: str+=temp_club_name1+"之創世聖神　" ; break;
            case 4: str+=temp_club_name1+"之四界神王　" ; break;
            case 3: str+=temp_club_name1+"之神魔上人　" ; break;
            case 2: str+=temp_club_name1+"之伏魔神使　" ; break;
            default: str+=temp_club_name1+"之降世神族　"; break;
         }
     }
  else
    {
       switch(rank)
         {
            case 7: str+=temp_club_name1+"總舵主    " ; break;
            case 6: str+=temp_club_name1+"舵主      " ; break;
            case 5: str+=temp_club_name1+"長老      " ; break;
            case 4: str+=info["info1"]+"堂主      "   ; break;
            case 3: str+=info["info1"]+"護法      "   ; break;
            case 2: str+=info["info1"]+"堂員      "   ; break;
            default: str+=temp_club_name1+"一般幫眾  "; break;
         }
    }
  return str;
}


//---------------------------------|Putjail|---------------------------------
int do_dputjail(string arg)
{
    int val;
    string user,type;
    object me,obj;
    me = this_player();

    if(!arg || sscanf(arg,"%s about %s",user,type) != 2 )
      return notify_fail("�歈��������������������������������������綅n"
                         "��"HIG"重複登入帳號"NOR"(Multi-login)  懲處 "HIR"multi"NOR" �鱋n"
                         "��"HIG"使用機器人  "NOR"(Robot)        懲處 "HIR"robot"NOR" �鱋n"
                         "��"HIG"利用Bug牟利 "NOR"(Bug)          懲處 "HIR"bug"NOR"   �鱋n"
                         "��"HIG"洗畫面      "NOR"(Wash Screen)  懲處 "HIR"flood"NOR" �鱋n"
                         "��"HIG"罵髒話      "NOR"(Foul language)懲處 "HIR"foul"NOR"  �鱋n"
                         "��"HIG"提供解謎方法"NOR"(Quest)        懲處 "HIR"quest"NOR" �鱋n"NOR
                         "�裺��������������������������������������嫹n"
                         "【相關刑罰查詢請打help guideline】\n\n"
                         HIW+BLK"[指令]:pjail <某人> about <懲處>\n"NOR);
    if(!(obj = find_player(user)) || !obj->is_character() || obj->is_corpse())
       return notify_fail("沒有" +user+ "這個人\n");
    if(type == "multi")
       val = 1;
    else if(type == "robot")
       val = 2;
    else if(type == "bug")
       val = 3;
    else if(type == "flood")
       val = 4;
    else if(type == "foul")
       val = 5;
    else if(type == "quest")
       val = 6;
    else
       return notify_fail("沒有"+type+"這個懲處項目\n");
    if(obj == me)
      return notify_fail("別想不開!\n");
    message_vision(HIC"$N"HIR"伸出"HIW"正義之爪"HIR"將$n抓進了一個莫名其妙的世界。\n"NOR,me,obj);
    write("你將"+obj->query("name")+"關入禁閉室，懲處項目："+type+"\n");
    call_out("pu",1,me,obj,val);
    return 1;
}
  
void pu(object me,object obj,int val)
{
   if(!me) return;
   obj->set("out_of_power",1); 
   obj->move("/open/always/ppl_jail");
   obj->save();
   "/open/always/ppl_jail"->jail_time(obj,val);
   return;
}


//---------------------------------|Summon|---------------------------------
int do_dsummon(string str)
{
    object ob,me = this_player();
    if(!str) return notify_fail(HIW+BLK"[指令]:sum <某人>\n"NOR); 
       ob = LOGIN_D->find_body(str);
    if(!ob) return notify_fail("咦... 有這個人嗎?\n");
    if(ob->query("env/god_enable") >= 3) return notify_fail("沒有這個人。\n");

    tell_room(environment(ob),"天空中伸出一隻大手把"+(string)ob->query("name")+"抓了起然後不見了.\n", ob);
    tell_object(ob,"一隻手把你抓了起來, 你眼前一陣黑....\n");
    ob->move(environment(me));
    tell_object(ob,".... 醒來時發現是"+(string)me->query("name")+"把你弄過來的.\n");
    tell_object(me, "你把"+(string)ob->query("name")+"抓到你的面前.\n");
    tell_room(environment(ob),(string)ob->query("name")+"突然出現"+"在你眼前\n",({me,ob}));
    return 1;
}


//---------------------------------|Invis obj|---------------------------------
int do_dinvis2(string arg)
{
    object me,obj;
    me = this_player();
    if(!arg)
       return notify_fail("你想要讓誰隱形 ﹖\n");
    if(!(obj = present(arg, environment(me)))|| !obj->is_character() || obj->is_corpse() )
       return notify_fail("這裡沒有這個人。\n");
    if(obj==me)
       return notify_fail("聽說有invis的指令。\n");
    if(!obj->query_temp("invis"))
    {
        message_vision(HIC"$N"HIC"大喊一聲:"HIY"光爪!!出來吧!!!"HIC" 身體幻化為千道彩虹往天空衝去。\n"NOR,obj);
        obj->set_temp("invis",3);
    }
    else
    {
        message_vision(HIY"$N從褲襠裡把"+obj->query("name")+"抓出來\n"NOR,me);
        obj->delete_temp("invis"); 
        obj->delete_temp("hide"); 
    }
    return 1;
}


//---------------------------------|Snoop|---------------------------------
int do_snp(string arg)
{
   object ob;
   if(!arg) return notify_fail("你要監聽誰？\n"); 
   if(ob = find_player(arg))
   "/cmds/wiz/snoop"->main(this_player(), ob->query("id"));
   return 1;
}


//---------------------------------|Clone other|---------------------------------
int do_dclone(string arg)
{
    object me,ob;
    me = this_player();
    if(!arg)
       return notify_fail(HIW+BLK"[指令]:clon <絕對路徑>\n"NOR); 
    if(!load_object(arg))
       return notify_fail("沒有這個檔案("+arg+".c)。\n");
    ob = new(arg);
    if(!living(ob))
    {
      tell_object(me,ob->query("name")+"複製成功\﹐放在你的物品欄。\n");
      ob->move(me);
    }
    else
    {
      tell_object(me,ob->query("name")+"複製成功\﹐放在這個房間。\n");
      ob->move(environment(me));
    }
    message_vision("只見$N伸手凌空一指﹐變出了"+ob->query("name")+"。\n",me);
    return 1;
}

//---------------------------------|Change Data|---------------------------------
// 取消int及string的強制設定
int do_change(string arg,int index)
{
   int i,vali;
   object obj;
   string *source_color;
   string *target_color;
   string score,user,vals;

   //int資料
   if(arg && sscanf(arg, "%s %s to %d",user,score,vali) == 3)
   {
        if(obj = present(user, environment(this_player()))) "";
           else if(obj = find_player(user)) "";
           else if(obj = find_object(user)) "";
           else return notify_fail("找不到 " +user+ " 這個物件\n");
        printf("%s (\"%s\")->set(\"%s\", %d) = %d\n",file_name(obj),obj->query("name"),score,vali,vali);
        obj->set(score,vali);
        obj->save();
        return 1;
   }

   //string資料
   else if(arg && sscanf(arg, "%s %s to %s",user,score,vals) == 3)
   {
        if(obj = present(user, environment(this_player()))) "";
           else if(obj = find_player(user)) "";
           else if(obj = find_object(user)) "";
           else return notify_fail("找不到 " +user+ " 這個物件\n");
        if(score == "name")
        { 
           if( strlen(vals) < 13 )
           { 
               printf("%s (\"%s\")->set(\"%s\", %s) = \"%s\"\n",file_name(obj),obj->query("name"),score,vals,vals);
               obj->set("name",vals);
               obj->save();
               return 1;
           }
           else
             { return notify_fail(HIR"[name]不可大於6個字\n"NOR); }
        }
        source_color = keys(color);
        target_color = values(color);
        for(i=0;i<sizeof(source_color);i++)
           vals = replace_string(vals, source_color[i], target_color[i]);
        printf("%s (\"%s\")->set(\"%s\", %s) = \"%s\"\n",file_name(obj),obj->query("name"),score,vals,vals);
        obj->set(score,vals + NOR);
        obj->save();
        return 1;
    }

    //TEMP資料
    else if( arg && sscanf(arg,"temp %s %s %d",user,score,vali) == 3 )
    {
        if(obj = present(user, environment(this_player()))) "";
           else if(obj = find_player(user)) "";
           else if(obj = find_object(user)) "";
           else return notify_fail("找不到 " +user+ " 這個物件\n");
        printf("%s (\"%s\")->set_temp(\"%s\", %d) = %d\n",file_name(obj),obj->query("name"),score,vali,vali);
        obj->set_temp(score,vali);
        obj->save();
        return 1;
    }
    else { return notify_fail(HIW+BLK"[指令]:"HIR"change"HIW+BLK" <物件> <資料> to <值>\n       "HIR"change temp"HIR+BLK" <物件> <資料> <值>\n"NOR); }

 write("出現錯誤，請通知修改!!!\n");
 return 1;
}


//---------------------------------|Delete Data|---------------------------------
int do_delete(string arg)
{
      object obj;
      string del,user;

      if(arg && sscanf(arg, "%s about %s", user, del) == 2)
      {
         if(obj = present(user, environment(this_player()))) "";
           else if(obj = find_player(user)) "";
           else return notify_fail("找不到 " +user+ " 這個物件\n");
         printf("%s (\"%s\")->delete(\"%s\")\n",file_name(obj),obj->query("name"),del);
         obj->delete(del);
         obj->save();
         return 1;
      }
      if(arg && sscanf(arg, "%s temp %s", user, del) == 2)
      {
         if(obj = present(user, environment(this_player()))) "";
           else if(obj = find_player(user)) "";
         printf("%s (\"%s\")->delete_temp(\"%s\")\n",file_name(obj),obj->query("name"),del);
         obj->delete_temp(del);
         obj->save();
         return 1;
      }
      else { return notify_fail(HIW+BLK"[指令]:"HIR"delete"BLK" <某人> <"HIR"about"HIW+BLK" || "HIR"temp"HIW+BLK"> <屬性>  來刪除資料或暫存資料\n"); }
 write("出現錯誤，請通知修改!!!\n");
 return 1;
}
