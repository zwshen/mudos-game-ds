#include <ansi.h>
#include <path.h>

inherit NPC;

string *go_temp = ({
"south","east","south","eastdown","east","east","south",
"east","east","east","east","east","east","east","east","east",
"south","east",
});

void create()
{
  set_name("黃沙賊", ({ "desert robber","robber" }) );
  set("gender", "男性" );
  set("long",@LONG
這是江湖上惡名昭彰的賊幫－－『黃沙幫』的嘍囉。
LONG
);
  set("age",26);
  set("level",14+random(3));
set("exp",5000+random(1000));
  set("race","human");
  set_skill("dodge",50);
  set_skill("parry",40);
  set("chat_chance_combat", 50 );
  set("chat_msg_combat", ({
(: command("cow") :),
}) );
  setup();
  set_living_name("robber_war");
  carry_object(__DIR__"eq/eq13")->wear();
  carry_object(__DIR__"wp/wp4")->wield();
  call_out("go",1,0);
}
void init()
{
  object ob = this_object(), me = this_player();
  object env = load_object(WD_PAST+"sand/room37");

  if(userp(me)) command("say 滾開！別擋路！！");
  if( me->query("id") == "harn-tar-fu" )
  {
    command("hehe");
    command("say 把錢拿出來！！動作快！！");
    call_out("robber",2,ob,env);
  }
}

void robber(object ob,object env)
{
  if(!ob) return;
  message_vision("錢莊很快的被$N洗劫一空！！\n",ob);
  message("world:world1:vision",
  HIY"黃沙賊大笑道：『哈哈哈，多謝各位老爺的銀子！！咱們後會有期了！』\n"NOR,users());
  call_out("robber_dest",2,ob); // 2003.4.10 新增  by ksj
  env->get_money();
  destruct(ob);
  return;
}

// 2003.4.10 新增  by ksj
void robber_dest(object ob)
{
  destruct(ob);
}

int go(int index)
{
  object ob = this_object();
  if(!environment(ob)) return 1;
  if(index == sizeof(go_temp)) return 1;

  if(ob->is_busy())
  {
    call_out("go",1,index);
    return 1;
  }

  command(go_temp[index]);

  call_out("go",random(4)+10,++index);
  return 1;
}

void die()
{
   object ob;
   if( !ob = query_temp("last_damage_from") )
   ob = this_player(1);
   if( ob ) ob->add_temp("quest/sandwarp", 1);

   ::die();
   return;
}

