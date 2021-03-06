#include <ansi.h>
inherit ITEM;

void create()
{
  set_name(MAG"腐毒丹丸"NOR, ({ "poison-snake pill","pill" }));
  set("long",@LONG
一顆散發惡臭的小丸子，吃下後說不定會腸穿肚爛。
LONG
);
  set_weight(50);
  if(clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "顆");
  }
  setup();
}

void init()
{
  add_action("do_eat", "eat");
}

int do_eat(string arg)
{
  string type,msg;
  object ob,me,env;
  me = this_player();
  ob = this_object();
  if( !ob ) return 0;
  if( !ob->id(arg) ) return 0;
  if( !env = environment(ob)) return 0;
  if( env != me && !ob->query("no_get")) return 0;
  if( me->is_busy() )
    return notify_fail("你上一個動作還沒有完成。\n");
  me->receive_damage("hp",100,ob);
  me->apply_condition("poison", me->query_condition("poison")+(random(5)+15) );
  if( me->query_condition("blooding") > 5)
    me->apply_condition("blooding", me->query_condition("blooding")-(random(5)+1) );
  if( me->is_fighting() ) me->start_busy(2);
  message_vision(MAG"$N吃下了一顆惡臭的丹丸，覺得肚腸絞痛無比...\n" NOR,me);
  destruct(ob);
  return 1;
}
