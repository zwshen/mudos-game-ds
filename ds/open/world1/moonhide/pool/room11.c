#include <ansi.h> 
inherit ROOM; 
void create() 
{
        set("short", "水寒星洞");
        set("long", @LONG
不知道哪吹來的微風，使得沙粒落在丘脊上保持不動，愈堆愈
高，高出地表好幾餘尺，主要岩石的成份為雲母石，在丘脊部份，
凸出了一根石柱，與洞穴頂端相連接，應該就是此洞穴的支柱。 
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room13",  
  "east" : __DIR__"room9",
])); 
        set("objects", ([ /*sizeof == 1*/
  __DIR__"npc/small-fish":1,
])); 
         set("item_desc", ([
                "地洞" : "一個黑黑的洞，看來可以進去(enter)。\n",
                ]));
        set("no_clean_up", 0);  
          setup();
}void init()
{
        add_action("do_enter","enter");
}

int do_enter(string arg)
{
          object me;
          me=this_player();
          if(arg != "地洞")
            return 0;
          else {
            message_vision("$N往地洞鑽了下去。\n",me);
            me->move("/open/world1/moonhide/pool/test");
            return 1;
          }
}

