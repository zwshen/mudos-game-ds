inherit NPC;

void create()
{
	set_name("巡邏機械人", ({ "robot guard","guard" }) );
	set("long", "一個正在負責巡邏的守衛。\n");
	set("race","機器人");
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
carry_object(__DIR__"wp/hgun.c")->wield();
 carry_object(__DIR__"wp/hclip.c");
carry_object(__DIR__"eq/suit.c")->wear();
}
void init()
{
        object ob;
        ::init();
        call_out("greeting", 1, ob);
}
void greeting(object ob)
{
object obj,me;
  me=this_player();
obj=this_object();
  if(me->query_temp("superbug/hatred")>0)
  {
    command("say 惡賊！納命來！！");
         obj->kill_ob(me);
  }
  else {
 //   command("stare "+me->query("id"));
  }
}



