inherit NPC;

void soldier_assist(object me);

void create()
{
  set_name("商隊工人", ({ "caravan worker","worker" }) );
  set("gender", "男性" );
  set("age", 28);
  set("long","他是一位跟著商隊工作的工人，長年在外奔波，皮膚被曬得黝黑發亮。");
  set("level",12);
  set("attitude", "friendly");
  setup();
}

void init()
{
  ::init();
  add_action("do_kill","kill");
}

int do_kill(string arg)
{
  object *inv, me = this_player();
  int i;

  if (!arg) return 0;
  if(present(arg, environment(me)) != this_object()) return 0;
  if( is_fighting(me) ) return 0;
  command("flop");
  command("scream");

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
    case 0: command("say 可惡！竟趕攔路打劫，你眼裡還有王法嗎？\n"); break;
    case 1: command("say 喂﹗你想幹什麼﹖"); break;
  }
  kill_ob(me);
  me->fight_ob(this_object());
}
