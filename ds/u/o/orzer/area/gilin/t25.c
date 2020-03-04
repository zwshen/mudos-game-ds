inherit ROOM;
void create()
{
        set("short","祭靈森林東側");
        set("long",@LONG
這裡已經蠻接近森林的最東側，寒氣總是如影隨形的緊跟著，東面
山壁有著一道小山澗，水質看起來還不錯，感覺可以洗把臉清醒一下，
可是從山澗中，似乎也有一股涼風吹來。
LONG
        );
        set("exits", ([
  "west" : __DIR__"t16",
   ]));
        set("item_desc", ([
            "山澗" : "一道山壁留下的泉水，水流看來不小，裡面似乎有個岩洞？\n",
            "岩洞" : "山壁上的一個小洞，被山澗遮掩著蠻難發現，也許\可以穿越(into)？\n",
         ]));   
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
}


void init()
{
 add_action("do_into","into");
}

int do_into(string arg)
{
  object me;
  me=this_player();
  if(!arg || arg != "岩洞") return notify_fail("你要穿越什麼東西 ?\n");
  if(me->is_busy())  return notify_fail("你正在忙\n");  
  message_vision("$N努力的往岩洞進入",me);
  me->start_busy(1);
  if(me->query_con()<50)
  message_vision("，可是體力不夠被水流沖了出來\n",me);
  else {
  message_vision("，$N無視水流穿了進去\n",me);    
  me->move(__DIR__"swn1");
  tell_room(environment(me), "轟隆一聲，"+me->name()+"從岩洞外撞了進來！\n", ({ me }));
  }
  return 1;
}








