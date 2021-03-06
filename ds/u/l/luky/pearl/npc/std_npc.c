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
//=========================基本設定==========================

        set_name( "畫畫的小孩", ({ "asan","小孩","kid",}));
        set("level",20);
        set("title","[1;36m鎮民[m");
        set("gender", "男性");
        set("race", "人類");
        set("age", 25);
        set("long", @LONG
一個頑皮的小孩，正拿著畫筆(pen)在圍牆上畫小叮噹。
LONG
        );

//========================屬性額外設定===============================
//   set("str", 7)�;
//   set("dex", 12);
//   set("int", 15);
//   set("con", 6);
//   set("combat_exp", 600);
//   set("score", 60);

//========================態度類別=================================
//   set("attitude", "friendly");   //友善的 NPC。
//   set("attitude", "peaceful");   //溫和的 NPC。
//   set("attitude", "heroism");    //英雄主義的 NPC。
//   set("attitude", "aggressive"); //主動攻擊,生性好鬥的的 NPC。
//   set("attitude", "killer");     //嗜殺成性的 NPC。

//   set("welcome_msg", "搞怪巫師說道: 歡迎來到 海底秘境. 可不可以幫我想點敘述啊?\n" );

//=============================自動動作=================================
set("startroom","/u/l/luky/workroom"); //回家的位置 (NOTE.1)
     set("chat_chance", 5 );  //動作機率
     set("chat_msg", ({       //動作內容
(: this_object(), "random_move" :),//自動亂走
(: this_object(), "return_home" :),//自動回家 (配合NOTE.1)
"小孩很有興致地注視著你, 眼神中似乎帶有一點俏皮.\n",
"小孩拿起一枝筆, 順手在牆上上塗起鴉來.\n",
(:command("say 哇勒~~ 昨天畫的又被人擦掉了..."):),
(:command("say 是誰又在我的小叮噹上亂寫字?? 又要重畫了.."):),
(:command("sigh"):),
(:command("sing"):),
(: drool :),
(: drool :),
}) );

//===========================問題回答==================================
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

//=========================戰鬥訊息===========================
/*     set("chat_chance_combat", 10);
     set("chat_msg_combat", ({
         HIR"小孩淒厲地哀號 : 「好痛啊∼﹗不要打我∼﹗救命啊∼﹗」\n"NOR,
     }) );
*/
//==========================技能設定=============================
/*      set_skill("spear", 200);   
      set_skill("dodge", 200);
      set_skill("unarmed", 300);
      set_skill("parry", 200);
*/

        setup();
//        set_heart_beat(1); //是否有特攻

//==========================裝備道具=============================
      add_money("coin", 220 );  //身上帶的錢
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
        msg = replace_string(msg, "啊", "");
        msg = replace_string(msg, "嗎", "");
        msg = replace_string(msg, "喔", "");
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

//======================動作反應======================================
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

//==========================對話設定==================================
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
/* =========================NPC的特攻=============================
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
message_vision(HIC"HMM...讓$N知道$n的利害...看$n的降頭術",enemy[i],me);
message_vision("突然一道奇怪的光茫射入$N的體內\n",enemy[i]);
 message_vision("$N身體突然感到十分的不適--->["+damage+"]\n"NOR,enemy[i]);
enemy[i]->receive_damage("hp",damage,me);
enemy[i]->set_temp("curse",2);
     }
else {
message_vision(HIR"$N身體感到越來越差了...["+damage+"]\n"NOR,enemy[i]);
enemy[i]->receive_damage("hp",damage,me);
}
}
 }
   if( me->query("hp") < 0 )
      me->die();
::heart_beat();
}
*/