#include <ansi.h>
inherit NPC;
void create()
{
        set_name( HIC"�ڻ�"NOR, ({ "mon soul", "soul"}) );
        set("level",36);
        set_skill("dodge",100);
        set_skill("parry",80);
        set_skill("blade",100);  
        set("long" ,"�E�Ѷ������C\n");
        set("attitude", "aggressive");
        set("age",290);
        set("title",HIR"�E�Ѷ���"NOR);
        set("chat_chance", 50);
        set("chat_msg", ({
           (: random_move :),
        }) ); 
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
        (: command("wield blade") :),  
        (: command("wield blade") :), 
        }));
        setup();
        set_living_name("westwar");
        carry_object(__DIR__"obj/blade")->wield();
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
          tell_object(ob,HIW"(�A�o�� 1 �I�n��C)\n"NOR);
          ob->delete_temp("westwar");
        }
        ::die();
        return;
}
