inherit NPC;
void create()
{
  set_name("小鵰", ({"little prey","prey"}) );
  set("long",@LONG
一隻小小鵰。
LONG
);
  set("race", "beast");
  set("unit","隻");
  set("age",5);
  set("level",20);
  set("limbs", ({ "頭部", "腹部","胸部","爪子","尾巴" }) );
  set("verbs", ({ "bite","claw" }) );
  setup();
  add_money("coin",100);
}


