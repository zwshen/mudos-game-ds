#include <ansi.h>
inherit NPC;

void create()
{
  set_name(HIW"刃爪鎌鼬"NOR, ({"blade mink","mink"}) );
  set("long",@LONG
據說鐮鼬會造成真空撕裂獵物，被真空切開的傷口將難以癒合，牠的
雙爪又利又長，簡直像是十把小刀。
LONG
);
  set("race", "beast");
  set("unit","隻");
  set("age",12);
  set("gender", "雄性" );
  set("level",30+random(3));
  set("title",HIW"  奇獸 "NOR);
  set("limbs", ({ "頭部", "身體","尾巴"}) );
  set("verbs", ({"bite","claw"}) );
  add("addition_damage",45);
  add("addition_armor",20);
  set("chat_chance", 25);
  set("chat_msg", ({
     (: random_move :),
     }));
  setup();
}

int special_attack(object me, object target, int hitchance)
{
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(9))
  {
    message_vision("$N化為一道旋風，從$n身旁擦過，$n只感到一陣劇痛！\n"NOR, me, target);
    target->apply_condition("blooding", target->query_condition("blooding")+(random(3)+1));
    return 1;
  }
  return 0;
}

void init()
{        
  ::init();
  switch( random(10) )
  {
    case 0:
         say(HIW"刃爪鎌鼬"NOR"化為一道旋風，消失不見了。\n");
         destruct(this_object());
         break;
  }
} 
