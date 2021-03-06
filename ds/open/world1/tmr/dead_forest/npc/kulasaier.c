// 絕對時間(the-time) Quest 2004/05/27
#include <npc.h>
#include <ansi.h>
#include <skill.h>

void create()
{
        set_name( "庫拉塞爾" , ({ "kulasaier" }) );
        set("long",@long
    庫拉塞爾是個體格瘦弱的男子，長相頗為英挺俊秀，讓人見了就
先有三分好感。然而他卻顯的鬱鬱寡歡，似乎有過什麼悲慘的過去難
以忘懷。你注意到他擁有一雙非常晶瑩鮮麗的紅色眼珠，越看越是讚
嘆這世界上怎會有這麼美麗的顏色。
long
);
        set_race( "special" );
        set("title", "窟盧塔族" );
        set("age", 45 );
        set("chat_chance", 5 );
        set("chat_msg", ({
                        "庫拉塞爾深深嘆了口氣，不禁流露出一股極度悲傷哀怨的神情...\n",
        }));
        setup();
        set_level( 20 );
}

int accept_object(object me, object ob)
{
           if( ob->query_learn("the-time") ) return 0;
       if( !ob->id("_THE_TIME_QUEST_") || is_fighting() ) {
              do_chat((: command, "say 你給我這個幹嘛？" :));
              return 0;
       }
        me->set_temp( "the-time-quest" , 1 );
                do_chat( ({
                        "庫拉塞爾捧著火紅之眼，不禁怔怔地流下兩行眼淚......\n" ,
                        "庫拉塞爾哽咽地說道：「真是謝謝你的幫忙，讓我還能再見到族人的遺物...」\n" ,
                        "庫拉塞爾緩了口氣，又繼續說道：「我想或許你跟我們族人也是有緣吧，我有一套老祖宗傳下來的祕法...如果...」\n" ,
                        "庫拉塞爾欲言又止，又繼續說道：「如果你願意替我們族人報仇的話，我願意傳你這套祕法...」\n" ,
                        ( : destruct , ob : ),
                }) );
       return 1;
}
void relay_say(object ob, string arg)
{
           object letter;
           // 已學得絕對時間的人，則不必再解了
            if( ob->query_learn("the-time") ) return;

        if( arg=="窟盧塔族")  {
                do_chat(
                        ({
                                "庫拉塞爾搖了搖頭說道：「這個族名以後將只會再出現在歷史上了，所有的族人都消失了...」\n",
                    })
            );
            return ;
        }
            if( !ob->query_temp("the-time-quest") ) return;  

                        if( arg=="願意") {
                                message_vision( CYN "庫拉塞爾附在$N耳邊，低聲地講述一連串有如咒文般的內容....\n" NOR , ob );
                    if(ob->query("skills_point") + 3 >  SKILL_MAX_POINT )  {
                        // 技能點數不足
                                        tell_object( ob , CYN "(但是你完全聽不懂他所講的內容...)\n" NOR );
                                }
                                else {
                                        tell_object( ob , CYN "\n(你覺得雙眼的曈孔發出熾熱灼痛感，但還算是忍耐的住...)\n" NOR );
                                        tell_object( ob , HIY "\n(你的技能點數減少三點了。)\n" NOR );
                    ob->improve_skill( "the-time" , ob->query_attr("int") );
                                    ob->add("skills_point" , 3 );
                                }
                                ob->delete_temp( "the-time-quest" );
                                return;
                        }
                        if( arg=="不願意") {
                                do_chat( ({ "庫拉塞謝道：「那也好，這種事是不能勉強的...」\n" }) );
                                ob->delete_temp( "the-time-quest" );
                                return;
                        }
}


