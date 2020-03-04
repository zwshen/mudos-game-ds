#include <ansi.h>
#include <path.h>
inherit NPC;
void cover();

void create()
{
        set_name("開羅將軍", ({ "kailo general","general" }) );
        set("level",40);
        set("long" ,"護著開羅城門的將軍，手下帶領著數萬兵力，實力不可小窺。\n");
        set("age",45);

        set("env/wimpy", 60);
        set("chat_chance_combat",41);
        set("chat_msg_combat", ({
           (:command("think"):),
         (: cover :),
         }) );
        set_skill("dodge",80);
        set_skill("parry",70); 
        set_skill("fork",90);   
        set_skill("unarmed",60);
        setup();
        carry_object(__DIR__"obj/fork")->wield();
} 

void cover()

{
        object ob,me,x; 
        me=this_player();   
        ob=this_object();
        if (ob->is_busy() ) return; 
        {
        message_vision(HIR"$N說：城後士兵全部出動，把"+HIW""+me->name(1)+""+HIR"給我殺了！\n"+NOR,me);   
        x->new(__DIR__"sword-soldier"); 
        x->move(environment(this_player()) ); 
        x->kill_ob(this_player());
        x->new(__DIR__"fork-soldier");
        x->move(environment(this_player()) );  
        x->kill_ob(this_player());
        x->new(__DIR__"axe-soldier");
        x->move(environment(this_player()) );  
        x->kill_ob(this_player());
        x->new(__DIR__"blade-soldier");
        x->move(environment(this_player()) ); 
        x->kill_ob(this_player()); 
        }
        return 1;
}
void die()
{ 
        object me;
        me=this_player(1);
        if( !me = query_temp("last_damage_from") )
        if( !me ) 
        {
                ::die();
                return;
        } 
        me->add("popularity",3);
        message("world:world1:vision",
   HIG"\n【開羅長城】開羅將軍被"+HIR""+me->name(1)+""+HIG"殺死了！！\n\n"+NOR
        ,users());
        ::die();
        return;
}

