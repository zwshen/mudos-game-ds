#include <ansi.h>
#include <path.h>

inherit NPC;

void create()
{
  set_name(YEL"黃沙賊"NOR, ({ "desert robber","robber" }) );
  set("gender", "男性" );
  set("long",@LONG
這是江湖上惡名昭彰的賊幫－－『黃沙幫』的嘍囉。
LONG
);
  set("age",25);
  set("level",10);
set("exp",3000+random(1000));
  set("race","human");
  set_skill("dodge",30);
  set_skill("parry",20);
  set("chat_chance", 30);
  set("chat_msg", ({
(: command("say 快把錢交出來！！！") :),
(: command("say 他媽的，要錢要命？！") :),
}));

  set("chat_chance_combat", 50 );        
  set("chat_msg_combat", ({
(: command("say 跟我作對？我操... 你不要以為你可以安全的走出這裡！") :),
}) );
  setup();
  add_money("coin",500);
  carry_object(__DIR__"eq/eq10")->wear();
  carry_object(__DIR__"wp/wp5")->wield();
//   call_out("loop",600);
}

void init()
{
  ::init();
  add_action("do_guard","go");
}


int do_guard(string arg)
{
  if(!this_player()->visible(this_object())) return 0;
  if(!this_player()->query_temp("robber_pass"))
  {
    command("say 要從此路過，留下買路財 !!");
    return 1;
  }
  this_player()->delete_temp("robber_pass");
  return 0;
}

void die()
{
   object me;
  object env = load_object(WD_PAST+"sand/room37");
   if( !me = query_temp("last_damage_from") )
   me = this_player(1);
   if( !me )
   {
     ::die();
     return;
   }
//7     env->start_robber();    // 重開囉
 command("tchat ... "+me->name(1)+"..你...老大會幫我報仇的....");  // 重開囉^^
  ::die();
  return;
}

int loop()
{
  object env = load_object(WD_PAST+"sand/room37");
  object ob = this_object();

  return 1;  // 取消自動開戰, 另外打死也不會開戰
  if(!ob) return 1;
  if(random(4))
  {
    remove_call_out("loop");
    call_out("loop",600);
    return 1;
  }

  command("say 時候到了，該通知老大一聲。");
  command("hehe");
  message_vision("$N急忙的回到山寨裡了。\n",ob);
  env->start_robber();
  destruct(ob);
  return 1;
}

int accept_object(object who, object ob)
{
  if(ob->query("id") != "coin" )
  {
    command("say 操！耍我是吧，快把錢交出來！！！");
    return notify_fail("");
  }
  if ( ob->query_amount() < random(300)+300 )
  {
    command("say 不夠不夠！媽的羔子！");
    return notify_fail("");
  }
  who->set_temp("robber_pass",1);
    destruct(ob);
  command("say 算你識相。");
  command("say 好，你可以滾了！");
  return 1;
}

