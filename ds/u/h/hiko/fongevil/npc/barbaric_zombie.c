#include <ansi.h>

inherit NPC;
inherit __DIR__"zombiekill";

void create()
{
        set_name(CYN "殘屍" NOR ,({"barbaric zombie","zombie"}) );
        set("long",@LONG
殘屍感覺樣子十分殘酷，動作非常暴躁，身上只靠著本能行動。殘屍
為殭屍王　戾絕的屍軍中戰力最強的屍體，因此有著很強的本領，生
前殺人如麻，因此身上帶著怨氣。
LONG
);
        set("age",60);
        set("race","人類");
        set("title","屍將");
        set("level",35);
        add("addition_armor",80);
        set("attitude", "peaceful");
        set("gender", "男性" );
        set("chat_chance",5);
        set("chat_msg", ({
           (: random_move :),
        }) );
        set("chat_chance_combat",30);
        set("chat_msg_combat",({
                (: zombie_heal,this_object() :),
                (: zombie_bite,this_object() :), 
        }));                 
        set_skill("parry",80);
        set_skill("dodge",80);
        set_skill("unarmed",100);
        set_skill("blade",100);
        setup();
       carry_object(__DIR__"../wp/bone_blade")->wield();
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
    message_vision("\n$N"+NOR+"一看到$n便伸出雙爪攻擊！！\n" NOR,this_object(),this_player() ); this_object()->kill_ob(this_player() ); 
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

