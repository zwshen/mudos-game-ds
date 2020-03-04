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
        set_name( "·d©Ç§Å®v", ({ "luky","npc","Luky",}));
        set("level",20);
        set("title","[1;36m¡i¹ê²ß§Å®v¡j[m");
        set("race", "¤HÃþ");
        set("age", 25);
        set("long", @LONG

     .--,       .--,
    ( (  \.---./  ) )
     '.__/o   o\__.'
        {=  ^  =}
         >  -  <
        /       \
       //  NPC  \\
      //|   .   |\\
      "'\       /'"_.-~^`'-.
         \  _  /--'         `
       ___)( )(___
      (((__) (__)))


LONG
        );

//ÄÝ©Ê³]©w
        set("str", 7)Ý;
        set("dex", 12);
        set("int", 15);
        set("con", 6);
        set("attitude", "friendly");
        set("welcome_msg", "·d©Ç§Å®v»¡¹D: Åwªï¨Ó¨ì ®ü©³¯µ¹Ò. ¥i¤£¥i¥HÀ°§Ú·QÂI±Ô­z°Ú?\n" );
        set("chat_chance", 5 );
        set("chat_msg", ({
"·d©Ç§Å®v«Ü¦³¿³­P¦aª`µøµÛ§A, ²´¯«¤¤¦ü¥G±a¦³¤@ÂI«N¥Ö.\n",
"·d©Ç§Å®v®³°_¤@ªKµ§, ¶¶¤â¦b¯È¤W¶î°_¾~¨Ó.\n",
"·d©Ç§Å®v¦ù¤â­âªÅ¤@«ü¡MÅÜ¥X¤@¥]¤p»æ°®, ¶}©l¦Y°_»æ°®¨Ó.\n",
                (: drool :),
                (: drool :),
                (: drool :),
                (: drool :),
        }) );

        set("inquiry/name", @LONG
  §Úªº¦W¦r¬Oªü¥ú,§A¥s¤°»ò°Ç?.
LONG );
        set("inquiry/job", @LONG
  §Ú­t³d¸Ñµª¤@¨Ç§A­Ì±`¨£ªº°ÝÃD. ¥i¬O....³o¥÷¤u§@§Ú¤]¬O­è¨Ó¤£¤[,
©Ò¥H¦³¨Ç¦a¤è§Ú¤]¤£²M·¡­C. ·Qª¾¹D¦³­þ¨Ç°ÝÃD¥i¥H¸ß°Ý, ¥i¥H
ask joan about faq.
LONG );
        set("inquiry/clc", @LONG
  °Ú ?  Às¯« ?  §Ú­Ìªº¦Ñ¤j¬O°¦¡u¥¨¤j¡vªºÀs, ¤£ºâ¨¤ªº¸Ü, ¦³
17 ¤½¤Ø°ª³á, ·íªì§Ú¬Ý¨ì¥L´N©È, ¤£¹L¬Ý¤[¤F´N²ßºD¤F....­n¬O§A¹J
¤WÀs¯«ªº¡u¥»´L¡v, ¤p¤ß¥L·|­AÄ_.
LONG );
        set("inquiry/eq", @LONG
  ¥´ i  ¬Ý¬Ý¦Û¤v¨­¤W§a, §A¨­¤W¬ïªº´N¬O°Ú.
LONG );
        setup();
/*
//      set_skill("literature", 40);
//      add_money("coin", 1000 );
//      carry_object(__DIR__"obj/female_uniform_coat")->wear();
//      carry_object(__DIR__"obj/female_uniform_skirt")->wear();
//      carry_object(__DIR__"obj/uniform_cap")->wear();
//      carry_object(__DIR__"obj/leather_belt")->wear();
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
