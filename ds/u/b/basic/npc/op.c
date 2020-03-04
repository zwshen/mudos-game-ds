
#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "路人", ({ "traveller","tr","路人" }) );
        set("level",1);
        set("long" ,"一個正在趕路的路人，他因為趕路，因此背上滿是臭臭的汗味。\n");
        set("age",20);
        set("chat_chance", 8);
        set("exp",10000000);
        setup();
       add_money("past/coin",1000000);

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
        {

        ob->add("popularity", 500); //聲望
 tell_object(ob,HIW"(因為你殺死了路人，所以你得到了 500 點聲望。)\n"NOR);
}
        ::die();
        return;
}
