#include <ansi.h>
inherit NPC;
void create()
{
        set_name("日本婦女",({ "japen woman","woman","japen" }));
        set("long",
        "他是一個日本婦人，手上抱著一個"HIC"小嬰兒"NOR"，肚子似乎也還有一個寶寶。\n"
        );
        set("age",32);
        set("level",10);
        set("gender", "女性");
        set("exp",514);     
        set("combat_exp",500);         
        set("evil",-20);  
        set_skill("blade",25);          
        set_skill("parry",10);          
        set_skill("dodge",30);  
        set_skill("perception",5);
        set_skill("combat",25); 
        set("talk_reply","寶寶他一直哭都不睡覺怎麼辦呢?。");    
        set("chat_chance",5);
        set("inquiry",([
        "肚子裡的寶寶" : "我希望他是女的一男一女恰恰好!\n",
        "小嬰兒" : "寶寶他一直哭都不睡覺不知道怎麼了...\n",
        ]));
        set("chat_msg", ({
        name()+"抱著手上的小嬰兒搖啊搖的。\n",
        name()+"用手逗著手上的小嬰兒。 \n",
        name()+"說:寶寶乖∼別哭別哭快睡覺∼。\n",
        name()+"對著你說:你有辦法可以讓我的寶寶不哭嗎?。\n",
        "你聽到日本婦女手上小孩的哭叫聲。\n",
       }) );
        set("chat_chance_combat",60);
        set("chat_msg_combat", ({
        "日本婦女大叫：救命啊！不要殺我！我肚子還有寶寶啊。\n",
         (: command("sob") :),
         (: command("help!") :),
         }) );
        setup();
        carry_object(__DIR__"eq/woman_cloth")->wear();} 
        void die()
        {
        message_vision("$N臨死之前哭哭啼啼的說:我還不想死呀.....\n",this_object());
        ::die();}
int accept_object(object who,object ob)
{
     object me;
     me=this_player();
     if(this_player()->query("gender") )
     { 
     message_vision("$N拿出了一"+ob->query("unit")+ob->query("name")+"給日本婦女的寶寶玩。\n",who);
     command("say 啊...謝謝你ㄌ..寶寶.大哥哥拿東西給你玩了ㄛ..乖乖別哭。");
     call_out("toy",3,me);
     destruct(ob);
        return 1;
     }
    else
     {
    message_vision("$N拿出了一"+ob->query("unit")+ob->query("name")+"給日本婦女的寶寶玩。\n",who);
    command("say 啊...謝謝妳ㄌ..寶寶.大姐姐拿東西給你玩了ㄛ..乖乖別哭。");
    call_out("toy",3,me);
    destruct(ob);
    return 1;
        }
}
void toy(object me)
{
     if(!me) return;
     message_vision(HIC"寶寶突然安靜了下來..。\n"NOR,me);
     message_vision(HIY"日本婦女高興的說﹕太好了!寶寶不哭了...。\n"NOR,me);
     call_out("toy1",3,this_player());  
     return;
}
void toy1(object me)
{
     if(!me) return;
     message_vision(HIR"沒多久寶寶又放聲大哭了起來....>_<。\n"NOR,me);
     message_vision(HIC"日本婦女失望的說﹕寶寶不睡覺怎麼辦呢??\n"NOR,me);
     command("sigh");
     return;
}

