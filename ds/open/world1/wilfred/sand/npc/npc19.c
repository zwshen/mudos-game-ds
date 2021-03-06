inherit NPC;

void create()
{
  set_name("商隊保鑣", ({ "caravan guard","guard" }) );
  set("gender", "男性" );
  set("age", 28);
  set("long", @LONG
他是一位被請來保護商隊保鑣，長年跟著商隊四處奔走，此人虎背熊腰，
濃眉大眼，渾身散發著一股英氣，看來並非易與之輩。
LONG
);
  set("level",25);
  set("attitude", "heroism");
  set_skill("blade",60);
  set_skill("dodge",70);
  set_skill("parry",60);
  setup();
  carry_object(__DIR__"wp/wp4")->wield();
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
  command("say 竟敢動到我頭上來了？ 找死！");

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

