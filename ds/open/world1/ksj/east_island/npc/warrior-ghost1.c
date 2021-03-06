#include <ansi.h>
inherit NPC;

void create()
{
  set_name("武士鬼魂",({"warrior ghost","ghost"}) );
  set("long",@LONG
以前到出雲山參與圍殺八岐大蛇武士的鬼魂，徘徊在山中不肯離去，
由於生前怨念太重，導致死後變成嗜殺的惡鬼。
LONG);
  set("race", "human");    
  set("unit","隻");
  set("attitude", "killer");
  set("level",35+random(11));
  add("addition_armor",40);
  add("addition_damage",20);
  set("orochi_beast_2",1);
  set_skill("unarmed", 40);
  set_skill("parry", 30);
  set_skill("dodge", 30);
  set("chat_chance", 10);
  set("chat_msg", ({
     (: random_move :),
     (: command,"wield sword" :),
     }));
  set_temp("apply/hit",50);
  set_temp("apply/dodge",50);
  setup();
  carry_object(__DIR__"eq/ghost-sword")->wield();
}

void die()
{
  message_vision("\n$N化為輕煙消失無蹤了。\n",this_object());
  destruct(this_object());
  ::die();
  return;
}
