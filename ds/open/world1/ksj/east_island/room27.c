#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
  set("short","草地");
  set("long",@LONG
這裡是農田旁的一片大草地，草地上長滿茂盛及膝的青草，是村
民用來放牧牲畜的地方，草地上有一些坑洞，草叢中不時有窸窣的聲
音。
LONG);
  set("exits",([ 
      "east":__DIR__"room22",
      "south":__DIR__"room26",
      "north":__DIR__"room28",
     ]));
  set("no_clean_up",0);
  set("outdoors","land");
  set("item_desc",([
      "草叢" : "一叢及腰的草叢，不時傳來窸窣的聲音。\n",
     ]));
  set("objects",([
      __DIR__"npc/spot-snake":2,
     ]) );
  setup();
}            

void init()
{
  add_action("do_search","search");
}

int do_search(string arg)
{
  object me=this_player(),snake;
  snake = new(__DIR__"npc/golden-snake.c");
  if(query_temp("snake1")) return notify_fail("你東翻西找，一無所獲。\n");
  if(arg !="草叢" )
    return notify_fail("你要找什麼東西呀？\n");
  else
  {
    message_vision(HIY"$N往草叢東翻翻西翻翻，突然許\多蛇影狂竄而出！\n\n"NOR,me);
    new(__DIR__"npc/golden-snake.c")->move(environment(me));
    new(__DIR__"npc/snake1.c")->move(environment(me));
    new(__DIR__"npc/snake1.c")->move(environment(me));
    new(__DIR__"npc/snake2.c")->move(environment(me));
    new(__DIR__"npc/snake2.c")->move(environment(me));
    new(__DIR__"npc/snake3.c")->move(environment(me));
    new(__DIR__"npc/snake3.c")->move(environment(me));
    new(__DIR__"npc/snake4.c")->move(environment(me));
    new(__DIR__"npc/snake4.c")->move(environment(me));
    new(__DIR__"npc/snake5.c")->move(environment(me));
  } 
  set_temp("snake1",1);
  call_out("delay",900,this_object());
  return 1;
}

void delay(object room)
{
  delete_temp("snake1");
}
