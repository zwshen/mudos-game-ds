#include <ansi.h>
inherit NPC;

void create()
{
  set_name("刺牛", ({"prick cow","cow"}) );
  set("long",@LONG
一隻全身長滿尖刺的水牛，牠的動作很緩慢，不然一不小心就會刺到
自己，性情溫和，喜歡吃草跟泡水。
LONG
);
  set("race", "beast");
  set("unit","隻");
  set("age",12);
  set("gender", "雄性" );
  set("level",33+random(4));
  set("title",HIW"  奇獸 "NOR);
  set("limbs", ({ "頭部", "身體","尾巴","前腳","後腳" }) );
  set("verbs", ({ "bite","crash" }) );
  set("chat_chance", 10);
  set("chat_msg", ({
   YEL"刺牛張嘴叫著：哞∼∼嗚∼。\n"NOR,
   YEL"刺牛好整以暇地低頭吃著草。\n"NOR,
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
    message_vision(HIW"\n刺牛突然往$N的身上一撞，扎出十多個傷口！\n\n"NOR, target);
    target->receive_damage("hp",random(50)+50,target);
    target->apply_condition("blooding", target->query_condition("blooding")+(random(3)+2));
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
         say("刺牛踩著小踏步，奔進小水窪中了。\n");
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
  switch( random(99) )
  {
    case  0..39: new(__DIR__"eq/cow-skin-armor")->move(this_object());
    break;
  }
  ::die();
  return;
}
