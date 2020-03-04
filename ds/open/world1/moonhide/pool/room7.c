#include <ansi.h> 
inherit ROOM; 
void create() 
{
        set("short", "水寒星洞");
        set("long", @LONG
洞頂裂縫滴下來的水，每一滴都留下了一點方解石，也溶解了
石灰石，慢慢累積成像冰柱一樣的懸狀垂石，像這種景觀，至少要
好幾百年才能形成。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"room10",  
  "east" : __DIR__"room4",
  "north" : __DIR__"room6",
])); 
        set("objects", ([ /* sizeof() == 1 */
 __DIR__"npc/bu-la-fish" : 1, 
]));
        set("no_clean_up", 0);

        setup();
}

