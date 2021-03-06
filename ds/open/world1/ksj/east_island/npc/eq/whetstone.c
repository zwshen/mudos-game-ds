#include <path.h>
inherit ITEM;
int i=0;

void create()
{
  set_name("磨刀石", ({"whetstone","stone"}) );
  set("long",@LONG
一塊方方長長由堅硬石頭製成的磨刀石，用來打磨武器回復銳利
(whet)。
LONG
);
  set_weight(500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "塊");
    set("volume",1);
    set("value",500);
  }
  setup(); 
}

void init()
{
  add_action("do_whet","whet");
}

int do_whet(string arg)
{
  object me,obj,stone;
  int dur;
  me=this_player();
  stone=this_object();
  if( me->is_busy() ) return notify_fail("你上一個動作還沒有完成。\n");
  if( me->is_fighting() ) return notify_fail("你在戰鬥中，沒空做這件事。\n");
  if(!arg) return notify_fail("你要用磨刀石修復什麼東西？\n");
  if(!objectp(obj = present(arg, me)) ) return notify_fail("你身上沒有這樣東西。\n");
  if( obj->query("no_repair") ) return notify_fail("這件東西沒辦法修復。\n");
  dur=obj->query_durable();
  if( dur < 70 ) return notify_fail(obj->query("name")+"已經損壞得無法磨利。\n");
  if( dur > 99 ) return notify_fail(obj->query("name")+"不需要修復。\n");
  message_vision("$N拿起磨刀石，仔細打磨$n受損的地方。\n",me,obj);
  obj->set_durable(100);
  i=i+1;
  stone->set_temp("used",i);
  if( stone->query_temp("used") > 2 )
  {
    tell_object(me,"磨刀石已經不堪使用了，你隨手丟在一旁。\n");
    destruct(stone);
  }
  return 1;
}
