inherit NPC;
void create()
{
set_name("守衛",({"guard"}));
set("long", " 這是負責守衛這秘密機地的守衛，你可能以成為他的目標了！\n");
set("race","人類");
set("age", 30);
set("level", 25);
set("max_hp", 5000);
set("max_mp", 5000);
set("max_ap", 5000);
set("attitude", "killer");
set("evil", 99);
set("combat_exp",100);
        set("chat_chance_combat", 100);
setup();
carry_object(__DIR__"obj/moon_clip");
}
