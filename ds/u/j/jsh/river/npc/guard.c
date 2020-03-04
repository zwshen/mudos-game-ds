#include <ansi.h>

inherit NPC;

void create()
{
        set_name("城門守衛", ({ "guard" }) );


        set("level",25);
        set("age",35);
        set("gender", "男性");
        set("long",
"護守城門的守衛，高大威武。\n"
);
        set("chat_chance",5);
        set("chat_msg",({
                (:command("yawn"):),
                "城門守衛不時的往下面瞧. . . .\n",       
        }) );
        setup();
        add_money("coin", 50);
        carry_object(__DIR__"wq/short-pike")->wield();
} 
void init()
{       
        object ob=this_player();

        ::init(); 
        if(ob->query_temp("sky-town-killer")==1) 
        {
        this_object()->kill_object(ob); 
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
   message("world:world1:vision", 
   HIW"【天空之城】"+HIR""+ob->query("name")+"被種下殺人種子了！\n"NOR,users()); 
   ob->add_temp("sky-town-killer",1);
   ::die();
   return;
}

