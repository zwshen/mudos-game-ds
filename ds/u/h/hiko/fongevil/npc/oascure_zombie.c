#include <ansi.h>

inherit NPC;
inherit __DIR__"zombiekill";

void create()
{
        set_name(CYN "晦屍" NOR ,({"obscure zombie","zombie"}) );
        set("long",@LONG
晦屍看來十分笨拙，面部毫無表情，行走極為緩慢，身上只靠著
本能行動。晦屍為殭屍王　戾絕的屍軍中最為弱小的殭屍，所以
戰鬥能力甚低。
LONG
);
        set("age",60);
        set("race","人類");
        set("title","屍兵");
        set("level",27);
        set("attitude", "peaceful");
        set("gender", "男性" );
        set("chat_chance",8);
        set("chat_msg", ({
           (: random_move :),
        }) );
        set("chat_chance_combat",20);
        set("chat_msg_combat",({
                (: zombie_heal,this_object() :),
                (: zombie_bite,this_object() :),
        }));
        set_skill("parry",80);
        set_skill("dodge",80);
        set_skill("unarmed",100);
        setup();
       carry_object(__DIR__"../eq/death_cloth")->wear();
       set_living_name("zombie-war-mob");
       set("actions", (: call_other, __FILE__, "query_action" :));
}

 mapping query_action()
{
        return s_action[random(sizeof(s_action))];
}
void init()
{
        ::init();

if(this_player()->query("level") > 20 && userp(this_player() ) && this_object()->visible(this_player()))
        {
    message_vision("\n$N"+NOR+"一看到$n便伸出雙爪攻擊！！\n" NOR,this_object(),this_player() );
        this_object()->kill_ob(this_player() ); 
        }
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

        ob->add("zombie_kill_war",1);
          if(ob->query("zombie_kill_war") > 2 )
        {
                tell_object(ob,HIG"你得到一點聲望。\n" NOR);
                ob->add("popularity",1); //聲望
                ob->set("zombie_kill_war",0);
        }
        ::die();
        return;
}





