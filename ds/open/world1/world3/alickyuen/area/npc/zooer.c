inherit NPC;
void create()
{
set_name("動物管理員",({"animal protector","protector"}));
set("long", " 負責管理這裡的動物人員！\n");
set("race","人類");
set("age", 30);
set("level", 25);
set_skill("gun", 80);
set_skill("dodge", 80);
set_skill("parry", 80);
set_skill("unarmed", 100);
set("chat_chance", 8);
        set("chat_msg", ({
(:command("reload clip"):),  
           (: random_move :),
        }) );
                set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (:command("shoot"):),
                (:command("reload clip"):),
         }) );
setup();
carry_object(__DIR__"wp/gun.c")->wield();
carry_object(__DIR__"wp/clip.c");
carry_object(__DIR__"eq/suit.c")->wear();
}
