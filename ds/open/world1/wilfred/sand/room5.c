#include <ansi.h>
inherit ROOM;
void create()
{
  set ("short", HIC"小河邊"NOR);
  set ("long", @LONG
這裡是個小小綠洲，一泓泉水，形成了一道銀色的小溪向東流去
，河邊稀落的幾棵樹，提供了清涼的庇蔭，跟黃沙道的酷熱氣候比起
來，這裡有如清涼世界，是個安靜謐寧的地方。
LONG
);

  set("exits", ([
  "east" : __DIR__"room6",
  "south" : __DIR__"room4",
]));
  set("objects",([
  __DIR__"npc/npc15" : 2,
]));
  set("item_desc", ([
  "泉水" : "從地底自然湧出的泉，看來清涼解渴，也許\你可以拿水袋來裝水(fill)。\n",
]));
  set("outdoors", "land");
  setup();
}

void init()
{
  add_action("do_fill","fill");
}

int do_fill()
{
  int i,index = 0;
  object me = this_player();
  object *inv;
  if(me->query("level") > 25) return notify_fail("此泉水僅供等級二十五之內的玩家使用\n");
  if(me->is_busy()) return notify_fail("你正在忙！\n");
  if(query("fill") > 500) return notify_fail("泉水將要乾涸了，還是水源回復時再說吧！\n");
  inv = all_inventory(me);
  if( !( present("traveler sack",me )) ) return notify_fail("你身上沒有可以裝水的東西。\n");
  for(i=0; i<sizeof(inv); i++)
  {
    if( inv[i]->query("id") == "traveler sack" )
    {
      if(inv[i]->query("fill_water") < 5)
      {
        inv[i]->add("fill_water",1);
        message_vision("$N用水袋裝了一些泉水。\n",me);
       add("fill",1);
        index++;
        break;
      }
      else continue;
    }
  }
  if(!index) return notify_fail("你身上的所有水袋都滿了。\n");
  return 1;
}

void reset()
{
  set("fill",0);
  ::reset();
}
