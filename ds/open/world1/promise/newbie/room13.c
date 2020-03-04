#include <ansi.h>
inherit ROOM;

void create()
{
  set("short", "幼龍塔"HIR" 龍王座"NOR);
  set("long", @LONG
進入此地後，發覺殺氣凜冽，有數道龍眼朝此襲擊來，讓人感到毛骨
悚然，殺氣騰騰，想趕快離開此地，到外呼吸新鮮空氣。
LONG);
  set("exits", ([
  "north" : __DIR__"room12",
 ])); 
    set("item_desc", ([
                "銅門" : HIC"\n\t一道用銅做的門，似乎可以推開(push)的樣子？\n\n"NOR,
]));
  set("no_member",1); 
  set("objects", ([ /* sizeof() == 1 */
 __DIR__"npc/dragon-king" : 1,
]));
 set("no_recall",1);
    set("no_clean_up",0);
  set("outdoor",0);
  setup();
}
void init()
{
        add_action("do_push","push");
}

int do_push(string arg)
{
          object me;
          me=this_player();
          if(arg != "銅門")
            return 0;
          else {
            message_vision("$N"HIW"用力推開的銅門，然後飛了出去不見人影！！\n"NOR,me);
            me->move("/open/world1/tmr/area/hotel");
            return 1;
          }
}

