inherit NPC;

void create()
{
	set_name("���޾���H", ({ "robot guard","guard" }) );
	set("long", "�@�Ӧu�áA���b���ޤ��C\n");
	set("race","�����H");
set("age",50);
	set("level", 25);
set("max_mp",5000);
set("max_ap",5000);
                set_skill("gun", 100);
                set_skill("combat", 75);
set_skill("dodge",50);
set_skill("parry",50);
    set("chat_chance",10);
        set("chat_msg",({
     (: random_move :),
                (:command("wield gun"):),
                         (:command,"reload clip":),}));
                set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (:command("shoot"):),
                (:command("reload clip"):),
         }) );
	setup();
 carry_object(__DIR__"wp/clip2.c");
carry_object(__DIR__"wp/gun2.c")->wield();
carry_object(__DIR__"eq/suit.c")->wear();
}

