// info_lady.c
// Modified from ES 2 drooler.c
// By Annihilator@Celestial.Empire (09/15/95)
// Last modified by Spock @ FF  97.Oct.30.

#include <ansi.h>

inherit NPC;

string *rnd_say = ({
        "¶Ù !",
        "hello !",
        "¶â....",
        "«z....",
        "µ¥µ¥....",
        "°Ú....",
});

varargs void drool(string msg, string who);

void create()
{
        set_name( "·d©Ç§Å®v", ({ "luky","npc","Luky",}));
        set("level",20);
        set("title","[1;36m¡i¹ê²ß§Å®v¡j[m");
        set("race", "¤HÃþ");
        set("age", 24);
        set("long", @LONG

     .--,       .--,
    ( (  \.---./  ) )
     '.__/o   o\__.'
        {=  ^  =}
         >  -  <
        /       \
       //       \\
      //|   .   |\\
      "'\       /'"_.-~^`'-.
         \  _  /--'         `
       ___)( )(___
      (((__) (__)))


LONG
        );
        set("ridable",1);
        set_skill("armor",1000);
        set("env/spellpower",5);
        set("str", 7);
        set("dex", 12);
        set("int", 15);
//        set("not", 10);
        set("con", 6);
  //      set("tec", 10);
        set("attitude", "friendly");
//        set("group", ({"newbie", "newbie_staff"}));
   //     set("score", 50 );
  //      set("positive_fame", 40 );
    //    set("negative_fame", 5 );

        set("welcome_msg", "·d©Ç§Å®v»¡¹D: Åwªï¨Ó¨ì ®ü©³¯µ¹Ò. ¥i¤£¥i¥HÀ°§Ú·QÂI±Ô­z°Ú?\n" );

        set("chat_chance", 5 );
        set("chat_msg", ({
"·d©Ç§Å®v¦ù¤â­âªÅ¤@«ü¡MÅÜ¥X¤@¥»¤p»¡, ¶}©l¾\\Åª°_¨Ó.\n",
"·d©Ç§Å®v®³°_¤@ªKµ§, ¶¶¤â¦b¯È¤W¶î°_¾~¨Ó.\n",
"·d©Ç§Å®v¦ù¤â­âªÅ¤@«ü¡MÅÜ¥X¤@¥]¤p»æ°®, ¶}©l¦Y°_»æ°®¨Ó.\n",
                (: drool :),
                (: drool :),
                (: drool :),
                (: drool :),
                (: drool :),
        }) );

        set("inquiry/name", @LONG
  §Úªº¦W¦r¬Oªü¥ú,§A¥s¤°»ò°Ç?.
LONG );
        set("inquiry/allena", @LONG
  ¨º­Ó³Ã¥ë±MªùÃM§Ú»¡....   ¦³ÂIÅÜºA...... ¦oªººD¥ÎªZ¾¹¬OÄúÀë©M
¥ÖÃ@..  ¬Ý¨ì¦o³Ì¦n¥s¦o¤k¤ý!!  §_«h.... 
LONG );
        set("inquiry/chenyuan", @LONG
  ¨º¬O¥þÅ]ªk­Ì³Ì¼É¤Oªº§Å®v. §ÚÄ±±o¥LÀ³¸Ó¥h§¤¹q´È..  ¼K¼K....
LONG );

        set("inquiry/job", @LONG
  §Ú­t³d¸Ñµª¤@¨Ç§A­Ì±`¨£ªº°ÝÃD. ¥i¬O....³o¥÷¤u§@§Ú¤]¬O­è¨Ó¤£¤[,
©Ò¥H¦³¨Ç¦a¤è§Ú¤]¤£²M·¡­C. ·Qª¾¹D¦³­þ¨Ç°ÝÃD¥i¥H¸ß°Ý, ¥i¥H
ask joan about faq.
LONG );
/*        set("inquiry/faq", @LONG
  ¦³«Ü¦h®É­Ô, ¸Ñµª´N¦b help ªº¤å¥ó¸Ì, ©Ò¥H§Ú¥u­t³d¦³Ãö©ó·s¤â¾Ç°|
°V½m¤¤¤ßªº°ÝÃD¸Ñµª³á. ¥H¤U¬O§Ú¯à¦^µªªº½d³ò:
¨Ò¦p ask joan about stairs  ¥H¸ß°Ý¼Ó±è¦b­þ¸Ì.

  stairs [¼Ó±è], staff [Â¾­û], principal [®Õªø], lavatory [´Z©Ò]
  cafe [À\ÆU], eq [¸Ë³Æ], train [°V½m]
LONG );
        set("inquiry/stairs", @LONG
  ³o´É«Ø¿vª«ªº«n°¼´N¬O¼Ó±è. ­n¤W¼Óªº¸Ü, ½Ð©¹«n¨«.
LONG );
        set("inquiry/staff", @LONG
  ¾ã­Ó·s¤â¾Ç°|ªºÂ¾­û«Ü¤Ö, ¾Ú®Õªøªº»¡ªk¬O¦]¬°¸g¶O¤£¨¬ªº­ì¦].
LONG );
*/        set("inquiry/clc", @LONG
  °Ú ?  Às¯« ?  §Ú­Ìªº¦Ñ¤j¬O°¦¡u¥¨¤j¡vªºÀs, ¤£ºâ¨¤ªº¸Ü, ¦³
17 ¤½¤Ø°ª³á, ·íªì§Ú¬Ý¨ì¥L´N©È, ¤£¹L¬Ý¤[¤F´N²ßºD¤F....­n¬O§A¹J
¤WÀs¯«ªº¡u¥»´L¡v, ¤p¤ß¥L·|­AÄ_.
LONG );
/*        set("inquiry/lavatory", @LONG
  ¦b¨C¼h¼Ó¼Ó±èªº®ÇÃä´N¬O´Z©Ò.
LONG );
        set("inquiry/cafe", @LONG
  À\ÆU¦b¤G¼Ó, ¤W¼Ó«á©¹¥_¨««K¥i¬Ý¨ì. §A¥i¥H¦bÀ\ÆUÁÊ¶R­¹ª«¤Î¶¼®Æ.
LONG );
*/
        set("inquiry/eq", @LONG
  ¥´ i  ¬Ý¬Ý¦Û¤v¨­¤W§a, §A¨­¤W¬ïªº´N¬O°Ú.
LONG );
/*        set("inquiry/train", @LONG
  ¤T¼Ó¥H¤W¬O°V½m¦U¶µ§Þ¯à©M¾Ç²ßª¾ÃÑªº±Ð«Ç, §A¥i¥H¦b¨º¸Ì¾Ç¨ì¤@¨Ç
°ò¥»ªº§Þ¯à.
LONG );
*/
        setup();
/*


//        add_money("silver", 12 );
  //      add_money("copper", 100 );
    //    carry_object(__DIR__"obj/female_uniform_coat")->wear();
    //    carry_object(__DIR__"obj/female_uniform_skirt")->wear();
   //     carry_object(__DIR__"obj/uniform_cap")->wear();
   //     carry_object(__DIR__"obj/leather_belt")->wear();
        carry_object(__DIR__"obj/white_shoes")->wear();
        carry_object(__DIR__"obj/white_gloves")->wear();
        carry_object(__DIR__"obj/pearl_earring")->wear();
        */
}

int add_phrase(string who, string msg)
{
        msg = replace_string(msg, "?", "");
        msg = replace_string(msg, "¡H", "");
        msg = replace_string(msg, "¡S", "");
        msg = replace_string(msg, "!", "");
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
        if( ob == this_object() ) return; // Don't process our own speech.
        if( add_phrase(who, msg) &&     random(10) > 4 )
                drool(msg, ob->query("name"));
}

void relay_emote(object ob, string verb)
{
        if( !userp(ob) ) return;

        switch(verb) {
        case "kick":
                command("angry " + ob->query("id") );
                command("say ½ðªº¦n!! ¬Ý§Úªº!!");
                command("chair " + ob->query("id") );
                break;
        default:
                command("smirk " + ob->query("id"));
                break;
        }
}

varargs void drool(string msg, string who)
{
        mapping mem;
        string *ob;
        object me;
        me=this_player();
        mem = query("memory");
        if( !mapp(mem) ) return;

        if( !msg || !who) {
                ob = keys(mem);
                who = ob[random(sizeof(ob))];
                msg = mem[who][random(sizeof(mem[who]))];
        }
        if( (strsrch(msg, "À°§Ú¥[") >= 0) ){
        command("nod "+me->query("id"));
        command("c armor "+me->query("id"));
        return;
        }
        if( (strsrch(msg, "¬°¤°»ò") >= 0) ) {
                if( sscanf(msg, "%*s¬°¤°»ò%s", msg)==2 ) msg = "¬°¤°»ò" + msg;
                switch(random(8)) {
                case 0: command("say " + who + "¡M§A¬O¦b°Ý§Ú¶Ü¡S"); break;
                case 1: command("say Ãö©ó" + msg + " ... "); break;
                case 2: command("say §c ... "); drool(); break;
                case 3: command("say ³o­Ó°ÝÃD¹À ...."); break;
                case 4: command("say " + who + "¡Mª¾¹D³o­Ó°ÝÃDªºµª®×¹ï§A¨º»ò­«­n¶Ü¡S"); break;
                case 5: command("say " + msg + "¡S"); break;
                case 6: command("say " + who + "§A¯à¤£¯à»¡²M·¡¤@ÂI¡S"); break;
                case 7: command("say " + who + "¡M§Ú¤£À´§A°Ýªº°ÝÃD"); break;
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
                case 0: command("say " + who + "¡M§A¬O»¡" + msg + "¶Ü¡S");      break;
                case 1: command("say §A½T©w" + msg + "¡S");     break;
                case 2: command("say " + msg + "¸ò§A¦³¤°»òÃö«Y¡S");     break;
                case 3: command("say ¶â ... " + who + "»¡±o¦n"); break;
                case 4: command("say " + who + "§A¬°¤°»ò¹ï" + msg + "³o»ò¦³¿³½ì¡S"); break;
                case 5: command("say ¬°¤°»ò§A»{¬°" + msg + "¡S"); break;
                case 6: command("say ´«­Ó¸ÜÃD§a"); drool(); break;
                case 7: command("say ¤~©Ç"); break;
                case 8: command("say ¤£¤@©w§a¡S"); break;
                case 9: command("say ¦³³o­Ó¥i¯à ...."); break;
                }
        }
         else              
                if((strsrch(msg, "§Ú") >= 0) ){
                if (strsrch(msg, "§Ú¥s") >= 0 ) command("say "+who+", §A¦n!!");
                if( sscanf(msg, "%*s§Ú%s", msg) == 2 ) msg = "§Ú" + msg;
                msg = replace_string(msg, "§Ú", "§A");
                msg = replace_string(msg, "?", "");
                switch(random(8)) {
                case 0: command("say §A¬O»¡" + msg + "¶Ü¡S"); break;
                case 1: command("say ¯uªº¡S" + msg + "¡S");     break;
                case 2: command("say ¦pªG" + msg + "¡M§Ú¯àÀ°§A¤°»ò¦£¶Ü¡S");     break;
                case 3: command("hmm"); break;
                case 4: command("say §A»{¬°" + msg + "¡S"); break;
                case 5: command("say §Ú¦³¦P·P"); break;
                case 6: command("say §A»¡ªº¡u" + msg + "¡v§Ú¤£¯à­e¦P"); break;
                case 7: command("say ¦³Ãö¡u" + msg + "¡vªº¸ÜÃD¨ì¦¹¬°¤î¦n¶Ü¡S"); break;
                }
        } else {
                switch(random(20)) {
                        case 0: command("say ¬°¤°»ò»¡" + msg + "?"); break;
                        case 1: command("say ¡u" + msg + "¡v¬O¤°»ò·N«ä¡S"); break;
                        case 2: command("say " + msg + "¡S"); break;
                        case 3: command("grin"); break;
                        case 4: command("smile"); break;
                        case 5: command("?"); break;
                        case 6: command("say ...."); break;
                        case 7: command("hmm"); break;
                        case 8: command("say " + rnd_say[random(sizeof(rnd_say))]); break;
                        case 9: command("say §A«ç»òª¾¹D" + msg + "?"); break;
                        case 10: command("say ­è­è" + who + "¤£¬O»¡¤F¡M" + msg); break;
                        case 11: command("say §Ú·íµMª¾¹D¡M" + msg); break;
                        case 12: command("say µM«á©O¡S"); break;
                        case 13: command("say ¯uªº¶Ü¡S"); break;
                        case 14: command("say §Ú¤£³o»ò»{¬°¡C"); break;
                        default:
                                break;
                }
        }
}

void reset()
{
        delete("memory");
}
