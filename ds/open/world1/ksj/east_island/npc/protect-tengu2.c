#include <ansi.h>
inherit NPC;

void create()
{
  set_name(HIC"守護天狗"NOR, ({"protect tengu","tengu","_PROTECT_TENGU2_"}) );
  set("long",@LONG
能力高於一般的天狗，負責守護天狗的首領，每位守護天狗都有其擅
長的能力。
LONG);
  set("race","monster");
  set("unit","隻");
  set("age",50);
  set("attitude", "aggressive");
  set("gender", "男性" );
  set("level",45);
  set_skill("fork",40+random(15));
  set_skill("dodge",40+random(10));
  set_skill("parry",30+random(10));
  add("addition_armor",60+random(10));
  set("chat_chance", 50);
  set("chat_msg",({
     (:command("defend black tengu"):),
     }) );
  set("chat_chance_combat",50);
  set("chat_msg_combat", ({
     (:command("defend black tengu"):),
     }) );
  setup();
  set_living_name("_NPC_PROTECT_TENGU2_");
}

int special_attack(object me,object target,int hitchance)
{
  int damage;
  if(random(8)) return 0; 
  if(!me || !target) return 0;
  message_vision("\n$N"HIW"飛向半空伸展雙翼，使出絕招"HIC"【天狗雷】"HIW"！\n"+NOR,me);
  damage = random(100)+300-(target->query_shield());
  if(damage < 0) damage=0;
  message_vision(HIR"$N被雷電當頭擊中，造成 ("+damage+") 點的嚴重灼傷！\n"NOR,target);
  target->receive_damage("hp", damage, me);
  target->add_busy(3);
  me->start_busy(2);
  COMBAT_D->report_status(target);
  return 1; 
}
