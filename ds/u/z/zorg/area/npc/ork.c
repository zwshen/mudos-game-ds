#include <ansi.h>
inherit NPC;

void create()
{
        set_name("豬面魔", ({"ork"}) );
        set("long", "曾經是羅馬的死神,是夜行性得亞人類,性情殘酷又好戰,
以部族為單位而形成戰鬥團體！\n");
        set("race", "妖魔");
        set("gender", "男性"); 
        set("level", 5);
        set("age", 50);
        set("attitude", "agreesive");
        set("level", 50);
        set("evil", 59);
        set("combat_exp",5000);
        set("chat_chance", 70 );  
        set("chat_msg", ({   
}) );
        set("chat_chance_combat",160);
        set("chat_msg_combat", ({
        }) );
        setup(); 
 }



