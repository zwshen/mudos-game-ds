#define DROP_CMD               "/cmds/std/drop"
#define LUKY		"/u/l/luky/area/"
#include <path.h>
inherit NPC;
//inherit F_DBASE;
inherit F_CLEAN_UP;

string *rnd_say = ({
        "嗨 !",
        "hello !",
        "嗯....",
        "哇....",
        "等等....",
});

varargs void drool(string msg, string who);

void create()
{
seteuid("Root");
//名稱設定
        set_name( "龍蝦2號", ({ "luky number one","warner"}));
        set("level",100);
        set("title","[1;36m【監視機器蝦】[m");
        set("race", "人類");
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
"某個巫師的機器人開始監視你.\n",
(:command("say 這裡有BUG, 請打qquit我幫你離線.."):),
        }) );

//environment(this_player())->set("no_kill",1);
//environment(this_player())->set("no_cast",1);
        setup();

        carry_object("/u/l/luky/tempsuit")->wear();
        
}

void init()
{
command("change suit");
command("say 這裡有BUG, 請打qquit我幫你離線..");
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
       return notify_fail("你正在戰鬥ㄟ...\n");
if(me->query_temp("wood"))
return notify_fail("等最後一根砍完再說.. OK??\n");
       
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
                        write("你的魂魄回到" + link_ob->name(1) + "的身上。\n");
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

write("\n你穿越了宇宙超重力場的束縛∼∼\n\n");
write("經過了不可思議的時光隧道[1;31m_,-~`~+.[1;32m_,-~`~+._,-~`~+.[1;33m_,-~`~+._,-~*[m\n");
write("[1;31m_,-~`~+._,-~`~+.[1;32m_,-~`~+._,-~`~+.[1;33m_,-~`~+._,-~`~+.[1;34m_,-~`~+._,-~`~+.[1;35m_,-~`~+._,-~[m\n");
write("[1;36m_,-~`~+.[1;31m_,-~`~+._,-~`~+.[1;32m_,-~`~+._,-~`~+.[1;33m_,-~`~+._,-~`~+.[1;34m_,-~`~+._,-~`~+.[1;35m_,-~\n");
write("[1;35m_,-~`~+._,-~`~+.[1;31m_,-~`~+._,-~`~+.[1;32m_,-~`~+._,-~`~+.[1;33m_,-~`~+._,-~`~+.[1;34m_,-~`~+._,-~[m\n\n");

        me->save();
efun::destruct(me);
       
shout("龍蝦2號回報: "+who+"成功的離開了這個世界!!");
return 1;
}



int add_phrase(string who, string msg)
{
        msg = replace_string(msg, "?", "");
        msg = replace_string(msg, "？", "");
        msg = replace_string(msg, "﹖", "");
        msg = replace_string(msg, "!", "");
        msg = replace_string(msg, "??", "");
        msg = replace_string(msg, "！", "");
        msg = replace_string(msg, "啊", "");
        msg = replace_string(msg, "嗎", "");
        msg = replace_string(msg, "耶", "");
        msg = replace_string(msg, "吧", "");

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
                command("say 踢的好!! 看我的!!");
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

        if( (strsrch(msg, "為什麼") >= 0) ) {
                if( sscanf(msg, "%*s為什麼%s", msg)==2 ) msg = "為什麼" + msg;
                msg = replace_string(msg, "為什麼你", "我");
                msg = replace_string(msg, "為什麼妳", "我");
                switch(random(50)) {
                case 0: command("say " + who + "﹐你是在問我嗎﹖"); break;
                case 1: command("say 關於" + msg + " ... "); break;
                case 2: command("say 笨!! 因為" + msg + "呀!!"); drool(); break;
                case 3: command("say 這個問題嘛 ...."); break;
                case 4: command("say " + msg + "﹖"); break;
                case 5: command("say " + who + "你能不能說清楚一點﹖"); break;
                }
        }
        else if( (strsrch(msg, "你") >= 0)
        ||      (strsrch(msg, "妳") >= 0)
        ||      (strsrch(msg, "drooler") >= 0)
        ||      (strsrch(msg, "Drooler") >= 0)) {
                if( sscanf(msg, "%*s你%s", msg) == 2 ) msg = "你" + msg;
                msg = replace_string(msg, "你", "我");
                msg = replace_string(msg, "妳", "我");
                switch(random(50)) {
                case 0: command("say " + who + "﹐你說" + msg + " ﹖");      break;
                case 2: command("say " + msg + "跟你有什麼關係﹖");     break;
                case 3: command("say 嗯 ... " + who + "說得好"); break;
                case 4: command("say " + who + "你對" + msg + "好像很有興趣喔.."); break;
                case 5: command("say 為什麼你認為" + msg + "﹖"); break;
                case 6: command("say 換個話題吧"); drool(); break;
                case 8: command("say 不一定吧﹖"); break;
                }
        }
         else              
                if((strsrch(msg, "我") >= 0) ){
                if (strsrch(msg, "我叫") >= 0 ) command("say "+who+", 你好!!");
                if( sscanf(msg, "%*s我%s", msg) == 2 ) msg = "我" + msg;
                msg = replace_string(msg, "我", "你");
                msg = replace_string(msg, "?", "");
                switch(random(20)) {
                case 0: command("say 你是說.." + msg + " 嗯.."); break;
                case 2: command("say 如果" + msg + "﹐我能幫你什麼忙嗎﹖");     break;
                case 3: command("hmm"); break;
                case 4: command("say 你認為" + msg + "﹖"); break;
                case 7: command("say 有關「" + msg + "」的話題到此為止好嗎﹖"); break;
                }
        } else {
                switch(random(50)) {
                        case 0: command("say 為什麼說" + msg + "?"); break;
                        case 2: command("say 「" + msg + "」是什麼意思﹖"); break;
                        case 4: command("flop"); break;
                        case 6: command("jump"); break;
                        case 8: command("smile"); break;
                        case 10: command("?"); break;
                        case 12: command("hmm"); break;
                        case 14: command("say " + rnd_say[random(sizeof(rnd_say))]); break;
                        case 16: command("say " + who + "是從哪裡來的啊?"); break;
                        default:
                                break;
                }
        }
}

void reset()
{
        delete("memory");
}
