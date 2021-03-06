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
string Name = "士兵";
string Id = "noname";
string Attitude ="";
string Gender="男姓";
string Race ="人類";
string Long = "";
string NickName = "";
string Title = "";
string ChatBuffer=({}),Pursuer="";
void create()
{
     set_name(HIC"NPC"HIB"製造機"NOR, ({ "npc maker", "maker" }) );
     set("long","請打 < help_npcmaker > 看說明。\n");
     set("unit", "個" );
     set("team_cwd","/u/e/eeman/npc/");//存放的目錄
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
                "make_npc"         : "創造一隻生物",
                "mn"               : 1,
                "set_npc"          : "設定基本屬性,請 [help_set_npc]",
                "sn"               : 1,
                "set_npc_long"     : "設定生物在被觀看時的敘述",
                "snl"              : 1,
                "set_chat_speed"   : "設定說話速度越小說話越慢",
                "scs"              : 1,
                "add_chat"         : "增加一個動作,例如add_chat say 我是xx",
                "ac"               : 1,
               "del_chat"         : "刪除一個動作",
                "help_npcmaker"    : 1,
                "help_set_npc"     : 1,
                "looknpc"          : "可以看你已經設定了什麼",
                "call_npc"         : "叫出已完成的生物-未完成-",
                "del_npc"          : "永遠清除已完成的生物(就是連檔一起清除)",
                "dest_npc"         : "把這個房間中的生物清掉(dest_npc id)",
                "npclist"          : "查看你已經創造了多少生物",
        ]);
        if (!query("team_cwd")) return notify_fail("這個"+ name() +"沒有伸請無�;
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
                   return notify_fail("你要清除誰﹖\n");
                if (ob->query("player_npc")!=query("team_cwd"))
                   return notify_fail("你不能清除這個生物.\n");
                seteuid(getuid());
                destruct(ob);
                return notify_fail("清除ok.\n");
        }else if (verb=="looknpc"){
printf("這個未出生的生物的設定有:\n等級(lv):%d.\n名字(name):%s.\nid:%s.\ntitle:;
                 return 1;
        }else if (verb=="help_npcmaker"){
          int i;
          string *help;
          arg ="";
          help = keys(can_command);
          for (i=0;i < sizeof(can_command);i++){
              if (intp(can_command[help[i]])) continue;
              if (help[i]=="help_set_room") continue;
              arg += sprintf("%-13s %s。\n",help[i],can_command[help[i]]);
          }
          write(arg);
          return 1;
        }else if (verb=="help_set_npc"){
                 arg=@TEXT
你可以設定的有:
age          (年齡)
attitude        (屬性  設為 aggressive 會自動攻擊人)
lv              (等級由1到100).
name            (名字).
id              (英文名字).
title           (稱號).
nickname        (匿稱).
skill           (技能).
race            (種族  現在只有人類跟野獸兩種).
gender          (性別  男性,女性,雄性,雌性,等).
money none      (這個生物沒有錢  如動物..等等).
pursuer YES     (這個生物會追殺人).
wimpy      (這個生物當寫降到多少時會逃跑).
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
                    return notify_fail("你不能刪除這個生物.\n");
                 seteuid(getuid());
                 destruct(ob);
                 rm(query("team_cwd")+arg);
                 return notify_fail("清除檔案"+arg+"ok.\n");
        }else if (verb=="call_npc"){
                 object ob;
                 if (!arg) return 0;
                 if ( sscanf(arg,"%*s.c") != 1 ) arg += ".c";
                 if (file_size(query("team_cwd")+arg) < 0) return notify_fail(";
                 if (!ob = new(query("team_cwd")+arg)) return notify_fail(arg +;
                 if (ob->query("player_npc")!=query("team_cwd"))
                    return notify_fail("你不能偷取別人的生物.\n");
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
        if (Race!="人類") code += sprintf("\tset(%crace%c,%c%s%c);\n",34,34,34,;
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
        if (Race!="人類") code += sprintf("\tset(%crace%c,%c%s%c);\n",34,34,34,;
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
        if (!write_file(file,code,1) ) return notify_fail("寫入檔案失敗。\n");
message_vision(HIR"\n士兵"HIW"說道：主公，有事請吩咐。\n"NOR,this_player());
        "/cmds/wiz/clone.c"->main(this_player(),file);
        Lv = 1;
        Age = random(60)+14;
        Attitude = "";
  Name="士兵";
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
        Gender="男姓";
        Race ="人類";
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
                if (data=="野獸"){
                   if (Gender=="男性") Gender = "雄性";
                   Race = data;
        string code,file,dir;

        dir = resolve_path(query("team_cwd"), 0);
        file = sprintf(dir+"npc%d.c",sizeof(get_dir(dir, -1)));
        code = @NPC_CODE
        else if (prop=="gender"){
                if (data=="男性"
                ||  data=="女性"
                ||  data=="雄性"
                ||  data=="雌性") Gender = data;
                else write("性別只可以是男性,女性,雌性或雄性.\n");
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
        printf("您增加[%s]這個動做.\n",arg);
        return 1;
}
int do_del_chat(string arg)
{
        if (!arg) return 0;
        ChatBuffer-=({arg});
        printf("您刪除動做內容中的[%s].\n",arg);
        return 1;
}
int do_set_chat_speed(string arg)
{
        int i;
        if (!arg) return 0;
        if (sscanf(arg,"%d",ChatSpeed)!=1) return 0;

        printf("您設定說話的速度為[%d].\n",ChatSpeed);
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
        if (!sizeof(files)) return notify_fail("沒有這個目錄。\n");
        for (i=0; i <sizeof(files); i++){
            if (file_size(dir + files[i][0]) < 1) continue;
            if (files[i][0][<2..]!=".c") continue;
            if (!ob = find_object(dir + files[i][0])) err = catch(call_other(di;
            if (stringp(dir + files[i][0])) err = catch(ob = load_object(dir + ;
            if (err) continue;
            temp = "生物檔名﹕" + files[i][0];
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
string Name = "士兵";
string Id = "noname";
string Attitude ="";
string Gender="男姓";
string Race ="人類";
string Long = "";
string NickName = "";
string Title = "";
string *ChatBuffer=({}),Pursuer="";
void create()
{

     set_name(HIC"NPC"HIB"製造機"NOR, ({ "npc maker", "maker" }) );
     set("long","請打 < help_npcmaker > 看說明。\n");
     set("unit", "個" );
     set("team_cwd","/u/m/morral/npc/");//存放的目錄
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
                "make_npc"         : "創造一隻生物",
                "mn"               : 1,
                "set_npc"          : "設定基本屬性,請 [help_set_npc]",
                "sn"               : 1,
                "set_npc_long"     : "設定生物在被觀看時的敘述",
                "snl"              : 1,
                "set_chat_speed"   : "設定說話速度越小說話越慢",
                "scs"              : 1,
                "add_chat"         : "增加一個動做,例如add_chat say 我是xx",
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
string Name = "某生物";
string Id = "mob";
string Attitude ="";
string Gender="男性";
string Race ="人類";
string Long = "";
string NickName = "";
string Title = "";
string *ChatBuffer=({}),Pursuer="";
void create()
