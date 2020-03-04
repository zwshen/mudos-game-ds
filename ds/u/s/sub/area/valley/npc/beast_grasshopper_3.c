inherit NPC;

void create()
{
        set_name("小蚱蜢", ({"small grasshopper","small","grasshopper"}) );
        set("long",@LONG
一隻活蹦亂跳的小蚱蜢，不停地在草叢裡跳來跳去。
LONG);
        set("unit","隻");
        set("race", "beast");
        set("limbs", ({ "頭部", "身體", "後腿", "翅膀"})); 
        set("verbs", ({ "bite","poke","crash" })); 
        set("age", 1);
        set("level",3);
        set_temp("apply/hit",-10);      
        set_temp("apply/dodge",-30);    
        set("chat_chance",1);
        set("chat_msg",({
               (: random_move :),
        }));

        setup();
}
