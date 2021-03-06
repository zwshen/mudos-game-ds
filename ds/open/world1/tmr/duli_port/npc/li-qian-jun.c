#include <npc.h>
#include <ansi.h>
inherit F_FIGHTER;
void create()
{
        set_name("力千鈞", ({ "li qian-jun","jun","li" }) );
        set("title","一拳斷嶽" );
        set_race("strength");
        set_attr("strength",50);
        set("force_ratio",10);
        set_skill("unarmed",120);
        set_skill("parry",120);
        set_skill("dodge",120);
        set("age", 30);
        set("long",@LONG
    力千鈞雖只有一般人的身高，但是兩手臂上肌肉暴起，異常結實，想
必是天賦異稟，才能練就這樣神力吧，傳聞他能一拳擊碎水泥牆，其拳勢
威猛無匹，才得來「一拳斷嶽」這個外號。
LONG
);
        set("chat_chance", 5);
        set("chat_msg", ({
                "力千鈞惡狠狠的說道：「可惡的旅團，我一定要殺光你們所有團員，好替我的家人報這個仇..」\n",
                "力千鈞說道：「想我苦練這二十年，練就這一身神力，我就不信報不了這個仇..」\n",
                "力千鈞右一拳左一拳的打了起來，拳勢帶起的風勁迫得你有點呼吸困難...\n",
        }));
        setup();
        set_level(15);
        set_attr("str",35);
        carry_object(__DIR__"obj/champion-belt")->wear();
        set_temp("apply/attack",100);
        set_temp("apply/damage",50);
}

int accept_fight(object ob)
{
        return 0;
}

void exchange(object player,object ob)
{
        object gloves;
        destruct(ob);
        command("snort");
        command("say 這可不是那個旅團的鳥東西嗎，瞧我不打碎它才怪！！喝！！");
        message_vision(HIW "$N奮起一拳，竟將蜘蛛戒指打成碎片了...\n" NOR , this_object());
        player->set_temp("duli_port/wire-nina",1);
}

int accept_object(object me, object ob)
{
       if(      !ob->id("_QUEST_ITEM_WIRE_NINA_")
                || is_fighting() )
           {
              do_chat((: command, "say 你給我這個幹嘛？" :));
              return 0;
       }
       do_chat(({ (: exchange,  me,ob :) }) );
       return 1;
}


/* Quest:可解到學 變-念力線性化 */
void relay_say(object ob, string arg)
{
        object note;
        if( arg=="幻影旅團"  )  {
              command("angry");
              command("say 滾滾滾！！！不要讓我再聽到這四個字，小心我一拳打死你...");
              return ;
        }
        //////////////////////////////////////////////////////////////
        // 以下為開始解 變－念力線性化　的關鍵字
        if( ob->query_temp("duli_port/wire-nina")<1 ) return;
        if( arg=="戒指" || arg=="蜘蛛戒指"  )  {
                command("say 這這....真是對不住，剛才一時氣憤，不小心打壞你的東西了..");
                command("say 不知我能賠償你什麼嗎？？");
                ob->set_temp("duli_port/wire-nina",2);
                return ;
        }
        if( ob->query_temp("duli_port/wire-nina")<2 ) return;
        if( arg=="賠償"  )  {
              command("say 這...我生平沒什麼積蓄，沒什麼錢能賠你耶，都怪我太魯莽了..");
              command("slap li qian-jun");
              command("sorry");
                ob->set_temp("duli_port/wire-nina",3);
              return ;
        }
        if( ob->query_temp("duli_port/wire-nina")<3 ) return;
        if( arg=="沒關係"  )  {
              command("say 啊！！你真是大大的好人，要不然我將前陣子撿到的一張紙條送了給你吧..");
              command("say 聽說上面記載著一個變化系專用的技能，你可以試著滴血(blooding)在上面，就能看到其中的奧妙。");
                tell_object( ob , CYN "(力千鈞給了你一張小紙條。)\n" NOR );
                note = new(__DIR__"obj/wire-nina-note");
                note->move(ob);
                ob->delete_temp( "duli_port/wire-nina" );
              return ;
        }
}

