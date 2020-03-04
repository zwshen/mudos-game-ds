#include <ansi.h>
inherit "/feature/autoload.c";
inherit ITEM;
int do_set_npc(string arg);
int do_set_npc_long(string arg);
int do_set_chat_speed(string arg);
int do_add_chat(string arg);
int do_del_chat(string arg);
string Skill = "unarmed";
int do_make_npc();
int do_show_all_npc();
int Age=14,Lv = 1,ChatSpeed=10,Check = 1,Wimpy = 0;
string Name = "¤h§L";
string Id = "noname";
string Attitude ="";
string Gender="¨k©m";
string Race ="¤HÃþ";
string Long = "";
string NickName = "";
string Title = "";
string ChatBuffer=({}),Pursuer="";
void create()
{
     set_name(HIC"NPC"HIB"»s³y¾÷"NOR, ({ "npc maker", "maker" }) );
     set("long","½Ð¥´ < help_npcmaker > ¬Ý»¡©ú¡C\n");
     set("unit", "­Ó" );
     set("team_cwd","/u/e/eeman/npc/");//¦s©ñªº¥Ø¿ý
}
void init()
{
        seteuid(getuid(this_player()));
        add_action("check_command","");
}
int check_command(string arg)
{
        string verb;
        mapping can_command = ([
                "make_npc"         : "³Ð³y¤@°¦¥Íª«",
                "mn"               : 1,
                "set_npc"          : "³]©w°ò¥»ÄÝ©Ê,½Ð [help_set_npc]",
                "sn"               : 1,
                "set_npc_long"     : "³]©w¥Íª«¦b³QÆ[¬Ý®Éªº±Ô­z",
                "snl"              : 1,
                "set_chat_speed"   : "³]©w»¡¸Ü³t«×¶V¤p»¡¸Ü¶VºC",
                "scs"              : 1,
                "add_chat"         : "¼W¥[¤@­Ó°Ê§@,¨Ò¦padd_chat say §Ú¬Oxx",
                "ac"               : 1,
               "del_chat"         : "§R°£¤@­Ó°Ê§@",
                "help_npcmaker"    : 1,
                "help_set_npc"     : 1,
                "looknpc"          : "¥i¥H¬Ý§A¤w¸g³]©w¤F¤°»ò",
                "call_npc"         : "¥s¥X¤w§¹¦¨ªº¥Íª«-¥¼§¹¦¨-",
                "del_npc"          : "¥Ã»·²M°£¤w§¹¦¨ªº¥Íª«(´N¬O³sÀÉ¤@°_²M°£)",
                "dest_npc"         : "§â³o­Ó©Ð¶¡¤¤ªº¥Íª«²M±¼(dest_npc id)",
                "npclist"          : "¬d¬Ý§A¤w¸g³Ð³y¤F¦h¤Ö¥Íª«",
        ]);
        if (!query("team_cwd")) return notify_fail("³o­Ó"+ name() +"¨S¦³¦ù½ÐµLª;
        verb = query_verb();
        if (!can_command[verb]) return 0;
        else if (verb=="make_npc"   || verb=="mn") return do_make_npc();
        else if (verb=="set_npc"    || verb=="sn") return do_set_npc(arg);
        else if (verb=="set_npc_long" || verb=="sl") return do_set_npc_long(arg;
        else if (verb=="add_chat"   || verb=="ac") return do_add_chat(arg);
        else if (verb=="set_chat_speed"   || verb=="scs") return do_set_chat_sp;
        else if (verb=="dest_npc"){
                object ob;
                if (!arg) return 0;
                if (!ob = present(arg,environment(this_player())))
                   return notify_fail("§A­n²M°£½Ö¡S\n");
                if (ob->query("player_npc")!=query("team_cwd"))
                   return notify_fail("§A¤£¯à²M°£³o­Ó¥Íª«.\n");
                seteuid(getuid());
                destruct(ob);
                return notify_fail("²M°£ok.\n");
        }else if (verb=="looknpc"){
printf("³o­Ó¥¼¥X¥Íªº¥Íª«ªº³]©w¦³:\nµ¥¯Å(lv):%d.\n¦W¦r(name):%s.\nid:%s.\ntitle:;
                 return 1;
        }else if (verb=="help_npcmaker"){
          int i;
          string *help;
          arg ="";
          help = keys(can_command);
          for (i=0;i < sizeof(can_command);i++){
              if (intp(can_command[help[i]])) continue;
              if (help[i]=="help_set_room") continue;
              arg += sprintf("%-13s %s¡C\n",help[i],can_command[help[i]]);
          }
          write(arg);
          return 1;
        }else if (verb=="help_set_npc"){
                 arg=@TEXT
§A¥i¥H³]©wªº¦³:
age          (¦~ÄÖ)
attitude        (ÄÝ©Ê  ³]¬° aggressive ·|¦Û°Ê§ðÀ»¤H)
lv              (µ¥¯Å¥Ñ1¨ì100).
name            (¦W¦r).
id              (­^¤å¦W¦r).
title           (ºÙ¸¹).
nickname        (°ÎºÙ).
skill           (§Þ¯à).
race            (ºØ±Ú  ²{¦b¥u¦³¤HÃþ¸ò³¥Ã~¨âºØ).
gender          (©Ê§O  ¨k©Ê,¤k©Ê,¶¯©Ê,»Û©Ê,µ¥).
money none      (³o­Ó¥Íª«¨S¦³¿ú  ¦p°Êª«..µ¥µ¥).
pursuer YES     (³o­Ó¥Íª«·|°l±þ¤H).
wimpy      (³o­Ó¥Íª«·í¼g­°¨ì¦h¤Ö®É·|°k¶]).
TEXT;
                 write(arg);
                 return 1;
        }else if (verb=="npclist"){
                 return do_show_all_npc();
        }else if (verb=="del_npc"){
                 object ob;
                 if (!arg) return 0;
                 if (!ob = present(arg,environment(this_player()))){
                    if ( sscanf(arg,"%*s.c") != 1 ) arg += ".c";
                    if (file_size(query("team_cwd")+arg) < 0) return notify_fai;
                    if (!ob = load_object(query("team_cwd")+arg)) return notify;
                 }
                 if (ob->query("player_npc")!=query("team_cwd"))
                    return notify_fail("§A¤£¯à§R°£³o­Ó¥Íª«.\n");
                 seteuid(getuid());
                 destruct(ob);
                 rm(query("team_cwd")+arg);
                 return notify_fail("²M°£ÀÉ®×"+arg+"ok.\n");
        }else if (verb=="call_npc"){
                 object ob;
                 if (!arg) return 0;
                 if ( sscanf(arg,"%*s.c") != 1 ) arg += ".c";
                 if (file_size(query("team_cwd")+arg) < 0) return notify_fail(";
                 if (!ob = new(query("team_cwd")+arg)) return notify_fail(arg +;
                 if (ob->query("player_npc")!=query("team_cwd"))
                    return notify_fail("§A¤£¯à°½¨ú§O¤Hªº¥Íª«.\n");
                 ob->move(environment(this_player()));
                 return 1;
        }
}
int do_make_npc()
{
        string code,file,dir;

        dir = resolve_path(query("team_cwd"), 0);
        file = sprintf(dir+"npc%d.c",sizeof(get_dir(dir, -1)));
        code = @NPC_CODE
inherit NPC;
void create()
{
NPC_CODE;
        code += sprintf("\tset(%cplayer_npc%c,%c%s%c);\n",34,34,34,query("team_;
        code += sprintf("\tset_name(%c%s%c,({%c%s%c}));\n",34,Name,34,34,Id,34);
        code += sprintf("\tset(%cage%c,%d);\n",34,34,Age);
        if (Race!="¤HÃþ") code += sprintf("\tset(%crace%c,%c%s%c);\n",34,34,34,;
        if (Wimpy!=0) code += sprintf("\tset(%cenv/wimpy%c,%d);\n",34,34,Wimpy);
        if (Long!="") code += sprintf("\tset(%clong%c,@LONG\n%s\nLONG\n\t);\n",;
        if (Attitude!="") code += sprintf("\tset(%cattitude%c,%c%s%c);\n",34,34;
        if (Pursuer!="")  code += sprintf("\tset(%cpursuer%c,1);\n",34,34);
        if (NickName!="") code += sprintf("\tset(%cnickname%c,%c%s%c);\n",34,34;
        if (Title!="") code += sprintf("\tset(%ctitle%c,%c%s%c);\n",34,34,34,Ti;
        if (sizeof(ChatBuffer)){
           int i;
           code += sprintf("\tset(%cchat_chance%c,%d);\n",34,34,ChatSpeed);
           code += sprintf("\tset(%cchat_msg%c,({\n",34,34);
        string code,file,dir;

        dir = resolve_path(query("team_cwd"), 0);
        file = sprintf(dir+"npc%d.c",sizeof(get_dir(dir, -1)));
        code = @NPC_CODE
inherit NPC;
void create()
{
NPC_CODE;
        code += sprintf("\tset(%cplayer_npc%c,%c%s%c);\n",34,34,34,query("team_;
        code += sprintf("\tset_name(%c%s%c,({%c%s%c}));\n",34,Name,34,34,Id,34);
        code += sprintf("\tset(%cage%c,%d);\n",34,34,Age);
        if (Race!="¤HÃþ") code += sprintf("\tset(%crace%c,%c%s%c);\n",34,34,34,;
        if (Wimpy!=0) code += sprintf("\tset(%cenv/wimpy%c,%d);\n",34,34,Wimpy);
        if (Long!="") code += sprintf("\tset(%clong%c,@LONG\n%s\nLONG\n\t);\n",;
        if (Attitude!="") code += sprintf("\tset(%cattitude%c,%c%s%c);\n",34,34;
        if (Pursuer!="")  code += sprintf("\tset(%cpursuer%c,1);\n",34,34);
        if (NickName!="") code += sprintf("\tset(%cnickname%c,%c%s%c);\n",34,34;
        if (Title!="") code += sprintf("\tset(%ctitle%c,%c%s%c);\n",34,34,34,Ti;
        if (sizeof(ChatBuffer)){
           int i;
           code += sprintf("\tset(%cchat_chance%c,%d);\n",34,34,ChatSpeed);
           code += sprintf("\tset(%cchat_msg%c,({\n",34,34);
           for (i=0; i < sizeof(ChatBuffer); i++){
               code += sprintf("\t    (: command,%c%s%c :),\n",34,ChatBuffer[i];
           }
           code += "\t}) );\n";
        }
        code += "\tsetup();\n";
        if (Check)
           code += sprintf("\tadd_money(\"silver\",%d);\n",Lv);
        code += "}\n";
        if (!write_file(file,code,1) ) return notify_fail("¼g¤JÀÉ®×¥¢±Ñ¡C\n");
message_vision(HIR"\n¤h§L"HIW"»¡¹D¡G¥D¤½¡A¦³¨Æ½Ð§h©J¡C\n"NOR,this_player());
        "/cmds/wiz/clone.c"->main(this_player(),file);
        Lv = 1;
        Age = random(60)+14;
        Attitude = "";
  Name="¤h§L";
        Id = "noname";
        Long = "";
        NickName = "";
        Title = "";
        ChatSpeed=3;
        ChatBuffer=({});
        Check = 1;
        string code,file,dir;

        dir = resolve_path(query("team_cwd"), 0);
        file = sprintf(dir+"npc%d.c",sizeof(get_dir(dir, -1)));
        code = @NPC_CODE       
        Gender="¨k©m";
        Race ="¤HÃþ";
        Pursuer="";
        Wimpy=0;
        return 1;
}
int do_set_npc(string arg)
{
        mixed data;
        string prop;

        if (!arg || sscanf(arg,"%s %s",prop,data)!=2) return 0;
        if (prop=="name") Name = data;
        else if (prop=="id")   Id = data;
 else if (prop=="nickname") NickName ->trans_color(data);
        else if (prop=="title") Title = data;
        else if (prop=="lv" || prop=="level"){
                sscanf(data,"%d",data);
       }else if (prop=="skill") Skill = data;
        else if (prop=="race"){
                if (data=="³¥Ã~"){
                   if (Gender=="¨k©Ê") Gender = "¶¯©Ê";
                   Race = data;
        string code,file,dir;

        dir = resolve_path(query("team_cwd"), 0);
        file = sprintf(dir+"npc%d.c",sizeof(get_dir(dir, -1)));
        code = @NPC_CODE
        else if (prop=="gender"){
                if (data=="¨k©Ê"
                ||  data=="¤k©Ê"
                ||  data=="¶¯©Ê"
                ||  data=="»Û©Ê") Gender = data;
                else write("©Ê§O¥u¥i¥H¬O¨k©Ê,¤k©Ê,»Û©Ê©Î¶¯©Ê.\n");
        }
        else if (prop=="age") sscanf(data,"%d",Age);
        else if (prop=="attitude") Attitude = data;
        else if (prop=="money" && data=="none") Check=0;
        else if (prop=="pursuer" && data =="YES") Pursuer = "YES";
        else if (prop=="wimpy") sscanf(data,"%d",Wimpy);
        write("ok.\n");
        return 1;
}
int do_set_npc_long(string arg)
{
        if (!arg) return 0;
        Long = arg;
        return 1;
}
        string code,file,dir;

        dir = resolve_path(query("team_cwd"), 0);
        file = sprintf(dir+"npc%d.c",sizeof(get_dir(dir, -1)));
        code = @NPC_CODE

int do_set_npc_long(string arg)
{
        if (!arg) return 0;
        Long = arg;
        return 1;
}
int do_add_chat(string arg)
{
        if (!arg) return 0;
        ChatBuffer+=({arg});
        printf("±z¼W¥[[%s]³o­Ó°Ê°µ.\n",arg);
        return 1;
}
int do_del_chat(string arg)
{
        if (!arg) return 0;
        ChatBuffer-=({arg});
        printf("±z§R°£°Ê°µ¤º®e¤¤ªº[%s].\n",arg);
        return 1;
}
int do_set_chat_speed(string arg)
{
        int i;
        if (!arg) return 0;
        if (sscanf(arg,"%d",ChatSpeed)!=1) return 0;

        printf("±z³]©w»¡¸Üªº³t«×¬°[%d].\n",ChatSpeed);
        return 1;
}
int do_show_all_npc()
{
        int i;
        mixed *files;
        string str="",dir,temp,err;
        object ob;

        dir = resolve_path(query("team_cwd"), 0);
        files = get_dir(dir, -1);
        if (!sizeof(files)) return notify_fail("¨S¦³³o­Ó¥Ø¿ý¡C\n");
        for (i=0; i <sizeof(files); i++){
            if (file_size(dir + files[i][0]) < 1) continue;
            if (files[i][0][<2..]!=".c") continue;
            if (!ob = find_object(dir + files[i][0])) err = catch(call_other(di;
            if (stringp(dir + files[i][0])) err = catch(ob = load_object(dir + ;
            if (err) continue;
            temp = "¥Íª«ÀÉ¦W¡R" + files[i][0];
            str += sprintf("%s - [%s]\n", temp, ob->short());
        }
        this_player()->start_more(str);
        return 1;
}
{
#include <ansi.h>
inherit "/feature/autoload.c";
inherit ITEM;
int do_set_npc(string arg);
int do_set_npc_long(string arg);
int do_set_chat_speed(string arg);
int do_add_chat(string arg);
int do_del_chat(string arg);
string Skill = "unarmed";
int do_make_npc();
int do_show_all_npc();
int Age=14,Lv = 1,ChatSpeed=10,Check = 1,Wimpy = 0;
string Name = "¤h§L";
string Id = "noname";
string Attitude ="";
string Gender="¨k©m";
string Race ="¤HÃþ";
string Long = "";
string NickName = "";
string Title = "";
string *ChatBuffer=({}),Pursuer="";
void create()
{

     set_name(HIC"NPC"HIB"»s³y¾÷"NOR, ({ "npc maker", "maker" }) );
     set("long","½Ð¥´ < help_npcmaker > ¬Ý»¡©ú¡C\n");
     set("unit", "­Ó" );
     set("team_cwd","/u/m/morral/npc/");//¦s©ñªº¥Ø¿ý
}
void init()
{
        seteuid(getuid(this_player()));
        add_action("check_command","");
}
int check_command(string arg)
{
        string verb;
        mapping can_command = ([
                "make_npc"         : "³Ð³y¤@°¦¥Íª«",
                "mn"               : 1,
                "set_npc"          : "³]©w°ò¥»ÄÝ©Ê,½Ð [help_set_npc]",
                "sn"               : 1,
                "set_npc_long"     : "³]©w¥Íª«¦b³QÆ[¬Ý®Éªº±Ô­z",
                "snl"              : 1,
                "set_chat_speed"   : "³]©w»¡¸Ü³t«×¶V¤p»¡¸Ü¶VºC",
                "scs"              : 1,
                "add_chat"         : "¼W¥[¤@­Ó°Ê°µ,¨Ò¦padd_chat say §Ú¬Oxx",
#include <ansi.h>
inherit "/feature/autoload.c";
inherit ITEM;
int do_set_npc(string arg);
int do_set_npc_long(string arg);
int do_set_chat_speed(string arg);
int do_add_chat(string arg);
int do_del_chat(string arg);
string Skill = "unarmed";
int do_make_npc();
int do_show_all_npc();
int Age=14,Lv = 1,ChatSpeed=10,Check = 1,Wimpy = 0;
string Name = "¬Y¥Íª«";
string Id = "mob";
string Attitude ="";
string Gender="¨k©Ê";
string Race ="¤HÃþ";
string Long = "";
string NickName = "";
string Title = "";
string *ChatBuffer=({}),Pursuer="";
void create()
