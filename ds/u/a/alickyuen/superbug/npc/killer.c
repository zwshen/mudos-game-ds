#include <ansi.h>
inherit NPC;
void create()
{
        set_name("殺手" , ({ "killer" }) );
        set("level",40);
 set("race", "人類");
        set("age", 30);
        set("long","一個殺手，他正在鬼鬼祟祟地看來看去。\n");
    set("chat_chance",10);
        set("chat_msg",({
    // (: random_move :),
}));
        setup();
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
ob->set_temp("killed_killer",1);
        ::die();
        //destruct(this_object());
        return;
}

