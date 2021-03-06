// 受傷的老人 能學到 「變-電性念力」
// -Tmr 2002/03/10

#include <npc.h>
#include <ansi.h>
#include <skill.h>

inherit F_VILLAGER;

void timeto_eat();

void create()
{
        set_name("受傷的老人", ({ "old man","man"}) );
        set_race("human");
        set_class("variation");

                map_skill("dodge", "lightswift");

        set("age", 75);
        set("gender", "male");
        set("long",@long
一個身上有數處刀傷的老人，衣服上的血跡早已漧涸了，看來受傷時日不短。
long
                        );
        setup();
        carry_money("coin", 1);
}

void init()
{
        ::init();
        if( is_fighting() || is_chatting() 
                        ||  this_player()->query_learn("electric nina")
                        ||  this_player()->query_temp("duli_forest/old-man") )
                        return;
        do_chat((: command, "say 咳...咳....我受了重傷，不知你有沒有藥草能救我一命呢？" :));
}

private void exchange(string food_name, object player)
{
        set_stat_current("food", 0);
        command("eat " + food_name);
        if( !player || environment(player) != environment() ) return;
       if( player->query_learn("electric nina") ) {
       command("say 真是謝謝你了。");
       return;
        }

                command("say 對了，不該白吃你的東西，我懂些電學，不知你是否有興趣要學？");
                player->set_temp("duli_forest/old-man",1);
}

int accept_object(object me, object ob)
{
       if( !ob->id("_OBJ_ID_WHALE_PELLET_")
                   || me->query_temp("duli_forest/old-man")  )
           {
              do_chat((: command, "say 咳...咳...你給我這個幹嘛？" :));
              return 0;
       }
       command("smile");
       command("say 咳... ..真是太好了﹗真謝謝你﹗ ...");
       do_chat(({ (: exchange, ob->query("id"), me :) }) );
       return 1;
}

void relay_say(object ob,string arg)
{
        if( ob->query_learn("electric nian") ) return;

        if( ob->query_temp("duli_forest/old-man")==1  ) {
        if( strsrch(arg,"想")!=-1 ||
                        strsrch(arg,"好")!=-1 )
                        {
                message_vision(CYN"受傷的老人打起精神，仔細地教導了$N電學的相關知識。 \n"NOR,ob);
                message_vision(CYN"受傷的老人在教了一段之後，又劇烈咳了起來...\n"NOR,ob);
                                /* 學習技能點數不夠 ||  讀書識字不夠  */
                                if(ob->query("skills_point")+3>SKILL_MAX_POINT
                                || ob->query_skill("literate") < 10 ) {
                                        tell_object(ob,CYN"(你完全聽不懂，看樣子也只有發棄了。)\n"NOR);
                                        ob->delete_temp("duli_forest/old-man");
                                        return;
                                }
                                tell_object(ob,CYN"(你心中對於剛才所學的，還是有些不了解，不知是否要再請教一下...)\n"NOR);
                                ob->set_temp("duli_forest/old-man",2);
                }       
                return;
        }
        if( ob->query_temp("duli_forest/old-man")==2  ) {
        if( strsrch(arg,"請教一下")!=-1  )
                        {
                  message_vision(CYN"受傷的老人望了$N一眼，說道：「喔...你還有不了解的地方，那我再指導你一些吧。」 \n"NOR,ob);
                message_vision(CYN"受傷的老人又開始教導$N一些電學的相關知識。 \n"NOR,ob);
                                message_vision(CYN"受傷的老人在教了一段之後，又劇烈咳了起來...\n"NOR,ob);
                                /* 學習技能點數不夠 ||  讀書識字不夠  */
                                if(ob->query("skills_point")+3>SKILL_MAX_POINT
                                || ob->query_skill("literate") < 10 ) {
                                        tell_object(ob,CYN"(你完全聽不懂，看樣子也只有發棄了。)\n"NOR);
                                        ob->delete_temp("duli_forest/old-man");
                                        return;
                                }
                                tell_object(ob,CYN"(在聽完這一段之後，你已經了解電學的原理，但是要如何將念力轉成電呢？)\n"NOR);
                                ob->set_temp("duli_forest/old-man",3);
                        }       
                return;
        }
        if( ob->query_temp("duli_forest/old-man")==3  ) {
        if( strsrch(arg,"要如何將念力轉成電")!=-1  )
                        {
                message_vision(CYN"受傷的老人望了$N一眼，說道：「這可是高深的學問了，不過為了報恩，我還是教你吧。」 \n"NOR,ob);
                message_vision(CYN"受傷的老人開始教導$N一些相關的知識。\n"NOR,ob);
                                /* 學習技能點數不夠 ||  讀書識字不夠  */
                                if(ob->query("skills_point")+3>SKILL_MAX_POINT
                                || ob->query_skill("literate") < 10 ) {
                                        tell_object(ob,CYN"(你完全聽不懂，看樣子也只有發棄了。)\n"NOR);
                                        ob->delete_temp("duli_forest/old-man");
                                        return;
                                }
                                message_vision(CYN"受傷的老人在教了一段之後，忽然兩眼發直，似乎停止呼吸了...\n"NOR,ob);
                                tell_object(ob,CYN"(看樣子你只有藉著這些淺薄的知識，找法子自修了。)\n"NOR);
                                ob->delete_temp("duli_forest/old-man");
                                ob->add("skills_point",3);
                ob->improve_skill("electric nina",100);
                tell_object(ob,HIG"(你的技能學習點數花掉三點。)\n" NOR);
                                die();
				destruct(this_object() );
                        }       
                return;
        }

}

