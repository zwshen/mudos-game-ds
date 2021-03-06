#include <ansi.h>
inherit NPC;
void create()
{
        int x;
        x = random(10);
        set_name( "毋獸", ({ "ghost" }) );
        set("level",30);
        set_skill("dodge",100);
        set_skill("parry",100);
        set_skill("sword",100);
        set("long" ,"這是眾多追隨奇倪遁入黑暗的第二批神獸之一,由於作為神獸的時日太短,在神獸錄中通稱為毋。\n");
        set("age",50);
        set("title",HIG"魂滅階級"NOR);
        set("chat_chance", 50);
        set("gender","雄性");
        set("ten_mob",1);
        set("chat_msg", ({
           (: random_move :),
           (:command("kill meo"):),
           (:command("kill guard"):),
           (:command("kill taoist"):),
        }) );
        setup();
        if (x == 1 || x == 2)
        {
                carry_object(__DIR__"eq/ghost_whip")->wield();
        }
        if (x == 3)
        {
                carry_object(__DIR__"eq/ghost_blade")->wield();
        }
        if (x == 4)
        {
                carry_object(__DIR__"eq/ghost_staff")->wield();
        }
        if (x == 5)
        {
                carry_object(__DIR__"eq/ghost_fist")->wield();
        }
}

void init()
{
        object ob;
        ::init();
        if(!this_object()->visible(this_player())) return;
        if(this_player()->query("level") > 9 && userp(this_player()) )
        {
          this_object()->kill_ob(this_player());
        }
}

void die()
{
        int i;
        object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
        i = random(23);
        ob->set_temp("skycitywar",i+1);
        if(i > 15) 
        {
          ob->add("popularity",1); //聲望
          tell_object(ob,CYN"\n你殺死了毋獸，得到了 1 點聲望。\n"NOR);
        }
        ::die();
        return;
}
