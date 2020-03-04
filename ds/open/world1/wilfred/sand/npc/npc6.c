inherit NPC;

void create()
{
  set_name("籪富", ({"dragonfly"}) );
  set("long",@LONG
娩常ǎ籪富
LONG
);
  set("race", "beast");
  set("unit","唉");
  set("age",1);
  set("level",2);
  set("con",1);
  set("limbs", ({ "繷场", "浮场","场" }) );
  set("verbs", ({ "bite" }) );
  setup();
  add_money("coin",10);
}
