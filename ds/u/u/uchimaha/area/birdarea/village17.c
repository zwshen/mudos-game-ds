#include <room.h>
inherit ROOM;
void create()
{
 set("short","屋頂上");
 set("long",@LONG
你到了一棟木屋的屋頂上, 突然看見有一位受了重傷
的人坐在那裡, 看地上的血跡, 她也許快不行了, 你可以
跳下屋頂去獵狐村.
LONG
    );
 
 set("exits",(["down":__DIR__"village15",
              ]));
 set("objects",([__DIR__"npc/purpler" : 1,
               ]));
 set("outdoors","land");
 set("no_fight",1);
 set("no_clean_up", 0);
 setup();
}        
