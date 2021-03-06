#include <ansi.h>
inherit NPC;
inherit SSERVER;
void normal_ai();
void combat_ai();

void create()
{
  set_name("護衛兵",({"marine guard","guard","_MARINE_GUARD1_"}) );
  set("long",@LONG
負責保護高級軍官安全的海軍士官，受過嚴格的訓練。
LONG);
  set("race", "human");    
  set("unit","位");
  set("title",HIC"海軍"NOR);
  set("level",40);
  add("addition_armor",50);
  add("addition_damage",30);
  set_skill("gun", 80);
  set_skill("parry", 60);
  set_skill("dodge", 60);
  set_skill("unarmed", 80);
  set("chat_chance", 30);
  set("chat_msg", ({
     (: normal_ai() :),
     }) );     
  set("chat_chance_combat", 100);
  set("chat_msg_combat", ({
     (: combat_ai() :),
     }) );     
  setup();
  set_living_name("_NPC_MARINE_GUARD1_");
  carry_object(__DIR__"eq/hand-gun")->wield();
}

void init()
{
  ::init();
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if(!this_object()->visible(this_player())) return;
  if( userp(this_player()) && this_player()->query_temp("marine_enemy") )
    this_object()->kill_ob(this_player());
}

void normal_ai()
{        
  object me,ob1,target;
  me=this_object();

  if( !random(7) )
  {
    message_vision("\n$N向少將敬禮後，轉身齊步離開了。\n",me);
    destruct(me);
    return;
  }

  ob1=find_living("_NPC_REAR_ADMIRAL_");
  target = offensive_target(ob1);

  if(target->can_fight(me))
  {
    target->kill_ob(me);
    me->kill_ob(target);
  }

  return;
}

void combat_ai()
{        
  return;
}

void die()
{
  object ob;
  if( !ob = query_temp("last_damage_from") )
    ob = this_player(1);
  if( !ob ) 
  {
    ::die();
    return;
  }
  ob->set_temp("marine_enemy",1);
  ::die();
  return;
}
