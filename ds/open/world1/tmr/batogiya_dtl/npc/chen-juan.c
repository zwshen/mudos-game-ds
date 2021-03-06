// 太極拳(taiji-quan) Quest
#include <npc.h>
#include <ansi.h>
#include <skill.h>

void create()
{
        set_name( "陳圈" , ({ "chen juan", "chen", "juan"}) );
        set("long",@long
　　陳圈長相平庸，身材中等，不胖也不瘦，瞧不出有何特別之處
long
);
                set("title","太極門弟子");
        set("age",25);
        set_skill("sword",100);
        set_skill("taiji-sword",100);
        map_skill("sword", "taiji-sword");

        set("chat_chance", 10 );
        set("chat_msg", ({
                        "陳圈對著自已說道：「此番出外遊歷，總要闖出些什麼名堂吧。」\n",
                        "陳圈傻兮兮地獨自笑了起來，似乎想到什麼得意之處。\n",
                        "陳圈忽然練起一套慢吞吞的拳路，你瞧了半天也看不懂。\n",
        }));
        setup();
          set_level( 15 );
          carry_object(__DIR__"obj/taiji-sword-book");
          carry_object("/d/obj/sword")->wield();


}

void relay_say(object ob, string arg)
{
           object card;
            if( ob->query_learn("taiji-quan") ) return;

        if( arg=="什麼名堂" || arg == "名堂")  {
                do_chat( ({
                                "陳圈說道：「所謂虎死留皮，人死留名，更何況學武之人，總是希望能有點名聲吧。」\n",
                                "陳圈話一說完，又開始練起拳路來...\n",
                    }) );
            ob->set_temp("taiji-quan-quest" , 1);
            return ;
        }

        if( ob->query_temp("taiji-quan-quest") == 1 && arg=="名聲") 
        {
                        do_chat( ({
                                        "陳圈嘆道：「唉....像我這樣默默無名，又武藝低微，真不知何時才能出人頭地。」\n",
                                        "(您正在思索能有什麼法子，可以幫他揚名立萬。)\n",
                            })     );
                    ob->set_temp("taiji-quan-quest" , 2);
                return;
                }

        if( ob->query_temp("taiji-quan-quest") == 2 && arg=="揚名立萬") 
        {
                     do_chat( ({
                                        (: command("hmm") :) ,
                                        "陳圈低聲說：「我曾聽朋友提過，在死亡森林那邊有法子取得具有特殊能力的卡片...」\n",
                                        "陳圈頓了一下，又繼續說：「聽說那能提升你在這個世界的名聲呢！！」\n",
                                        "(您想或許該去死亡森林那兒找找吧。)\n",
                            })     );
                    ob->set_temp("taiji-quan-quest" , 3);
                return;
                }

       if( ob->query_temp("taiji-quan-quest") == 4 )
       {
                        if( arg=="好" || arg=="想")  {
                                message_vision( CYN "\n陳圈將拳招姿勢及口訣仔細傳授給$N....\n" NOR, ob );
                    if(ob->query("skills_point") + 3 >  SKILL_MAX_POINT )  {
                                        tell_object( ob , CYN "(但是你完全聽不懂他所講的內容...)\n" NOR );
                                } else {
                                        tell_object( ob , CYN "\n(你學到了太極拳！！)\n" NOR );
                                        tell_object( ob , HIY "\n(你的技能點數減少三點了。)\n" NOR );
                    ob->improve_skill( "taiji-quan" , ob->query_attr("int") );
                                    ob->add("skills_point" , 3 );
                                }
                                do_chat( ({ "陳圈不停地撫摸手上的卡片，似乎非常高興。\n" }) );
                                ob->delete_temp( "taiji-quan-quest" );
                                return;
                        }
                        
                        if( arg=="不好" || arg == "不想" ) {
                                do_chat( ({ "陳圈道：「也好，我會將你的恩情銘記在心。」\n" }) );
                                ob->delete_temp( "taiji-quan-quest" );
                                return;
                        }
                }
}

void exchange( object player, object card )
{
        destruct(card);
    if( !player || environment(player) != environment() ) return;
        player->set_temp("taiji-quan-quest", 4);
}
 
int accept_object(object me, object ob)
{
       if( !ob->id("_55_CARD_")
           || me->query_learn("taiji-quan")
           || me->query_temp("taiji-quan-quest") != 3 )
              return 0;

                do_chat( ({
                        (: command("wa") :) ,
                        "陳圈拿著卡片，不禁感動地落下來淚來...\n" ,
                         "陳圈道：「真是太謝謝你了，我這兒有一套拳法，想要傳授給你，以感謝你的幫忙，不知你意下如何？？」\n",
                (: exchange, me, ob :) ,
                }) );
       return 1;
}


