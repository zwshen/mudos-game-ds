#include <ansi.h>
inherit NPC;
string *rnd_say = ({
        "¶Ù !",
        "hello !",
        "¶â....",
        "«z....",
        "µ¥µ¥....",
});
varargs void drool(string msg, string who);

void create()
{
//=========================°ò¥»³]©w==========================

        set_name( "µeµeªº¤p«Ä", ({ "asan","¤p«Ä","kid",}));
        set("level",20);
        set("title","[1;36mÂí¥Á[m");
        set("gender", "¨k©Ê");
        set("race", "¤HÃþ");
        set("age", 25);
        set("long", @LONG
¤@­Ó¹x¥Öªº¤p«Ä¡A¥¿®³µÛµeµ§(pen)¦b³òÀð¤Wµe¤p¥m¾´¡C
LONG
        );

//========================ÄÝ©ÊÃB¥~³]©w===============================
//   set("str", 7)Ý;
//   set("dex", 12);
//   set("int", 15);
//   set("con", 6);
//   set("combat_exp", 600);
//   set("score", 60);

//========================ºA«×Ãþ§O=================================
//   set("attitude", "friendly");   //¤Íµ½ªº NPC¡C
//   set("attitude", "peaceful");   //·Å©Mªº NPC¡C
//   set("attitude", "heroism");    //­^¶¯¥D¸qªº NPC¡C
//   set("attitude", "aggressive"); //¥D°Ê§ðÀ»,¥Í©Ê¦n°«ªºªº NPC¡C
//   set("attitude", "killer");     //¶Ý±þ¦¨©Êªº NPC¡C

//   set("welcome_msg", "·d©Ç§Å®v»¡¹D: Åwªï¨Ó¨ì ®ü©³¯µ¹Ò. ¥i¤£¥i¥HÀ°§Ú·QÂI±Ô­z°Ú?\n" );

//=============================¦Û°Ê°Ê§@=================================
set("startroom","/u/l/luky/workroom"); //¦^®aªº¦ì¸m (NOTE.1)
     set("chat_chance", 5 );  //°Ê§@¾÷²v
     set("chat_msg", ({       //°Ê§@¤º®e
(: this_object(), "random_move" :),//¦Û°Ê¶Ã¨«
(: this_object(), "return_home" :),//¦Û°Ê¦^®a (°t¦XNOTE.1)
"¤p«Ä«Ü¦³¿³­P¦aª`µøµÛ§A, ²´¯«¤¤¦ü¥G±a¦³¤@ÂI«N¥Ö.\n",
"¤p«Ä®³°_¤@ªKµ§, ¶¶¤â¦bÀð¤W¤W¶î°_¾~¨Ó.\n",
(:command("say «z°Ç~~ ¬Q¤Ñµeªº¤S³Q¤HÀ¿±¼¤F..."):),
(:command("say ¬O½Ö¤S¦b§Úªº¤p¥m¾´¤W¶Ã¼g¦r?? ¤S­n­«µe¤F.."):),
(:command("sigh"):),
(:command("sing"):),
(: drool :),
(: drool :),
}) );

//===========================°ÝÃD¦^µª==================================
set("inquiry/name", @LONG
  §Úªº¦W¦r¬Oªü¤T,§A¥s¤°»ò°Ç?.
LONG );

set("inquiry/pen", @LONG
  °Ú~~~ ³o­Óµ§¬O§H¦WÁôªÌ­ô­ôµ¹§Úªº! «Üº}«G§a! ¨þ¨þ~~~
LONG );

set("inquiry/password", @LONG
  ±K½X??§Ú«ç»òª¾¹D? 
                  ¸Ó§Ú°Ý§A¤F, §AÄ±±o§Úµeªº¦n¤£¦n¬Ý? ^_^ 
                  ¥i±¤³òÀð³£³Q¤H¶Ã¼g¦r..  §Ú³£§Ö¨S¦a¤èµe¹Ï¤F..  
LONG );
set("inquiry/±K½X", @LONG
  ±K½X??§Ú«ç»òª¾¹D? 
                  ¸Ó§Ú°Ý§A¤F, §AÄ±±o§Úµeªº¦n¤£¦n¬Ý? ^_^ 
                  ¥i±¤³òÀð³£³Q¤H¶Ã¼g¦r..  §Ú³£§Ö¨S¦a¤èµe¹Ï¤F..  
LONG );

//=========================¾Ô°«°T®§===========================
/*     set("chat_chance_combat", 10);
     set("chat_msg_combat", ({
         HIR"¤p«Ä²Y¼F¦a«s¸¹ : ¡u¦nµh°Ú¡ã¡T¤£­n¥´§Ú¡ã¡T±Ï©R°Ú¡ã¡T¡v\n"NOR,
     }) );
*/
//==========================§Þ¯à³]©w=============================
/*      set_skill("spear", 200);   
      set_skill("dodge", 200);
      set_skill("unarmed", 300);
      set_skill("parry", 200);
*/

        setup();
//        set_heart_beat(1); //¬O§_¦³¯S§ð

//==========================¸Ë³Æ¹D¨ã=============================
      add_money("coin", 220 );  //¨­¤W±aªº¿ú
/*      carry_object(__DIR__"obj/female_uniform_coat")->wear();
      carry_object(__DIR__"obj/female_uniform_skirt")->wear();
      carry_object(__DIR__"obj/uniform_cap")->wear();
      carry_object(__DIR__"obj/leather_belt")->wear();
      carry_object(__DIR__"obj/white_shoes")->wear();
      carry_object(__DIR__"obj/white_gloves")->wear();
*/
      carry_object("/u/d/disappear/spear/pen")->wield();

}

int add_phrase(string who, string msg)
{
        msg = replace_string(msg, "?", "");
        msg = replace_string(msg, "!", "");
        msg = replace_string(msg, "??", "");
        msg = replace_string(msg, "°Ú", "");
        msg = replace_string(msg, "¶Ü", "");
        msg = replace_string(msg, "³á", "");
        msg = replace_string(msg, "§a", "");

        if( msg != "" ) {
                add("memory/" + who, ({ msg }));
                return 1;
        } else return 0;
}

void relay_say(object ob, string msg)
{
        string who, phrase;

        if( !userp(ob) ) return;
        who = ob->query("name");

// Don't process our own speech.
        if( ob == this_object() ) return;

        if( add_phrase(who, msg) &&     random(10) > 4 )
                drool(msg, ob->query("name"));
}

//======================°Ê§@¤ÏÀ³======================================
void relay_emote(object ob, string verb)
{
        if( !userp(ob) ) return;
        switch(verb) {
        case "kick":
                command("cry");
                command("say ¶ã~~" + ob->query("id") +"´Û­t§Ú!!!");
                command("sob " + ob->query("id") );
                break;
        default:
                command("bow");
                break;
        }
}

//==========================¹ï¸Ü³]©w==================================
varargs void drool(string msg, string who)
{
        mapping mem;
        string *ob;

        mem = query("memory");
        if( !mapp(mem) ) return;

        if( !msg || !who) {
                ob = keys(mem);
                who = ob[random(sizeof(ob))];
                msg = mem[who][random(sizeof(mem[who]))];
        }

        if( (strsrch(msg, "¬°¤°»ò") >= 0) ) {
                if( sscanf(msg, "%*s¬°¤°»ò%s", msg)==2 ) msg = "¬°¤°»ò" + msg;
                msg = replace_string(msg, "¬°¤°»ò§A", "§Ú");
                msg = replace_string(msg, "¬°¤°»ò©p", "§Ú");
                switch(random(6)) {
                case 0: command("say " + who + "¡M§A¬O¦b°Ý§Ú¶Ü¡S"); break;
                case 1: command("say Ãö©ó" + msg + " ... "); break;
                case 2: command("say ²Â!! ¦]¬°" + msg + "§r!!"); drool(); break;
                case 3: command("say ³o­Ó°ÝÃD¹À ...."); break;
                case 4: command("say " + msg + "¡S"); break;
                case 5: command("say " + who + "§A¯à¤£¯à»¡²M·¡¤@ÂI¡S"); break;
                }
        }
        else if( (strsrch(msg, "§A") >= 0)
        ||      (strsrch(msg, "©p") >= 0)
        ||      (strsrch(msg, "drooler") >= 0)
        ||      (strsrch(msg, "Drooler") >= 0)) {
                if( sscanf(msg, "%*s§A%s", msg) == 2 ) msg = "§A" + msg;
                msg = replace_string(msg, "§A", "§Ú");
                msg = replace_string(msg, "©p", "§Ú");
                switch(random(10)) {
                case 0: command("say " + who + "¡M§A»¡" + msg + " ¡S");      break;
                case 2: command("say " + msg + "¸ò§A¦³¤°»òÃö«Y¡S");     break;
                case 3: command("say ¶â ... " + who + "»¡±o¦n"); break;
                case 4: command("say " + who + "§A¹ï" + msg + "¦n¹³«Ü¦³¿³½ì³á.."); break;
                case 5: command("say ¬°¤°»ò§A»{¬°" + msg + "¡S"); break;
                case 6: command("say ´«­Ó¸ÜÃD§a"); drool(); break;
                case 8: command("say ¤£¤@©w§a¡S"); break;
                }
        }
         else              
                if((strsrch(msg, "§Ú") >= 0) ){
                if (strsrch(msg, "§Ú¥s") >= 0 ) command("say "+who+", §A¦n!!");
                if( sscanf(msg, "%*s§Ú%s", msg) == 2 ) msg = "§Ú" + msg;
                msg = replace_string(msg, "§Ú", "§A");
                msg = replace_string(msg, "?", "");
                switch(random(8)) {
                case 0: command("say §A¬O»¡.." + msg + " ¶â.."); break;
                case 2: command("say ¦pªG" + msg + "¡M§Ú¯àÀ°§A¤°»ò¦£¶Ü¡S");     break;
                case 3: command("hmm"); break;
                case 4: command("say §A»{¬°" + msg + "¡S"); break;
                case 7: command("say ¦³Ãö¡u" + msg + "¡vªº¸ÜÃD¨ì¦¹¬°¤î¦n¶Ü¡S"); break;
                }
        } else {
                switch(random(20)) {
                        case 0: command("say ¬°¤°»ò»¡" + msg + "?"); break;
                        case 2: command("say ¡u" + msg + "¡v¬O¤°»ò·N«ä¡S"); break;
                        case 4: command("flop"); break;
                        case 6: command("jump"); break;
                        case 8: command("smile"); break;
                        case 10: command("?"); break;
                        case 12: command("hmm"); break;
                        case 14: command("say " + rnd_say[random(sizeof(rnd_say))]); break;
                        case 16: command("say " + who + "¬O±q­þ¸Ì¨Óªº°Ú?"); break;
                        default:
                                break;
                }
        }
}

void reset()
{
        delete("memory");
}
/* =========================NPCªº¯S§ð=============================
void heart_beat()
{
  object *enemy,me;
int damage;
  int i;
  me = this_player();
  if( me->is_fighting() )
  {
if(random(300)>200)
    {
      enemy = me->query_enemy();
      i=random(sizeof(enemy));
enemy[i]=present(enemy[i],environment(me));
damage=100+random(200);
if(enemy[i]->query_temp("curse")<1)
{
message_vision(HIC"HMM...Åý$Nª¾¹D$nªº§Q®`...¬Ý$nªº­°ÀY³N",enemy[i],me);
message_vision("¬ðµM¤@¹D©_©Çªº¥ú¯í®g¤J$NªºÅé¤º\n",enemy[i]);
 message_vision("$N¨­Åé¬ðµM·P¨ì¤Q¤Àªº¤£¾A--->["+damage+"]\n"NOR,enemy[i]);
enemy[i]->receive_damage("hp",damage,me);
enemy[i]->set_temp("curse",2);
     }
else {
message_vision(HIR"$N¨­Åé·P¨ì¶V¨Ó¶V®t¤F...["+damage+"]\n"NOR,enemy[i]);
enemy[i]->receive_damage("hp",damage,me);
}
}
 }
   if( me->query("hp") < 0 )
      me->die();
::heart_beat();
}
*/