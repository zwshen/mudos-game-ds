#include <ansi.h>

inherit NPC;
inherit __DIR__"ghost-forest";

void create()
{
        set_name("無妄" ,({"ghost wu-won","won"}) );
        set("long",@LONG
無妄為佔據鬼斷森林的鬼王，生性兇殘狠辣。數十年前，無妄原也只
是安份度日的青年子弟，但似乎曾經歷過慘絕人寰的事，憤而一夜成鬼，
更憑藉生前所學的武功，在鬼界中呼風喚雨，更率領十二鬼眾肆掠人間，
於十幾年前，不知為何的被封印在鬼斷森林中....
LONG
);
        set("age",200);
        set("race","人類");
        set("title","鬼王");
        set("level",40);
        set("attitude", "aggressive");
        set("gender", "男性" );
        set_skill("parry",100);
        set_skill("dodge",100);
        set_skill("unarmed",100);
        set_skill("staff",100);
	set("chat_chance_combat",50);
	set("chat_msg_combat",({
		(: ghost_kill,this_object() :),
	}) );

        setup();
        set_living_name("ghost-forest-war-ghost");
//        carry_object(__DIR__"eq/gold_helmet")->wear();
//        carry_object(__DIR__"eq/silver_armor")->wear();
//        carry_object(__DIR__"wp/copper_cane")->wield();

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
        HIB"\n鬼王 無妄在臨死前發出一聲吶喊：「我會再回來找"+ob->name(1)+"報這殺身之仇的！！！」\n\n"+NOR
        ,users());
          ob->add("popularity",2); //聲望
        ::die();
        return;
}
