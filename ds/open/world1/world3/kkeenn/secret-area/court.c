#include <room.h>
inherit ROOM;
void create()
{
        set("short", "¦a¤U«°ªþÄÝªk°|");
        set("long", @LONG
¢z¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢{
    ¢x        Â÷                Â÷      ¢x
    ¢xÂ÷Â÷Â÷Â÷Â÷Â÷Â÷Â÷Â÷      Â÷        ¢x
    ¢x  Â÷Â÷      Â÷Â÷      Â÷Â÷        ¢x 
    ¢x  Â÷  Â÷  Â÷  Â÷    Â÷Â÷  Â÷      ¢x
    ¢x  Â÷    Â÷    Â÷  Â÷  Â÷    Â÷    ¢x
    ¢x  Â÷  Â÷  Â÷  Â÷      Â÷Â÷Â÷Â÷Â÷Â÷¢x
    ¢xÂ÷Â÷Â÷Â÷Â÷Â÷Â÷Â÷Â÷    Â÷    Â÷    ¢x
    ¢x        Â÷            Â÷    Â÷    ¢x
    ¢xÂ÷Â÷Â÷Â÷Â÷Â÷Â÷Â÷Â÷    Â÷Â÷Â÷Â÷Â÷Â÷¢x
    ¢xÂ÷      Â÷      Â÷    Â÷    Â÷    ¢x
    ¢xÂ÷      Â÷  Â÷  Â÷    Â÷    Â÷    ¢x
    ¢xÂ÷      Â÷  Â÷  Â÷    Â÷Â÷Â÷Â÷Â÷Â÷¢x
    ¢xÂ÷      Â÷Â÷Â÷  Â÷    Â÷    Â÷    ¢x
    ¢xÂ÷      Â÷  Â÷  Â÷    Â÷    Â÷    ¢x
    ¢xÂ÷    Â÷      Â÷Â÷    Â÷Â÷Â÷Â÷Â÷Â÷¢x 
    ¢|¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢}
LONG
        );
        set("exits", ([ /* sizeof() == 4 */ 
       "east":__DIR__"sec10.c",
]) ); 
        set("objects", ([ /* sizeof() == 1 */
 __DIR__"npc/judge.c" :1,
]));
        set("light",1);

        setup();
        replace_program(ROOM);

}

