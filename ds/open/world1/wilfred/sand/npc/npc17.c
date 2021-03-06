inherit NPC;
inherit SELLMAN;

void soldier_assist(object me);

void create()
{
  set_name("商隊老闆", ({ "caravan boss","boss" }) );
  set("gender", "男性" );
  set("age", 30);
  set("long", @LONG
他是一位經常往來滄縣與磐龍城的商人，長年在外奔波，皮膚被曬得
黝黑發亮，也許你可以跟他買點東西 <看存貨: list   買東西: buy>。
LONG
);
  set("level",10);
  set("attitude", "friendly");
  set("chat_chance", 20);
  set("chat_msg", ({
(: command("say 來來來，看看上好的貨品，保證滿意。") :),
"商隊老闆伸長了衣袖，擦了擦臉上的汗。\n",
(: command("smile") :),
}) );

  set("sell_list",([
__DIR__"obj/obj9" : 10,
__DIR__"obj/obj10" : 5,
__DIR__"obj/obj11" : 20,
__DIR__"eq/eq16" : 2,
__DIR__"eq/eq17" : 2,
__DIR__"eq/eq18" : 2,
]) );
  setup();
  add_money("coin",500);
}

void init()
{
  ::init();
  add_action("do_list","list");
  add_action("do_buy","buy");
  add_action("do_kill","kill");
}

int do_kill(string arg)
{
  object *inv, me = this_player();
  int i;

  if (!arg) return 0;
  if(present(arg, environment(me)) != this_object()) return 0;
  if( is_fighting(me) ) return 0;
  command("say 殺人哪∼∼∼快來救我哪∼∼∼");

  inv = all_inventory(environment());
  for(i=0;i<sizeof(inv);i++)
  {
    if(inv[i] ==  this_object()) continue;
    inv[i]->soldier_assist(me);
  }
  return 0;
}

void soldier_assist(object me)
{
  if( !living(this_object()) || is_fighting(me) ) return;

  switch(random(2))
  {
    case 0: command("say 可惡！竟敢攔路打劫，你眼裡還有王法嗎？\n"); break;
    case 1: command("say 喂﹗你想幹什麼﹖"); break;
  }
  kill_ob(me);
  me->fight_ob(this_object());
}
