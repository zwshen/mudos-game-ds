#include <npc.h>
#include "barbarian_base.c"

void create()
{
        set_name("村長", ({ "barbarian village head","head","barbarian" }) );
        set("long",@long
　　在你眼前的這個已上了年紀的野蠻人，是這個島上野蠻人村落的村長
，在野蠻人的社會具有極高的地位，常常是擁有光榮戰蹟的戰士才能榮升
此地位，不過瞧著村長

long
);
        set_race("human");
        set("title","野蠻人");
        set("age", 50);
        set_attr("str",30);
        set_skill("blunt",80);                  // 棒法
        set_skill("twohanded blunt",60);        // 雙握棒法
        set_skill("parry",50);
       set("chat_change",10);
        set("chat_msg", ({
                "村長恨恨的地說道：「死小偷，竟然敢趁全村忙著祭典的時候，跑來偷取東西....」\n",
                (: command("snort") :),
        }));
        setup();
        set_level(20);
        carry_object("/d/obj/woodblunt")->wield();
        carry_object(__DIR__"obj/monster_pants")->wear();
}

void exchange(object player,object ob)
{
	object boots=new(__DIR__"obj/barbarian_boots");
        // 不同房間.
        if(environment()!=environment(player) ) return;
        destruct(ob);
        command("say 真是謝謝你，我這雙靴子已經很久沒穿了，就送給你吧。");
        message_vision("$n從屋內一角的箱子裡取出一雙靴子，送給了$N。\n",player,this_object() );
        if(!boots->move(player) )
                boots->move(environment());
}

int accept_object(object me, object ob)
{
       if(      !ob->id("_OBJ_ID_BATTLE_AXE_")
                || is_fighting() )
           {
              return 0;
       }
       command("ack");
       command("say 啊....你幫我找回我的武器了......");
       do_chat(({ (: exchange,  me,ob :) }) );
       return 1;
}

void relay_say(object ob, string arg)
{
        if( strsrch(arg,"小偷")!=-1 )  {
              command("snort");
              command("say 無知宵小，大概是臨島另一族的人，前兒半夜竟跑來偷取我們村的戰斧。");
              return ;
        }
        if( arg=="戰斧"  )  {
              command("hmm");
              command("say 那是我們村落傳之已久的利器，是勇猛的戰士所不可或缺的。");
              return ;
        }
}

