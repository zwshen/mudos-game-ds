#include <room.h>
inherit ROOM;

void create()
{
  set("short","河堤北端");
  set("long",@LONG
這裡是一座高高的土堤，土堤上鋪著大小不一的石塊，你現在所
站的位置是土堤的北邊末端，往東邊走下去是一大片的農田，河堤下
的岸邊有一塊水域的水流較平緩，可以練習泳技(practice swim)。
LONG);
  set("exits",([ 
      "east":__DIR__"room30",
      "south":__DIR__"room34",
     ]));
  set("no_clean_up",0);
  set("outdoors","land");
  setup();
}            

void init()
{
  if( this_player()->query_temp("Swim") )
    this_player()->delete_temp("Swim");
  add_action("do_practice","practice");
}

int room_effect(object me)
{
  me=this_player();
  if(me->query_temp("Swim")) 
  {
    if(me->query("swim")>39) return notify_fail("你的泳技在這水淺的地方，已經無法進步了。\n");
    if(me->query("ap")<10) return notify_fail("你的體力不夠了，無法再練習游泳。\n");
    message_vision("$N在水上努力的練習游泳，似乎頗有心得。\n",me);
    me->improve_skill("swim", random(me->query_int()+5)+1);
  }   
}
int do_practice(string arg)
{
  object me;
  me=this_player();
  if(arg != "swim")  return notify_fail("你只能在這裡練習游泳(swim)。\n");
  if( me->query_skill("swim",1)<20)
    return notify_fail("你的泳技不夠純熟，在水中載浮載沉後狼狽不堪地爬了上來。\n");
  if( me->over_encumbranced() ) return notify_fail("你的負荷過重﹐動彈不得。\n");
  if( me->query("wound/foot") > 10 ) return notify_fail("你的雙腳傷勢過重，無法游泳。\n");
  if( me->query("wound/hand") > 10 ) return notify_fail("你的雙手傷勢過重，無法游泳。\n");
  if( me->query("wound/head") > 10 ) return notify_fail("你的頭部傷勢過重，無法游泳。\n");
  if( me->query("wound/body") > 10 ) return notify_fail("你的身體傷勢過重，無法游泳。\n");
  if(me->query("ap") <10) return notify_fail("你的體力不夠，無法繼續練習游泳。\n");
  if( me->query_temp("Swim"))
    return notify_fail("你已經在練習游泳了。\n");
  if( me->is_fighting() )
    return notify_fail("你正忙著打架，沒空練習游泳。\n");
  if( me->is_ghost() )
    return notify_fail("都死了，難道你要當個水鬼害人？\n");
  if( me->is_busy() )
    return notify_fail("你正忙著，沒有空練習游泳。\n");
  if( me->query_skill("swim",1) > 39 )
    return notify_fail("在這種水淺，你的泳技無法進步了。\n");
  message_vision("$N深深吸了一口氣，開始練習游泳了。\n",me);
  me->set_temp("Swim",1);
  return 1;
}           
