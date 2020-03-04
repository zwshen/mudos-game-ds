inherit NPC;
void create()
{

//名稱設定
        set_name( "院士", ({ "academician" }));
        set("level",30);
        set("race", "人類");
        set("age", 35);
        set("coin",random(300));
        set("long", @LONG

一個穿著樸素的院士，正在向來訪的客人解說修道院的歷史。
LONG
        );
/*        set("chat_chance", 5 );
        set("chat_msg", ({
(:command("sigh"):),
        }) );
*/
set("evil",-3000);
set("inquiry/name", @LONG
  我的名字是浦島郁升。
LONG );

set("inquiry/sala", @LONG
嗯.. 這是很久以前的事了..  所以我也不太清楚.
我只知道賽拉他和海龜族的交情不錯.. 你可以去問問
看海龜族的人. 或許會知道的更多.

LONG );

set("inquiry/password", @LONG
  密碼??我怎麼知道? 

LONG );
set("inquiry/密碼", @LONG
  密碼??我怎麼知道? 

LONG );
      setup();
//    carry_object("/u/d/disappear/spear/pen")->wield();
}

void init()
{
 add_action("no_kill","kill");
}

int no_kill(string arg)
{
 if(arg=="perfect" || arg=="chief perfect")
 notify_fail("院士並不想和你作戰。\n");
 return 0;
}

void relay_say(object ob, string msg)
{
        string who, phrase;
        if( !userp(ob) ) return;
        who = ob->query("name");
// Don't process our own speech.
        if( ob == this_object() ) return;

}

void relay_emote(object ob, string verb)
{
        if( !userp(ob) ) return;
        switch(verb) {
        case "kick":
                command("? "+ ob->query("id") );
//              command("say 嗚~~" + ob->query("id") +"欺負我!!!");
                break;
        default:
                command("smile");
                break;
        }
}

void reset()
{
// delete("memory");
}
