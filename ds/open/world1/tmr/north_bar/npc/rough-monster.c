#include <ansi.h>
inherit NPC;

void create()
{
  set_name( "菌絲獸" , ({"hypha monster","monster"}) );
  set("long",@LONG
這是一隻全身披滿青綠色菌絲的野獸，散發出非常
噁心的臭味，有如腐敗的屍體。
LONG
);
  set("race", "beast");
  set("unit","隻");
  set("age",45);
  set("gender", "雄性" );
  set("attitude", "aggressive");
  set("level", 25 + random(5));
  set("title", "魂獸" );
  set("limbs", ({ "身體","頭部","背部", "前胸", "前腳","後腳" }) );
  set("verbs", ({ "bite", "claw" }) );
  add("addition_damage",30+random(15));
  set("chat_chance", 20);
  set("chat_msg", ({
     (: random_move :),
     }));
  setup();
}
