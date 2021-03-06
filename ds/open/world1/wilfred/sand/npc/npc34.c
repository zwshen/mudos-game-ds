#include <ansi.h>
inherit NPC;

int quest();

void create()
{
  set_name("迷途旅人", ({ "traveler" }) );
  set("gender", "男性" );
  set("long",@LONG
這是一位穿著普通的旅行者，他的臉色驚慌，看來是迷路了。
LONG
);      
  set("age",22);
  set("level",1);
  set("race","human");

  set("chat_chance", 20);
  set("chat_msg", ({
"旅人慌張的看了看了四周，再比對手上的地圖。\n",
(: command("say 奇怪，明明是往這裡走沒錯啊...") :),
(: command("ack") :),
(: command("help!") :),
}));

  set("chat_chance_combat", 50 );
  set("chat_msg_combat", ({
(: command("help!") :),
}) );
  set("talk_reply","我迷路了！救命啊！！救命啊！！你能帶我回黃沙鎮外嗎∼∼∼\n");
  setup();
}

void init()
{
  object ob = this_object();
  object inv = environment(ob);
  if(inv->query("short") == "黃沙鎮外")
  {
    command("follow none");
    command("say 吁 .... 得救了 ... ");
    command("thank");

    if(!random(6))
    {
      command("say 我有要緊事要辦，少陪了，這東西是我在平原上撿到的，看來挺值錢的，給你吧。");
      message_vision(HIW"[$N丟下一個某物品]\n"NOR,ob);
      new("/open/always/time-q/white_crystal")->move(inv);
    }

    message_vision("$N急忙的離開了。\n",ob);
    call_out("dest_temp",1);
  }
}

void relay_say(object me, string str)
{
  object ob = this_object();
  if( !userp(me) ) return;
  if( me == this_object() ) return;
  if(   strsrch(str,"可") != -1 
     || strsrch(str,"能") != -1
     || strsrch(str,"行") != -1
     || strsrch(str,"好") != -1
    )
  {
    command("say 你要幫我嗎？快想個辦法吧!");
    return;
  }
  if(strsrch(str,"follow") != -1 && ( strsrch(str,"me") != -1 || strsrch(str,me->query("id")) != -1 ) )
  {
    call_out("do_follow",1,me);
    return;
  }
  if(strsrch(str,"跟") != -1 && ( strsrch(str,"我") != -1 || strsrch(str,me->query("name")) != -1 ) )
  {
    call_out("do_follow",1,me);
    return;
  }
  return;
}

int do_follow(object me)
{
  command("thank");
  command("follow "+me->query("id"));
  return 1;
}

void dest_temp()
{
  destruct(this_object());
}
