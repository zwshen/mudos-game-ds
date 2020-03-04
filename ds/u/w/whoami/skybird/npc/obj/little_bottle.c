#include <ansi.h>
inherit ITEM;
void create()
{
  set_name("小瓶子",({"litte bottle","bottle"}));
  set_weight(700);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long","這是一個用玻璃製成的小瓶子，裡面盛裝的液體就是天梟聖泉的\n"
               "泉水•份量大約只能使用一次，因此不是在萬不得已的情況下，\n"
               "是不會隨便動用的•\n"
               "使用方法：use bottle\n");
    set("value",0);
  }
  set("no_put",1);
  setup();

}

void init()
{
  add_action("do_use","use");
}

int do_use(string str)
{
  object ob = this_object(), me = this_player();
  if(!str || str != "bottle") return 0;
  if(  me->is_fighting() ) 
    return notify_fail("這麼激烈的戰鬥，你還有心情管傷口？\n"); 
  if(  me->query("hp") >= me->query("max_hp")/3  )
    return notify_fail("你的狀況還不差，不需要用到這種妙藥吧•\n"); 
  if(  me->query("mp") >= me->query("max_mp")/3  )
    return notify_fail("你的狀況還不差，不需要用到這種妙藥吧•\n"); 
  if(  me->query("ap") >= me->query("max_ap")/3  )
    return notify_fail("你的狀況還不差，不需要用到這種妙藥吧•\n"); 
  if(  me->query("wound/left_arm") <= 60 )
    return notify_fail("你的狀況還不差，不需要用到這種妙藥吧•\n"); 
  if( me->query("wound/right_arm") <= 60 )
    return notify_fail("你的狀況還不差，不需要用到這種妙藥吧•\n"); 
  if( me->query("wound/right_leg") <= 60 )
    return notify_fail("你的狀況還不差，不需要用到這種妙藥吧•\n"); 
  if( me->query("wound/left_leg") <= 60 )
    return notify_fail("你的狀況還不差，不需要用到這種妙藥吧•\n"); 
  if( me->query("wound/body") <= 60 )
    return notify_fail("你的狀況還不差，不需要用到這種妙藥吧•\n"); 
  if( me->query("wound/head") <= 60 )
    return notify_fail("你的狀況還不差，不需要用到這種妙藥吧•\n"); 
  me->receive_heal("hp", 3000); 
  me->receive_heal("mp", 3000);
  me->receive_heal("ap", 3000);
  me->receive_curing("all",100); 
  me->start_busy(2);
  message_vision(HIC"$N小心翼翼的把瓶子裡的水塗抹在受傷的地方……\n"NOR,me);
  return 1;
}


