//u/t/tqc/world1/blackly_forest/nivi_vacancy.c
#include <ansi.h>

inherit ROOM;
void create()
{
        set("short", "空地");
        set("long", @LONG
這裡是忍者村東邊的一小片空地,
四周都有訓練後留下的痕跡,不知是何人為!!
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  
   "northwest"  : __DIR__"parade3",      //訓練區3
 
 ]));
       
        setup();
replace_program(ROOM);
}

