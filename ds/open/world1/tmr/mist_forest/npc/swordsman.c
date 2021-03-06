#include <npc.h>
#include <ansi.h>

void create()
{
        set_name("劍客", ({ "swordsman" }) );
        set("long",@long
    這是一個不知名的劍客，滿臉驚恐受怕的模樣，所穿的一件白衣服也
沾了不少血跡，手上拿著的短劍也發抖發個不停，
long
);
        set_race("human");
        set("age", 28);
        set_skill("sword",60);
        set_skill("dodge",50);

        set_attr("str",25);
          set("chat_chance", 20);
        set("chat_msg", ({
                (: command("shiver") :),
                "劍客一眼望見你，隨即一把拉住你，詢問道：「不知你是否能帶我走出這片森林啊？」。\n",
                "劍客渾身不停的發抖，嘴裡不停地唸著：「我不想死在這裡，我得快點離開這裡。」\n",
        }));

        setup();
        set_level(2);                  // 爛劍客
        carry_object("/d/obj/shortsword")->wield();
}

void init()
{
        string env;
        object me,ob;
        if( query("quest_ok") ) return;
        ob=this_object();
        me=ob->query_leader();
        env=file_name(environment(this_object()));
        // 已經成功到達杜尼森林入口
        if( env=="/d/duli_forest/map_0_9" ) {
                set("quest_ok",1);
                call_out("do_quest",1,me,ob);
        } // end if
        ::init();
}
int do_quest(object me,object ob)
{
        object item;
        // 戰鬥中就算了
        if( ob->is_fighting() ) return 1;
        // 末解迷
        if( !query("quest_ok") ) return 1;
        // 沒有解迷者，直接destrcut..
        if(!me) {
                message_vision(CYN"劍客揮了揮手，快步離開這裡了。\n"NOR,ob);
        } else {
                // 解迷者 得到 喝不完水袋(unlimted skin)
                item=new("/d/obj/unlimted-skin");
                if(!item->move(me))
                        item->move(environment());
                        command("jump");
                        message_vision(CYN"劍客喜道：「真是謝謝你了，這個東西就送給你吧。」\n"NOR,ob);
        		message_vision("$N給了$n一個水袋。\n"NOR,ob,me);
                        message_vision(CYN"劍客揮了揮手，快步離開這裡了。\n"NOR,ob);
                }
                destruct(ob);
        return 1;
}
int accept_fight(object ob)
{
        do_chat("劍客搖搖頭說：「我只想趕快離開這森林，那有空理你啊。」\n");
        return 0;
}

/* Quest:帶劍客逃離迷霧森林 */
void relay_say(object me, string arg)
{
        object ob=this_object();
        if(arg=="能" && !ob->is_fighting() )
        {
                do_chat("劍客高興地說道：「真是謝謝你，就讓我跟著你一起行動吧。」 \n");
                ob->guard_ob(me);
                ob->set_leader(me);
                return;
        }
        if(arg=="不能" && !ob->is_fighting() )
        {
                do_chat("劍客失望地說道：「好吧，那下次再見了。」 \n");
                command("follow none");
                command("guard cancel");
                return;
        }
        
}
