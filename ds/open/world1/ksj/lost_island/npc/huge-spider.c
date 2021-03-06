#include <ansi.h>
inherit NPC;

void create()
{
  set_name(MAG"巨嘴蜘蛛"NOR, ({"huge spider","spider"}) );
  set("long",@LONG
一隻巨大的蜘蛛，除了有強壯的肢腳外，最可怕的是有四瓣嘴唇佈
滿利齒的大嘴，是隻可怕的掠食者。
LONG);
  set("race", "beast");
  set("gender", "雄性");
  set("unit","隻");
  set("age",12);
  set("level",26+random(5));
  set("title",HIW"  奇獸 "NOR);
  set("limbs", ({ "頭部", "身體","前肢","後肢","背部" }) );
  set("verbs", ({ "bite"}) );
  set("combat_exp", 12000);
  add("addition_armor",20);
  set("chat_chance", 40);
  set("chat_msg", ({
     (: random_move :),
     }));
  setup();
}

void init()
{        
  ::init();
  switch( random(10) )
  {
    case 0:
         say(MAG"巨嘴蜘蛛"NOR"幾個跳躍，隨即消失於草叢中。\n");
         destruct(this_object());
         break;
  }
} 

int special_attack(object me, object target, int hitchance)
{
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(10))
  {
    message_vision(MAG"巨嘴蜘蛛"NOR"張開大嘴撲向$n，咬出一個皮開肉綻的傷口！"NOR, this_object(), target);
    target->recive_damage("hp",random(50)+30,me);
    target->apply_condition("blooding", target->query_condition("blooding")+(random(2)+1));
    return 1;
  }
  return 0;
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
  switch( random(99) )
  {
    case  0..3: new(__DIR__"eq/purple-jade-ring")->move(this_object());
          break;
  }
  ::die();
  return;
}
