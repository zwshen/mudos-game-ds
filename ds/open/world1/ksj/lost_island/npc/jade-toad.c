#include <ansi.h>
inherit NPC;

void create()
{
  set_name(HIC"碧玉蟾"NOR, ({"jade toad","toad"}) );
  set("long",@LONG
一隻全身晶瑩如玉的蟾蜍，兩隻眼睛紅澄澄地像是兩顆紅寶石。
LONG
);
  set("race", "beast");
  set("gender", "雌性");
  set("unit","隻");
  set("age",8);
  set("level",23+random(2));
  set("title",HIW"  奇獸 "NOR);
  set("limbs", ({ "頭部","身體","前腳","後腳" }) );
  set("verbs", ({"crash" }) );
  set("chat_chance", 10);
  set("chat_msg", ({
     (: random_move :),
     }));
  setup();
}

void init()
{        
  ::init();
  switch( random(14) ) 
  {
    case 0:
         say(HIC"碧玉蟾"NOR"跳進草叢間消失不見了。\n");
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
    case  0..10: new(__DIR__"eq/jade-toad-wrists")->move(this_object());
          break;
  }
  ::die();
  return;
}
