#include <ansi.h>
inherit ROOM;
void create()
{
    set("short",HIG"古東討論室"NOR);
set("long",HIW"\n\n\t為古東所開的討論室\n\n"NOR);
             set("exits", ([ /* sizeof() == 1 */
"west":"/u/j/jsh/workroom",
])); 
     setup(); 
call_other("/obj/board/peboard_b","???");
}

