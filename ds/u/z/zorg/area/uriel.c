#include <ansi.h>
inherit NPC;

void create()
{
        set_name("尤里耶爾", ({"uriel"}) );
   set("long", "你眼前就是四大熾天使中的殘酷天使！擁有三對羽翼的最高級神聖天使\n");
        set("race", "人類");
        set("gender", "男性"); 
        set("age", 2000);
        set("attitude", "aggressive");
        set("level",70);
        set("evil", -999);
        set("combat_exp",5000);
        set_skill("sword", 100);
        set_skill("unarmed",100);
        set("title",HIW"【"HIR"熾天使"HIW"】"NOR);
        set_skill("cloudsteps", 100);
        set_skill("thundersword", 100);
        set_skill("poken", 100);
        set_skill("parry", 100);  
        set("env/wimpy", 10);        
        set("chat_chance", 90 );      
        set("chat_msg", ({   
        (: this_object(), "random_move" :),     //會自己走動  
        (:command("人類的罪是會遺傳"):),
}) );
        set("chat_chance_combat",160);
        set("chat_msg_combat", ({
        (:command("wield sword"):),
        (:command("wield sword"):),
        (:command("exert thundersword"):),
        (:command("exert poken"):),
        (:command("exert cloudsteps"):),
        (:command("尤里耶爾面無表情的說道:人類是罪惡的根源"):),
        }) );
        setup(); 
        carry_object(__DIR__"wp/lightsaber.c");
}


