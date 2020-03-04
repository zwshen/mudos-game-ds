#include <ansi.h>
inherit NPC;

void create()
{
  set_name(HIW"雪男"NOR, ({"umaro"}));
  set("long",@LONG
身形高大，長得像猩猩的雪怪，全身長滿了長長的白毛，力大無比，
攀登雪山的人偶爾會遇見牠，據說牠會引發暴風雪。
LONG);
  set("race", "beast");
  set("unit","隻");
  set("age",50);
  set("gender", "雄性" );
  set("level",27+random(4));
  set("limbs", ({ "頭部", "身體","腹部","前腳","後腳"}));
  set("verbs", ({"bite","claw"}));
  add("addition_damage",15+random(5));
  setup();
  carry_object(__DIR__"eq/ice-crystal");
}
