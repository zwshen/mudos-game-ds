#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"獵狐村"NOR"－"HIW"廣場"NOR);
 set("long",@LONG
這裡是獵狐村的廣場, 也是村民們的集會所, 附近來來往往
的人們不算多, 可是也不能說少, 在獵狐村裡的人們, 不是獵人
便是織布者, 他們對你的到來似乎非常的好奇.
LONG
    );
 
 set("exits",(["west":__DIR__"village3",
               "north":__DIR__"village12",
               "south":__DIR__"village5",
           ]));
 set("objects",([__DIR__"npc/villager" : 2+random(3),
     ]));
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        

