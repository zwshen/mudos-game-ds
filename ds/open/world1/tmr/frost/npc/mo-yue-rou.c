#include <ansi.h>
inherit NPC;
void combat_ai();

void create()
{
        set_name("莫月柔" , ({ "mo yue-rou", "mo", "yue","rou" }) );
        set("long",@long
莫月柔是是寒澈派觀主莫月鼎的獨生女，長得貌如天仙，巧笑倩兮
一雙古靈精怪的大眼睛讓你看得魂不守舍。
long
);
        create_family( "寒澈派", 3, "以心契道");
        set("level", 35);
	set("race","celestial");
        set("age",25);
        set("class1","寒澈派");
        set("gender","女性");
        set_skill("unarmed",100);
        set_skill("pick-plumblossom",100);
        set_spell("freeze-ball",100);
        set_spell("fall-thunder",100);

        set("inquiry", ([
                "畢大哥" : "喔喔∼∼你認識倚霄派的畢大哥嗎？",
                "畢松柏" : "唉...是啊，今日難得畢大哥來這兒做客，但他要事纏事，沒有空跟我見面。",
        ]) );

          set("chat_chance", 5);
        set("chat_msg",({
                (: command("sigh") :),
                (: command("sob") :),
                (: command("say 真想見見畢大哥一面啊...") :),
        }) );
        set("chat_chance_combat",200);
        set("chat_msg_combat", ({
                (: combat_ai() :),
        }) );
        set("evil",-30);
        setup();
        set_temp("apply/shield",100);
        set_temp("apply/armor",50);
                  carry_object(__DIR__"wp/qing-yang-claw")->wield();
                carry_object(__DIR__"eq/frostarmor")->wear();
                carry_object(__DIR__"eq/frostboots")->wear();
                carry_object(__DIR__"eq/frostcloth")->wear();
         carry_object(__DIR__"obj/water");
         carry_object(__DIR__"obj/water");
         carry_object(__DIR__"obj/water");
         carry_object(__DIR__"obj/water");
         carry_object(__DIR__"obj/water");
         carry_object(__DIR__"obj/water");
         carry_object(__DIR__"obj/water");
         carry_object(__DIR__"obj/water");
         carry_object(__DIR__"obj/water");
         carry_object(__DIR__"obj/water");
}

void init()
{
        ::init();
        add_action("do_speak","say");
}


void clear_quest() {
    if(!objectp(this_object())) return;
        delete("quest");
}

int do_speak(string arg)
{
        object me, ob;
        me=this_player();

        if(arg == "見面" && !me->query_temp("frost_quest/rou") ) {
                if(query("quest")) {
                        command("say 真是謝謝你了，剛已經有人幫我這個忙了。");
                } else {
                        command("say 如果你願意的話，是否能請妳幫我把這個絲娟交給他呢？");
                        me->set_temp("frost_quest/rou",1);
                }
        }
        if(arg == "願意" && me->query_temp("frost_quest/rou")==1 ) {
                set("quest",1);
                command("jump");
                command("say 那真是謝謝你了。");
                ob = new(__DIR__"obj/silk-cloth");
                ob->move(me);
                message_vision("$N從懷中取出一條絲娟交給了$n。\n",this_object(), me);
                me->delete_temp("frost_quest/rou");
                call_out("clear_quest", 600);
        }

        return 0;
}



void combat_ai()
{
        int i;
        object *target;
        object liu=this_object();

        target = all_inventory(environment(liu));

        /* 武器被打掉，則裝回去 */
        if( !liu->query_temp("weapon") ) 
                command("wield fist");

        i = sizeof(target);
        while( i-- )
        {
                if( liu->is_killing(target[i]) || liu->is_fighting(target[i]) )
                {
                        if( !target[i]->is_busy() ) continue;
                        if( userp(target[i]) )
                                 command("cast fall-thunder on " + getuid(target[i]) );
                        else
                                command("cast fall-thunder on " + target[i]->query("id") );
                            return;
                }
        }
        // 找不到busy的敵人，就發封寒球
        command("cast freeze-ball");
        return;
}

void die()
{
        object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
        message("world:world1:vision",
                HIG"\n【道派消息】"HIM"寒澈派觀主莫月鼎的獨生愛女「莫月柔」竟死在" +ob->name(1)+"的手上了！！\n"+NOR,users());
        ob->add("popularity", 1); //聲望
        tell_object(ob,HIW"(你得到了１點聲望。)"NOR);
        ::die();
        return;
}

