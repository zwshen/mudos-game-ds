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

//¦WºÙ³]©w
        set_name( "µeµeªº¤p«Ä", ({ "asan","¤p«Ä","kid",}));
        set("level",20);
        set("title","[1;36mÂí¥Á[m");
        set("race", "¤HÃþ");
        set("age", 25);
	set("evil",-20);
        set("coin",random(200));
        set("long", @LONG

¤@­Ó¹x¥Öªº¤p«Ä¡A¥¿®³µÛµeµ§(pen)¦b³òÀð¤Wµe¤p¥m¾´¡C
LONG
        );
        set("chat_chance", 5 );
        set("chat_msg", ({
"¤p«Ä«Ü¦³¿³­P¦aª`µøµÛ§A, ²´¯«¤¤¦ü¥G±a¦³¤@ÂI«N¥Ö.\n",
"¤p«Ä®³°_¤@ªKµ§, ¶¶¤â¦bÀð¤W¤W¶î°_¾~¨Ó.\n",
(:command("say «z°Ç~~ ¬Q¤Ñµeªº¤S³Q¤HÀ¿±¼¤F..."):),
(:command("say ¬O½Ö¤S¦b§Úªº¤p¥m¾´¤W¶Ã¼g¦r?? ¤S­n­«µe¤F.."):),
(:command("sigh"):),
(:command("sing"):),
(: drool :),
(: drool :),
        }) );

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
      setup();
      set_skill("spear", 80);
      carry_object(__DIR__"wp/pen")->wield();
}

int add_phrase(string who, string msg)
{
        msg = replace_string(msg, "?", "");
        msg = replace_string(msg, "¡H", "");
        msg = replace_string(msg, "¡S", "");
        msg = replace_string(msg, "!", "");
        msg = replace_string(msg, "??", "");
        msg = replace_string(msg, "¡I", "");
        msg = replace_string(msg, "°Ú", "");
        msg = replace_string(msg, "¶Ü", "");
        msg = replace_string(msg, "­C", "");
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
