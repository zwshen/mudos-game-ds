inherit NPC;

void create()
{
  set_name("小王", ({"little wang","wang"}) );
  set("long",@LONG
古墓的管理員。
LONG
);
  set("race", "human");
  set("unit","隻");
  set("age",54);
  set("level",30);
  setup(); 
  carry_object(__DIR__"under/npc/obj/fire-fruit");
  add_money("coin",200);
}


