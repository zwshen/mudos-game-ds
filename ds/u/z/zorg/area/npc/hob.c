#include <ansi.h>
inherit NPC;

void create()
{
        set_name("丘陵地精", ({"Hob Goblin","hob","goblin"}) );
        set("long", "身高在兩公尺以上,討厭陽光而在地下生活的大型亞族人！\n");
        set("race", "妖魔");
        set("gender", "男性"); 
        set("age", 83);
        set("attitude", "agreesive");
        set("level", 2);
        set("evil", -99);
        set("combat_exp",200);
        set("env/wimpy", 25);        
        set("chat_chance", 1 );    
        set("chat_msg", ({   
        (:command("say 殺"):),
        (:command(""):),
        (:command(""):),
}) );
        set("chat_chance_combat",160);
        set("chat_msg_combat", ({
        (:command(""):),
        (:command(""):),
        }) );
        setup(); 
 }

