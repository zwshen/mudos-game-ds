#include <ansi.h>
inherit ITEM;

void create()
{
  set_name(HIW"銀翼龍心"NOR, ({"silver dragon heart","heart"}) );
  set("long", 
      "銀翼龍的心臟，像木桶般大小，發出冰冷的寒氣。\n"
     );
  set_weight(10000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "個");
    set("volume",20);
    set("value",600);
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

  me->receive_heal("mp", me->query("max_mp") - me->query("mp"));
  me->apply_condition("poison", 0);

  if( me->is_fighting() ) me->start_busy(2);
  message_vision(HIW "$N拿起了龍心大口地吃了下去，覺得全身清暢無比...\n" NOR,me);
  destruct(ob);
  return 1;
}
