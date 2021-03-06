#include <ansi.h>
inherit NPC;
void combat_ai();

void create()
{
  set_name("持斧武者",({"axeman","_AXEMAN_"}) );
  set("long",@LONG
以法術召喚出來的式鬼，是一名高大的武士，雙手持握著雙刃鐵斧。
LONG);
  set("race", "human");    
  set("unit","位");
  set("age",103);
  set("title",RED"前鬼"NOR); 
  set("level",35+random(4));
  add("addition_armor",150);
  add("addition_damage",60);
  set("str",80);
  set_skill("axe", 70);
  set_skill("parry", 50);
  set_skill("dodge", 50);
  set("chat_chance", 80);
  set("chat_msg", ({
     (:command("wield axe"):),
     (:command("defend oldwoman"):),
     }) );     
  set("chat_chance_combat",80);
  set("chat_msg_combat", ({
     (: combat_ai() :),
     }) );
  setup();
  set_living_name("_NPC_AXEMAN_");
  carry_object(__DIR__"eq/ghost-axe")->wield();
}

void init()
{
  ::init();
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if(!this_object()->visible(this_player())) return;
  if(userp(this_player()) )
     this_object()->kill_ob(this_player());
}

void combat_ai()
{
  object me,ob;
  me=this_object();
  ob=find_living("_NPC_CAT_OLDWOMAN_");

  if( !me->query_temp("weapon") )
  { 
    command("wield axe");
  }
  else if( me->query_temp("protecter") != ob )
    command("defend oldwoman");

  return;
}

void die()
{
  message_vision("\n$N受創過重，化為輕煙消失無蹤了。\n",this_object());
  destruct(this_object());
  ::die();
  return;
}
