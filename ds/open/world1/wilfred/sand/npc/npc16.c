#include <ansi.h>
inherit NPC;

int action(object me, object ob);
void combat_action();

void create()
{
  set_name(WHT"小賊"NOR, ({ "young thief","thief" }) );
  set("gender", "男性" );
  set("long",@LONG
一位身穿破爛衣服的小孩子，有著一副令人討厭的嘴臉，專門對路過的人下手。
LONG
);
  set("age",10);
  set("level",25);
  set("race","human");
  set("str",30+random(5));
  set("class1","thief");
  set_skill("dagger",100);
  set_skill("backstab",100);

  set("chat_chance", 5);
  set("chat_msg", ({
(: command("hehe") :),
(: command("say 今天撈了不少啊...") :),
(: random_move :),
}));

  set("chat_chance_combat", 50 );
  set("chat_msg_combat", ({
(: combat_action :),
}) );
  setup();
  carry_object(__DIR__"wp/wp7")->wield();
  carry_object("/open/always/thief_mark")->set_temp("invis",1);

  set_temp("hide",1);

  call_out("do_shout",1);
  call_out("destobj",600);
}

void combat_action()
{
  random_move();
  set_temp("hide",1);
}

void do_shout()
{
  message("world:world1:vision",HIC"\n\t有竊賊出現在黃沙道附近，請旅人多加注意。\n\n"NOR,users());
  return;
}

void init()
{
  object me, ob = this_object();
  ::init();

  if( interactive(me = this_player()) )
    action(me,ob);
}

int action(object me, object ob)
{
  object obj;
  int temp1, temp2;

  if(me->query("level") < 10 || wizardp(me)) return 1;

  if( me == query_temp("last_opponent") )
  {
    call_out("kill_enemy",1,me);
    return 1;
  }

  if(obj = present("coin",me))
    if(random(6))
    {
      write(HIR"你突然覺得身上好像少了些什麼。\n"NOR);
      command("hehe");

      temp1 = obj->query_amount();
      if( temp1 >= 100 )
        temp2 = random( (temp1-100)/100 ) + 100;
      else
        temp2 = temp1;
      obj->set_amount( temp1 - temp2 );
      ob->receive_money( temp2 );
    }
    else
    {
      message_vision(HIR"$N發覺不大對勁了，一回頭看見$n"HIR"正抓著$N的古幣！！\n"NOR,me,ob);
      command("walileh");
      ob->delete_temp("hide");
      call_out("flee",3);
    }
  if(!random(7)) call_out("flee",1);
  else command("hmm");
}

void flee()
{
  this_object()->random_move();
  this_object()->set_temp("hide",1);
}

void kill_enemy(object me)
{
  if(!me || !environment(me) || environment(this_object()) != environment(me) ) return;
  command("wield poison dagger");
  command("backstab " + me->query("id"));
}

void destobj()
{
  if(!environment(this_object())) return;
  message("world:world1:vision",HIC"\n\t竊賊逃得不知去向了。\n\n"NOR,users());
  destruct(this_object());
}

void die()
{
  object obj;
  remove_call_out("destobj");
  obj = present("mulit-function dagger",this_object());
  if( objectp(obj) ) destruct(obj);
  ::die();
  return;
}

