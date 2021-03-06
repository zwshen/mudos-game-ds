#include <ansi.h>
inherit NPC;
void create()
{
        set_name("官兵", ({ "garrison" }) );
        set("level", 20);
        set("race","人類");
        set("gender","男性");
        set("age",30);
        set_skill("parry", 60);
        set_skill("unarmed", 50);
        set_skill("dodge", 60);
        set_skill("sword",65);
        set("long","他是一位盡忠職守的官兵。\n");
        set("chat_chance_combat",50);
        set("chat_msg_combat", ({
           (:command("wield sword"):),
        }) );
        setup();
        carry_object(__DIR__"eq/cloth2")->wear();
        carry_object(__DIR__"eq/waist")->wear();
        carry_object(__DIR__"eq/helmet")->wear();
        carry_object(__DIR__"wp/sword2");
}
void init()
{
        object me;
        ::init();
        add_action("do_kill","kill");
        me=this_player();
        if(!this_object()->visible(this_player())) return;
        call_out("greeting", 1, me);
}
void greeting(object ob)
{
  object me,obj;
  me=this_player();
  obj=this_object();
  if(me->query_temp("SKYCITY/jail")>0)
  {
    command("say 惡賊！納命來！！");
    obj->kill_ob(me);
  }
  else {
    if(me->query_temp("SKYCITY/hatred")>0)
    {
      command("say 惡賊！納命來！！");
      obj->kill_ob(me);
    }
  }
}
void do_kill(string arg)
{
        object ob,me,*obs;
        me=this_player();
        ob=this_object();
        if (!arg) return;
        if(!objectp(present(arg, environment(me)))) return;
        
        if( is_fighting(me) ) return;
	message_vision("$N說道﹕咦？造反啦？竟敢亂殺人！！去死吧 ...\n",this_object());
	obs = all_inventory(environment());
	for(int i=0;i<sizeof(ob);i++)
	{
		obs[i]->soldier_assist(this_object(), me);
	}
}

void soldier_assist(object alert, object me)
{
        if( alert==this_object()
        ||      !living(this_object())
        ||      is_fighting(me) )
                return;
        switch(random(4)) {
        case 0: command("say 大膽刁民！竟敢公然逞兇！"); break;
        case 1: command("say 反了反了！兄弟們﹐拿下這個匪徒！"); break;
        case 2: command("say 小賊！納命來！！"); break;
        case 3: command("say 大伙們！拿下那個可疑的傢伙！"); break;
        }
        kill_ob(me);
        me->fight_ob(this_object());
}
