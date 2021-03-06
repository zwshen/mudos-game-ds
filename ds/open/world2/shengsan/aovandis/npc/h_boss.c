#include <ansi.h>
inherit NPC;

void make_mark();

void create()
{
        set_name("旅館老板",({"hotel's boss","boss"}) );
        set("long","他是這間旅館的老板，眉開眼笑的，不知在高興個什麼勁兒。\n如果你想打工：『輸入 sign in 之後接著輸入 dusting』\n");
        set("age",55);
        set("level",10);
        set("race","人類");
        set("gender","男性");
        set("evil",-5);         // 邪惡度 -5 (正的表邪惡, 負表善良)
        set("exp_point",0);     // 設定強度, exp及combat_exp會參考到這個值
                                // 0 <= exp_point <= 9
                                // 內定值為 0 , 請依據強度來設合理的值...
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: make_mark :),
        }) );
        set_skill("dodge",10);
        set_skill("block",10);
        set_skill("parry",10);
        set_skill("unarmed",10);
        set("inquiry",([
            "打工" : "你想打工哦！？找我就對了，你只要向我登記(sign in)，就能開始打工(dusting)了。\n[相關話題:工錢]\n",
            "工錢" : "我們這兒打工是全世界最好賺的了，只要掃個一次就能領二十枚金幣哦。\n[相關話題:領錢]\n",
            "領錢" : "你只要說出(say)領錢，我就會幫你結算工錢。\n",
        ]));
        set("talk_reply","你想打工嗎！？很好賺的哦。");
        setup();
        add_money("dollar",50);
}

void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_sign","sign");
        add_action("do_say","say");
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        if(random(2)) command("say 您好!歡迎光臨!!");
}
void make_mark()
{
        object *enemy, ob;
        command("say 哇！救命阿！");

        enemy = query_enemy();
        if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];
        if(!ob) return;

        if( this_object()->query("helpready/"+ob->query("id")) )
                return;

        command("say "+ob->query("name")+"，你是個魔鬼。");
        ob->add_temp("quest/aovandis",1);       // 將欺負市民的人做上標記
        this_object()->set("helpready/"+ob->query("id"),1);     // 與 id 結仇

}
int do_sign(string arg)
{
        object me;
        me=this_player();
        if(arg != "in") return notify_fail("你要簽什麼？\n");
        if(me->query_temp("dusting") > 0)
        {
          tell_object(me,"你已經在打工了。\n");
          return 1;
        }
        else {
          message_vision("$N對著旅館老板說道：我要打工。\n",me);
message_vision("旅館老板拿了個本子給$N，$N在上頭簽了名，再蓋\上了一個大頭章。\n",me);
          me->set_temp("dusting",1);
          return 1;
        }
}
int do_say(string arg)
{
        int i;
        object me;
        me=this_player();
        i=me->query_temp("addmoney");
        if( arg == "領錢" )
        {
          if(me->query_temp("addmoney") == 0 ) return notify_fail("旅館老板對你說：你又沒掃地就要找我領錢？\n");
          if(me->query_temp("addmoney") > 0 )
          {
            message_vision(GRN"$N說：領錢\n"NOR,me);
            message_vision("旅館老板從櫃檯拿出了"+ i*20 +"枚金幣給$N。\n",me);
            me->receive_money(i*20);
          me->delete_temp("addmoney");
          }
          return 1;
        }
}
