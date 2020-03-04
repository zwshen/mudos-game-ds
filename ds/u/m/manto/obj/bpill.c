#include <ansi.h>
inherit ITEM;

void create()
{ 
  set_name(CYN"八氣丹"NOR, ({ "bagi-power pill","pill" }));
  set("long",
      "八極門內秘傳妙藥，能補充大量的八極勁道•\n"
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
  me->add_temp("exert_mark/bagi-power",200);
  if( me->is_fighting() ) me->start_busy(2); 
  message_vision("$N吃下了一顆$n•\n" NOR,me,ob);
  destruct(ob);
  return 1;
}

