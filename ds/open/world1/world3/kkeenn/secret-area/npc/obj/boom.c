#include <ansi.h>
inherit ITEM;

void create()
{
  set_name("手榴彈",({"boom"}));
  set_weight(5000);
  set("long","威力強大的手榴彈, 要丟出去請用 throw [方向]  或 throw");
  set("value",2000);
  set("no_get","笨蛋!快被炸死了還不快逃!還想撿起來ㄛ!");
  set("no_sac", 1);
   setup();
}

void init()
{
  add_action("do_throw","throw");
}

int do_throw(string str)
{
  object me = this_player(), ob = this_object();
  object env = environment(me), target, rope;
  mapping exit = env->query("exits");

  if(!env) return notify_fail("四處一片黑暗，你無法行動。\n");
  if(me->is_busy()) return notify_fail("你正在忙.\n");
  if(!str)
  {
    target = environment(me);
    str = "HERE";
  }
  else
  {
    if(undefinedp(exit[str])) return notify_fail("這裡沒有這個方向。\n");
    if( !target = find_object(exit[str]) ) return notify_fail("你發現事情不大對了，但又說不上來，最好敢快通知巫師。\n");
  }

  message_vision(HIW"$N(Radio): Fire in the hole!! ("+str+")。\n"NOR,me);
  call_out("do_move",1,ob,target);
  me->add_busy(1);
  return 1;
}

void do_move(object ob, object target)
{
  if(!ob->move(target)) return;
  tell_room(target,HIW"有一顆手榴彈飛了過來。\n"NOR);
  call_out("boom",1,target);
}

void boom(object target)
{
  object *obs = all_inventory(target);
  int i, damage;
  string name;

  tell_room(target,HIY"\n一聲轟然巨響!\n\n"NOR);

  for(i=0;i<sizeof(obs);i++)
  {
    if(!living(obs[i])) continue;
    if(obs[i]->query("id") == "master") continue;
    damage = random(250)+50;
    obs[i]->receive_damage("hp",damage);
    tell_room(target,"爆炸威力造成"HIC+obs[i]->name(1)+NOR"("+damage+")點的傷害.\n");
    (this_player()) ? name = this_player()->name(1) : name = "某人";
    obs[i]->set_temp("temp/death_type",HIR"[被"+name+"炸死]"NOR);
}
  destruct(this_object());
}


