#include <ansi.h>
inherit NPC;

void create()
{
        set_name( HIY "Zorg-Mob 2" NOR , ({"zorgmob2", "zorg-mob2","zmob2"}) );
        set("long", ""HIY"What you can see is a mob."NOR"！\n");
        set("race", "人類");
        set("gender", "女性"); 
        set("exp",999999);         set("age", 50);
        set("attitude", "aggressive");
        set("level", 50);
        set("str", 100);
        set("con", 30);
        set("dex", 25);
        set("int", 25);
        set("evil", 999);
        set("combat_exp",5000);
        set_skill("godsword", 100); 
        set_skill("sword", 100); 
        set_skill("unarmed", 10);
        set("title",HIW"【"HIG"Zorg's "HIR"Second "HIC"Mob"HIW"】"NOR);
        set_skill("fogseven", 100);
        set_skill("dodge", 100);
        set_skill("parry", 50); 
        set("chat_chance", 70 );  
        set("chat_msg", ({   
        (: this_object(), "random_move" :),     //會自己走動 
}) );
        set("chat_chance_combat",160);
        set("chat_msg_combat", ({
        (:command("cac"):),
        (:command("exert godsword"):),        (:command("exert fogseven")
:),
        }) );
        setup(); 
      add_money("dollar", 50000);           //帶的錢  
}












