#include <ansi.h>
inherit ROOM;

void create()
{
  set("short", "遺世島－"HIG"獸原"NOR);
  set("long", @LONG
這裡是一望無際的大草原的西北方，這裡的地勢較高，西北方是
一片高大的化石樹林，石林粗壯密集，加上周圍岩壁坍塌下來的落石
使得進入石林的路徑被阻斷，或許可以用輕功跳過去。
LONG
);
  set("exits", ([ /* sizeof() == 4 */
      "southwest" : __DIR__"room26",
      "southeast" : __DIR__"room24",
      "northeast" : __DIR__"room30",
     ]));
  set("no_clean_up", 0);
  set("outdoors","land");
  set("no_auc", 1);
  set("item_desc", ([
      "石林" : "高約數丈的一片岩壁，陡峭而濕滑。\n",
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
  if(!arg || arg!="石林" ) return 0;
  if(me->query_skill("dodge",2) <60)
  {
    message_vision("$N的輕身能力不足，踏斷樹枝掉了下來。\n",me);
    return 1;        
  }
  message_vision(HIW"$N提氣一躍而上，雙足連點，縱身上了石林。\n"NOR,me);
  me->move(__DIR__"room33");
  tell_room(environment(me),me->query("name")+"施展純熟的身法，從石林下跳了上來。\n",me );
  return 1;
}
