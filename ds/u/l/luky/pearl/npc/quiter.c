#define DROP_CMD               "/cmds/std/drop"
#define LUKY		"/u/l/luky/area/"
#include <path.h>
inherit NPC;
//inherit F_DBASE;
inherit F_CLEAN_UP;

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
seteuid("Root");
//¦WºÙ³]©w
        set_name( "Às½¼2¸¹", ({ "luky number one","warner"}));
        set("level",100);
        set("title","[1;36m¡iºÊµø¾÷¾¹½¼¡j[m");
        set("race", "¤HÃþ");
        set("age", 30);
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

        set("chat_chance", 1 );
        set("chat_msg", ({
"¬Y­Ó§Å®vªº¾÷¾¹¤H¶}©lºÊµø§A.\n",
(:command("say ³o¸Ì¦³BUG, ½Ð¥´qquit§ÚÀ°§AÂ÷½u.."):),
        }) );

//environment(this_player())->set("no_kill",1);
//environment(this_player())->set("no_cast",1);
        setup();

        carry_object("/u/l/luky/tempsuit")->wear();
        
}

void init()
{
command("change suit");
command("say ³o¸Ì¦³BUG, ½Ð¥´qquit§ÚÀ°§AÂ÷½u..");
add_action("do_qquit","qquit");
}

int do_qquit()
{
object *inv, link_ob, me;
string who;
int i;
me = this_player();
who = me->query("name");
if(me->is_fighting())
       return notify_fail("§A¥¿¦b¾Ô°«£°...\n");
if(me->query_temp("wood"))
return notify_fail("µ¥³Ì«á¤@®Ú¬å§¹¦A»¡.. OK??\n");
       
        if( !wizardp(me) ) {
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                        if( !inv[i]->query_autoload())
                                DROP_CMD->do_drop(me, inv[i]);
        }

//  me->remove_all_enemy();
        link_ob = me->query_temp("link_ob");
        me->set("startroom",base_name(environment(me)));

// We might be called on a link_dead player, so check this.
        if( link_ob ) {

// Are we possessing in others body ?
                 if( link_ob->is_character() ) {
                        write("§Aªº»î¾z¦^¨ì" + link_ob->name(1) + "ªº¨­¤W¡C\n");
                        exec(link_ob, me);
                        link_ob->setup();
                        return 1;
                }

// * if(me->query_temp("damage_type/lance"))
// * me->set("damage_type/lance",me->querytemp("damage_type/lance"));
                me->set("cmdcount",0);          // add by shengsan
                link_ob->set("last_on", time());
                link_ob->set("last_from", query_ip_name(me));
                link_ob->save();
command("nod");
me->save();
(int)link_ob->save();

                destruct(link_ob);
        }

write("\n§A¬ï¶V¤F¦t©z¶W­«¤O³õªº§ô¿£¡ã¡ã\n\n");
write("¸g¹L¤F¤£¥i«äÄ³ªº®É¥úÀG¹D[1;31m_,-~`~+.[1;32m_,-~`~+._,-~`~+.[1;33m_,-~`~+._,-~*[m\n");
write("[1;31m_,-~`~+._,-~`~+.[1;32m_,-~`~+._,-~`~+.[1;33m_,-~`~+._,-~`~+.[1;34m_,-~`~+._,-~`~+.[1;35m_,-~`~+._,-~[m\n");
write("[1;36m_,-~`~+.[1;31m_,-~`~+._,-~`~+.[1;32m_,-~`~+._,-~`~+.[1;33m_,-~`~+._,-~`~+.[1;34m_,-~`~+._,-~`~+.[1;35m_,-~\n");
write("[1;35m_,-~`~+._,-~`~+.[1;31m_,-~`~+._,-~`~+.[1;32m_,-~`~+._,-~`~+.[1;33m_,-~`~+._,-~`~+.[1;34m_,-~`~+._,-~[m\n\n");

        me->save();
efun::destruct(me);
       
shout("Às½¼2¸¹¦^³ø: "+who+"¦¨¥\ªºÂ÷¶}¤F³o­Ó¥@¬É!!");
return 1;
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
                switch(random(50)) {
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
                switch(random(50)) {
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
                switch(random(20)) {
                case 0: command("say §A¬O»¡.." + msg + " ¶â.."); break;
                case 2: command("say ¦pªG" + msg + "¡M§Ú¯àÀ°§A¤°»ò¦£¶Ü¡S");     break;
                case 3: command("hmm"); break;
                case 4: command("say §A»{¬°" + msg + "¡S"); break;
                case 7: command("say ¦³Ãö¡u" + msg + "¡vªº¸ÜÃD¨ì¦¹¬°¤î¦n¶Ü¡S"); break;
                }
        } else {
                switch(random(50)) {
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
