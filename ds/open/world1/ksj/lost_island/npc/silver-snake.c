#include <ansi.h>
inherit NPC;

void create()
{
  set_name(HIW"鰭背銀蟒"NOR, ({"silver snake","snake"}) );
  set("long",@LONG
背上長著尖鰭，全身銀白的鱗片閃閃發光，身長超過３０尺的巨蟒，
爬行時有如一道白光穿梭於草叢之中。
LONG
);
  set("race", "beast");
  set("unit","隻");
  set("age",50);
  set("gender", "雄性" );
  set("level",25+random(3));
  set("title",HIW"  奇獸 "NOR);
  set("limbs", ({ "頭部", "身體","尾巴" }) );
  set("verbs", ({ "bite" }) );
  set("chat_chance", 20);
  set("chat_msg", ({
     (: random_move :),
     }));
  setup();
}

int special_attack(object me, object target, int hitchance)
{
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(12))
  {
    message_vision("$N游動身形迅速到$n腳下，狠狠的咬了$n一口！\n"NOR, this_object(), target);
    target->apply_condition("poison", target->query_condition("poison")+(random(5)+3));
    return 1;
  }
  return 0;
}

void init()
{        
  ::init();
  switch( random(14) )
  {
    case 0:
         say(HIW"鰭背銀蟒"NOR"一溜煙消失在草叢間。\n");
         destruct(this_object());
         break;
  }
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
  switch( random(100) )
  {
    case  0..10: new(__DIR__"eq/silver-snake-waist")->move(this_object());
          break;
  }
  ::die();
  return;
}
