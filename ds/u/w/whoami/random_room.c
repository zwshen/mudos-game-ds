#include <ansi.h> 
#include <room.h> 
inherit ROOM;
string *mob =({
"slime2.c",
"mouse2.c",
"snake2.c",
"mutate rat2.c",
"rat2.c",
});

void create()
{
        set("short","【下水道】"HIY"測試屋"NOR);
        set("long", "
"NOR
     );
         
                            
         set("objects", ([ 
      "/d/road/npc/"+mob[random(5)] : 3,
      "/d/road/npc/"+mob[random(5)] : 1,
      "/d/road/npc/"+mob[random(5)] : 2,
      "/d/road/npc/"+mob[random(5)] : 3,
      "/d/road/npc/"+mob[random(5)] : 4,
]));

                  
        setup();
        
        
}

