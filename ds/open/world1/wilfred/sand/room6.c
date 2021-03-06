#include <ansi.h>
inherit ROOM;
void create()
{
  set ("short", HIG"竹園"NOR);
  set ("long", @LONG
這裡種著許多青竹，蒼翠勁拔，顯然是有人特意加以照料的，竹
子分佈疏密有致，微風吹來，竹葉沙沙作響，彷如世外桃源。
LONG
);

  set("exits", ([
  "west" : __DIR__"room5",
  "north" : __DIR__"room7",
]));

  set("item_desc", ([
  "青竹" : "這裡長了許\多青竹，也許\可以砍(cut)下來製作東西。\n",
]));
  set("outdoors", "land");
  set("no_clean_up", 0);
  setup();
}

void init()
{
  add_action("do_cut","cut");
}

int do_cut(string str)
{
  object ob = this_object(), me = this_player();
  object axe;

  if(me->is_busy()) return notify_fail("你正忙著，沒空作其他事。\n");
  if(!str) return notify_fail("你要砍什麼呀?\n");
  if(str != "青竹" && str != "竹子") return notify_fail("這裡沒有" +str+ "。\n");
  if(!axe = present("axe",me)) return notify_fail("你需要一把斧頭來砍竹子。\n");
  if(ob->query("no_cut")) return notify_fail("你看到竹子快被砍光了，搖了搖頭，心想還是不要破壞如此美景好了。\n");
  
  message_vision("$N舉起手中的斧頭，使勁的朝著竹子攔腰砍去。\n",me);
  me->start_busy(2);
  ob->set("no_cut",1);
  call_out("loop",4);
  return 1;
}

int loop()
{
  object me = this_player();
  message_vision("啪啦！竹子從中斷成兩載。\n",me);
  message_vision("$N將竹子削枝去葉，作成了一把竹柺杖。\n",me);
  new(__DIR__"npc/wp/wp8")->move(environment(me));
  return 1;
}

void reset()
{
  delete("no_cut");
  return ::reset();
}
