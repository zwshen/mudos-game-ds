// Room: /u/t/truewind/Minetown/area/machinefield5.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "漂浮車維修廠");
	set("long", @LONG
這裡是各類漂浮車維修的工廠，放眼望去，各式各樣的漂浮車堆
的跟山一樣高，幾乎要遮蔽了你的視線。這附近堆了很多大箱子還有
吃剩的垃圾，一股濃濃的臭味從身旁的大箱子底下傳出來，你不禁懷
疑這裡的管理員到底有沒有在做事情??
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 0);
        set("item_desc", ([ /* sizeof() == 1 */
  "大箱子" : "這裡有一大堆亂七八糟的箱子，其中有幾個好像可以推動(push)。
",
]));

	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"machinefield4",
  "south" : __DIR__"machinefield6",
  "east" : __DIR__"machinefield2",
  "down" : __DIR__"pool01",
]));
  set("no_clean_up", 0);
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
          if(arg != "大箱子")
            return 0;
          else {
            message_vision("$N左推右推的把大箱子一個一個推到一邊去...。\n\n",me);
            message_vision("$N在垃圾堆中發現了一個向下的地道入口。\n",me);
            set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"machinefield4",
  "south" : __DIR__"machinefield6",
  "east" : __DIR__"machinefield2",
  "down" : __DIR__"pool01",
]));
            return 1;
          }
}

void reset()
{
        set("exits", ([
        "north" : __DIR__"machinefield4",
        "south" : __DIR__"machinefield6",
        "east" : __DIR__"machinefield2",
        ]));
        ::reset();
}
