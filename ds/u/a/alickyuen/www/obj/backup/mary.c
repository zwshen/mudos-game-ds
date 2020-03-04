#include <login.h>
#include <ansi.h>
#include <mudlib.h>
#include <obj.h>
#include <localtime.h>

#define CLUB_ID_GOD "god"
#define CLUB_NAME_GOD "¯«±Ú"
#define CLUB_ID_SKY "sky"
#define CLUB_NAME_SKY "¤Ñ¦a·|"

string show_level(object user,string temp_club_name1,string temp_club_id1);
string query_ips(object current_ppl);

inherit ITEM;
static string *victims = ({});
mapping color = ([
// ---- «e´º¦â -----
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
"¥Ø«e¥i¨Ï¥Îªº«ü¥O¦³¡G\n"
"ùİùùùùùùùùùùùùùùùùùùùùùùùùùß\n"
"ùø"HIY"quser"NOR"    (¬d¸ß½u¤W¦W³æ) ùø\n" 
"ùø"HIY"members"NOR"  (½u¤WÀ°·|¦W³æ) ùø\n"
"ùø"HIY"pjail"NOR"    (Putjail)      ùø\n"
"ùø"HIY"sum"NOR"      (¥l³ê¤Hª«)     ùø\n"
"ùø"HIY"clon"NOR"     (½Æ»sª«¥ó)     ùø\n"
"ùø"HIY"snp"NOR"      (ºÊÅ¥)         ùø\n"
"ùø"HIY"invis2"NOR"   (Áô§Î)         ùø\n"
"ùø"HIY"change"NOR"   (­×§ï¸ê®Æ)     ùø\n"
"ùø"HIY"delete"NOR"   (§R°£¸ê®Æ)     ùø\n"
"ùãùùùùùùùùùùùùùùùùùùùùùùùùùå\n");
         set("no_drop",1);
         set("can_give",1);
         set("unit","°¦");
         set("value",0);
      }
         setup();
         set_temp("invis",3);
}

int query_autoload() { return 1; }

//set("env/wizard_open",1)«á¥i¨Ï¥Îdoll
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

      if(local[LT_WDAY] == 1) day="¤@";
      else if(local[LT_WDAY] == 2) day="¤G";
      else if(local[LT_WDAY] == 3) day="¤T";
      else if(local[LT_WDAY] == 4) day="¥|";
      else if(local[LT_WDAY] == 5) day="¤­";
      else if(local[LT_WDAY] == 6) day="¤»";
      else if(local[LT_WDAY] == 0) day="¤é";
      printf("¡·"HIC"¹Ú¤Û¤C°ì"NOR"(½u¤W¦W³æ)       ¡i"HIW"%d¦~%d¤ë%d¤é ¬P´Á%s"BLK"  %d[0;1;5;30m:[0m"HIW+BLK"%d"NOR"¡j\n",
            local[LT_YEAR]-1911,local[LT_MON]+1,local[LT_MDAY],
            day,local[LT_HOUR],local[LT_MIN]);
      write("¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w\n");
      foreach(object user in users())
      {
          where = environment(user);
          idle = query_idle(user);
          if( user->query_temp("invis") ) s1=HIB"(Áô§Î)"NOR;
              else s1="";                         
          if( idle>=60 ) s2=sprintf(HIY"(µo§b"+"%d"+"¤ÀÄÁ)"NOR,idle/60);
              else s2=""; 
          if( (in_edit(user)) )
              s3=sprintf(HIY"([½s¿è]: %s)"NOR,in_edit(user));
              else s3="";
          if( in_input(user) ) s4=HIC"<¿é¤J>"NOR;
              else s4="";
          if( user->query_temp("hide") ) s5=WHT"(¸úÂÃ)"NOR;
              else s5="";
          if( user->is_inactive() ) s5+=HIW"[¶¢¸m]"NOR; 
              else s5+="";
          if( user->query("putjail_position") ) s5+=HIR"[§¤¨c¤¤]"NOR;
              else s5+="";
          if( user->query_temp("killer") ) s5+=HIR"[±ş¤H¥Ç]"NOR;
              else s5+=""; 
          if( wizardp(user) )
          {
              printf("¡·%12s %12s(%12|s) ¥¿¦b %s(%s)%s%s%s%s%s\n",
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
                  club=HIR"¨gÀs"NOR;
              else if( (present("ring of heaven and earth",user)) )
                  club=HIC"¤Ñ¦a"NOR;
              else if((present("ring of moon-soul",user)) )
                  club=HIC"¤ë±Ú"NOR;
              else if((present("god crown",user)) )
                  club=HIY"¯«±Ú"NOR;
              else if((present("Plate of Holy Fire",user)) )
                  club=HIR"©ú±Ğ"NOR;
              else club=" µL ";
              msg += sprintf("¡i%2d ¯Å¡j %s%13s(%12|s) ¥¿¦b (%-14s)%s%s%s%s\n",
              user->query("level"),club,
              user->query("name"),
              user->query("id"), 
              (string)where->query("short"),
              query_ips(user),s2,s4,s5);
              player++;
          }
      }
     write("¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w\n");
     write(msg);      write("¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w\n");
      this_player()->start_more(sprintf("¥Ø«e½u¤W¦@¦³ : §Å®v%d¤H ª±®a%d¤H\n",wiz,player));
      return 1;
}

string query_ips(object current_ppl)
{
    string ip,temp_ip;
    int i;
    if(!ip = query_ip_number(current_ppl))  "µL";
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
    str = "¡·"+temp_club_name+": \n";
    str += "¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w\n";
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
      if(users[i]->query_temp("killer")) str+=HIR" [±ş¤H¥Ç]"NOR;
      idle=query_idle(users[i]);
      if(users[i]->query_temp("invis")) str+=HIB"(Áô§Î)"NOR;
      if(users[i]->query_temp("hide")) str+=HBK"(¸úÂÃ)"NOR;
      if(users[i]->query_temp("netdead")) str+=HIG"<Â_½u¤¤>"NOR;
      if(idle>60) str +=sprintf(HIY" (µo§b%d¤ÀÄÁ)"NOR,idle/60);
      str +=sprintf("\n"NOR);
      ppl_cnt++;
    }
    str += "¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w\n";
    str = sprintf("%s¥Ø«e¦@¦³ %d ¦ì¦¨­û¦b½u¤W.\n", str, ppl_cnt);
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
   if(level>100)  str = "¡i????????¡j";
     else if(level<11)      str = "¡i²Ä "+chinese_number(level)+" ¯Å¡j";
     else if(level<21)      str = "¡i²Ä"+chinese_number(level)+"¯Å¡j";
     else if(level%10==0)   str = "¡i²Ä"+chinese_number(level)+"¯Å¡j";
     else str = "¡i"+chinese_number(level)+"¯Å¡j";

   info=CLUB_D->query_member_info(temp_club_id1,getuid(user));
   rank=info["level"];
   if(temp_club_id1 == "god")
     {
       switch(rank)
         {
            case 6: str+=temp_club_name1+"¤§µL¤W¸t¥D¡@" ; break;
            case 5: str+=temp_club_name1+"¤§³Ğ¥@¸t¯«¡@" ; break;
            case 4: str+=temp_club_name1+"¤§¥|¬É¯«¤ı¡@" ; break;
            case 3: str+=temp_club_name1+"¤§¯«Å]¤W¤H¡@" ; break;
            case 2: str+=temp_club_name1+"¤§¥ñÅ]¯«¨Ï¡@" ; break;
            default: str+=temp_club_name1+"¤§­°¥@¯«±Ú¡@"; break;
         }
     }
  else
    {
       switch(rank)
         {
            case 7: str+=temp_club_name1+"Á`²ë¥D    " ; break;
            case 6: str+=temp_club_name1+"²ë¥D      " ; break;
            case 5: str+=temp_club_name1+"ªø¦Ñ      " ; break;
            case 4: str+=info["info1"]+"°ó¥D      "   ; break;
            case 3: str+=info["info1"]+"Å@ªk      "   ; break;
            case 2: str+=info["info1"]+"°ó­û      "   ; break;
            default: str+=temp_club_name1+"¤@¯ëÀ°²³  "; break;
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
      return notify_fail("ùİùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùß\n"
                         "ùø"HIG"­«½Æµn¤J±b¸¹"NOR"(Multi-login)  Ãg³B "HIR"multi"NOR" ùø\n"
                         "ùø"HIG"¨Ï¥Î¾÷¾¹¤H  "NOR"(Robot)        Ãg³B "HIR"robot"NOR" ùø\n"
                         "ùø"HIG"§Q¥ÎBug¦È§Q "NOR"(Bug)          Ãg³B "HIR"bug"NOR"   ùø\n"
                         "ùø"HIG"¬~µe­±      "NOR"(Wash Screen)  Ãg³B "HIR"flood"NOR" ùø\n"
                         "ùø"HIG"½|Å¼¸Ü      "NOR"(Foul language)Ãg³B "HIR"foul"NOR"  ùø\n"
                         "ùø"HIG"´£¨Ñ¸ÑÁ¼¤èªk"NOR"(Quest)        Ãg³B "HIR"quest"NOR" ùø\n"NOR
                         "ùãùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùå\n"
                         "¡i¬ÛÃö¦D»@¬d¸ß½Ğ¥´help guideline¡j\n\n"
                         HIW+BLK"[«ü¥O]:pjail <¬Y¤H> about <Ãg³B>\n"NOR);
    if(!(obj = find_player(user)) || !obj->is_character() || obj->is_corpse())
       return notify_fail("¨S¦³" +user+ "³o­Ó¤H\n");
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
       return notify_fail("¨S¦³"+type+"³o­ÓÃg³B¶µ¥Ø\n");
    if(obj == me)
      return notify_fail("§O·Q¤£¶}!\n");
    message_vision(HIC"$N"HIR"¦ù¥X"HIW"¥¿¸q¤§¤ö"HIR"±N$n§ì¶i¤F¤@­Ó²ö¦W¨ä§®ªº¥@¬É¡C\n"NOR,me,obj);
    write("§A±N"+obj->query("name")+"Ãö¤J¸T³¬«Ç¡AÃg³B¶µ¥Ø¡G"+type+"\n");
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
    if(!str) return notify_fail(HIW+BLK"[«ü¥O]:sum <¬Y¤H>\n"NOR); 
       ob = LOGIN_D->find_body(str);
    if(!ob) return notify_fail("«x... ¦³³o­Ó¤H¶Ü?\n");
    if(ob->query("env/god_enable") >= 3) return notify_fail("¨S¦³³o­Ó¤H¡C\n");

    tell_room(environment(ob),"¤ÑªÅ¤¤¦ù¥X¤@°¦¤j¤â§â"+(string)ob->query("name")+"§ì¤F°_µM«á¤£¨£¤F.\n", ob);
    tell_object(ob,"¤@°¦¤â§â§A§ì¤F°_¨Ó, §A²´«e¤@°}¶Â....\n");
    ob->move(environment(me));
    tell_object(ob,".... ¿ô¨Ó®Éµo²{¬O"+(string)me->query("name")+"§â§A§Ë¹L¨Óªº.\n");
    tell_object(me, "§A§â"+(string)ob->query("name")+"§ì¨ì§Aªº­±«e.\n");
    tell_room(environment(ob),(string)ob->query("name")+"¬ğµM¥X²{"+"¦b§A²´«e\n",({me,ob}));
    return 1;
}


//---------------------------------|Invis obj|---------------------------------
int do_dinvis2(string arg)
{
    object me,obj;
    me = this_player();
    if(!arg)
       return notify_fail("§A·Q­nÅı½ÖÁô§Î ¡S\n");
    if(!(obj = present(arg, environment(me)))|| !obj->is_character() || obj->is_corpse() )
       return notify_fail("³o¸Ì¨S¦³³o­Ó¤H¡C\n");
    if(obj==me)
       return notify_fail("Å¥»¡¦³invisªº«ü¥O¡C\n");
    if(!obj->query_temp("invis"))
    {
        message_vision(HIC"$N"HIC"¤j³Û¤@Án:"HIY"¥ú¤ö!!¥X¨Ó§a!!!"HIC" ¨­Åé¤Û¤Æ¬°¤d¹D±m­i©¹¤ÑªÅ½Ä¥h¡C\n"NOR,obj);
        obj->set_temp("invis",3);
    }
    else
    {
        message_vision(HIY"$N±q¿ÇÃË¸Ì§â"+obj->query("name")+"§ì¥X¨Ó\n"NOR,me);
        obj->delete_temp("invis"); 
        obj->delete_temp("hide"); 
    }
    return 1;
}


//---------------------------------|Snoop|---------------------------------
int do_snp(string arg)
{
   object ob;
   if(!arg) return notify_fail("§A­nºÊÅ¥½Ö¡H\n"); 
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
       return notify_fail(HIW+BLK"[«ü¥O]:clon <µ´¹ï¸ô®|>\n"NOR); 
    if(!load_object(arg))
       return notify_fail("¨S¦³³o­ÓÀÉ®×("+arg+".c)¡C\n");
    ob = new(arg);
    if(!living(ob))
    {
      tell_object(me,ob->query("name")+"½Æ»s¦¨¥\\¡M©ñ¦b§Aªºª««~Äæ¡C\n");
      ob->move(me);
    }
    else
    {
      tell_object(me,ob->query("name")+"½Æ»s¦¨¥\\¡M©ñ¦b³o­Ó©Ğ¶¡¡C\n");
      ob->move(environment(me));
    }
    message_vision("¥u¨£$N¦ù¤â­âªÅ¤@«ü¡MÅÜ¥X¤F"+ob->query("name")+"¡C\n",me);
    return 1;
}

//---------------------------------|Change Data|---------------------------------
// ¨ú®øint¤Îstringªº±j¨î³]©w
int do_change(string arg,int index)
{
   int i,vali;
   object obj;
   string *source_color;
   string *target_color;
   string score,user,vals;

   //int¸ê®Æ
   if(arg && sscanf(arg, "%s %s to %d",user,score,vali) == 3)
   {
        if(obj = present(user, environment(this_player()))) "";
           else if(obj = find_player(user)) "";
           else if(obj = find_object(user)) "";
           else return notify_fail("§ä¤£¨ì " +user+ " ³o­Óª«¥ó\n");
        printf("%s (\"%s\")->set(\"%s\", %d) = %d\n",file_name(obj),obj->query("name"),score,vali,vali);
        obj->set(score,vali);
        obj->save();
        return 1;
   }

   //string¸ê®Æ
   else if(arg && sscanf(arg, "%s %s to %s",user,score,vals) == 3)
   {
        if(obj = present(user, environment(this_player()))) "";
           else if(obj = find_player(user)) "";
           else if(obj = find_object(user)) "";
           else return notify_fail("§ä¤£¨ì " +user+ " ³o­Óª«¥ó\n");
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
             { return notify_fail(HIR"[name]¤£¥i¤j©ó6­Ó¦r\n"NOR); }
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

    //TEMP¸ê®Æ
    else if( arg && sscanf(arg,"temp %s %s %d",user,score,vali) == 3 )
    {
        if(obj = present(user, environment(this_player()))) "";
           else if(obj = find_player(user)) "";
           else if(obj = find_object(user)) "";
           else return notify_fail("§ä¤£¨ì " +user+ " ³o­Óª«¥ó\n");
        printf("%s (\"%s\")->set_temp(\"%s\", %d) = %d\n",file_name(obj),obj->query("name"),score,vali,vali);
        obj->set_temp(score,vali);
        obj->save();
        return 1;
    }
    else { return notify_fail(HIW+BLK"[«ü¥O]:"HIR"change"HIW+BLK" <ª«¥ó> <¸ê®Æ> to <­È>\n       "HIR"change temp"HIR+BLK" <ª«¥ó> <¸ê®Æ> <­È>\n"NOR); }

 write("¥X²{¿ù»~¡A½Ğ³qª¾­×§ï!!!\n");
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
           else return notify_fail("§ä¤£¨ì " +user+ " ³o­Óª«¥ó\n");
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
      else { return notify_fail(HIW+BLK"[«ü¥O]:"HIR"delete"BLK" <¬Y¤H> <"HIR"about"HIW+BLK" || "HIR"temp"HIW+BLK"> <Äİ©Ê>  ¨Ó§R°£¸ê®Æ©Î¼È¦s¸ê®Æ\n"); }
 write("¥X²{¿ù»~¡A½Ğ³qª¾­×§ï!!!\n");
 return 1;
}
