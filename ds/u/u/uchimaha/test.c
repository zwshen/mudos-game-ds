#include <ansi.h>
inherit NPC;
void create()
{
set_name(NOR"骷髏\守衛"MAG"(恐懼)"NOR, ({ "dread skeleton guard","guard" }) );
           set("level",20+random(15));
           set("combat_exp",35000);
           set("age",300+random(184));
           set("gender","無性");
           set("evil",999);
set("long" ,"橘紅色如同火燄一般的眼睛，白森森的骨骼，冰冷的四肢，死者是令
人懼怕的，即使是最勇敢的戰士也震懾於他們令人不寒而慄的死亡氣息，
骷髏守衛\是暗斯德塔的法師們在遭到危險時所會招喚的幾個比較高等的戰
士，這些從地獄來的戰士的意識受到魔法的限制而只會攻擊特定的目標，
同時他們的能力也因為魔法的影響而受到不同的限制。\n");
           set_skill("unarmed",80);
           set_skill("parry",75);
           set_skill("dodge",60);
           set_skill("sword",100);
        setup();
}
int special_attack(object me,object target,int hitchance)
{
  if(!me || !target) return 0;
  if(me->is_busy()) return 0;

  if(random(5)) 
  {
    int damage;
    message_vision(GRN"\n\t$N大嘴一張，露出白森森的牙齒，一股屍氣向$n噴去！！\n\n"NOR,me,target);
    damage = 580+random(250);
    message_vision(HIR"$n一個不小心，吸進了大量的屍氣，一股作嘔的感覺立時衝上喉頭..."NOR,target);
    message_vision(HIM"$n胸中一陣劇痛！看來這股屍氣還有著強烈的腐蝕性..."HIR"("+damage+")\n"NOR,me,target);
    target->receive_damage("hp",damage);
//    message_vision(MAG"$n覺得頭一陣陣的劇痛，看來是中毒了！！"NOR,target);
//    target->apply_condition("poison", target->query_condition("poison")+(random(5)+2));
    return 1;
  }
  return 0;
}


