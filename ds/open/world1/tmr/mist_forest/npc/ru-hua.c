#include <npc.h>
#include <ansi.h>

void create()
{
        set_name("如花", ({ "ru hua","hua" }) );
        set("long",@long
如花是這一帶有名的戰士，長得滿臉橫肉，四肢發達，以身負蠻力而
出名，尋常的壯漢也難以撂倒她吧。瞧她正神色凝重的似乎在四處尋找什
麼東西。
long
);
        set_race("strength");
        set("gender","female");
        set("age", 40);
        set_attr("str",25);
        set_skill("twohanded axe",50);
        set_skill("dodge",50);
        set_skill("parry",50);
        set("title","女戰士");
        set("chat_chance", 20);
        set("chat_msg", ({
                "如花喃喃自語道：唉呀...阿娜達給我的玉戒指竟然搞丟了，不知在那裡啊...。\n",
                (: command("sigh") :),
                (: command("search") :),
        }));
        set_attr("str",15);
        setup();
        advance_stat("hp",200);
        set_level(10);                 
        carry_object("/d/obj/axe")->wield("twohanded axe");
        carry_object(__DIR__"obj/purple-hairpin")->wear();
}

void exchange(object player,object ob)
{
           destruct(ob);
           tell_object(player,GRN"如花在你的耳邊說道：您要是不嫌棄的話，我可以請我的好姐妹傳授你幾招武功。\n"NOR);
           player->set_temp("quest_finger_guessing",1);
}

int accept_object(object me, object ob)
{
        object item;
       if(      !ob->id("_OBJ_ID_JADE_RING_")
                || is_fighting()
                || me->query_learn("finger-guessing fist") 
                || me->query_temp("quest_finger_guessing") )
           {
              do_chat((: command, "shake" :));
              return 0;
       }
       command("wa");
       command("say 這這.....這就是我找了好久的訂情戒指啊，真是謝謝你啊。");
       do_chat(({ (: exchange,  me,ob :) }) );

       return 1;
}

void relay_say(object ob, string arg)
{
        if( arg=="好"
        && ob->query_temp("quest_finger_guessing")==1
         )  {
              command("say 嗯，那就請您移駕到森林外找我的似玉姐妹吧。");
               ob->set_temp("quest_finger_guessing",2);
              return ;
        }
        if( arg=="不好"
        && ob->query_temp("quest_finger_guessing")==1
         )  {
              command("say 好吧，不過還是很謝謝你的幫忙。");
               ob->delete_temp("quest_finger_guessing");
              return ;
        }
}

