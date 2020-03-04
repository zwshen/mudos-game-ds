#include <ansi.h>

inherit NPC;
inherit __DIR__"zombiekill";

void create()
{
        set_name(CYN "獨眼屍" NOR ,({"one-eye zombie","zombie"}) );
        set("long",@LONG
獨眼屍樣子極為威武，看來十分不凡，身上有著很高武藝。獨眼屍是
被殭屍王　戾絕所信任的屍體，它有著比其他屍體都高的智商，生前
該是一名天朝大將，有著強大氣勢。
LONG
);
        set("age",60);
        set("race","人類");
        set("title","屍將");
        set("level",38);
        set("Merits/bio",6);
        set("Merits/bar",6);
        set("str",90);
        set("attitude", "peaceful");
        set("gender", "男性" );
        add("addition_armor",90);
        set("chat_chance",5);
        set("chat_msg", ({
           (: random_move :),
        }) );
        set("chat_chance_combat",40);
        set("chat_msg_combat",({
                (: zombie_heal,this_object() :),
                (: zombie_bite,this_object() :), 
        }));                 
        set_skill("parry",80);
        set_skill("dodge",80);
        set_skill("unarmed",100);
        set_skill("fork",100);
        setup();
       carry_object(__DIR__"../wp/funeral_pike")->wield();
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
        tell_object(ob,HIG"你得到一點聲望。\n" NOR);
        ob->add("popularity",1); //聲望
        ::die();
        return;
}






