#include <ansi.h>
inherit NPC;
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

//名稱設定
        set_name( "畫畫的小孩", ({ "asan","小孩","kid",}));
        set("level",20);
        set("title","[1;36m鎮民[m");
        set("race", "人類");
        set("age", 25);
	set("evil",-20);
        set("coin",random(200));
        set("long", @LONG

一個頑皮的小孩，正拿著畫筆(pen)在圍牆上畫小叮噹。
LONG
        );
        set("chat_chance", 5 );
        set("chat_msg", ({
"小孩很有興致地注視著你, 眼神中似乎帶有一點俏皮.\n",
"小孩拿起一枝筆, 順手在牆上上塗起鴉來.\n",
(:command("say 哇勒~~ 昨天畫的又被人擦掉了..."):),
(:command("say 是誰又在我的小叮噹上亂寫字?? 又要重畫了.."):),
(:command("sigh"):),
(:command("sing"):),
(: drool :),
(: drool :),
        }) );

set("inquiry/name", @LONG
  我的名字是阿三,你叫什麼勒?.
LONG );

set("inquiry/pen", @LONG
  啊~~~ 這個筆是佚名隱者哥哥給我的! 很漂亮吧! 呵呵~~~
LONG );

set("inquiry/password", @LONG
  密碼??我怎麼知道? 
                  該我問你了, 你覺得我畫的好不好看? ^_^ 
                  可惜圍牆都被人亂寫字..  我都快沒地方畫圖了..  
LONG );
set("inquiry/密碼", @LONG
  密碼??我怎麼知道? 
                  該我問你了, 你覺得我畫的好不好看? ^_^ 
                  可惜圍牆都被人亂寫字..  我都快沒地方畫圖了..  
LONG );
      setup();
      set_skill("spear", 80);
      carry_object(__DIR__"wp/pen")->wield();
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
                command("cry");
                command("say 嗚~~" + ob->query("id") +"欺負我!!!");
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

        if( (strsrch(msg, "為什麼") >= 0) ) {
                if( sscanf(msg, "%*s為什麼%s", msg)==2 ) msg = "為什麼" + msg;
                msg = replace_string(msg, "為什麼你", "我");
                msg = replace_string(msg, "為什麼妳", "我");
                switch(random(6)) {
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
                switch(random(10)) {
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
                switch(random(8)) {
                case 0: command("say 你是說.." + msg + " 嗯.."); break;
                case 2: command("say 如果" + msg + "﹐我能幫你什麼忙嗎﹖");     break;
                case 3: command("hmm"); break;
                case 4: command("say 你認為" + msg + "﹖"); break;
                case 7: command("say 有關「" + msg + "」的話題到此為止好嗎﹖"); break;
                }
        } else {
                switch(random(20)) {
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
