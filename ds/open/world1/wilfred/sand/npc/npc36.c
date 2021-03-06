#include <ansi.h>
inherit NPC;

void create()
{
  set_name("刺蝟", ({"hedgehog"}) );
  set("long",@LONG
全身都是刺的刺蝟，遠看便有如一個帶刺的大肉球，
聽說此種生於沙漠的刺蝟其皮甚厚，可用來製作上好皮甲。
LONG
);
  set("race", "beast");
  set("unit","隻");
  set("age",2);
  set("level",20);
  set("limbs", ({ "頭部", "腹部","胸部","爪子" }) );
  set("verbs", ({ "bite","claw" }) );
  setup();
}

int receive_damage(string type,int cost)
{
  object ob,me;
  int i;
  ob = this_object();
  me = this_player();

  if(ob && random(2))
  {
    i = random(30);
    me->recive_damage("hp",i,me);
    me->apply_condition("blooding", me->query_condition("blooding")+random(2)+1);
    message_vision(CYN"$N一不小心被刺蝟刺到，痛得臉色蒼白！"HIR"("+i+")\n"NOR,me,ob);
  }

  ::receive_damage(type,cost,me);
  return 0;
}

void die()
{
  new(__DIR__"obj/obj6")->move(this_object());
  ::die();
  return;
}
