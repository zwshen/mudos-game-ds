//u/c/chiaa/world2/blackly_forest/path1.c

#include <path.h>    
inherit ROOM;
void create()
{
        set("short", "小徑");
        set("long", @LONG
這是一條頗不成路的小徑,其路的狹隘不過數步之寬,
行走其間,就像是在樹與樹之間的空隙行走,
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
     "south"  : __DIR__"trail1",   //幽徑1
  
]));
       
            setup();
replace_program(ROOM);
}
