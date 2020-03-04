//u/c/chiaa/world2/blackly_forest/garrison2.c

#include <ansi.h>
inherit ROOM;

void create ()
{
  set("short", "駐守處");
  set("long", @LONG
當你從上方掉下來還搞不清楚方向時,映入你眼簾的居然是一個村落,
有幾個穿著類似忍者服裝的人,正盯著你看,
難道這就是傳聞中居住在黑暗森林的忍者一族嗎??
LONG
        );


  set("exits", ([ /* sizeof() == 4 */
     "up"    : __DIR__"nivi_entranceway",   //忍者村入口
     "east"  : __DIR__"hut",               //休息所
     "west"  : __DIR__"garrison1",         //駐守處1
     "south" : __DIR__"nivi_road1",        //忍村道路1
]));


 setup();
  replace_program(ROOM);
}
