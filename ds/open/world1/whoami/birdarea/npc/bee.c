#include <ansi.h>
inherit NPC;
void create()
{
       set_name("變種虎頭蜂",({"tigerhead bee","bee"}));
        set("level",30+random(10));
        set("race", "野獸");
        set("age", 23);
        set("long", "兇猛的一種蜂類，雖然是蜂類，但是他卻用爪子來攻擊人。\n");
        set("limbs", ({ "頭部", "身體", "翅膀", "爪子"}) );
        set("verbs", ({ "claw","crash"}) );
        setup();
}

int special_attack(object me, object target, int hitchance)
{
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(6))
  {
    message_vision(MAG"\n$N用自己的毒針，猛力刺向$n！\n"NOR, this_object(), target);
    target->receive_damage("hp",random(100),me);
    target->apply_condition("poison", target->query_condition("poison")+(random(5)+5));
    return 1;
  }
  return 0;
}

