#include <npc.h>
#include <ansi.h>
#include <skill.h>

void create()
{
        set_name("似玉", ({ "si-yu","yu" }) );
        set("long",@long
似玉長的非常瘦且高、一眼望去宛如像是皮包骨的骷髏，長相非常不
討人喜歡，但是她左右手刀法使得頗為精悍，和女戰士如花也是莫逆之交
，尋常人等想要和她們說上個句話，倒也不容易。
long
);
        set_race("strength");
        set("gender","female");
        set("age", 40);
        set_attr("str",25);
        set_skill("blade",50);
        set_skill("secondhand blade",50);
        set_skill("dodge",50);
        set_skill("parry",50);
        set("title","女刀客");

        set_attr("str",25);
        setup();
        advance_stat("hp",200);
        set_level(10);                 
        carry_object("/d/obj/blade")->wield();
        carry_object("/d/obj/kris")->wield("secondhand blade");
        carry_object(__DIR__"obj/black-bodysuit")->wear();
}

void relay_say(object ob, string arg)
{
        if( arg=="武功\"
         && ob->query_temp("quest_finger_guessing")==2 )
        {
              command("say 嗯..我有套「邪拳」，雖然招式精簡，但是威力十足，你要學嗎？");
              ob->set_temp("quest_finger_guessing",3);
              return ;
        }

        if( arg=="要" && ob->query_temp("quest_finger_guessing")==3 )  {
              if( ob->query("skills_point")+1 > SKILL_MAX_POINT 
                 || ob->query_learn("finger-guessing fist")
              ) {
                      command("sigh");
                      command("say 我瞧您是學不起來的，不過還是謝謝您這次的幫忙。");
                      ob->delete_temp("quest_finger_guessing");
                      return;
              }
              message_vision(CYN"$N將邪拳的口訣和招式詳細地教給了$n。\n"NOR,this_object(),ob );
              tell_object(ob,HIG"(你的技能學習點數花掉一點。)\n" NOR);
              ob->add("skills_point", 1 );
              ob->delete_temp("quest_finger_guessing");
              ob->improve_skill("finger-guessing fist",100);
              return ;
        }
        if( arg=="不要"
        && ob->query_temp("quest_finger_guessing")==3
         )  {
              command("say 好吧，不過還是謝謝您的幫忙。");
              ob->delete_temp("quest_finger_guessing");
              return ;
        }
}

void init() 
{
        object me=this_player();
        if(me->query_temp("quest_finger_guessing")==2) {
		command("say 原來是您幫了我如花姐妹的忙哦，您是來學武功\的嗎？");
        }
}


