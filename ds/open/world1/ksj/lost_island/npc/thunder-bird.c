#include <ansi.h>
inherit NPC;

void create()
{
  set_name(HIC"雷犀鳥"NOR, ({"thunder bird","bird"}) );
  set("long",@LONG
牠最奇特的地方就是頭上的尖角了，可以發出電流擊昏敵人，幾隻雷
犀鳥就可以電昏一隻大象，但此鳥卻經常被閃電擊斃。
LONG
);
  set("race", "beast");
  set("unit","隻");
  set("age",20);
  set("gender", "雄性" );
  set("level",30+random(3));
  set("title",HIW"  奇獸 "NOR);
  set("limbs", ({ "頭部", "身體","翅膀"}) );
  set("verbs", ({"poke"}) );
  set("chat_chance", 30);
  set("chat_msg", ({
  (: random_move :),
  }));
  setup();
}

int special_attack(object me, object target, int hitchance)
 {
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(6))
  {
    message_vision("$N頭上的角發出一道電光擊向$n，$n感到全身發痲無法動彈！\n"NOR, this_object(), target);
    target->add_busy(2);
    return 1;
  }
  return 0;
 }

void init()
{        
        ::init();
        switch( random(10) ) {
                case 0:
                  say(HIC"雷犀鳥"NOR"飛到高空，失去了蹤影。\n");
                  destruct(this_object());
                  break;
        }
} 
