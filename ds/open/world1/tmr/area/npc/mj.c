/*
°õ¦æ®É¬q¿ù»~¡R*Value being indexed is zero.

µ{¦¡¡Ropen/world1/tmr/area/npc/mj.c ²Ä684¦æ
ª«¥ó: open/world1/tmr/area/npc/mj#1924 ("µô§P¤p©j")
¨ç¼Æ©I¥s¦^·¹:
¨ç¼Æ:do_win()           <- open/world1/tmr/area/npc/mj.c:²Ä684¦æ [ª«¥ó:open/world1/tmr/area/npc/mj#1924 ("µô§P¤p©j")]
=======================¥H¤W¿ù»~½ÐºÉ§Ö­×´_========================

*/
//Aip@The.Never.Been.Place 6/16/1997
#include <ansi2.h>
inherit F_SAVE;
inherit NPC;
#define RECORD_PLAYERS 4
#define END 286
#define START 0
void check_flower(mapping who);
int to_say_play();
int to_say_rule();
int do_check_Mj(string datastr,string str);
int do_check_eat(string num1,string num2,string LastDump);
int delete_last_dump(string whoId);
int do_check_win(string str);
int check_hu(string strW);
int set_mjdata(object me,int *score);
int get_tc(mapping who);
varargs int do_dump(string str,object me);
varargs int do_touch(string str,object me);
varargs int wash_mj(int amount);
varargs int do_win(string str,object me);
varargs int do_gon(string str,object me);
varargs int do_pon(string str,object me);
string check_id(string str,string kind);
string do_delete_Mj(string datastr,string str,int amount);
string show_mj(string str,int flag);
string sort_data(string str);
mixed do_check_num(string str,int flag);
//µP°¦¸ê®Æ
string MjE= "1w2w3w4w5w6w7w8w9w1t2t3t4t5t6t7t8t9t1s2s3s4s5s6s7s8s9seasowenojofabaf1f2f3f4f5f6f7f8";
string *MjC = ({"",
                "¤@¸U","¤G¸U","¤T¸U","¥|¸U","¥î¸U","¤»¸U","¤C¸U","¤K¸U","¤E¸U",
                "¤@µ©","¤Gµ©","¤Tµ©","¥|µ©","¥îµ©","¤»µ©","¤Cµ©","¤Kµ©","¤Eµ©",
                "¤@¯Á","¤G¯Á","¤T¯Á","¥|¯Á","¥î¯Á","¤»¯Á","¤C¯Á","¤K¯Á","¤E¯Á",
                "ªF­·","«n­·","¦è­·","¥_­·","¬õ¤¤","«Cµo","¥ÕªO",
                "1 ¬K","2 ®L","3 ¬î","4 ¥V","1 ±ö","2 Äõ","3 ¦Ë","4 µâ","·tºb"
              });
int K;
string Tc = "";
//¸ê®Æ
int Auto;
int Auto_Tin;
int Auto_Gon;
int Auto_Pon;
int Count;
int count;
int end;
int Goned;
int HU_F;
int NO_HU;
int NO_GON;
int Playing;
int Play;
int Times;
int Touched;
int NowPlayer;
int Player_leave;
string List ="";
string LookP ="";
string *NowPlayerId = ({ "","","","" });
string LastDumpId="";
string LastDump="";

mapping P1Data = ([
"Show": "color","Id": "","Name": "","Mj": "","Out": "","OutGon": "","OutPon": "",
"OutFlower": "","Auto": "","AutoTin": "","AutoGon": "","AutoPon": "","Dump": ""
               ]);
mapping P2Data = ([
"Show": "color","Id": "","Name": "","Mj": "","Out": "","OutGon": "","OutPon": "",
"OutFlower": "","Auto": "","AutoTin": "","AutoGon": "","AutoPon": "","Dump": ""
               ]);
mapping P3Data = ([
"Show": "color","Id": "","Name": "","Mj": "","Out": "","OutGon": "","OutPon": "",
"OutFlower": "","Auto": "","AutoTin": "","AutoGon": "","AutoPon": "","Dump": ""
               ]);
mapping P4Data = ([
"Show": "color","Id": "","Name": "","Mj": "","Out": "","OutGon": "","OutPon": "",
"OutFlower": "","Auto": "","AutoTin": "","AutoGon": "","AutoPon": "","Dump": ""
               ]);
mapping record;
void create()
{
	set_name("³Â±N¦è¬I",({"mj lady","lady"}));
	set("long",@LONG

¤@­Ó¬üÄRªº¤p©j¥¿¹ïµÛ§A·L¯º¡C
	
LONG
);
        set_weight(1);
        set("race","human");
        set("gender","¤k©Ê");
        set("level",25);
        set("age",18);
        set("attitude", "friendly");
        set("unit","¦ì");
        set("inquiry",([
           "mj": (: to_say_play :),
           "³Â±N": (: to_say_play :),
           "ª±ªk": (: to_say_play :),
           "play": (: to_say_play :),
           "³W«h": (: to_say_rule :),
           "rule": (: to_say_rule :),
           ]));
        setup();
        seteuid(getuid());
	if( !restore() )
        {
        	record = ([]);
        }
}

void init()
{
   add_action("do_addin","addin");
   add_action("do_dump","dump");
   add_action("do_dump","dd");
   add_action("do_eat","eat");
   add_action("do_gon","gon");
   add_action("do_win","hu");
   add_action("do_help","help");
   add_action("do_look","look");
   add_action("do_look",".");
   add_action("do_look",".1");
   add_action("do_look",".2");
   add_action("do_look",".3");
   add_action("do_look",".4");
   add_action("do_look","..");
   add_action("do_touch","mo");
   add_action("do_touch","0");
   add_action("do_pon","pon");
   add_action("do_pon","p");
   add_action("do_restart","restart");
   add_action("wash_mj","start");
   add_action("do_setmj","setmj");
   add_action("show_top","top");
   add_action("do_tin","tin");
   add_action("ch","ch");
}
int sort_user(string str1, string str2)
{
	return strcmp(str1[45..50],str2[45..50]);
}
int query_Play() { return Play; }
mapping query_record() { return record; }
int clear_record() { record=([ ]); this_object()->save(); return 1; }
int test_record(string id,int aa,int bb,int cc,int dd,int ee,int ff)
{
	record[id] = ([
		"name": id,
		"rounds" : aa,
		"self" : bb,
		"win" : cc,
		"lose" : dd,
		"total" : ee,
		"bad" : ff,
		]);
	return 1;
}
int do_addin()
{
        object me=this_player();
        if (me->query("id")==P1Data["Id"]
        ||  me->query("id")==P2Data["Id"]
        ||  me->query("id")==P3Data["Id"]
        ||  me->query("id")==P4Data["Id"]){
            if (!Playing) message_vision("$N¤j³Û: [¤í¸}°Ú¡ã¡ã] ¤£°±ªº­ú­ú³Ú³Ú.....¡C\n",me);
            else message_vision("$N¹ïµÛ¤j®a»¡: ¤µ¤Ñ¦ÛºN"+(random(12)+1)+"¦¸´N¦n¡C\n",me);
            return 1;
        }
       if (Playing){
                if (random(2))
                message_vision(this_object()->name()+
                "¹ïµÛ"+me->name()+"»¡¡G µP§½¥¿¦b¶i¦æ¤¤½Ð¨ì®ÇÃä§¤¤@¤U...¡C\n",me);
                else  message_vision("$N³ÛµÛ: [§Ú¤]­nª±°Õ¡ã¡ã] ¤£°±ªº­ú­ú³Ú³Ú.....¡C\n",me);
                return 1;
        }
        if (!P1Data["Id"] || P1Data["Id"]==""){
           P1Data["Id"]=me->query("id");
           NowPlayerId[Play]=me->query("id");
           message_vision("$N¥[¤J¤F³o³õµP§½¡C\n",me);
           Play++;
           Times=0;
           LookP+="¦b«e­±¦³"+me->name()+"¡A";
           return 1;
        }else if (!P2Data["Id"] || P2Data["Id"]==""){
                 P2Data["Id"]=me->query("id");
                 message_vision("$N¥[¤J¤F³o³õµP§½¡C\n",me);
                 NowPlayerId[Play]=me->query("id");
                 Play++;
                 Times=0;
                 LookP+=me->name()+"¡A";
                 return 1;
        }else if (!P3Data["Id"] || P3Data["Id"]==""){
                 P3Data["Id"]=me->query("id");
                 message_vision("$N¥[¤J¤F³o³õµP§½¡C\n",me);
                 NowPlayerId[Play]=me->query("id");
                 Play++;
                 Times=0;
                 LookP+=me->name()+"¡A";
                 return 1;
        }else if (!P4Data["Id"] || P4Data["Id"]==""){
                 P4Data["Id"]=me->query("id");
                 message_vision("$N¥[¤J¤F³o³õµP§½¡C\n",me);
                 NowPlayerId[Play]=me->query("id");
                 Play++;
                 Times=0;
                 LookP+=me->name();
                 return wash_mj(Play);
        }
        return notify_fail("¤H¼Æ¤w¨¬¡C\n");
}
int do_dump(string str,object me)
{
        int check,i;
        int *score=({ 0,0,0,0,0 });
        string ponid;
        mapping who;
        object met,user;
 
        if (!me) me=this_player();
        if (check_id(me->query("id"),"player")!="");
        else {
           command("stare "+me->query("id"));
           command("say ³oµP§½¸ò§A¨SÃö«Y¡C");
           return 1;
        }
        if (!Playing){
           command("kick "+me->query("id"));
           command("say µP§½ÁÙ¨S¶}©l½Ð¤£­n®³µP¶Ã¥á!!");
           return 1;
        }
        tell_object(me,"´«½Ö¥´µP:"+NowPlayerId[NowPlayer]+"\n");
        if (!str) return notify_fail("«ü¥O:dump <¥N½X>\n");
        if (me->query("id")!=NowPlayerId[NowPlayer]){
           command("hammer "+me->query("id"));
           command("say ·Q°½¥´µP!!§@¹ú£«?");
           return 1;
        }
        if (!Touched){
           command("faint "+me->query("id"));
           command("say §AÁÙ¨SºNµP!!");
           return 1;
        }
        if (Goned==5){
           message_vision("$N»¡¹D¡G¦¹§½¦]"+HIR+"¤­ºb¦XµP"+NOR+"½Ð¦A­«·s¶}©l start ¡C\n",this_object());
           Playing=0;
           Count++;
           if (Play>=RECORD_PLAYERS){
              for (i=0;i<Play;i++){
                  met=present(NowPlayerId[i], environment(this_object()));
                  if (!met) met=find_player(NowPlayerId[i]);
                  if (!met);
                  else{
                     score = ({ 0,0,0,0,0 });
                     set_mjdata(met,score);
                     this_object()->save();
                  }
              }
           }
           return 1;
        }
        NO_HU=0;
        HU_F=0;
        NO_GON=0;
        if (me->query("id")==P1Data["Id"]) who=P1Data;
        else if (me->query("id")==P2Data["Id"]) who=P2Data;
        else if (me->query("id")==P3Data["Id"]) who=P3Data;
        else if (me->query("id")==P4Data["Id"]) who=P4Data;
        check=do_check_Mj(MjE,str);
        if (check==0) return notify_fail("¨S¦³["+str+"]³oºØ¥N½X¡C\n");
        check=do_check_Mj(who["Mj"],str);
        if (check==0) return notify_fail("§A¨S"+do_check_num(str,0)+"³o±iµP¡C\n");
        tell_object(me,"§A»¡¹D¡G"+do_check_num(str,0)+"\n");
        tell_room(environment(this_object()),YEL+me->name()+"»¡¡G"+do_check_num(str,0)+"¡C\n"+NOR,me);
//        command("say "+me->name()+"¥´¥X¤F¤@±i.."+do_check_num(str,0));
        message_vision("$N¥´¥X¤F¤@±i.."+do_check_num(str,3)+"\n",me);
        who["Mj"]=do_delete_Mj(who["Mj"],str,1);
        LastDump=str;
        who["Dump"]+=str;
        LastDumpId=who["Id"];
        Touched=0;
        NowPlayer++;
        NowPlayer%=Play;
        message_vision(YEL+"$N»¡¡GÁÙ³Ñ¤U["HIC+(end-count-16-Goned)/2+NOR+YEL+"]±iµP¥iºN¡A²{¦b½ü¨ì "+HIY+capitalize(NowPlayerId[NowPlayer])+NOR+YEL+" ºNµP¡C\n"+NOR,this_object());
        if(user = present(NowPlayerId[NowPlayer], environment(this_object())))
        {
        	tell_object(user,HIW+"<¸Ó§AÅo!!>\n"+NOR);
        }
        if (Auto_Tin){
           ponid=check_id(str,"tin");
           if (ponid!=""){
              me=present(ponid, environment(this_object()));
              if (!me) me=find_player(ponid);
              if (!me) return 1;
              return do_win(str,me);
           }
        }
        if (Auto_Gon){
           ponid=check_id(str,"gon");
           if (ponid!=""){
              me=present(ponid, environment(this_object()));
              if (!me) me=find_player(ponid);
              if (!me) return 1;
              do_gon(str,me);
           }
        }
        if (Auto_Pon){
           ponid=check_id(str,"pon");
           if (ponid!=""){
              me=present(ponid, environment(this_object()));
              if (!me) me=find_player(ponid);
              if (!me) return 1;
              do_pon(str,me);
           }
        }
        if (count==(end-16-Goned)){
           Playing=0;
           Count++;
           message_vision(YEL+"$N»¡¡G¦¹§½"+HIY+"¬y§½"+NOR+YEL+"½Ð¦A­«·s¶}©l "+HIR+"start"+NOR+YEL+" ¡C\n"+NOR,this_object());
           str="©Ò³Ñ¤UªºµP°¦¦³:"+show_mj(List[count..end],2)+"\n";
           tell_room(environment(this_object()),str);
           if (Play>=RECORD_PLAYERS){
              for (i=0;i<Play;i++){
                  met=present(NowPlayerId[i], environment(this_object()));
                  if (!met) met=find_player(NowPlayerId[i]);
                  if (!met);
                  else{
                     score = ({ 0,0,0,0,0 });
                     set_mjdata(met,score);
                     this_object()->save();
                  }
              }
           }
           return 1;
        }
        if (Auto){
           if (NowPlayerId[NowPlayer]==P1Data["Id"]) who=P1Data;
           else if (NowPlayerId[NowPlayer]==P2Data["Id"]) who=P2Data;
           else if (NowPlayerId[NowPlayer]==P3Data["Id"]) who=P3Data;
           else if (NowPlayerId[NowPlayer]==P4Data["Id"]) who=P4Data;
           if (who["Auto"]=="auto"){
              me=present(NowPlayerId[NowPlayer], environment(this_object()));
              if (!me) me=find_player(NowPlayerId[NowPlayer]);
              if (!me) return 1;
              call_out("do_touch",1,"AUTO",me);
           }
        }
        return 1;
}
int do_eat(string str)
{
        int LastDumpMan,i;
        string num1,num2;
        object me=this_player();
        mapping who;
 
        if (!str || sscanf(str,"%s %s",num1,num2)!=2) return 0;
        if (check_id(me->query("id"),"player")!="");
        else {
           command("stare "+me->query("id"));
           command("say ³oµP§½¸ò§A¨SÃö«Y¡C");
           return 1;
        }
        if (!Playing){
           command("say µP§½ÁÙ¨S¶}©l¡C");
           return 1;
        }
        tell_object(me,"´«½ÖºNµP:"+NowPlayerId[NowPlayer]+"\n");
        if (me->query("id")!=NowPlayerId[NowPlayer]){
           command("hammer "+me->query("id"));
           command("say ÁÙ¨S½ü¨ì§A¡C");
           return 1;
        }
        if (!LastDump || LastDump==""){
           command("hammer "+me->query("id"));
           command("say ºNµP§a¡C");
           return 1;
        }
        if (Touched){
           command("flop "+me->query("id"));
           command("say ¥´µP°Õ!!");
           return 1;
        }
        if (do_check_eat(num1,num2,LastDump)==0){
           command("flop "+me->name());
           command("say §A²´·úªá¤F£«!!³o¼Ë¤]¯à¦Y¡C");
           return 1;
        }
        if (num1==num2){
           command("flop "+me->name());
           command("say ¬Û¦PªºµP¤£¯à¦Y¡A¥u¯à¥Î¸I(pon)ªº¡C");
           return 1;
        }
        if (me->query("id")==P1Data["Id"]) who=P1Data;
        else if (me->query("id")==P2Data["Id"]) who=P2Data;
        else if (me->query("id")==P3Data["Id"]) who=P3Data;
        else if (me->query("id")==P4Data["Id"]) who=P4Data;
        LastDumpMan=do_check_Mj(MjE,num1);
        if (LastDumpMan==0) return notify_fail("¨S¦³["+num1+"]³oºØ¥N½X¡C\n");
        LastDumpMan=do_check_Mj(MjE,num2);
        if (LastDumpMan==0) return notify_fail("¨S¦³["+num2+"]³oºØ¥N½X¡C\n");
        LastDumpMan=do_check_Mj(who["Mj"],num1);
        if (LastDumpMan==0) return notify_fail("§A¨S"+do_check_num(num1,0)+"³o±iµP¡C\n");
        LastDumpMan=do_check_Mj(who["Mj"],num2);
        if (LastDumpMan==0) return notify_fail("§A¨S"+do_check_num(num2,0)+"³o±iµP¡C\n");
 message_vision(HIG+"\n¡i ¡ã ¦Y ¡ã ¡j"+NOR+"\n$N®³¥X¤F¤@±i"+do_check_num(num1,3)+
                      "»P¤@±i"+do_check_num(num2,3)+
                      "¦Y¤U¤F"+do_check_num(LastDump,3)+"¡C\n\n",me);
        who["Out"]+=num2;
        who["Out"]+=LastDump;
        who["Out"]+=num1;
        who["Mj"]=do_delete_Mj(who["Mj"],num1,1);
        who["Mj"]=do_delete_Mj(who["Mj"],num2,1);
        Touched=1;
        NO_HU=1;
        NO_GON=1;
        i=0;
        if (who["Show"]=="¥N½X") i=3;
        if (who["Show"]=="color") i=5;
        tell_object(me,show_mj(who["Mj"],i));
        return delete_last_dump(who["Id"]);
}
int do_gon(string str,object me)
{
        int i;
        mapping who;
 
        if (!me) me=this_player();
        if (check_id(me->query("id"),"player")!="");
        else {
           command("stare "+me->query("id"));
           command("say ³oµP§½¸ò§A¨SÃö«Y¡C");
           return 1;
        }
        if (!Playing){
           command("say µP§½ÁÙ¨S¶}©l!!");
           return 1;
        }
        if (LastDumpId==me->query("id") && !str){
           command("stare "+me->query("id"));
           command("say ¨º±iµP¬O§A¦Û¤v¥´ªº¡C");
           return 1;
        }
        if (Touched && NowPlayerId[NowPlayer]!=me->query("id")){
           command("hammer "+me->query("id"));
           command("say §O¤H¨S¥´µP§A«ç»òºb¡C");
           return 1;
        }
        if (!str) str=LastDump;
 
        if (me->query("id")==P1Data["Id"]) who=P1Data;
        else if (me->query("id")==P2Data["Id"]) who=P2Data;
        else if (me->query("id")==P3Data["Id"]) who=P3Data;
        else if (me->query("id")==P4Data["Id"]) who=P4Data;
        if (who["Auto"]=="auto") return 1;
        i=do_check_Mj(who["Mj"],str);
        if (i==1){
           if (!Touched) return notify_fail("§AÁÙ¨SºNµP¡C\n");
           i=do_check_Mj(who["OutPon"],str);
           if (!i) return notify_fail("§A¥u¦³¤@±i¤£¯àºb¡C\n");
           if (NO_GON) return notify_fail("³o¼ËµLªkºbµP¡C\n");
              message_vision("\n$N»¡¹D¡G"+HIB+"¡i ¡ã ºb ¡ã ¡j"+NOR+"\n\n",me);
              who["Mj"]=do_delete_Mj(who["Mj"],str,1);
              sort_data(who["OutPon"]+=str);
              str=List[end..end+1];
              end-=2;
              Goned++;
              message_vision("\n$N±q«á­±¸É¤F¤@±iµP¡C\n\n",me);
              printf("§A¸É¨ì¤@±i%s\n",do_check_num(str,0));
              i=0;
              if (who["Show"]=="¥N½X") i=3;
              if (who["Show"]=="color") i=5;
              who["Mj"]+=str;
              check_flower(who);
              tell_object(me,show_mj(who["Mj"],i));
              Touched=1;
              return 1;
        }
        if (i < 3) return notify_fail("§A¤â¤¤­n¦³¤T±i"+do_check_num(str,0)+"¤~¯àºb¡C\n");
        if (!Touched){
           if (str!=LastDump) return notify_fail("³o¼ËµLªkºb¡C\n");
        }
        else if (i < 4) return notify_fail("§A¤â¤¤­n¦³¥|±i"+do_check_num(str,0)+"¤~¯à·tºb¡C\n");
        for (i=0;i<Play;i++) {
            if (NowPlayerId[NowPlayer]==me->query("id")) break;
            NowPlayer++;
            NowPlayer%=Play;
        }
        who["Mj"]=do_delete_Mj(who["Mj"],str,3);
        if (Touched && NowPlayerId[NowPlayer]==me->query("id")){
           NO_HU=0;
           if(random(2)) message_vision("\n$NÁy¤WÅS¥X¨¸´cªº¯º®e»¡¡G¤£¦n·N«ä..§Ú·tºb..hehe...\n\n",me);
           else message_vision("\n$N­±µLªí±¡ªº»¡¡G³o¦¸·tºb¤j·§·|ºb¦º¤@°ï¤H¡C\n\n",me);
           who["Mj"]=do_delete_Mj(who["Mj"],str,1);
           for (i=0;i<4;i++) who["Out"]+="xx";
           for (i=0;i<4;i++) who["OutGon"]+=str;
        }else{
           NO_HU=1;
           message_vision("\n$N¤j¥s¡G"+do_check_num(str,0)+"¡ã"+HIW+"¡i ¡ã ºb ¡ã ¡j"+NOR+"\n\n",me);
           for (i=0;i<4;i++) who["Out"]+=str;
        }
        str=List[end..end+1];
        end-=2;
        Goned++;
        message_vision("$N±q«á­±¸É¤F¤@±iµP¡C\n",me);
        tell_object(me,"§A¸É¨ì¤@±i"+do_check_num(str,0)+"\n");
        who["Mj"]+=str;
        check_flower(who);
        i=0;
        if (who["Show"]=="¥N½X") i=3;
        if (who["Show"]=="color") i=5;
        tell_object(me,show_mj(who["Mj"],i));
        if (Touched) return 1;
        Touched=1;
        return delete_last_dump(who["Id"]);
}
varargs int do_win(string str,object me)
{
        int i,j;
        int *score=({0,0,0,0,0});
        string Mj="";
        mapping who;
        object met;
 
        if (!me) me=this_player();
        if (check_id(me->query("id"),"player")!="");
        else {
           command("stare "+me->query("id"));
           command("say ³oµP§½¸ò§A¨SÃö«Y¡C");
           return 1;
        }
        if (!Playing){
           command("say µP§½ÁÙ¨S¶}©l...");
           return 1;
        }
        if ( NO_HU ) return notify_fail("³o¼Ë¤£¯à­JµP¡C\n");
        if (LastDump==""&&Touched) message_vision("\n$N¤j¥s¡G"+HIW+"¡i ¤Ñ ¡ã¡ã ­J ¡ã¡ã¡j"+NOR+"\n\n",me);
        else{
             tell_room(environment(this_object()),"\n"+me->name()+"¤j¥s¡G"+HIW+"¡i §Ú¡ã­J¡ã°Õ¡ã ¡j"+NOR+"\n\n",me);
             tell_object(me,"\n§A¤j¥s¡G"+HIW+"§Ú¡ã­J¡ã°Õ¡ã"+NOR+"\n\n");
        }
        if (Touched&&NowPlayerId[NowPlayer]==me->query("id"))
           message_vision("$N»¡¹D¡G­J®a"+me->name()+HIG+"¦ÛºN"+NOR+"¡ã¡ã¡ã¡ã¡ã¡ã¡ã"+HIR+"¦Y¬õ"+NOR+"¡ã¡ã¡ã¡ã¡ã\n",this_object());
        else if ( LastDumpId==me->query("id") ) return notify_fail("§A­n­J§A¦Û¤v¥´ªºµP??\n");
        else command("say "+me->name()+"­J¤F");
        if (me->query("id")==P1Data["Id"]) who=P1Data;
        else if (me->query("id")==P2Data["Id"]) who=P2Data;
        else if (me->query("id")==P3Data["Id"]) who=P3Data;
        else if (me->query("id")==P4Data["Id"]) who=P4Data;
        if (sizeof(who["OutFlower"]) ==16) i=1;
        else if (sizeof(who["OutFlower"]) ==14&&sizeof(P1Data["OutFlower"]+P2Data["OutFlower"]+P3Data["OutFlower"]+P4Data["OutFlower"])==16) i=1;
        if (!HU_F) i=0;
        if (i){
           Mj+="­J®aªºªáµP¬O:\n";
           Mj+=show_mj(who["OutFlower"],1);
           if (NowPlayerId[NowPlayer]==who["Id"]) Mj+="­J®aªá­J¦ÛºN\n";
           else{
             if (sizeof(P1Data["OutFlower"])==2) LastDumpId=P1Data["Id"];
             else if (sizeof(P2Data["OutFlower"])==2) LastDumpId=P2Data["Id"];
             else if (sizeof(P3Data["OutFlower"])==2) LastDumpId=P3Data["Id"];
             else if (sizeof(P4Data["OutFlower"])==2) LastDumpId=P4Data["Id"];
             Mj+="\nªáµP©ñºjªÌ:"+HIB+LastDumpId+NOR+"\n";
           }
        }else{
          Mj+="­J®aªºµP¬O:\n";
          if (who["OutGon"]!=""){
             Mj+="·tºbªº¦³:\n";
             Mj+=show_mj(who["OutGon"],0);
          }
          Mj+=who["Id"]+":¤â¤¤ªºµP¦³:\n";
          if (!Touched){
             who["Mj"]+=LastDump;
             who["Mj"]=sort_data(who["Mj"]);
             Mj+=show_mj(who["Mj"],0);
             Mj+="©Ò­JªºµP¬O:"+HIR+do_check_num(LastDump,0)+NOR;
             Mj+="\n©ñºjªÌ:"+HIB+LastDumpId+NOR+"\n";
          }else{
             Mj+=show_mj(who["Mj"],0);
             if (str) Mj+="©Ò¦ÛºNªºµP¬O:"+HIR+do_check_num(str,0)+NOR+"\n";
          }
        }
        Playing=0;
        tell_room(environment(this_object()),Mj);
        Tc="";
        if (do_check_win(who["Mj"])==1||i==1){
//ºâ¥x///////////////////////////////////
        mixed MjT = ([
"@1" : ({ "²ø®a", 1 }),"@2" : ({ "¦ÛºN", 1 }),"@3" : ({ "ªáµP", 1 }),"@4" : ({ "ªù²M", 1 }),
"@5" : ({ "ªF­·", 1 }),"@6" : ({ "«n­·", 1 }),"@7" : ({ "¦è­·", 1 }),"@8" : ({ "¥_­·", 1 }),
"@9" : ({ "¬õ¤¤", 1 }),"@0" : ({ "«Cµo", 1 }),"@a" : ({ "¥ÕªO", 1 }),"@G" : ({ "¤@¬×¤f", 1 }),
"@b" : ({ "®ü©³ºN¤ë", 1 }),"@c" : ({ "®ü©³¼´³½", 1 }),"@d" : ({ "¥­­J", 2 }),"@e" : ({ "ªF­·ªF", 2 }),
"@f" : ({ "«n­·«n", 2 }),"@g" : ({ "¦è­·¦è", 2 }),"@h" : ({ "¥_­·¥_", 2 }),"@i" : ({ "¥þ¨D¤H", 2 }),
"@j" : ({ "¤T·t¨è", 2 }),"@H" : ({ "¤G¬×¤f", 2 }),"@k" : ({ "¤Tºb¤l", 2 }),"@B" : ({ "¬K®L¬î¥V", 2 }),
"@C" : ({ "±öÄõµâ¦Ë", 2 }),"@l" : ({ "ªù²M¦ÛºN", 3 }),"@m" : ({ "¸I¸I­J", 4 }),"@n" : ({ "²V¤@¦â", 4 }),
"@o" : ({ "¤p¤T¤¸", 4 }),"@p" : ({ "¥|·t¨è", 6 }),"@q" : ({ "²M¤@¦â", 8 }),"@r" : ({ "¦r¤@¦â", 8 }),
"@s" : ({ "¤C¹ï¤l", 8 }),"@t" : ({ "¤j¤T¤¸", 8 }),"@u" : ({ "¤­·t¨è", 8 }),"@F" : ({ "¤p¥|³ß", 8 }),
"@D" : ({ "¤C·m¤@", 8 }),"@E" : ({ "ºñ¤@¦â", 16 }),"@v" : ({ "¤j¥|³ß", 16 }),"@w" : ({ "¤Ñ­J", 16 }),
"@x" : ({ "¦a­J", 16 }),"@y" : ({ "¤H­J", 16 }),"@z" : ({ "°ê¤hµLÂù", 16 }),"@A" : ({ "¤K¥P¹L®ü", 16 }),
"@J" : ({ "²M¦ÑÀY", 8 }),"@I" : ({ "²V¦ÑÀY", 4 }),
]);//H
           get_tc(who);
////////////////
           str="\t\t\t¡Ý¡Ý¡Ý¡Ý¡Ý¡Ý¡Ý¡Ý¡Ý¡Ý¡Ý¡Ý¡Ý¡Ý¡Ý¡Ý¡Ý¡Ý¡Ý\n";
           for (i=0;i<sizeof(Tc);i+=2){
              str+=sprintf("\t\t\t%-12s%8s ¥x\n",MjT[Tc[i..i+1]][0],chinese_number(MjT[Tc[i..i+1]][1]));
              j+=MjT[Tc[i..i+1]][1];
           }
           if (Count){
              str+=sprintf("\t\t\t%-12s%8s ¥x\n","³s"+chinese_number(Count)+"©Ô"+chinese_number(Count),chinese_number(Count*2));
              j+=Count*2;
           }
           str+=sprintf("\t\t\t°ò¥»¥x            ¤T ¥x\n\t\t\t%20s\n","Á`¥x¼Æ:"+chinese_number(j+3)+" ¥x");
           str+="\t\t\t¡Ý¡Ý¡Ý¡Ý¡Ý¡Ý¡Ý¡Ý¡Ý¡Ý¡Ý¡Ý¡Ý¡Ý¡Ý¡Ý¡Ý¡Ý¡Ý\n";
           tell_room(environment(this_player()),str);
/////////////
           if (!Touched){
              if (Play>=RECORD_PLAYERS){
		 score = ({ 0,1,0,j+3,0}); // ({ ¦ÛºN,­JµP,©ñºj,¥x¼Æ<©ñºj¬°­tªº>,¥Ç³W })
                 set_mjdata(me,score);
                 met=present(LastDumpId, environment(this_object()));
                 if (!met) met=find_player(LastDumpId);
                 if (!met);
                 else{
		    score = ({ 0,0,1,-j-3,0 });  // ({ ¦ÛºN,­JµP,©ñºj,¥x¼Æ<©ñºj¬°­tªº>,¥Ç³W })
                    set_mjdata(met,score);
                    this_object()->save();
                 }
                 for (i=0;i<Play;i++){
                     met=present(NowPlayerId[i], environment(this_object()));
                     if (!met) met=find_player(NowPlayerId[i]);
                     if (!met);
                     else{
                        score = ({ 0,0,0,0,0 });  // ({ ¦ÛºN,­JµP,©ñºj,¥x¼Æ<©ñºj¬°­tªº>,¥Ç³W })
                        set_mjdata(met,score);
                        this_object()->save();
                     }
                 }
              }
           }else{ //¦ÛºN
              if (Play>=RECORD_PLAYERS || this_object()->query("debug")){
		 score = ({ 1,0,0,(j+3)*(Play-1),0 });  // ({ ¦ÛºN,­JµP,©ñºj,¥x¼Æ<©ñºj¬°­tªº>,¥Ç³W })
                 set_mjdata(me,score);
                 for (i=0;i<Play;i++){
                     if (NowPlayerId[i]==me->query("id")) continue;
                     met=present(NowPlayerId[i], environment(this_object()));
                     if (!met) met=find_player(NowPlayerId[i]);
                     if (!met);
                     else{
			score = ({ 0,0,0,-j-3,0 });  // ({ ¦ÛºN,­JµP,©ñºj,¥x¼Æ<¿é¬°­tªº>,¥Ç³W })
                        set_mjdata(met,score);
                        this_object()->save();
                     } //else
                 } //for
              } // player==4
           }
         if (NowPlayerId[0]==who["Id"]) Count++;
         else{
           Times++;
           Count=0;
         }
        }else{
           command("sigh "+who["Id"]);
           message_vision(YEL+"$N»¡¡Gª±®a ["+HIY+who["Id"]+NOR+YEL+"] "+HIR+" ¨¥¥E ¡ã ¥j¤ë ¡ã¡ã"+NOR+YEL+"¡C\n"+NOR,this_object());
           Times++;
           Count=0;
           if (Play>=RECORD_PLAYERS){
              if (NowPlayerId[NowPlayer]==who["Id"]&&Touched){
                 if (who["Out"]==""&&who["OutPon"]==""){
                    j=12;
                 }else {
                    j=9;
                 }
              }else{
                 if (who["Out"]==""&&who["OutPon"]==""){
                    j=4;
                 }else{
                    j=3;
                 }
              }
////////////////
              str="\t\t\t¡Ý¡Ý¡Ý¡Ý¡Ý¡Ý¡Ý¡Ý¡Ý¡Ý¡Ý¡Ý¡Ý¡Ý¡Ý¡Ý¡Ý¡Ý¡Ý\n";
              str+=sprintf("\t\t\t%-12s%8s ¥x\n","¨¥¥E¥j¤ë",chinese_number(j));
              str+=sprintf("\t\t\t%20s\n","­Ë¦©Á`¥x¼Æ:"+chinese_number(j)+" ¥x");
              str+="\t\t\t¡Ý¡Ý¡Ý¡Ý¡Ý¡Ý¡Ý¡Ý¡Ý¡Ý¡Ý¡Ý¡Ý¡Ý¡Ý¡Ý¡Ý¡Ý¡Ý\n";
              tell_room(environment(this_player()),str);
/////////////
	      score = ({ 0,0,0,-j,1 });  // ({ ¦ÛºN,­JµP,©ñºj,¥x¼Æ<©ñºj¬°­tªº>,¥Ç³W })
              set_mjdata(me,score);
              for (i=0;i<Play;i++){
                  met=present(NowPlayerId[i], environment(this_object()));
                  if (!met) met=find_player(NowPlayerId[i]);
                  if (!met);
                  else{
              	     score = ({ 0,0,0,0,0 });  // ({ ¦ÛºN,­JµP,©ñºj,¥x¼Æ<©ñºj¬°­tªº>,¥Ç³W })
                     set_mjdata(met,score);
                     this_object()->save();
                  }
              }
           }
        }
        if(Play >= RECORD_PLAYERS)
        {
	        Mj="\n[0;1;36;46m¢i";
	        for (i=0; i<26; i++) Mj+="¢i";
	        Mj+="[1;36;46m¢«[0m\n";
	        Mj+="[1;36;46m¢i[0;36m¢j    "+HIW+"¤¤[0m¤å¦W¦r  [1m¤w[0mª±§½¼Æ  [1mÁ`[0m¾ÔÂÝ  [1m¦Û[0mºN¦¸¼Æ  [1m©ñ[0mºj¦¸¼Æ  [1m¥Ç[0m³W¦¸¼ÆÆ[1;36;46m¢j[0m\n";
	        for (i=0;i<Play;i++){
	            Mj+=sprintf("[1;36;46m¢i[0;36m¢j[1;37m%12s  [33m%8d  [35m%6d  [32m%8d  [34m%8d  [34m%8d[1;36;46m¢j[0m\n",
	                         NowPlayerId[i],record[NowPlayerId[i]]["rounds"],record[NowPlayerId[i]]["total"],record[NowPlayerId[i]]["self"],record[NowPlayerId[i]]["lose"],record[NowPlayerId[i]]["bad"]);
	        }
	        Mj+="[1;36;46m¢«";
	        for (i=0; i<26; i++) Mj+="¢v";
	        Mj+="[46m¢@[0m\n";
	        tell_room(environment(this_object()),Mj);
        }
        return wash_mj(Play);
}
int do_check_win(string str)
{
        int size=strlen(str),i,check;
        int t,k,W,T,S,Sp;
        string tempW="",tempT="",tempS="",tempB="";
        string Special="1w9w1s9s1t9teasowenojofaba";
 
        K=0;
        if (size > 33){
           if (do_check_Mj(str,"ea")&&do_check_Mj(str,"so")&&do_check_Mj(str,"we")&&do_check_Mj(str,"no")&&
               do_check_Mj(str,"jo")&&do_check_Mj(str,"fa")&&do_check_Mj(str,"ba")&&
               do_check_Mj(str,"1w")&&do_check_Mj(str,"9w")&&do_check_Mj(str,"1s")&&
               do_check_Mj(str,"9s")&&do_check_Mj(str,"1t")&&do_check_Mj(str,"9t")){
                  //¥ý§R±¼13°¦
                  for (i=0;i<sizeof(Special);i+=2) {
                      if (do_check_Mj(str,Special[i..i+1])){
                         str=do_delete_Mj(str,Special[i..i+1],1);
                      }
                  }
                  //¬dÁÙ¦³¨S13¤\¤¤ªºµP°¦
                  for (i=0;i<sizeof(Special);i+=2) {
                      if (do_check_Mj(str,Special[i..i+1])){
                         Sp++;
                      }
                  }
                  if (Sp==1){
                     for (i=0;i<sizeof(Special);i+=2) {
                         if (do_check_Mj(str,Special[i..i+1])){
                            str=do_delete_Mj(str,Special[i..i+1],1);
                            t++;
                          Tc+="@z";//13¤\
                         }
                     }
                  }
                  else if (Sp==2){
                    for (i=0;i<sizeof(str);i+=2){
                         if (do_check_Mj(str,str[i..i+1])==2){
                            str=do_delete_Mj(str,str[i..i+1],1);
                            Sp=0;
                            t++;
                         }
                    }
                    if (Sp!=0){
                       if (str[0..1]+1==str[2..3]){
                          str=do_delete_Mj(str,str[6..7],1);
                          t++;
                       }else{
                          str=do_delete_Mj(str,str[0..1],1);
                          t++;
                       }
                    }
                  }
           }else{
              for (i=0;i<sizeof(str);i+=2){
                   if (do_check_Mj(str,str[i..i+1])==2) Sp++;
                   else if (do_check_Mj(str,str[i..i+1])==3) check++;
                   else if (do_check_Mj(str,str[i..i+1])==4) Sp++;
              }
              if (Sp==14&&check==3){
                  for (i=0;i<sizeof(str);i+=2){
                      if (do_check_Mj(str,str[i..i+1])==2){
                         str=do_delete_Mj(str,str[i..i+1],2);
                         i=-2;
                      }
                      else if (do_check_Mj(str,str[i..i+1])==4){
                              str=do_delete_Mj(str,str[i..i+1],4);
                              i=-2;
                      }
                      else if (do_check_Mj(str,str[i..i+1])==3) t++;
                  }
                  t=1;
                  Tc+="@s";//7¹ï¤l
              }
           }
        }
        while(size--){
              size--;
          if (do_check_num(str[size..size+1],1) < 10) tempW+=str[size..size+1];
          else if (do_check_num(str[size..size+1],1) < 19) tempT+=str[size..size+1];
          else if (do_check_num(str[size..size+1],1) < 28) tempS+=str[size..size+1];
          else tempB+=str[size..size+1];
        }
        if (tempB!=""){
           for (i=0;i<strlen(tempB);i+=2){//
               check=do_check_Mj(tempB,tempB[i..i+1]);
               if (check==1) return 0;
               else if (check==2){
                       tempB=do_delete_Mj(tempB,tempB[i..i+1],2);
                       t++;
                       i=-2;
               }else if (check==3){
                        tempB=do_delete_Mj(tempB,tempB[i..i+1],3);
                        K++;
                        i=-2;
               }
           }//
        }
        if (tempW!="") W=check_hu(tempW);
        if (tempT!="") T=check_hu(tempT);
        if (tempS!="") S=check_hu(tempS);
        if (K==3) Tc+="@j";//¤T·t¨è
        else if (K==4) Tc+="@p";//¥|·t¨è
        else if (K==5) Tc+="@u";//¤­·t¨è
        if (W+T+S+t==1) return 1;
        return 0;
}
int check_hu(string strW)
{
        int i,j,check;
        int k,t;
        int A,B,C,D,E,F;
        for (i=0;i<sizeof(strW);i+=2) {//¦A§â¶¶¤l§R±¼
        A=do_check_num(strW[i..i+1],2);
        B=do_check_num(strW[i+2..i+3],2);
        C=do_check_num(strW[i+4..i+5],2);
        D=do_check_num(strW[i+6..i+7],2);
        E=do_check_num(strW[i+8..i+9],2);
        F=do_check_num(strW[i+10..i+11],2);
        if (sizeof(strW) > 11 &&do_check_num(strW[i-2..i-1],2)!=A&&A+1==B&&B==C&&C+1==D&&D==E&&E+1==F
           ||do_check_num(strW[i-2..i-1],2)!=A&&A==B&&B+1==C&&C==D&&D+1==E&&E==F){
              if (A==B&&B+1==C&&C==D&&D+1==E&&E==F){
                 if (do_check_Mj(Tc,"@G")==1){
                    Tc=do_delete_Mj(Tc,"@H",1);
                    Tc+="@H";
                 }else        Tc+="@G";
              }
              for (j=0;j<6;j++) {  //§R±¼¶¶¤l1 22 33 4 && 22 33 44
                  strW=do_delete_Mj(strW,strW[i..i+1],1);
              }
           i=-2;
        }
        else if (A+1==B&&B==C&&C==D&&D==E&&E+1==F){
              for (j=0;j<2;j++) {  //§R±¼¶¶¤l1 2 2 2 2 3
                  strW=do_delete_Mj(strW,strW[i..i+1],1);
              }
              strW=do_delete_Mj(strW,strW[i+6..i+7],1);
           i=-2;
           }
        else if (sizeof(strW) > 9 && A+1==B&&B==C&&C==D&&D+1==E){
              //§R±¼¶¶¤l12223¤¤ªº1 2 3
                  strW=do_delete_Mj(strW,strW[i..i+1],1);
                  strW=do_delete_Mj(strW,strW[i..i+1],1);
                  strW=do_delete_Mj(strW,strW[i+4..i+5],1);
           i=-2;
        }
        else if (sizeof(strW) > 9 && A==B&&B+1==C&&C+1==D&&D+1==E){
             for (j=0;j<3;j++) {   //§R±¼¶¶¤l11234¤¤ªº2 3 4
                 strW=do_delete_Mj(strW,strW[i+4..i+5],1);
             }
           i=-2;
        }
        else if (sizeof(strW) > 5 && A+1==B&&B+1==C){
             for (j=0;j<3;j++) {   //§R±¼¶¶¤l123¤¤ªº1 2 3
                 strW=do_delete_Mj(strW,strW[i..i+1],1);
             }
           i=-2;
        }
        }
 
        if (sizeof(strW) > 5){
           for (i=0;i<sizeof(strW);i+=2) {//¦A§â¨è§R±¼
               check=do_check_Mj(strW,strW[i..i+1]);
               if (check==3){
                  K++;
                  strW=do_delete_Mj(strW,strW[i..i+1],3);
                  i=-2;
                  }
              }
           }
           for (i=0;i<sizeof(strW);i+=2) {//¦A§â¹ï§R±¼
               check=do_check_Mj(strW,strW[i..i+1]);
               if (check==2){
                  t++;
                  strW=do_delete_Mj(strW,strW[i..i+1],2);
                  i=-2;
               }
           }
           if (strW!="") return 99;
           return t;
}
int do_touch(string str,object me)
{
        int i,check;
        mapping who;
 
        if (!me) me=this_player();
        if (check_id(me->query("id"),"player")!="");
        else {
           command("stare "+me->query("id"));
           command("say ³oµP§½¸ò§A¨SÃö«Y¡C");
           return 1;
        }
        if (!Playing){
           command("say µP§½ÁÙ¨S¶}©l§A­nºNµP¥hÂÃ°_¨Ó£«~~");
           return 1;
        }
        tell_object(me,"´«½ÖºNµP:"+NowPlayerId[NowPlayer]+"\n");
        if (me->query("id")!=NowPlayerId[NowPlayer]){
           command("hammer "+me->query("id"));
           command("say ·Q°½µP!!¨S¨º»ò®e©ö~~");
           return 1;
        }
        if (Touched){
           command("flop "+me->query("id"));
           command("say ¥´µP°Õ!!");
           return 1;
        }
        NO_HU=0;
        NO_GON=0;
        if (me->query("id")==P1Data["Id"]) who=P1Data;
        else if (me->query("id")==P2Data["Id"]) who=P2Data;
        else if (me->query("id")==P3Data["Id"]) who=P3Data;
        else if (me->query("id")==P4Data["Id"]) who=P4Data;
        if (who["Auto"]=="auto"){
           if (str=="AUTO");
           else{
             write("³]©w¦Û°ÊÅ¥µP«á¡B¤£¥i¦Û¤vºNµP¡C\n");
              return 1;
            }
        }
        Touched=1;
        str=List[count..count+1];
        count+=2;
        tell_room(environment(this_object()),me->name()+"ºN¤F¤@±iµP¡C\n",me);
        tell_object(me,"§AºN¤F¤@±iµP¡C\n");
        tell_object(me,"§AºN¨ì¤@±i.."+do_check_num(str,3)+"\n");
        if (who["Auto"]=="auto"){
           if (do_check_num(str,1) > 34){
              for (i=0;i<1;i++){
                   who["OutFlower"]+=str;
                   HU_F=1;
                   tell_room(environment(this_object()),YEL+me->name()+"»¡¡G"+HIB+"ªáµP"+NOR+YEL+"¸Éªá!!¡C\n\n"+NOR+me->name()+"©¹«á­±¸É¤F¤@±iµP¡C\n",me);
                   tell_object(me,"§A»¡¡G"+HIB+"ªáµP"+NOR+"¸Éªá!!¡C\n\n§A©¹«á­±¸É¤F¤@±iµP¡C\n");
                   str=List[end..end+1];
                   end-=2;
                   tell_object(me,"§AºN¨ì¤F¤@±i"+do_check_num(str,3)+"\n");
                   if (do_check_num(str,1) > 34) i--;
              }
           }
           check=do_check_Mj(who["AutoTin"],str);
           if (check!=0){
              who["Mj"]+=str;
              who["Mj"]=sort_data(who["Mj"]);
              return do_win(str,me);
           }
           call_out("do_dump",0,str,me);
        }
        who["Mj"]+=str;
        check_flower(who);
        i=0;
        if (who["Show"]=="¥N½X") i=3;
        if (who["Show"]=="color") i=5;
        tell_object(me,show_mj(who["Mj"],i));
        return 1;
}
int do_pon(string str,object me)
{
        int i;
        mapping who;
 
        if (!me) me=this_player();
        if (check_id(me->query("id"),"player")!="");
        else {
           command("stare "+me->query("id"));
           command("say ³oµP§½¸ò§A¨SÃö«Y¡C");
           return 1;
        }
        if (!Playing){
           command("die "+me->query("id"));
           command("say µP§½ÁÙ¨S¶}©l!!¸I§AªºÀY°Õ!!");
           return 1;
        }
        if (Touched){
           command("hammer "+me->query("id"));
           command("say §O¤H¨S¥´µP§A«ç»ò¸I¡C");
           return 1;
        }
        if (LastDumpId==me->query("id")){
           command("stare "+me->query("id"));
           command("say ¨º±iµP¬O§A¦Û¤v¥´ªº!¡C");
           return 1;
        }
        if (!str) str=LastDump;
        else if (str!=LastDump) return notify_fail("¨º±i"+do_check_num(str,0)+"¤w¸g¹L´Á¤F¡C\n");
        if (me->query("id")==P1Data["Id"]) who=P1Data;
        else if (me->query("id")==P2Data["Id"]) who=P2Data;
        else if (me->query("id")==P3Data["Id"]) who=P3Data;
        else if (me->query("id")==P4Data["Id"]) who=P4Data;
        if (who["Auto"]=="auto") return 1;
        i=do_check_Mj(who["Mj"],str);
        if (i==0) return notify_fail("§A¨S"+do_check_num(str,0)+"³o±iµP­n«ç»ò¸I¡C\n");
        if (i < 2) return notify_fail("§A¤â¤¤­n¦³¨â±i"+do_check_num(str,0)+"¤~¯à¸I¡C\n");
        message_vision("\n$N¤j¥s¡G"+do_check_num(str,0)+"¡ã"+HIW+"¡i ¡ã ¸I ¡ã ¡j"+NOR+"\n\n",me);
        for (i=0;i<Play;i++) {
            if (NowPlayerId[NowPlayer]==me->query("id")) break;
            NowPlayer++;
            NowPlayer%=Play;
        }
        for (i=0;i<3;i++) who["OutPon"]+=str;
        who["Mj"]=do_delete_Mj(who["Mj"],str,2);
        who["AutoPon"]=do_delete_Mj(who["AutoPon"],str,1);
        NO_HU=1;
        NO_GON=1;
        Touched=1;
        i=0;
        if (who["Show"]=="¥N½X") i=3;
        if (who["Show"]=="color") i=5;
        tell_object(me,show_mj(who["Mj"],i));
        return delete_last_dump(who["Id"]);
}
//ÀË¬d¥Ø«eµP§½¬O§_¥¿±`. return 0 (¤£¥¿±`,¥irestart) return 1(¥¿±`)
int check_player()
{
	object user;
	if(Play<2) return 0;
	else {
		if(Play > 3)
		{
			if(user = present(P4Data["Id"], environment(this_object())))
			{
				if(user->query_temp("netdead")) return 0;
				if(query_idle(user)>180) return 0;
				if(user->is_inactive()) return 0;
			}
			else return 0;
		}
		if(Play > 2)
		{
			if(user = present(P3Data["Id"], environment(this_object())))
			{
				if(user->query_temp("netdead")) return 0;
				if(query_idle(user)>180) return 0;
				if(user->is_inactive()) return 0;
			}
			else return 0;
		}
		if(user = present(P2Data["Id"], environment(this_object())))
		{
			if(user->query_temp("netdead")) return 0;
			if(query_idle(user)>180) return 0;
			if(user->is_inactive()) return 0;
		}
		else return 0;
		if(user = present(P1Data["Id"], environment(this_object())))
		{
			if(user->query_temp("netdead")) return 0;
			if(query_idle(user)>180) return 0;
			if(user->is_inactive()) return 0;
		}
		else return 0;
		
	}
	return 1;
}

int do_restart(string str)
{
        object me=this_player();
        if (me->query("id")=="guest") return 0;
        if (str!="mj"){
           if (check_id(me->query("id"),"player")!="");
           else if(!check_player());
           else 
           {
              command("stare "+me->query("id"));
              command("say ³oµP§½¸ò§A¨SÃö«Y¡C");
              return 1;
           }
        }
        message_vision("$N§âµP§½­«·s³]©w¡C\n",me);
        message_vision(YEL+"$N»¡¡GµP§½­«·s³]©w½Ð¥Î"+HIR+" addin "+NOR+YEL+"¥[¤JµP§½¡C\n"+NOR,this_object());
        NowPlayerId[0]="";
        NowPlayerId[1]="";
        NowPlayerId[2]="";
        NowPlayerId[3]="";
        P1Data["Id"]="";
        P2Data["Id"]="";
        P3Data["Id"]="";
        P4Data["Id"]="";
        Count=0;
        LookP ="";
        Play=START;
        Times=START;
        end=END;
        count=START;
        Playing=START;
        return 1;
}
int wash_mj(int amount)
{
        int i,x;
        string str,countstr="";
        mixed *X,MjE_Data = ([
"1w" : 0,"2w" : 0,"3w" : 0,"4w" : 0,"5w" : 0,"6w" : 0,"7w" : 0,"8w" : 0,"9w" : 0,
"1s" : 0,"2s" : 0,"3s" : 0,"4s" : 0,"5s" : 0,"6s" : 0,"7s" : 0,"8s" : 0,"9s" : 0,
"1t" : 0,"2t" : 0,"3t" : 0,"4t" : 0,"5t" : 0,"6t" : 0,"7t" : 0,"8t" : 0,"9t" : 0,
"ea" : 0,"so" : 0,"we" : 0,"no" : 0,"jo" : 0,"fa" : 0,"ba" : 0,
"f1" : 0,"f2" : 0,"f3" : 0,"f4" : 0,"f5" : 0,"f6" : 0,"f7" : 0,"f8" : 0
                            ]);
        if (!Play){
           command("say ¨S¦³ª±®a­n§Ú¥Õ¬~µP!!ªù³£¨S¦³¡C");
           return 1;
        }
        if (Playing){
           command("say µP§½¥¿¦b¶i¦æ¤¤¡C");
           return 1;
        }
        command("say §ÚÀ°¦£¬~µP¡Aµ¥µ¥½Ö­J­n¦Y¬õ³á..:)");
        if (Play<RECORD_PLAYERS) command("say ª±®a¤£¨¬¦³®Ä¤H¼Æ©Ò¥H¤£­p¤À¡C");
        P1Data["Mj"]="";
        P1Data["OutGon"]="";
        P1Data["Out"]="";
        P1Data["OutPon"]="";
        P1Data["OutFlower"]="";
        P1Data["Auto"]="";
        P1Data["AutoTin"]="";
        P1Data["AutoGon"]="";
        P1Data["AutoPon"]="";
        P1Data["Dump"]="";
 
        P2Data["Mj"]="";
        P2Data["OutGon"]="";
        P2Data["Out"]="";
        P2Data["OutPon"]="";
        P2Data["OutFlower"]="";
        P2Data["Auto"]="";
        P2Data["AutoTin"]="";
        P2Data["AutoGon"]="";
        P2Data["AutoPon"]="";
        P2Data["Dump"]="";
 
        P3Data["Mj"]="";
        P3Data["OutGon"]="";
        P3Data["Out"]="";
        P3Data["OutPon"]="";
        P3Data["OutFlower"]="";
        P3Data["Auto"]="";
        P3Data["AutoTin"]="";
        P3Data["AutoGon"]="";
        P3Data["AutoPon"]="";
        P3Data["Dump"]="";
 
        P4Data["Mj"]="";
        P4Data["OutGon"]="";
        P4Data["Out"]="";
        P4Data["OutPon"]="";
        P4Data["OutFlower"]="";
        P4Data["Auto"]="";
        P4Data["AutoTin"]="";
        P4Data["AutoGon"]="";
        P4Data["AutoPon"]="";
        P4Data["Dump"]="";
 
        end=END;
        NO_HU=START;
        NO_GON=START;
        count=START;
        Playing=START;
        List="";
        NowPlayer=START;
        Touched=START;
        Auto=START;
        Auto_Tin=START;
        Auto_Gon=START;
        Auto_Pon=START;
        Goned=START;
        LastDump="";
        LastDumpId="";
        X = keys(MjE_Data);
        for (i=0;i<144;i++){
            x = random(sizeof(X));
            if (X[x]=="f1"||X[x]=="f2"||X[x]=="f3"||X[x]=="f4"||
                X[x]=="f5"||X[x]=="f6"||X[x]=="f7"||X[x]=="f8"){
                if (MjE_Data[X[x]] < 1){
                   MjE_Data[X[x]] = MjE_Data[X[x]] + 1;
                   List += X[x];
                } else i--;
            }else{
               if (MjE_Data[X[x]] < 4){
                  MjE_Data[X[x]] = MjE_Data[X[x]] + 1;
                  List += X[x];
               } else i--;
           }
        }
 
//        for (i=0;i<sizeof(X);i++) printf("%s=%d ",X[i],MjE_Data[X[i]]);
        message_vision("\n$N«Ü§Öªº§â®à¤WªºµP¾ã²z¦n¡C\n\n",this_object());
        command("say ¶â!!¦n¤F¥i¥H¶}©l¤F¨Ó§a!!");
        if (Count) countstr="[³s²ø"+chinese_number(Count)+"]";
        if (!Times);
        else{
          if (Count);
          else {
            str=NowPlayerId[0];
            if (Play>1) NowPlayerId[0]=NowPlayerId[1];
            if (Play>2) NowPlayerId[1]=NowPlayerId[2];
            if (Play>3) NowPlayerId[2]=NowPlayerId[3];
            NowPlayerId[Play-1]=str;
          }
        }
        if (Times/Play == 4) Times=0;
        if (Times/Play == 3) str=HIW+"¥_­·"+NOR;
        if (Times/Play == 2) str=HIY+"¦è­·"+NOR;
        if (Times/Play == 1) str=HIR+"«n­·"+NOR;
        if (Times/Play == 0) str=HIG+"ªF­·"+NOR;
        i=Times;
        i%=Play;
        i++;
        message_vision("["+str+chinese_number(i)+"]µP§½¶}©l:²ø®a"+HIY+NowPlayerId[0]+HIR+countstr+NOR+"ÂY¥X»ë¤l"+
                       "["+HIG+chinese_number(i=3+random(16))+NOR+ "]ÂI¡C\n",this_object());
        //ª±®a¨úµP¤@¦¸¨ú16°¦:Q
        if (Play>0) P1Data["Mj"]=List[0..31];
        if (Play>1) P2Data["Mj"]=List[32..63];
        if (Play>2) P3Data["Mj"]=List[64..95];
        if (Play>3) P4Data["Mj"]=List[96..127];
        count=(Play*2*16);
        if (Play>0) check_flower(P1Data);
        if (Play>1) check_flower(P2Data);
        if (Play>2) check_flower(P3Data);
        if (Play>3) check_flower(P4Data);
        Playing=1;
        message_vision(YEL+"$N»¡¡G²ø®a"+HIY+NowPlayerId[0]+NOR+YEL+"½Ð¶}ªùµP¡C\n"+NOR,this_object());
        return 1;
}
int do_setmj(string str)
{
        int check;
        string numstr;
        mapping who;
        object me=this_player();
 
        if (me->query("id")==P1Data["Id"]) who=P1Data;
        else if (me->query("id")==P2Data["Id"]) who=P2Data;
        else if (me->query("id")==P3Data["Id"]) who=P3Data;
        else if (me->query("id")==P4Data["Id"]) who=P4Data;
        else return 0;
        if (!str){
           numstr=this_object()->name()+"¹ïµÛ§A»¡: §A¥Ø«eªº³]©w¦³:\n";
          if (who["AutoTin"]!="") numstr+="¹J¨ì"+HIB+show_mj(who["AutoTin"],2)+NOR+"·|¦Û°Ê"+HIB+"[­JµP]"+NOR+"¡C\n";
          if (who["AutoGon"]!="") numstr+="¹J¨ì"+HIY+show_mj(who["AutoGon"],2)+NOR+"·|¦Û°Ê"+HIY+"[ºbµP]"+NOR+"¡C\n";
          if (who["AutoPon"]!="") numstr+="¹J¨ì"+HIG+show_mj(who["AutoPon"],2)+NOR+"·|¦Û°Ê"+HIG+"[¸IµP]"+NOR+"¡C\n";
          if (who["Show"]=="¥N½X")    numstr+="Åã¥Ü¤è¦¡¬°"+HIY+"[¥N½X]"+NOR+"¤è¦¡¡C\n";
          if (who["Show"]=="color")   numstr+="Åã¥Ü¤è¦¡¬°"+HIG+"[±m¦â]"+NOR+"¡C\n";
          if (who["Auto"]=="auto")    numstr+="§A³]©w"+HIR+"[¦Û°ÊÅ¥µP]"+NOR+"¡C\n";
          if (who["AutoTin"]==""&&who["AutoGon"]==""&&who["AutoPon"]==""&&who["Show"]==""&&who["Auto"]=="") numstr+="§A¨S¦³¥ô¦ó³]©w¡C\n";
           tell_room(environment(me),this_object()->name()+"¦b"+me->name()+"¦ÕÃä»¡¤F¤@¨Ç¸Ü¡C\n",me);
           tell_object(me,numstr);
           return 1;
        }
        if (sscanf(str,"%s %s",str,numstr)!=2) return notify_fail("«ü¥O:setmj <tin>&<gon>&<pon> <¥N½X>\n");
        if (str=="tin"){
           if (numstr=="none"){
              who["AutoTin"]="";
              return notify_fail("§A¨ú®ø¦Û°Ê­JµP³]©w¡C\n");
           }
           check=do_check_Mj(MjE,numstr);
           if (check!=1) return notify_fail("¨S¦³["+numstr+"]³oºØµP¡C\n");
           check=do_check_Mj(who["AutoTin"],numstr);
           if (check){
              who["AutoTin"]=do_delete_Mj(who["AutoTin"],numstr,1);
              return notify_fail("§A"+HIR+"§R±¼¤F"+NOR+"¹J¨ì"+do_check_num(numstr,0)+"·|¦Û°Ê­JµPªº³]©w¡C\n");
           }
           who["AutoTin"]+=numstr;
           Auto_Tin=1;
           write("§A³]©w¹J¨ì"+do_check_num(numstr,0)+"®É·|¦Û°Ê­JµP¡C\n");
           return 1;
        }
        else if (str=="gon"){
           if (numstr=="none"){
              who["AutoGon"]="";
              return notify_fail("§A¨ú®ø¦Û°ÊºbµP³]©w¡C\n");
           }
           check=do_check_Mj(who["Mj"],numstr);
           if (check==0) return notify_fail("§A¨S"+do_check_num(numstr,0)+"³o±iµP¡C\n");
           if (check < 3) return notify_fail("§A¤â¤¤­n¦³¤T±i"+do_check_num(numstr,0)+"¤~¯à³]©wºb¦¹µP¡C\n");
           check=do_check_Mj(who["AutoGon"],numstr);
           if (check){
              who["AutoGon"]=do_delete_Mj(who["AutoGon"],numstr,1);
              return notify_fail("§A"+HIR+"§R±¼¤F"+NOR+"¹J¨ì"+do_check_num(numstr,0)+"·|¦Û°ÊºbµPªº³]©w¡C\n");
           }
           who["AutoGon"]+=numstr;
           Auto_Gon=1;
           write("§A³]©w¹J¨ì"+do_check_num(numstr,0)+"®É·|¦Û°ÊºbµP¡C\n");
           return 1;
        }
        else if (str=="pon"){
           if (numstr=="none"){
              who["AutoPon"]="";
              return notify_fail("§A¨ú®ø¦Û°Ê¸IµP³]©w¡C\n");
           }
           check=do_check_Mj(who["Mj"],numstr);
           if (check==0) return notify_fail("§A¨S"+do_check_num(numstr,0)+"³o±iµP¡C\n");
           if (check < 2) return notify_fail("§A¤â¤¤­n¦³¨â±i"+do_check_num(numstr,0)+"¤~¯à³]©w¸I¦¹µP¡C\n");
           check=do_check_Mj(who["AutoPon"],numstr);
           if (check){
              who["AutoPon"]=do_delete_Mj(who["AutoPon"],numstr,1);
              return notify_fail("§A"+HIR+"§R±¼¤F"+NOR+"¹J¨ì"+do_check_num(numstr,0)+"·|¦Û°Ê¸IµPªº³]©w¡C\n");
           }
           who["AutoPon"]+=numstr;
           Auto_Pon=1;
           write("§A³]©w¹J¨ì"+do_check_num(numstr,0)+"®É·|¦Û°Ê¸IµP¡C\n");
           return 1;
        }
        else if (str=="show"){
           if (numstr=="none"||numstr=="1"){
              who["Show"]="";
              return notify_fail("§A¨ú®øÅã¥Ü³]©w¡C\n");
           }
 
           if (numstr=="¥N½X"||numstr=="3"){
              numstr="¥N½X";
              write("§A³]©w¥uÅã¥Ü¥N½X¡C\n");
           }
           else if (numstr=="color"||numstr=="2"){
                numstr="color";
                 write("§A³]©w±m¦âÅã¥Ü¡C\n");
           }
           else return 1;
           who["Show"]=numstr;
           return 1;
        }
        else if (str=="auto"){
           if (numstr=="none"){
              return notify_fail("¤£¯à¨ú®ø¦Û°ÊÅ¥µP¡A­n¬O³]©w¿ù»~µ¥µÛ¶B­J§a!!:>¡C\n");
           }
           if (who["AutoTin"]=="") return notify_fail("½Ð¥ý³]©w­nÅ¥ªºµP¡C\n");
           if (!Touched) return notify_fail("½Ð¥ýºNµP¦A°µ¦¹³]©w¡C\n");
           if (numstr=="tin") write("§A³]©w¦Û°ÊÅ¥µP¡C\n");
           else return 1;
           message_vision("\n$N¤j¥s¤@Án¡G"+HIW+"§ÚÅ¥°Õ¡ã¡ã¡ã"+NOR+"\n\n",me);
           Auto=1;
           who["Auto"]="auto";
           return 1;
        }
        else return notify_fail("¨S¦³³oºØ³]©w¡C\n");
}
int do_check_eat(string num1,string num2,string LastDump)
{
        int A,B,C;
        A=do_check_num(num1,1);
        B=do_check_num(num2,1);
        C=do_check_num(LastDump,1);
        if (A<10){
           if (B>10||C>10) return 0;
        }
        else if (A<19&&A>10){
                if (B>19||C>19&&B<10||C<10) return 0;
        }
        else if (A<28&&A>19){
                if (B<19||C<19) return 0;
        }
        A=do_check_num(num1,2);
        B=do_check_num(num2,2);
        C=do_check_num(LastDump,2);
 
        if (A > 9 || B > 9 || C > 9) return 0;
        if ((A+B)%2!=0){
           if (A > B){
               if (C==(A+1) || C==(A-2)) return 1;
           }else{
               if (C==(B+1) || C==(B-2)) return 1;
           }
           return 0;
        }else{
            if (A > B){
              if (C==(A-1) || C==(B+1)) return 1;
             }else{
              if (C==(B-1) || C==(A+1)) return 1;
             }
            return 0;
        }
}
string show_mj(string str,int flag)
{
        string Mj="",Mj1="";
        int size=strlen(str)+2,a,b;
        if (!str||str=="") return "";
        if (flag!=3)
        {
           if (flag==2)
           {
           	while(size--){
              		size--;
             		Mj+=do_check_num(str[size..size+1],3)+".";
           	}
           	Mj1=Mj;
           }
           else{
 	     while(size--){
                size--;
                Mj+=do_check_num(str[size..size+1],0);
             }
             size=strlen(Mj);
             Mj1="¢z";
             for (a=0;a<(size/2)-1;a++){
                 if (a%2==0) Mj1+="¢w";
                 else Mj1+="¢s";
             }
             Mj1+="¢{\n¢x";
 
             for (a=0;a<size-1;a++){
                 if (flag==5 || flag==6){
                    if (Mj[a+2..a+3]=="¸U") Mj1+=HIR;
                    else if (Mj[a+2..a+3]=="µ©") Mj1+=HIC;
                    else if (Mj[a+2..a+3]=="¯Á") Mj1+=HIG;
                    else if (Mj[a+2..a+3]=="­·") Mj1+=HIM;
                    else if (Mj[a+2..a+3]=="¤¤") Mj1+=HIR;
                    else if (Mj[a+2..a+3]=="µo") Mj1+=HIG;
                    else if (Mj[a+2..a+3]=="ªO") Mj1+=HIW;
                    else if (Mj[a+2..a+3]=="¬K"
                         ||  Mj[a+2..a+3]=="®L"
                         ||  Mj[a+2..a+3]=="¬î"
                         ||  Mj[a+2..a+3]=="¥V") Mj1+=HIR;
                    else if (Mj[a+2..a+3]=="±ö"
                         ||  Mj[a+2..a+3]=="Äõ"
                         ||  Mj[a+2..a+3]=="¦Ë"
                         ||  Mj[a+2..a+3]=="µâ") Mj1+="[1;30m";
                 }
                 Mj1+=Mj[a..a+1];
                 a++;a++;a++;
                 Mj1+=NOR+"¢x";
             }
             Mj1+="\n¢x";
             for (a=2;a<size;a++){
                 if (flag==5 || flag==6){
                         if (Mj[a..a+1]=="¸U") Mj1+=RED;
                    else if (Mj[a..a+1]=="¯Á") Mj1+=GRN;
                    else if (Mj[a..a+1]=="µ©") Mj1+=CYN;
                    else if (Mj[a..a+1]=="­·") Mj1+=MAG;
                    else if (Mj[a..a+1]=="¤¤") Mj1+=HIR;
                    else if (Mj[a..a+1]=="µo") Mj1+=HIG;
                    else if (Mj[a..a+1]=="¥Õ") Mj1+=HIW;
                    else if (Mj[a..a+1]=="¬K") Mj1+=HIG;
                    else if (Mj[a..a+1]=="®L") Mj1+=HIB;
                    else if (Mj[a..a+1]=="¬î") Mj1+=HIY;
                    else if (Mj[a..a+1]=="¥V") Mj1+=HIW;
                    else if (Mj[a..a+1]=="±ö") Mj1+=HIW;
                    else if (Mj[a..a+1]=="Äõ") Mj1+=HIR;
                    else if (Mj[a..a+1]=="¦Ë") Mj1+=HIG;
                    else if (Mj[a..a+1]=="µâ") Mj1+=HIY;
                 }
                 Mj1+=Mj[a..a+1];
                 a++;a++;a++;
                 Mj1+=NOR+"¢x";
             }
             Mj1+="\n¢|";
             for (a=(size/2)-1;a>0;a--){
                 if (a%2!=0){
                    if (flag==0 || flag==5) Mj1+=str[a-1..a];
                    else Mj1+="¢w";
                 }
                 else Mj1+="¢r";
             }
             Mj1+="¢}\n";
           }
           return Mj1;
        }else{
            size*=2;
            for (a=(size/2)-1;a>0;a--){
                if (a%2!=0) Mj1+=str[a-1..a];
                else Mj1+=" ";
           }
           Mj1+="\n";
        }
        return Mj1;
}
string check_id(string str,string kind)
{
        int check,i;
        if (!str) return "";
        if (kind=="tin"){
           check=NowPlayer;
           for (i=0;i<Play-1;i++) {
           if (NowPlayerId[check]==P1Data["Id"] && do_check_Mj(P1Data["AutoTin"],str)!=0) return P1Data["Id"];
           if (NowPlayerId[check]==P2Data["Id"] && do_check_Mj(P2Data["AutoTin"],str)!=0) return P2Data["Id"];
           if (NowPlayerId[check]==P3Data["Id"] && do_check_Mj(P3Data["AutoTin"],str)!=0) return P3Data["Id"];
           if (NowPlayerId[check]==P4Data["Id"] && do_check_Mj(P4Data["AutoTin"],str)!=0) return P4Data["Id"];
               check++;
               check%=Play;
           }
           return "";
        }
        if (kind=="gon"){
           check=do_check_Mj(P1Data["AutoGon"],str);
           if (check!=0){
              check=do_check_Mj(P1Data["Mj"],str);
              if (check < 3) return "";
              else return P1Data["Id"];
           }
           check=do_check_Mj(P2Data["AutoGon"],str);
           if (check!=0){
              check=do_check_Mj(P2Data["Mj"],str);
              if (check < 3) return "";
              else return P2Data["Id"];
           }
           check=do_check_Mj(P3Data["AutoGon"],str);
           if (check!=0){
              check=do_check_Mj(P3Data["Mj"],str);
              if (check < 3) return "";
              else return P3Data["Id"];
           }
           check=do_check_Mj(P4Data["AutoGon"],str);
           if (check!=0){
              check=do_check_Mj(P4Data["Mj"],str);
              if (check < 3) return "";
              else return P4Data["Id"];
           }
           return "";
        }
        if (kind=="pon"){
           check=do_check_Mj(P1Data["AutoPon"],str);
           if (check!=0){
              check=do_check_Mj(P1Data["Mj"],str);
              if (check < 2) return "";
              else return P1Data["Id"];
           }
           check=do_check_Mj(P2Data["AutoPon"],str);
           if (check!=0){
              check=do_check_Mj(P2Data["Mj"],str);
              if (check < 2) return "";
              else return P2Data["Id"];
           }
           check=do_check_Mj(P3Data["AutoPon"],str);
           if (check!=0){
              check=do_check_Mj(P3Data["Mj"],str);
              if (check < 2) return "";
              else return P3Data["Id"];
           }
           check=do_check_Mj(P4Data["AutoPon"],str);
           if (check!=0){
              check=do_check_Mj(P4Data["Mj"],str);
              if (check < 2) return "";
              else return P4Data["Id"];
           }
           return "";
        }
        if (kind=="player"){
           for (i=0;i<Play;i++) {
               if (NowPlayerId[i]==str) check=1;
           }
        if (check) return "Y";
        return "";
        }
}
int delete_last_dump(string whoId)
{
        mapping who;
        if (LastDumpId==P1Data["Id"]) who=P1Data;
        else if (LastDumpId==P2Data["Id"]) who=P2Data;
        else if (LastDumpId==P3Data["Id"]) who=P3Data;
        else if (LastDumpId==P4Data["Id"]) who=P4Data;
        if (who["Dump"]!="") who["Dump"]=do_delete_Mj(who["Dump"],LastDump,1);
        return 1;
}
//§â­^¤å¦rÂà¬°¥N½X or ¤¤¤å flag 1 ´N¬OÂà¬°¥N½X flag 2 Âà¬°1..9,flag 3 ¬°¤¤¤å¥[¤WÃC¦â
mixed do_check_num(string str,int flag)
{
        int number;
 
        if (!str) return MjC[0];
        sscanf(str,"%d%s",number,str);
        if (number == 0){
        if (str=="ea") number=28;
        else if (str=="so") number=29;
        else if (str=="we") number=30;
        else if (str=="no") number=31;
        else if (str=="jo") number=32;
        else if (str=="fa") number=33;
        else if (str=="ba") number=34;
        else if (str=="f1") number=35;
        else if (str=="f2") number=36;
        else if (str=="f3") number=37;
        else if (str=="f4") number=38;
        else if (str=="f5") number=39;
        else if (str=="f6") number=40;
        else if (str=="f7") number=41;
        else if (str=="f8") number=42;
        else if (str=="xx") number=43;
        }else{
          if (str=="w") number=0+number;
          else if (str=="t") number=9+number;
          else if (str=="s") number=18+number;
          if (flag==2){
             number%=9;
             if (number==0) number=9;
          }
        }
        if (!flag) return MjC[number];
        else if(flag==3) {
        	if(str=="w") return HIR+MjC[number]+NOR;
        	else if(str=="t") return HIC+MjC[number]+NOR;
        	else if(str=="s") return HIG+MjC[number]+NOR;
        	else return HIM+MjC[number]+NOR;
        }
        else return number;
}
void check_flower(mapping who)
{
        string newstr = "",str=who["Mj"],temp,temp1;
        int i = strlen(str),j;
 
        while(i--){
              i--;
           temp=str[i..i+1];
           if (temp=="f1"||temp=="f2"||temp=="f3"||temp=="f4"||
               temp=="f5"||temp=="f6"||temp=="f7"||temp=="f8"){
              if (Playing){
                 tell_room(environment(this_object()),YEL+this_player()->name()+"»¡¡G"+HIB+"ªáµP"+NOR+YEL+"¸Éªá!!¡C\n\n"+NOR+this_player()->name()+"©¹«á­±¸É¤F¤@±iµP¡C\n",this_player());
                 tell_object(this_player(),"§A»¡¹D¡G"+HIB+"ªáµP"+NOR+"¸Éªá!!¡C\n\n§A©¹«á­±¸É¤F¤@±iµP¡C\n");
                 tell_object(this_player(),"§AºN¨ì¤F¤@±i"+do_check_num(List[end..end+1],0)+"\n");
              }
              HU_F=1;
              who["OutFlower"]+=temp;
              str[i..i+1]=List[end..end+1];
              end-=2;
              i+=2;
              continue;
           }
           else newstr+=temp;
        }
        who["Mj"]=sort_data(newstr);
}
int do_check_Mj(string datastr,string str)
{
        int size=strlen(datastr),check=0;
 
        while(size--){
              size--;
          if (datastr[size..size+1]==str) check++;
        }
        return check;
}
string do_delete_Mj(string datastr,string str,int amount)//§â¬YµP¥h±¼
{
        int size=strlen(datastr),check;
        string temp="";
 
        while(size--){
              size--;
          if (datastr[size..size+1]==str && amount!=0) amount--;
          else temp+=datastr[size..size+1];
        }
        size=strlen(temp);
        datastr=temp;
        temp="";
        while(size--){
              size--;
              temp+=datastr[size..size+1];
        }
        return temp;
}
string sort_data(string str)
{
        int i = strlen(str),a,b,c,d;
 
        string newstr="",temp="";
        for (a=-1;a<i;a++){
            a++;
            for (b=a+2;b<i;b++){
                b++;
                c=do_check_num(str[a..a+1],1);
                d=do_check_num(str[b-1..b],1);
                if (c < d){
                   temp=str[a..a+1];
                   str[a..a+1]=str[b-1..b];
                   str[b-1..b]=temp;
                }
            }
        }
        return str;
}
int do_look(string arg)
{
        int i,l;
        object me=this_player();
        string Mj="",p1o="",p2o="",p3o="",p4o="",verb;
        mapping who;
 	verb = query_verb();
        if (verb==".")  arg="mj";
        if (verb=="..") arg="chicken";
        if (verb==".1") arg="1p";
        if (verb==".2") arg="2p";
        if (verb==".3") arg="3p";
        if (verb==".4") arg="4p";
        if (verb==".0") arg="all";
        if (me->query("id")==P1Data["Id"]) who=P1Data;
        else if (me->query("id")==P2Data["Id"]) who=P2Data;
        else if (me->query("id")==P3Data["Id"]) who=P3Data;
        else if (me->query("id")==P4Data["Id"]) who=P4Data;
        else return 0;
        if (who["Auto"]=="auto") l=1;
        if (arg=="1p"||arg=="2p"||arg=="3p"||arg=="4p"||arg=="all"||arg=="chicken"||arg=="end"||arg=="dump"||arg=="mj");
        else return 0;
        if (arg=="1p") who=P1Data;
        if (arg=="2p") who=P2Data;
        if (arg=="3p") who=P3Data;
        if (arg=="4p") who=P4Data;
        if (arg=="1p"||arg=="2p"||arg=="3p"||arg=="4p"){
           i=0;
           if (who["Show"]=="¥N½X") i=3;
           if (who["Show"]=="color") i=5;
           if (!Playing||check_id(me->query("id"),"player")==""||l==1){
              if (who["OutGon"]!=""){
                 Mj+=who["Id"]+":·tºbªºµP¦³:\n";
                 Mj+=show_mj(who["OutGon"],i+1);
              }
              Mj+=who["Id"]+":¤â¤¤ªºµP¦³:\n";
              Mj+=show_mj(who["Mj"],i);
           }
           Mj+=who["Id"]+":Â\\¦b¥~­±ªºµP¦³:\n";
           Mj+=show_mj(who["Out"]+who["OutPon"]+who["OutFlower"],i+1);
           Mj+=who["Id"]+":¥´¹LªºµP:\n";
           Mj+=show_mj(who["Dump"],2);
        }
        else if (arg=="mj") {
           if (!Playing) return 0;
           if (who["OutGon"]!=""){
              Mj+="§Aªº·tºbªºµP¦³:\n";
              Mj+=show_mj(who["OutGon"],1);
           }
           if (who["Show"]=="¥N½X") i=3;
           if (who["Show"]=="color") i=5;
           Mj+="§AÂ\\¦b¥~­±ªºµP¦³:\n";
           Mj+=show_mj(who["Out"]+who["OutPon"]+who["OutFlower"],i+1);
           Mj+="§A¤â¤¤ªºµP¦³:\n";
           Mj+=show_mj(who["Mj"],i);
           Mj+="§Aªº³]©w¦³:";
        }else if (arg=="all") {
              i=0;
              if (who["Show"]=="¥N½X") i=3;
              if (who["Show"]=="color") i=5;
              Mj+=P1Data["Id"]+":Â\\¦b¥~­±ªºµP¦³:\n";
              Mj+=show_mj(P1Data["Out"]+P1Data["OutPon"]+P1Data["OutFlower"],i+1);
              Mj+=P1Data["Id"]+":¥´¹LªºµP¦³:\n";
              Mj+=show_mj(P1Data["Dump"],2)+"\n";
              Mj+=P2Data["Id"]+":Â\\¦b¥~­±ªºµP¦³:\n";
              Mj+=show_mj(P2Data["Out"]+P2Data["OutPon"]+P2Data["OutFlower"],i+1);
              Mj+=P2Data["Id"]+":¥´¹LªºµP¦³:\n";
              Mj+=show_mj(P2Data["Dump"],2)+"\n";
              Mj+=P3Data["Id"]+":Â\\¦b¥~­±ªºµP¦³:\n";
              Mj+=show_mj(P3Data["Out"]+P3Data["OutPon"]+P3Data["OutFlower"],i+1);
              Mj+=P3Data["Id"]+":¥´¹LªºµP¦³:\n";
              Mj+=show_mj(P3Data["Dump"],2)+"\n";
              Mj+=P4Data["Id"]+":Â\\¦b¥~­±ªºµP¦³:\n";
              Mj+=show_mj(P4Data["Out"]+P4Data["OutPon"]+P4Data["OutFlower"],i+1);
              Mj+=P4Data["Id"]+":¥´¹LªºµP¦³:\n";
              Mj+=show_mj(P4Data["Dump"],2)+"\n";
        }else if (arg=="chicken"){
                 if (Playing){
                    Mj=LookP+"¥¿»{¯uªº¦b¥´µP\n";
                    Mj+="ÁÙ³Ñ¤U"+sprintf("%d",(end-count-16-Goned)/2)+"°¦µP´N¬y§½¤F¡C\n";
                    if (LastDump!="") Mj+=LastDumpId+"­è­è¥´¥X¤F"+show_mj(LastDump,2)+"\n";
                    if (Count) Mj+=NowPlayerId[0]+":³s²ø"+chinese_number(Count)+"\n";
                    if (P1Data["Out"]=="" && P1Data["OutPon"]=="") p1o=HIY+"ªù²M"+NOR;
                    if (P2Data["Out"]=="" && P2Data["OutPon"]=="") p2o=HIY+"ªù²M"+NOR;
                    if (P3Data["Out"]=="" && P3Data["OutPon"]=="") p3o=HIY+"ªù²M"+NOR;
                    if (P4Data["Out"]=="" && P4Data["OutPon"]=="") p4o=HIY+"ªù²M"+NOR;
                    Mj+="1.ªF®a¬O:"+NowPlayerId[0]+p1o+"\n2.«n®a¬O:"+NowPlayerId[1]+p2o+"\n";
                    Mj+="3.¦è®a¬O:"+NowPlayerId[2]+p3o+"\n4.¥_®a¬O:"+NowPlayerId[3]+p4o+"\n";
                 }
                 else if (NowPlayerId[0]!="") Mj=LookP+"¥¿¦bµ¥¤H¥´µP";
                 else Mj=LookP+"¤@°¦³Â±NÂû¥¿µ¥¤H¥[¤J(addin)µP§½¡C";
        }else if (arg=="end"){
           Mj+="ÁÙ¦³"+chinese_number((end-count-16-Goned)/2)+"°¦µP´N¬y§½¤F\n";
        }else if (arg=="dump"){
           Mj+=LastDumpId+"­è­è¥´¥X¤F"+show_mj(LastDump,2)+"\n";
        }
        else return 0;
        if (arg=="mj"){
          if (who["AutoTin"]!="") Mj+="¹J¨ì"+show_mj(who["AutoTin"],2)+"·|¦Û°Ê­JµP¡B";
          if (who["AutoGon"]!="") Mj+="¹J¨ì"+show_mj(who["AutoGon"],2)+"·|¦Û°ÊºbµP¡B";
          if (who["AutoPon"]!="") Mj+="¹J¨ì"+show_mj(who["AutoPon"],2)+"·|¦Û°Ê¸IµP¡C";
          if (who["Show"]=="¥N½X")    Mj+="Åã¥Ü¤è¦¡¬°¥N½X¤è¦¡¡C";
          if (who["Show"]=="color")   Mj+="Åã¥Ü¤è¦¡¬°±m¦â¡C";
          if (who["Auto"]=="auto")    Mj+="§A³]©w¦Û°ÊÅ¥µP¡C";
          if (who["AutoTin"]==""&&who["AutoGon"]==""&&who["AutoPon"]==""&&who["Show"]==""&&who["Auto"]=="") Mj+="§A¨S¦³¥ô¦ó³]©w¡C\n";
        }
        printf("%s\n",Mj);
        return 1;
}
int do_tin(string str)
{
write(@HELP_TIN

½Ð¨Ï¥Î setmj ¨Ó³]©w¦Û°ÊÅ¥µP¡C
--------------------------------------------------------------------
1: setmj tin 1w        ³]©w·|¦Û°Ê­J¤@¸U(1w)¡C
2: setmj auto tin      ³]©w¦Û°ÊÅ¥µP¡C
3: setmj tin none      ¨ú®ø·|¦Û°Ê­JµP³]©w¡C

½d¨Ò:
     ºNµP¤§«áµo²{¥´±¼¤T¸U¤§«á¥i¥HÅ¥¤G¸U¤Î¤­¸U¡A¦Û°ÊÅ¥µP¨BÆJ¦p¤U:
     1. setmj tin 2w     (³]©wÅ¥¤G¸U)
     2. setmj tin 5w     (³]©wÅ¥¤­¸U)
     3. setmj auto tin   (³]©w¦Û°ÊºN¥´)
     4. dump 3w          (¥´±¼¼oµP¶}©l¦Û°ÊÅ¥µP)
     
   <PS. ¦pªG³]©w·í¤¤¥´¿ù¤F, ½Ð¥´ setmj tin none ­«·s³]©w­nÅ¥ªºµP¡C>

   ·Q¬d¸ß§ó¸Ô²Óªºsetmj ¥Îªk½Ð¥´ help setmj ¡C
--------------------------------------------------------------------
HELP_TIN);
        return 1;
}
int do_help(string str)
{
        if (str=="setmj"){
write(@HELP
                       °ò  ¥»  ³]  ©w
            setmj ¥i¥Îªº¦³¦Û°Ê­J¡Bºb¡B¸I¡BÅ¥¡BÅã¦¡¤èªk¡C
--------------------------------------------------------------------
¨Ò¤l1: setmj pon 1w        ³]©w·|¦Û°Ê¸I1w ·í§O¤H¥´¥X¤@¸U®É·|¦Û°Ê¸I¤@¸U¡C
       setmj gon 1w                                         ¦Û°Êºb¤@¸U¡C
       setmj tin 1w        (¥i¦h¦¸³]©w¥H«K­J¦h­ÓµP)         ¦Û°Ê­J¤@¸U¡C
¨Ò¤l2: setmj show ¥N½X     ³]©w¬°¥uÅã¥Ü¥N½X¡C
       setmj show color    ³]©w¬°±m¦âÅã¥Ü¡C
¨Ò¤l3: setmj tin none      ¨ú®ø·|¦Û°Ê­JµP³]©w¡C
       setmj gon none
       setmj pon none
¨Ò¤l4: setmj auto tin      ³]©w¦Û°ÊÅ¥µP¡C
--------------------------------------------------------------------
HELP);
        return 1;
        }
        return 0;
}
int to_say_play()
{
write(@HELP
        «ü  ¥O    ¨Ò          ¤l                             »¡    ©ú
    ¢z¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢{
    ¢x  addin     ----------                                 ¥[¤J±Æ§½ ¢x
    ¢x  look      l mj©Î.¬Ý¦Û¤vµP,l 1p©Î.1¬Ýª±®a1ªºµP                 ¢x
    ¢x            l all©Î..¬Ý¥þ³¡,l end¬Ý¬y§½l dump¡C        ¬ÝµP     ¢x
    ¢x  mo(0)     ----------                                 ºNµP     ¢x
    ¢x  dump(dd)  dump <¥N½X>¡C                              ¥´µP     ¢x
    ¢x  eat       eat <¥N½X1> <¥N½X2>¡C                      ¦YµP     ¢x
    ¢x  pon(p)    ----------                                 ¸IµP     ¢x
    ¢x  gon       gon ©Î gon <¥N½X>(·tºb¥Î)¡C                ºbµP     ¢x
    ¢x  hu                                                   ­JµP     ¢x
    ¢x  setmj     help setmj¡C                               ³]©w°Ñ¼Æ ¢x
    ¢x  start     ----------                                 µP§½¶}©l ¢x
    ¢x  restart   restart ©Î restart mj¡C                    ­«·s¶}©l ¢x
    ¢x  top       top                                        ¬d¸ê®Æ   ¢x
    ¢|¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢}
HELP);
        return 1;
}
int to_say_rule()
{
write(@HELP
 
¡@¡@¨C­J´N¦³©³¥x¢²¡A¦b¥[¤W©Ò±oªº¥x´N¬OÁ`¥x¡A­n¬O¦ÛºN´N¡¯¢²¡A¬Û·í©ó¤T¤@ªººâªk¡C
©ñºj´N¥ÑÁ`¾ÔÁZ¨º¦©±¼©Ò¥¢ªº¥x¼Æ¡C­JªÌ«h¥[¤W¥h¡C
 
HELP);
        return 1;
}
int show_top(string str)
{
        string output="",*user_data=({}),*record_key=({""});
        int i;
        object me;
        me=this_player();
        if (sizeof(record) < 1)
           return notify_fail("¥Ø«e¨S¦³¾ÔÁZ°O¿ý¡C\n");
	record_key = keys(record);
	for(i=0;i<sizeof(record_key);i++)
	{       // [0..23]name [25..28]rounds [30..33]self [35..38]win [40..43]lose [45..50]total [52..55]bad
		user_data+=({sprintf("%-24s %4d %4d %4d %4d %6d %4d",
			record[record_key[i]]["name"],
			record[record_key[i]]["rounds"],
			record[record_key[i]]["self"],
			record[record_key[i]]["win"],
			record[record_key[i]]["lose"],
			record[record_key[i]]["total"],
			record[record_key[i]]["bad"]
			)});
	}
	user_data = sort_array(user_data, "sort_user", this_object());
	output  = "       ª±    ®a           §½¼Æ ¦ÛºN ­JµP ©ñºj ¾ÔÁZ¤À ¥Ç³W\n";
	output += "========================= ==== ==== ==== ==== ====== ====\n";
	for(i=0;i<sizeof(user_data);i++)
		output+=user_data[i]+"\n";
	me->start_more(output);
	return 1;
//	else return notify_fail("¾ÔÁZ°O¿ýªí¥¿¦b­×§ï¤¤¡C\n");
	
}
// score ®æ¦¡: ({ 0¦ÛºN,1­JµP,2©ñºj,3¥x¼Æ<©ñºj¬°­tªº>,4¥Ç³W })
int set_mjdata(object me,int *score)
{
	if(!me ) return 0;
	message_vision("$N¥ß¨è±N$nªº¦¨ÁZ°O¿ý¤U¨Ó¡C\n",this_object(),me);
	if(undefinedp(record[getuid(me)]))
	{
		record[getuid(me)] = ([
		"name": me->name_id(1),
		"rounds" : 1,
		"self" : score[0],
		"win" : score[1],
		"lose" : score[2],
		"total" : score[3],
		"bad" : score[4],
		]);
	}
	else
	{
		record[getuid(me)]["rounds"]++;
		record[getuid(me)]["self"]+=score[0];
		record[getuid(me)]["win"]+=score[1];
		record[getuid(me)]["lose"]+=score[2];
		record[getuid(me)]["total"]+=score[3];
		record[getuid(me)]["bad"]+=score[4];
		
	}
        return 1;
}

int get_tc(mapping who)
{
        int size,i,check;
        string str,tempW="",tempT="",tempS="",tempB="";
        str=who["Mj"]+who["Out"]+who["OutPon"]+who["OutGon"];
        //²ø®a
        if (NowPlayerId[0]==who["Id"]) Tc+="@1";
        //ªù²M&¦ÛºN
        if (who["Out"]==""&&who["OutPon"]==""&&Touched) Tc+="@l";
        else if (who["Out"]==""&&who["OutPon"]=="") Tc+="@4";
        else if (Touched) Tc+="@2";
        //¥þ¨D¤H
        if (strlen(who["Mj"]) < 5) Tc+="@i";
        size=strlen(str);
        while(size--){
              size--;
          if (do_check_num(str[size..size+1],1) < 10) tempW+=str[size..size+1];
          else if (do_check_num(str[size..size+1],1) < 19) tempT+=str[size..size+1];
          else if (do_check_num(str[size..size+1],1) < 28) tempS+=str[size..size+1];
          else tempB+=str[size..size+1];
        }
        //­·µP
        if (Times/Play == 0 && NowPlayerId[0]==who["Id"]&&do_check_Mj(tempB,"ea")>2) Tc+="@e";
        else if (Times/Play == 0 && do_check_Mj(tempB,"ea") > 2
             ||  NowPlayerId[0]==who["Id"]&&do_check_Mj(tempB,"ea")>2) Tc+="@5";
        if (Times/Play == 1 &&NowPlayerId[1]==who["Id"]&&do_check_Mj(tempB,"so")>2) Tc+="@f";
        else if (Times/Play == 1 && do_check_Mj(tempB,"so") > 2
             ||  NowPlayerId[1]==who["Id"]&&do_check_Mj(tempB,"so")>2) Tc+="@6";
        if (Times/Play == 2 &&NowPlayerId[2]==who["Id"]&&do_check_Mj(tempB,"we")>2) Tc+="@g";
        else if (Times/Play == 2 && do_check_Mj(tempB,"we") > 2
             ||  NowPlayerId[2]==who["Id"]&&do_check_Mj(tempB,"we")>2) Tc+="@7";
        if (Times/Play == 3 && NowPlayerId[3]==who["Id"]&&do_check_Mj(tempB,"no")>2) Tc+="@h";
        else if (Times/Play == 3 && do_check_Mj(tempB,"no") > 2
             ||  NowPlayerId[3]==who["Id"]&&do_check_Mj(tempB,"no")>2) Tc+="@8";
        //ªáµP
        if (sizeof(who["OutFlower"]) ==16) Tc+="@A";//¤K¥P¹L®ü
        else if (sizeof(who["OutFlower"]) ==14&&sizeof(P1Data["OutFlower"]+P2Data["OutFlower"]+P3Data["OutFlower"]+P4Data["OutFlower"])==16) Tc+="@D";//¤C·m¤@
        else if (do_check_Mj(who["OutFlower"],"f1")==1&&do_check_Mj(who["OutFlower"],"f2")==1
        &&  do_check_Mj(who["OutFlower"],"f3")==1&&do_check_Mj(who["OutFlower"],"f4")==1) Tc+="@B";//¬K®L¬î¥V
        else if (do_check_Mj(who["OutFlower"],"f5")==1&&do_check_Mj(who["OutFlower"],"f6")==1
        &&  do_check_Mj(who["OutFlower"],"f7")==1&&do_check_Mj(who["OutFlower"],"f8")==1) Tc+="@C";//±öÄõµâ¦Ë
        else if (NowPlayerId[0]==who["Id"]&&do_check_Mj(who["OutFlower"],"f1")==1
        ||  NowPlayerId[0]==who["Id"]&&do_check_Mj(who["OutFlower"],"f5")==1
        ||  NowPlayerId[1]==who["Id"]&&do_check_Mj(who["OutFlower"],"f2")==1
        ||  NowPlayerId[1]==who["Id"]&&do_check_Mj(who["OutFlower"],"f6")==1
        ||  NowPlayerId[2]==who["Id"]&&do_check_Mj(who["OutFlower"],"f3")==1
        ||  NowPlayerId[2]==who["Id"]&&do_check_Mj(who["OutFlower"],"f7")==1
        ||  NowPlayerId[3]==who["Id"]&&do_check_Mj(who["OutFlower"],"f4")==1
        ||  NowPlayerId[3]==who["Id"]&&do_check_Mj(who["OutFlower"],"f8")==1) Tc+="@3";
        //²M¤@¦â¸ò¦r¤@¦â
        if (tempW!=""&&tempT==""&&tempS==""&&tempB=="") Tc+="@q";
        else if (tempW==""&&tempT!=""&&tempS==""&&tempB=="") Tc+="@q";
        else if (tempW==""&&tempT==""&&tempS!=""&&tempB=="") Tc+="@q";
        else if (tempW==""&&tempT==""&&tempS==""&&tempB!="") Tc+="@r";
        //²V¤@¦â
        if (tempW!=""&&tempT==""&&tempS==""&&tempB!="") Tc+="@n";
        else if (tempW==""&&tempT!=""&&tempS==""&&tempB!="") Tc+="@n";
        //ºñ¤@¦â
        else if (tempW==""&&tempT==""&&tempS!=""&&tempB!=""){
             if (do_check_Mj(tempB,"fa")==3&&sizeof(tempB)==6
             ||  do_check_Mj(tempB,"fa")==2&&sizeof(tempB)==4
             && do_check_Mj(tempS,"1s")==0&& do_check_Mj(tempS,"5s")==0
             && do_check_Mj(tempS,"7s")==0&& do_check_Mj(tempS,"9s")==0) Tc+="@E";
             else Tc+="@n";
        }
        //¤j¤T¤¸
        if (do_check_Mj(tempB,"jo") > 2
        &&  do_check_Mj(tempB,"fa") > 2
        &&  do_check_Mj(tempB,"ba") > 2) Tc+="@t";
        //¤p¤T¤¸
        else if (do_check_Mj(tempB,"jo") > 1
        &&  do_check_Mj(tempB,"fa") > 1
        &&  do_check_Mj(tempB,"ba") > 1) Tc+="@o";
        else if (do_check_Mj(tempB,"jo") > 2) Tc+="@9";
        else if (do_check_Mj(tempB,"fa") > 2) Tc+="@0";
        else if (do_check_Mj(tempB,"ba") > 2) Tc+="@a";
        //¤j¥|³ß
        if (do_check_Mj(tempB,"ea") > 2
        &&  do_check_Mj(tempB,"so") > 2
        &&  do_check_Mj(tempB,"we") > 2
        &&  do_check_Mj(tempB,"no") > 2) Tc+="@v";
        //¤p¥|³ß
        else if (do_check_Mj(tempB,"ea") > 1
        &&  do_check_Mj(tempB,"so") > 1
        &&  do_check_Mj(tempB,"we") > 1
        &&  do_check_Mj(tempB,"no") > 1) Tc+="@F";
 
        for (i=0;i<sizeof(str);i+=2){
            if (str[i..i+1]=="xx") continue;
            if (do_check_Mj(str,str[i..i+1])==3) check++;
            else if (do_check_Mj(str,str[i..i+1])==4) check++;
        }
        //¸I¸I­J
        if (check>14){
           if (who["Out"]==""&&who["OutPon"]==""&&do_check_Mj(Tc,"@u")==0) Tc+="@m@u";
           else  Tc+="@m";
        }
        check=0;
        for (i=0;i<sizeof(str);i+=2){
            if (do_check_num(str[i..i+1],1)!=1&&do_check_num(str[i..i+1],1)>8) check++;

        }
        if (check=0&&tempB!="") Tc+="@I";//²V¦ÑÀY
        else if (check=0&&tempB="") Tc+="@J";//²M¦ÑÀY
        //¥­­J
        if (tempB==""&&who["OutFlower"]==""&&check==0&&sizeof(who["AutoTin"])>3) Tc+="@d";
        //ªe©³ºN¤ë
        if (count==((end-16-(Goned*2))-2)&&Touched) Tc+="@b";
        //¼´³½
        if (count==((end-16-(Goned*2))-2)&&!Touched) Tc+="@c";
        //¤Ñ­J
        if (LastDump==""&&count==(Play*2*16)+2) Tc+="@w";
        //¦a­J&¤H­J
        printf("%d > %d\n",count,((Play*2*16)+(Play*2)));
        if (count < ((Play*2*16)+(Play*2))
        &&P1Data["Out"]==""&&P1Data["PonOut"]==""
        &&P2Data["Out"]==""&&P2Data["PonOut"]==""
        &&P3Data["Out"]==""&&P3Data["PonOut"]==""
        &&P4Data["Out"]==""&&P4Data["PonOut"]==""){
           if (Touched) Tc+="@x";
           else Tc+="@y";
        }
        return 1;
}
int ch(string str)
{
        object me=this_player();
        mapping who;
        if (me->query("id")==P1Data["Id"]) who=P1Data;
        else if (me->query("id")==P2Data["Id"]) who=P2Data;
        else if (me->query("id")==P3Data["Id"]) who=P3Data;
        else if (me->query("id")==P4Data["Id"]) who=P4Data;
        if(!str) return 0;
        if(!wizardp(me)) return 0;
        write("§A§âµP"+who["Mj"]+"´«¦¨"+str+" ok.\n");
        str=sort_data(str);
        who["Mj"]=str;
        return 1;
}
string query_save_file() { return __DIR__ + "past_mj1_data"; }