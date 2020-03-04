#include <ansi.h>
inherit NPC;

void create()
{
        set_name("烏理耶爾", ({"uriel"}) );
   set("long", "你眼前就是四大熾天使中的殘酷天使！擁有三對羽翼的最高級神聖天使\n");
        set("race", "人類");
        set("gender", "男性"); 
        set("age", 2000);
        set("attitude", "heroism");
        set("level",100);
        set("str",100);   
        set("con",100);
        set("int",100);
        set("dex",100);
        set("evil", -999);
        set("combat_exp",5000);
        set("title",HIW"【"HIR"熾天使 "HIG"地 "HIC"殘酷天使"HIW"】"NOR);
        set_skill("unarmed",100);
        set_skill("parry", 100);  
        set_skill("cloudsteps", 100);  
        set_skill("dagger", 100);  
        set_skill("poken", 100);  
        set_skill("dodge", 100);  
        set_skill("sky-dagger", 100);  
        set("env/wimpy", 10);        
        set("chat_chance", 1);      
        set("chat_msg", ({   
       "烏理耶爾面無表情的說道:人類的罪是會遺傳,人類是罪惡的根源.\n"
}) );
        set("chat_chance_combat",190);
        set("chat_msg_combat", ({  
        (:command("defend michel"):), 
        (:command("cast god-benison on $n"):), 
        (:command("cast god-benison"):), 
        (:command("exert poken"):), 
        (:command("exert sky-dagger"):),
        (:command("exert cloudsteps"):),
        "烏理耶爾一臉怒火的的說道:人類是罪惡的根源\n"
        }) );
        setup(); 
        carry_object("/u/z/zorg/obj/dagger.c")->wield();
        carry_object("/u/z/zorg/obj/dagger1.c")->wield();
}




