#include <ansi.h>
inherit NPC;
void create()
{
        set_name("酒鬼" , ({ "drunkard" }) );
        set("level",10);
        set("race","人類");
    set("chat_chance",10);
        set("age", 50);
        set("long","一個渴得爛醉如泥的男子，你最好別接近他，免得失常。\n");
        setup();
}

void die()
{
  int i;
        object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        LOGIN_D->set_reboot(0);
        if( !ob ) 
        {
                ::die();
                return;
        }
  i=ob->query_temp("superbug/hatred");
  if(ob->query_temp("superbug/hatred")==0)
  ob->set_temp("superbug/hatred",i+1);
        ::die();
        //destruct(this_object());
        return;

}
