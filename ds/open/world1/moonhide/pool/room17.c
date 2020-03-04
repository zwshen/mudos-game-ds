#include <ansi.h> 
inherit ROOM; 
void create() 
{
        set("short", "水寒星洞");
        set("long", @LONG
在這裡，小細流在基岩劃下深深的河溝，使得這裡的地型，兩
旁比中間高，西方的不遠處，堆積著大量岩屑，許多小生物都聚集
在那裡。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"room20",  
  "east" : __DIR__"room14",
  "north" : __DIR__"room16",])); 
        set("objects",([ /* sizeof() == 1*/
  __DIR__"npc/la-ah":1,
  __DIR__"npc/bu-la-fish":2,
]));        set("no_clean_up", 0);

        setup();
}

