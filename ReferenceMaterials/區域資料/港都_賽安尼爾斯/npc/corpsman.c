#include <ansi.h>
inherit NPC;
inherit SSERVER;
void normal_ai();
void combat_ai();

void create()
{
  set_name("���ħL",({"corpsman","_CORPSMAN_"}) );
  set("long",@LONG
���x���t�d�������h�L�A�Y�����U�l�ΪӻH�W��¸���������r�ˡC
LONG);
  set("race", "human");    
  set("unit","��");
  set("title",HIC"���x"NOR);
  set("level",25);
  add("addition_armor",40);
  add("addition_damage",20);
  set_skill("unarmed", 40);
  set_skill("parry", 30);
  set_skill("dodge", 60);
  set("chat_chance", 30);
  set("chat_msg", ({
     (: normal_ai() :),
     }) );     
  set("chat_chance_combat", 100);
  set("chat_msg_combat", ({
     (: combat_ai() :),
     }) );     
  setup();
  set_living_name("_NPC_CORPSMAN_");
}

void normal_ai()
{        
  int mp,adm_hp,max_hp;
  object me,ob1,target,env;
  ob1=find_living("_NPC_REAR_ADMIRAL_");
  target = offensive_target(ob1);
  me=this_object();
  env=environment(me);
  adm_hp=ob1->query("hp");
  max_hp=ob1->query("max_hp");

  if( (target->can_fight(me)) && (me->query_temp("last_opponent") != target) )
  {
    me->kill_ob(target);
  }

  if(!random(7))
  {
    message_vision("\n$N��z������A�U�h�𮧤F�C\n",me);
    destruct(me);
    return;
  }

  if(me->is_busy()) return;
  if( objectp(ob1) )
  {
    if( env != environment(ob1) )
    {
      return;
    }
    else if( adm_hp < (max_hp-500) )
    {
      message_vision(HIG"\n$N���t�a�q�Ľc�����X���Ĥή��r�Ĥ��A���ֱN����檺�����C\n"NOR,me);
      ob1->receive_heal("hp",300+random(100));
      return;
    }
  }
  return;
}

void combat_ai()
{        
  int mp,adm_hp,max_hp;
  object me,ob1,env;
  ob1=find_living("_NPC_REAR_ADMIRAL_");
  me=this_object();
  env=environment(me);

  adm_hp=ob1->query("hp");
  max_hp=ob1->query("max_hp");
 
  if(me->is_busy()) return;
  if( objectp(ob1) )
  {
    if( env != environment(ob1) )
    {
      return;
    }
    else if( adm_hp < (max_hp-1000) )
    {
      message_vision(HIG"\n$N���t�a�b�ֱN���W���ˤf��W��徯�A�P�ɥ��F��h�w�C\n"NOR,me);
      ob1->receive_heal("hp",300+random(100));
      return;
    }
  }
  return;
}