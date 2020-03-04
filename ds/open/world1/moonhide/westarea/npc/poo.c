#include <ansi.h>
inherit NPC;
void create()
{
        set_name( HIC"破魂"NOR, ({ "poo soul", "soul"}) );
        set("level",36);
        set_skill("dodge",100);
        set_skill("parry",80);
        set_skill("axe",100);  
        set("long" ,"九天雲魂的高手。\n");
        set("attitude", "aggressive");
        set("age",310);
        set("title",HIR"九天雲魂"NOR);
        set("chat_chance", 50);
        set("chat_msg", ({
           (: random_move :),
        }) ); 
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
        (: command("wield axe") :),  
        (: command("wield axe") :), 
        }));
        setup();
        set_living_name("westwar");
        carry_object(__DIR__"obj/axe")->wield();
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
        i=ob->query_temp("westwar");
        ob->set_temp("westwar",i+1);
        if(ob->query_temp("westwar")>2) 
        {
          ob->add("popularity",1); 
          tell_object(ob,HIW"(你得到 1 點聲望。)\n"NOR);
          ob->delete_temp("westwar");
        }
        ::die();
        return;
}


