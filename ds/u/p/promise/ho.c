#include <ansi.h>
#include <login.h>
inherit NPC;

void flee();

void create()
{
  set_name("黃馬",({"yellow horse","horse"}) );
  set("race", "beast");
  set("level",25);
  set("age",10);
  set("limbs", ({ "頭部", "身體", "前腳", "後腳","復部"}));
  set("verbs", ({"bite","hoof","crash"}));
  set("ridable",1);
  set("chat_chance_combat", 30);
  set("value", 700);
          setup();
}
void init()
{
        ::init(); //luky
        add_action("do_name","name");
        if(environment(this_object())==this_player())
        {
          add_action("do_member","member");
          add_action("do_run","run");
          add_action("do_power","power");
          add_action("do_full","full");
        }
}


int ride_before_action(object me)
{
  message_vision("$N一個翻身，躍上了"+this_object()->name()+"的馬背。\n",me);
  return 1;
}

int ride_after_action(object me)
{
  message_vision("$N已經騎上了"+this_object()->name()+"。\n",me);
  return 1;
}

int ride_off_action(object me)
{
  message_vision("$N從"+this_object()->name()+"的背上跳了下來。\n",me);
  return 1;
}


