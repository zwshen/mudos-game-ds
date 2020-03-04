#include <weapon.h>
inherit ROOM;

void create()
{

set("short","¥D¿ì¤½«Ç");
set("long", @LONG
     

LONG
);

set("valid_startroom", 1);     
set("light",1);
set("exits", ([ 
                
                "south"  : "/u/p/piliykt/a_1.c", 
   
                    ]));

 setup();
        load_object("/obj/board/piliykt_b.c");
}

