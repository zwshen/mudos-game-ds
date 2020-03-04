inherit ROOM;
void create()
{
        set("short","古木上");
        set("long",@LONG
你來到了古木的另一段分枝，這裡比起剛剛要更高了，讓你心裡面也感
覺不太踏實，不過越往前進生物們也就更加的凶狠，似乎在守護著什麼東西
一般，或許跟這棵樹上的奇特鳴聲有關。
LONG
        );
        set("exits", ([
  "east" : __DIR__"stn5",
]));
        set("no_clean_up", 0);
        set("light",0);
        set("item_desc", ([
            "枝幹" : "古木上的其中一段分枝，在離此處稍彽處，也許\可以跳下去(jump down)看看？\n",
            ]));   
        setup();
}


void init()
{
 add_action("do_jump","jump");
}

int do_jump(string arg)
{
  object me;
  me=this_player();
  if(!arg || arg != "down") return notify_fail("你要跳到哪裡 ?\n");
  if(me->is_busy())  return notify_fail("你正在忙\n");  
  message_vision("$N奮力往下一跳",me);
  me->start_busy(1);
  if(me->query_skill("dodge",1)<65){
   message_vision("，可是一時站不穩往樹下掉了下去\n",me);
   me->receive_wound("left_leg",5+random(20));
   me->receive_wound("right_leg",5+random(20));
   me->receive_wound("left_arm",5+random(20));
   me->receive_wound("right_arm",5+random(20));
   me->receive_wound("head",5+random(20));
   me->receive_wound("body",5+random(20));             
   me->receive_damage("hp",me->query("hp")*1/4);
   me->move(__DIR__"t18.c");
   tell_room(environment(me), "砰的一聲，"+me->name()+"從古木掉了下來，看來受傷不淺！\n", ({ me }));
  }    
  else {
  message_vision("，$N穩穩的跳上了枝幹上\n",me);    
  me->move(__DIR__"stn3");
  tell_room(environment(me), "忽然旁邊一陣聲響，"+me->name()+"從上面的枝幹優雅的落了下來！\n", ({ me }));
  }
  return 1;
}











