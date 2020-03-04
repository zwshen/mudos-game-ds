#include <ansi.h>
inherit NPC;
void create()
{
  set_name("毒蛇", ({"snake"}) );
  set("long",@LONG
這是一種具有猛烈劇毒的毒蛇，被咬到可不是好玩的。
LONG
);
  set("race", "beast");
  set("unit","隻");
  set("age",1);
  set("level",7);
  set("limbs", ({ "頭部", "腹部","胸部","尾巴" }) );
  set("verbs", ({ "bite" }) );
  setup();
}

int special_attack(object me, object target, int hitchance)
{
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(3))
  {
    message_vision("$N伸出毒牙，狠狠的咬了$n一口！\n"NOR, this_object(), target);
    target->apply_condition("poison", target->query_condition("poison")+(random(5)+1));
    return 1;
  }
  return 0;
}
