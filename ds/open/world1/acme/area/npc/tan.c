#include <ansi.h>
inherit NPC;
void create()
{
        set_name("仇天錚", ({ "tan gen","gen" }) );
        set("level", 15);
        set("race","人類");
        set("gender","男性");
        set("age",30);
        set_skill("sword", 40);
        set_skill("parry", 30);
        set_skill("dodge", 40);
        set_skill("godsword",40);
        set_skill("mirage-steps",50);
        set_spell("god-fire",40);
        set("chat_chance_combat",50);
        set("chat_msg_combat", ({
                  (:command("exert godsword"):),
        }) );
        set("chat_chance", 8);
        set("chat_msg", ({
                  (:command("exert mirage-steps"):),
                  (:command("exert godsword"):),
                  (:command("cast god-fire"):),
        }) );
        set("long",
            "他身穿青杉，鮮血順著手臂流至長劍上，神色剛毅，\n"
            "毫無把身上的傷放在心上。\n",
            );
        setup();
        carry_object(__DIR__"wp/longsword")->wield();
}
void init()
{
        int i;
        object ob;
        ::init();
        i= this_object()->query("max_hp");
        this_object()->set("hp",i-50);
        call_out("greeting", 3, ob);
        add_action("do_say","say");
        add_action("do_nod","nod");
if(this_player()->query("name")!="蕭日山") this_object()->kill_ob(this_player());
if(this_player()->query_temp("canadd_senwu")==1) call_out("senwuquest",1);
}
void greeting(object ob)
{
  object me;
  me=this_player();
  if(me->query_temp("killbandit") > 0 && me->is_fighting() )
  {
     message_vision("仇天錚笑道：這位"+ RANK_D->query_respect(me) +"，原來不是那人的幫手，請恕在下有眼無珠。\n",me);
     me->remove_all_killer();
  }
  else {
     message_vision("仇天錚對著$N喝道：惡賊！納命來！\n",me);
  }
}
int do_say(string arg)
{
          object me,paper;
          me=this_player();
           if(arg == "那人" || arg =="那人的幫手" || arg=="金過涯" && me->query_temp("killbandit") >0 )
          {
            message_vision(YEL"$N說：" + arg +"\n"NOR,me );
            message_vision("仇天錚對著$N說道：那人就是外面的金老賊，因誤入他的地盤，他竟率人來追殺我。\n",me);
            message_vision("仇天錚對著$N說道：這位"+ RANK_D->query_respect(me) +"可否幫我一個忙？\n",me);
            me->set_temp("killbandit",2);
            return 1;
          }
          if(arg == "可" && me->query_temp("killbandit") >1 )
          {
            message_vision(YEL"$N說：" + arg +"\n"NOR,me );
            message_vision("仇天錚對著$N說道：太好了，你只要幫我把這東西交給「在水一方」蕭日山，就成了。\n",me);
            message_vision("仇天錚對著$N深深的鞠了一個躬。\n",me);
            message_vision("仇天錚給了$N一件事物。\n",me);
            paper=new(__DIR__"obj/paper2.c");
            paper->move(me);
            return 1;
          }
}
int do_nod(string arg)
{
    object me,paper;
    me=this_player();
    if( arg == "gen" && me->query_temp("killbandit") > 1 )
    {
      message_vision(HIY"$N對著仇天錚點了點頭。\n"NOR,me);
      message_vision("仇天錚對著$N說道：太好了，你只要幫我把這東西交給「在水一方」蕭日山，就成了。\n",me);
      message_vision("仇天錚對著$N深深的鞠了一個躬。\n",me);
      message_vision("仇天錚給了$N一件事物。\n",me);
      paper=new(__DIR__"obj/paper2.c");
      paper->move(me);
      return 1;
     }
}
void senwuquest()
{
      this_player()->set_temp("canadd_senwu",2);
message_vision("你看見蕭日山保護著仇天錚走出了這個野林。\n",this_player());
      destruct(this_object());
}
